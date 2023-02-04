#include "../mag_i.h"
#include <stdio.h>
#include <string.h>

#define LF_HZ 125000
#define LF_PULSE_US 60

void play_halfbit(bool value, MagSetting* setting);
void play_track(uint8_t* bits_manchester, uint16_t n_bits, MagSetting* setting, bool reverse);

void tx_init_rf(int hz);
void tx_init_rfid();
void tx_init_piezo();
bool tx_init(MagSetting* setting);
void tx_deinit_piezo();
void tx_deinit_rfid();
bool tx_deinit(MagSetting* setting);

uint16_t add_bit(bool value, uint8_t* out, uint16_t count);
uint16_t add_bit_manchester(bool value, uint8_t* out, uint16_t count);
uint16_t mag_encode(
    char* data,
    uint8_t* out_manchester,
    uint8_t* out_raw,
    uint8_t track_bits,
    uint8_t track_ascii_offset);
void debug_mag_string(char* data, uint8_t track_bits, uint8_t track_ascii_offset);
void mag_spoof(Mag* mag);
void mag_spoof_raw(Mag* mag);

void lf_carrier_deinit();
void lf_carrier_init(int freq, float duty_cycle);
void lf_set_carrier(bool value);
void lf_carrier_pulse();
void lf_comparator_trigger_callback_isr(bool level, void *ctx);
