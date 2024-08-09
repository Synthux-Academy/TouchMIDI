#include "daisy_seed.h"
#include "daisysp.h"
#include "midi_ui.h"
#include "touch/touch.h"
// #include "log.h"

using namespace daisy;
using namespace daisysp;
using namespace synthux;

DaisySeed hw;
MIDIUI ui;

int main(void)
{
	hw.Init();
	ui.Init(hw);

	// HW::hw().setHW(&hw);
	// HW::hw().startLog();

	while(1) {
		ui.Process(hw);
		System::Delay(4);
	}
}
