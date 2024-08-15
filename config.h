#pragma once

static const uint8_t midi_channel = 1;

///////////////////////////////////////////////////////////////////////////////
// PADS //////////////////////////////////////////////////////////////////////
static const uint8_t scale[7] = { 60, 62, 64, 65, 67, 69, 71 };

///////////////////////////////////////////////////////////////////////////////
// SWITCHES ///////////////////////////////////////////////////////////////////
static const uint8_t SWITCH_A_NR = 29; // the one on the left (S09/S10)
static const uint8_t SWITCH_B_NR = 30; // the one on the right (S07/S08)

///////////////////////////////////////////////////////////////////////////////
// KNOBS & FADERS /////////////////////////////////////////////////////////////
// SXX_NR -> is default controller number of the knob /////////////////////////
// SXX_TO_NR -> is controller number of the knob when TO (pad 10) is touched //
// SXX_CH_NR -> is controller number of the knob when CH (pad 11) is touched //
//    |-| (*)   (*)   (*)    (*) |-|
//    | | S31   S32   S33    S34 | |
//    |||                        |||
//    |_| (*)                (*) |_|
//    S36 S30                S35 S37
//
//      S10 o o S09    o S07
//                   o S08

static const uint8_t S30_NR = 5;
static const uint8_t S30_TO_NR = 6;
static const uint8_t S30_CH_NR = 7;

static const uint8_t S31_NR = 8;
static const uint8_t S31_TO_NR = 9;
static const uint8_t S31_CH_NR = 10;

static const uint8_t S32_NR = 11;
static const uint8_t S32_TO_NR = 12;
static const uint8_t S32_CH_NR = 13;

static const uint8_t S33_NR = 14;
static const uint8_t S33_TO_NR = 15;
static const uint8_t S33_CH_NR = 16;

static const uint8_t S34_NR = 17;
static const uint8_t S34_TO_NR = 18;
static const uint8_t S34_CH_NR = 19;

static const uint8_t S35_NR = 20;
static const uint8_t S35_TO_NR = 21;
static const uint8_t S35_CH_NR = 22;

static const uint8_t S36_NR = 23;
static const uint8_t S36_TO_NR = 24;
static const uint8_t S36_CH_NR = 25;

static const uint8_t S37_NR = 26;
static const uint8_t S37_TO_NR = 27;
static const uint8_t S37_CH_NR = 28;
