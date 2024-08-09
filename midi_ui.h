#pragma once

#include "config.h"
#include "daisy_seed.h"
#include "touch/touch.h"
#include "mintvalue.h"
#include "nocopy.h"

namespace synthux {

class MIDIUI {
public:
    MIDIUI();
    ~MIDIUI() {}

    void Init(daisy::DaisySeed& hw);
    void Process(daisy::DaisySeed& hw);

private:
    NOCOPY(MIDIUI)

    void _on_pad_touch(uint16_t pad);
    void _on_pad_release(uint16_t pad);
    void _process_midi();

    static constexpr uint8_t kNotesCount = 7;
    static constexpr uint16_t kFirstNotePad = 3;

    static constexpr uint8_t kKnobsCount = 8;

    bool _is_to_touched;
    bool _is_ch_touched;

    daisy::MidiUsbHandler _midi;
    Touch _touch;

    MIntValue _s30;
    MIntValue _s30_to;
    MIntValue _s30_ch;

    MIntValue _s31;
    MIntValue _s31_to;
    MIntValue _s31_ch;

    MIntValue _s32;
    MIntValue _s32_to;
    MIntValue _s32_ch;

    MIntValue _s33;
    MIntValue _s33_to;
    MIntValue _s33_ch;

    MIntValue _s34;
    MIntValue _s34_to;
    MIntValue _s34_ch;

    MIntValue _s35;
    MIntValue _s35_to;
    MIntValue _s35_ch;

    MIntValue _s36;
    MIntValue _s36_to;
    MIntValue _s36_ch;

    MIntValue _s37;
    MIntValue _s37_to;
    MIntValue _s37_ch;

    uint8_t _switch_a_value;
    uint8_t _switch_b_value;

    daisy::AnalogControl* _knob[kKnobsCount];

    MIntValue* _val[kKnobsCount] = {
        &_s30, 
        &_s31, 
        &_s32, 
        &_s33, 
        &_s34, 
        &_s35, 
        &_s36, 
        &_s37 
    };

    MIntValue* _val_to[kKnobsCount] = {    
        &_s30_to, 
        &_s31_to, 
        &_s32_to, 
        &_s33_to, 
        &_s34_to, 
        &_s35_to, 
        &_s36_to, 
        &_s37_to 
    };

    MIntValue* _val_ch[kKnobsCount] = {
        &_s30_ch, 
        &_s31_ch, 
        &_s32_ch, 
        &_s33_ch, 
        &_s34_ch, 
        &_s35_ch, 
        &_s36_ch, 
        &_s37_ch 
    };

    char ctrl_nr[kKnobsCount] = {
        S30_NR,
        S31_NR,
        S32_NR,
        S33_NR,
        S34_NR,
        S35_NR,
        S36_NR,
        S37_NR
    };

    char ctrl_nr_to[kKnobsCount] = {
        S30_TO_NR,
        S31_TO_NR,
        S32_TO_NR,
        S33_TO_NR,
        S34_TO_NR,
        S35_TO_NR,
        S36_TO_NR,
        S37_TO_NR
    };

    char ctrl_nr_ch[kKnobsCount] = {
        S30_CH_NR,
        S31_CH_NR,
        S32_CH_NR,
        S33_CH_NR,
        S34_CH_NR,
        S35_CH_NR,
        S36_CH_NR,
        S37_CH_NR
    };
};

};
