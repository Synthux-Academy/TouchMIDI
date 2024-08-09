#include "midi_ui.h"

using namespace synthux;
using namespace daisy;

void send_note_on(const uint8_t number, MidiUsbHandler& midi) {
    uint8_t data[3] = { 0 };
    
    data[0] = (midi_channel & 0x0F) + 0x90;
    data[1] = number;
    data[2] = 0x7F;

    midi.SendMessage(data, 3);
};

void send_note_off(const uint8_t number, MidiUsbHandler& midi) {
    uint8_t data[3] = { 0 };
    
    data[0] = (midi_channel & 0x0F) + 0x80;
    data[1] = number & 0x7F;
    data[2] = 0x7F;

    midi.SendMessage(data, 3);
};

void send_controller(char controller_number, uint8_t value, MidiUsbHandler& midi) {
    uint8_t data[3] = { 0 };
    
    data[0] = (midi_channel & 0x0F) + 0xB0;
    data[1] = controller_number & 0x7F;
    data[2] = value & 0x7F;

    midi.SendMessage(data, 3);
};

void process_switch(uint8_t value, char controller_number, MidiUsbHandler& midi) {
    uint8_t ctrl_value;
    if (value == 2) { ctrl_value = 0; }
    else if (value == 1) { ctrl_value = 127; }
    else { ctrl_value = 64; }

    send_controller(controller_number, ctrl_value, midi);
}

void process_value(MIntValue& v, char controller_number, MidiUsbHandler& midi) {
    if (!v.IsTracking()) return;

    send_controller(controller_number, v.Value(), midi);  
};

MIDIUI::MIDIUI():
_switch_a_value { 0xff },
_switch_b_value { 0xff }
{
    auto& knobs = _touch.knobs();
    _knob[0] = &(knobs.s30());
    _knob[1] = &(knobs.s31());
    _knob[2] = &(knobs.s32());
    _knob[3] = &(knobs.s33());
    _knob[4] = &(knobs.s34());
    _knob[5] = &(knobs.s35());
    _knob[6] = &(knobs.s36());
    _knob[7] = &(knobs.s37());
};

void MIDIUI::Init(daisy::DaisySeed& hw) {
    _touch.Init(hw);

    // Assign callbacks ////////////////////////////////////////
    ////////////////////////////////////////////////////////////
    using namespace std::placeholders;
    auto on_touch = std::bind(&MIDIUI::_on_pad_touch, this, _1);
    auto on_release = std::bind(&MIDIUI::_on_pad_release, this, _1);
    _touch.pads().SetOnTouch(on_touch);
    _touch.pads().SetOnRelease(on_release);

    MidiUsbHandler::Config cfg;
    _midi.Init(cfg);
};

void MIDIUI::_on_pad_touch(uint16_t pad) {
    if (pad >= kFirstNotePad && pad <= kFirstNotePad + kNotesCount - 1) {
        send_note_on(scale[pad - kFirstNotePad], _midi);
    }
};

void MIDIUI::_on_pad_release(uint16_t pad) {
    if (pad >= kFirstNotePad && pad <= kFirstNotePad + kNotesCount - 1) {
        send_note_off(scale[pad - kFirstNotePad], _midi);
    }
};

void MIDIUI::Process(daisy::DaisySeed& hw) {
    _touch.Process();

    _is_to_touched = _touch.pads().IsTouched(10);
    _is_ch_touched = _touch.pads().IsTouched(11);
    auto is_none_touched = !_is_to_touched && !_is_ch_touched;

    for (auto i = 0; i < kKnobsCount; i++) {
        auto knob_val = static_cast<uint16_t>(_knob[i]->Process() * 127.f);
        _val[i]->Process(knob_val, is_none_touched);
        process_value(*(_val[i]), ctrl_nr[i], _midi);

        _val_to[i]->Process(knob_val, _is_to_touched);
        process_value(*(_val_to[i]), ctrl_nr_to[i], _midi);

        _val_ch[i]->Process(knob_val, _is_ch_touched);
        process_value(*(_val_ch[i]), ctrl_nr_ch[i], _midi);
    }

    auto switch_a_new = _touch.switches().A();
    if (switch_a_new != _switch_a_value) {
        _switch_a_value = switch_a_new;
        process_switch(switch_a_new, SWITCH_A_NR, _midi); 
    }

    auto switch_b_new = _touch.switches().B();
    if (switch_b_new != _switch_b_value) {
        _switch_b_value = switch_b_new;
        process_switch(switch_b_new, SWITCH_B_NR, _midi);
    }    
};
