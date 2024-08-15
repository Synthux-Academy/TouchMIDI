# TouchMIDI

## QUICK INSTALL
Download the [Binary file](https://github.com/Synthux-Academy/TouchMIDI/raw/main/TouchMIDI.bin) and flash using the [Daisy Seed web programmer](https://electro-smith.github.io/Programmer/)

## CONTROLS
See [config.h](https://github.com/Synthux-Academy/TouchMIDI/blob/main/config.h)

## SETUP
```shell
$ git clone --recurse-submodules https://github.com/Synthux-Academy/TouchMIDI.git
$ cd TouchMIDI/lib/libDaisy
$ make
$ cd ../DaisySP
$ make
$ cd ../.. 
$ make clean; make
```

## UPLOAD
```shell
$ make program-dfu
```
