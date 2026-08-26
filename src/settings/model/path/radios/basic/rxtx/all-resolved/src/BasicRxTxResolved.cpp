#include "BasicRxTxResolved.h"

// Pre-resolved field descriptors (no string processing at runtime)
// Uncomment the ones you need, likewise in BasicRxTxResolved.h
/*
const SettingDescriptor active_bands = SettingDescriptor(
    SettingPath{1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band = SettingDescriptor(
    SettingPath{1, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_band_request = SettingDescriptor(
    SettingPath{1, 1, 1},
    AutoCompleteTrigger::BAND,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_band = SettingDescriptor(
    SettingPath{1, 1, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_band_name = SettingDescriptor(
    SettingPath{1, 1, 2, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_band_label = SettingDescriptor(
    SettingPath{1, 1, 2, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_band_lowest_frequency = SettingDescriptor(
    SettingPath{1, 1, 2, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_band_highest_frequency = SettingDescriptor(
    SettingPath{1, 1, 2, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_band_landing_frequency = SettingDescriptor(
    SettingPath{1, 1, 2, 5},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_band_default_fine_step = SettingDescriptor(
    SettingPath{1, 1, 2, 6},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_band_default_coarse_step = SettingDescriptor(
    SettingPath{1, 1, 2, 7},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_band_default_mode = SettingDescriptor(
    SettingPath{1, 1, 2, 8},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_band_default_mode_type = SettingDescriptor(
    SettingPath{1, 1, 2, 8, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_band_default_mode_name = SettingDescriptor(
    SettingPath{1, 1, 2, 8, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_band_default_mode_label = SettingDescriptor(
    SettingPath{1, 1, 2, 8, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_band_default_mode_lo_cut = SettingDescriptor(
    SettingPath{1, 1, 2, 8, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_band_default_mode_hi_cut = SettingDescriptor(
    SettingPath{1, 1, 2, 8, 5},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_band_default_mode_offset = SettingDescriptor(
    SettingPath{1, 1, 2, 8, 6},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_mode_request = SettingDescriptor(
    SettingPath{1, 1, 3},
    AutoCompleteTrigger::MODE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_mode = SettingDescriptor(
    SettingPath{1, 1, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_mode_type = SettingDescriptor(
    SettingPath{1, 1, 4, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_mode_name = SettingDescriptor(
    SettingPath{1, 1, 4, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_mode_label = SettingDescriptor(
    SettingPath{1, 1, 4, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_mode_lo_cut = SettingDescriptor(
    SettingPath{1, 1, 4, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_mode_hi_cut = SettingDescriptor(
    SettingPath{1, 1, 4, 5},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_mode_offset = SettingDescriptor(
    SettingPath{1, 1, 4, 6},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_rf = SettingDescriptor(
    SettingPath{1, 1, 5},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_rf_frequency = SettingDescriptor(
    SettingPath{1, 1, 5, 1001},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_rf_frequency_value = SettingDescriptor(
    SettingPath{1, 1, 5, 1001, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_rf_frequency_coarse_delta = SettingDescriptor(
    SettingPath{1, 1, 5, 1001, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_rf_frequency_fine_delta = SettingDescriptor(
    SettingPath{1, 1, 5, 1001, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_rf_frequency_use_fine = SettingDescriptor(
    SettingPath{1, 1, 5, 1001, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_rf_gain = SettingDescriptor(
    SettingPath{1, 1, 5, 1002},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_rf_gain_value = SettingDescriptor(
    SettingPath{1, 1, 5, 1002, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_rf_gain_coarse_delta = SettingDescriptor(
    SettingPath{1, 1, 5, 1002, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_rf_gain_fine_delta = SettingDescriptor(
    SettingPath{1, 1, 5, 1002, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_rf_gain_use_fine = SettingDescriptor(
    SettingPath{1, 1, 5, 1002, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_if = SettingDescriptor(
    SettingPath{1, 1, 6},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_if_gain = SettingDescriptor(
    SettingPath{1, 1, 6, 1001},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_if_gain_value = SettingDescriptor(
    SettingPath{1, 1, 6, 1001, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_if_gain_coarse_delta = SettingDescriptor(
    SettingPath{1, 1, 6, 1001, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_if_gain_fine_delta = SettingDescriptor(
    SettingPath{1, 1, 6, 1001, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_if_gain_use_fine = SettingDescriptor(
    SettingPath{1, 1, 6, 1001, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_if_bandwidth = SettingDescriptor(
    SettingPath{1, 1, 6, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_agc_speed = SettingDescriptor(
    SettingPath{1, 1, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor receiver = SettingDescriptor(
    SettingPath{2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor receiver_volume = SettingDescriptor(
    SettingPath{2, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor receiver_volume_gain = SettingDescriptor(
    SettingPath{2, 2, 1001},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor receiver_volume_gain_value = SettingDescriptor(
    SettingPath{2, 2, 1001, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor receiver_volume_gain_coarse_delta = SettingDescriptor(
    SettingPath{2, 2, 1001, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor receiver_volume_gain_fine_delta = SettingDescriptor(
    SettingPath{2, 2, 1001, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor receiver_volume_gain_use_fine = SettingDescriptor(
    SettingPath{2, 2, 1001, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor transmitter = SettingDescriptor(
    SettingPath{3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor transmitter_mic = SettingDescriptor(
    SettingPath{3, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor transmitter_mic_gain = SettingDescriptor(
    SettingPath{3, 2, 1001},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor transmitter_mic_gain_value = SettingDescriptor(
    SettingPath{3, 2, 1001, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor transmitter_mic_gain_coarse_delta = SettingDescriptor(
    SettingPath{3, 2, 1001, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor transmitter_mic_gain_fine_delta = SettingDescriptor(
    SettingPath{3, 2, 1001, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor transmitter_mic_gain_use_fine = SettingDescriptor(
    SettingPath{3, 2, 1001, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor ptt = SettingDescriptor(
    SettingPath{4},
    AutoCompleteTrigger::NONE,
    false
);
*/
