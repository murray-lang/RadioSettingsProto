#include "settings/model/path/SplitBandDualIqResolved.h"

// Pre-resolved field descriptors (no string processing at runtime)
// Uncomment the ones you need, likewise in SplitBandDualIqResolved.h
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
    true
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
const SettingDescriptor active_bands_focus_band_focus_pipeline = SettingDescriptor(
    SettingPath{1, 1, 10},
    AutoCompleteTrigger::NONE,
    true
);
*/
/*
const SettingDescriptor active_bands_focus_band_focus_pipeline_base = SettingDescriptor(
    SettingPath{1, 1, 10, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_focus_pipeline_base_mode_request = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 1},
    AutoCompleteTrigger::MODE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_focus_pipeline_base_mode = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_focus_pipeline_base_mode_type = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 2, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_focus_pipeline_base_mode_name = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 2, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_focus_pipeline_base_mode_label = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 2, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_focus_pipeline_base_mode_lo_cut = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 2, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_focus_pipeline_base_mode_hi_cut = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 2, 5},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_focus_pipeline_base_mode_offset = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 2, 6},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_focus_pipeline_base_rf = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_focus_pipeline_base_rf_frequency = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 3, 1001},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_focus_pipeline_base_rf_frequency_value = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 3, 1001, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_focus_pipeline_base_rf_frequency_coarse_delta = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 3, 1001, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_focus_pipeline_base_rf_frequency_fine_delta = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 3, 1001, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_focus_pipeline_base_rf_frequency_use_fine = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 3, 1001, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_focus_pipeline_base_rf_max_negative_offset = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 3, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_focus_pipeline_base_rf_max_positive_offset = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 3, 5},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_focus_pipeline_base_iq_corrections = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_focus_pipeline_base_iq_corrections_amplitude = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 4, 1001},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_focus_pipeline_base_iq_corrections_amplitude_value = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 4, 1001, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_focus_pipeline_base_iq_corrections_amplitude_coarse_delta = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 4, 1001, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_focus_pipeline_base_iq_corrections_amplitude_fine_delta = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 4, 1001, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_focus_pipeline_base_iq_corrections_amplitude_use_fine = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 4, 1001, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_focus_pipeline_base_iq_corrections_phase = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 4, 1002},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_focus_pipeline_base_iq_corrections_phase_value = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 4, 1002, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_focus_pipeline_base_iq_corrections_phase_coarse_delta = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 4, 1002, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_focus_pipeline_base_iq_corrections_phase_fine_delta = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 4, 1002, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_focus_pipeline_base_iq_corrections_phase_use_fine = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 4, 1002, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_focus_pipeline_mute = SettingDescriptor(
    SettingPath{1, 1, 10, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_focus_pipeline_agc_speed = SettingDescriptor(
    SettingPath{1, 1, 10, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_a = SettingDescriptor(
    SettingPath{1, 1, 11},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_a_base = SettingDescriptor(
    SettingPath{1, 1, 11, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_a_base_mode_request = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 1},
    AutoCompleteTrigger::MODE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_a_base_mode = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_a_base_mode_type = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 2, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_a_base_mode_name = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 2, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_a_base_mode_label = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 2, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_a_base_mode_lo_cut = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 2, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_a_base_mode_hi_cut = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 2, 5},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_a_base_mode_offset = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 2, 6},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_a_base_rf = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_a_base_rf_frequency = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 3, 1001},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_a_base_rf_frequency_value = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 3, 1001, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_a_base_rf_frequency_coarse_delta = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 3, 1001, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_a_base_rf_frequency_fine_delta = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 3, 1001, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_a_base_rf_frequency_use_fine = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 3, 1001, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_a_base_rf_max_negative_offset = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 3, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_a_base_rf_max_positive_offset = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 3, 5},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_a_base_iq_corrections = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_a_base_iq_corrections_amplitude = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 4, 1001},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_a_base_iq_corrections_amplitude_value = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 4, 1001, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_a_base_iq_corrections_amplitude_coarse_delta = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 4, 1001, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_a_base_iq_corrections_amplitude_fine_delta = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 4, 1001, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_a_base_iq_corrections_amplitude_use_fine = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 4, 1001, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_a_base_iq_corrections_phase = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 4, 1002},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_a_base_iq_corrections_phase_value = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 4, 1002, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_a_base_iq_corrections_phase_coarse_delta = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 4, 1002, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_a_base_iq_corrections_phase_fine_delta = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 4, 1002, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_a_base_iq_corrections_phase_use_fine = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 4, 1002, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_a_mute = SettingDescriptor(
    SettingPath{1, 1, 11, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_a_agc_speed = SettingDescriptor(
    SettingPath{1, 1, 11, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_b = SettingDescriptor(
    SettingPath{1, 1, 12},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_b_base = SettingDescriptor(
    SettingPath{1, 1, 12, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_b_base_mode_request = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 1},
    AutoCompleteTrigger::MODE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_b_base_mode = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_b_base_mode_type = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 2, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_b_base_mode_name = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 2, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_b_base_mode_label = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 2, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_b_base_mode_lo_cut = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 2, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_b_base_mode_hi_cut = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 2, 5},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_b_base_mode_offset = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 2, 6},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_b_base_rf = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_b_base_rf_frequency = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 3, 1001},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_b_base_rf_frequency_value = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 3, 1001, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_b_base_rf_frequency_coarse_delta = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 3, 1001, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_b_base_rf_frequency_fine_delta = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 3, 1001, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_b_base_rf_frequency_use_fine = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 3, 1001, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_b_base_rf_max_negative_offset = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 3, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_b_base_rf_max_positive_offset = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 3, 5},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_b_base_iq_corrections = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_b_base_iq_corrections_amplitude = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 4, 1001},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_b_base_iq_corrections_amplitude_value = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 4, 1001, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_b_base_iq_corrections_amplitude_coarse_delta = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 4, 1001, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_b_base_iq_corrections_amplitude_fine_delta = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 4, 1001, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_b_base_iq_corrections_amplitude_use_fine = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 4, 1001, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_b_base_iq_corrections_phase = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 4, 1002},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_b_base_iq_corrections_phase_value = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 4, 1002, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_b_base_iq_corrections_phase_coarse_delta = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 4, 1002, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_b_base_iq_corrections_phase_fine_delta = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 4, 1002, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_b_base_iq_corrections_phase_use_fine = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 4, 1002, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_b_mute = SettingDescriptor(
    SettingPath{1, 1, 12, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_pipeline_b_agc_speed = SettingDescriptor(
    SettingPath{1, 1, 12, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_is_multi_pipeline = SettingDescriptor(
    SettingPath{1, 1, 13},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_focus_pipeline_id = SettingDescriptor(
    SettingPath{1, 1, 14},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_tx_pipeline = SettingDescriptor(
    SettingPath{1, 1, 15},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_tx_pipeline_base = SettingDescriptor(
    SettingPath{1, 1, 15, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_tx_pipeline_base_mode_request = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 1},
    AutoCompleteTrigger::MODE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_tx_pipeline_base_mode = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_tx_pipeline_base_mode_type = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 2, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_tx_pipeline_base_mode_name = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 2, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_tx_pipeline_base_mode_label = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 2, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_tx_pipeline_base_mode_lo_cut = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 2, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_tx_pipeline_base_mode_hi_cut = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 2, 5},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_tx_pipeline_base_mode_offset = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 2, 6},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_tx_pipeline_base_rf = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_tx_pipeline_base_rf_frequency = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 3, 1001},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_tx_pipeline_base_rf_frequency_value = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 3, 1001, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_tx_pipeline_base_rf_frequency_coarse_delta = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 3, 1001, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_tx_pipeline_base_rf_frequency_fine_delta = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 3, 1001, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_tx_pipeline_base_rf_frequency_use_fine = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 3, 1001, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_tx_pipeline_base_rf_max_negative_offset = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 3, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_tx_pipeline_base_rf_max_positive_offset = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 3, 5},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_tx_pipeline_base_iq_corrections = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_tx_pipeline_base_iq_corrections_amplitude = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 4, 1001},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_tx_pipeline_base_iq_corrections_amplitude_value = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 4, 1001, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_tx_pipeline_base_iq_corrections_amplitude_coarse_delta = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 4, 1001, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_tx_pipeline_base_iq_corrections_amplitude_fine_delta = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 4, 1001, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_tx_pipeline_base_iq_corrections_amplitude_use_fine = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 4, 1001, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_tx_pipeline_base_iq_corrections_phase = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 4, 1002},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_tx_pipeline_base_iq_corrections_phase_value = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 4, 1002, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_tx_pipeline_base_iq_corrections_phase_coarse_delta = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 4, 1002, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_tx_pipeline_base_iq_corrections_phase_fine_delta = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 4, 1002, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_tx_pipeline_base_iq_corrections_phase_use_fine = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 4, 1002, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_focus_band_tx_pipeline_id = SettingDescriptor(
    SettingPath{1, 1, 16},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1 = SettingDescriptor(
    SettingPath{1, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_band_request = SettingDescriptor(
    SettingPath{1, 1, 1},
    AutoCompleteTrigger::BAND,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_band = SettingDescriptor(
    SettingPath{1, 1, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_band_name = SettingDescriptor(
    SettingPath{1, 1, 2, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_band_label = SettingDescriptor(
    SettingPath{1, 1, 2, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_band_lowest_frequency = SettingDescriptor(
    SettingPath{1, 1, 2, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_band_highest_frequency = SettingDescriptor(
    SettingPath{1, 1, 2, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_band_landing_frequency = SettingDescriptor(
    SettingPath{1, 1, 2, 5},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_band_default_fine_step = SettingDescriptor(
    SettingPath{1, 1, 2, 6},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_band_default_coarse_step = SettingDescriptor(
    SettingPath{1, 1, 2, 7},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_band_default_mode = SettingDescriptor(
    SettingPath{1, 1, 2, 8},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_band_default_mode_type = SettingDescriptor(
    SettingPath{1, 1, 2, 8, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_band_default_mode_name = SettingDescriptor(
    SettingPath{1, 1, 2, 8, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_band_default_mode_label = SettingDescriptor(
    SettingPath{1, 1, 2, 8, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_band_default_mode_lo_cut = SettingDescriptor(
    SettingPath{1, 1, 2, 8, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_band_default_mode_hi_cut = SettingDescriptor(
    SettingPath{1, 1, 2, 8, 5},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_band_default_mode_offset = SettingDescriptor(
    SettingPath{1, 1, 2, 8, 6},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_rf = SettingDescriptor(
    SettingPath{1, 1, 5},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_rf_frequency = SettingDescriptor(
    SettingPath{1, 1, 5, 1001},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_rf_frequency_value = SettingDescriptor(
    SettingPath{1, 1, 5, 1001, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_rf_frequency_coarse_delta = SettingDescriptor(
    SettingPath{1, 1, 5, 1001, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_rf_frequency_fine_delta = SettingDescriptor(
    SettingPath{1, 1, 5, 1001, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_rf_frequency_use_fine = SettingDescriptor(
    SettingPath{1, 1, 5, 1001, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_rf_gain = SettingDescriptor(
    SettingPath{1, 1, 5, 1002},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_rf_gain_value = SettingDescriptor(
    SettingPath{1, 1, 5, 1002, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_rf_gain_coarse_delta = SettingDescriptor(
    SettingPath{1, 1, 5, 1002, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_rf_gain_fine_delta = SettingDescriptor(
    SettingPath{1, 1, 5, 1002, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_rf_gain_use_fine = SettingDescriptor(
    SettingPath{1, 1, 5, 1002, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_if = SettingDescriptor(
    SettingPath{1, 1, 6},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_if_gain = SettingDescriptor(
    SettingPath{1, 1, 6, 1001},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_if_gain_value = SettingDescriptor(
    SettingPath{1, 1, 6, 1001, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_if_gain_coarse_delta = SettingDescriptor(
    SettingPath{1, 1, 6, 1001, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_if_gain_fine_delta = SettingDescriptor(
    SettingPath{1, 1, 6, 1001, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_if_gain_use_fine = SettingDescriptor(
    SettingPath{1, 1, 6, 1001, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_if_bandwidth = SettingDescriptor(
    SettingPath{1, 1, 6, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_focus_pipeline = SettingDescriptor(
    SettingPath{1, 1, 10},
    AutoCompleteTrigger::NONE,
    true
);
*/
/*
const SettingDescriptor active_bands_band_1_focus_pipeline_base = SettingDescriptor(
    SettingPath{1, 1, 10, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_focus_pipeline_base_mode_request = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 1},
    AutoCompleteTrigger::MODE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_focus_pipeline_base_mode = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_focus_pipeline_base_mode_type = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 2, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_focus_pipeline_base_mode_name = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 2, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_focus_pipeline_base_mode_label = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 2, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_focus_pipeline_base_mode_lo_cut = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 2, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_focus_pipeline_base_mode_hi_cut = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 2, 5},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_focus_pipeline_base_mode_offset = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 2, 6},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_focus_pipeline_base_rf = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_focus_pipeline_base_rf_frequency = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 3, 1001},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_focus_pipeline_base_rf_frequency_value = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 3, 1001, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_focus_pipeline_base_rf_frequency_coarse_delta = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 3, 1001, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_focus_pipeline_base_rf_frequency_fine_delta = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 3, 1001, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_focus_pipeline_base_rf_frequency_use_fine = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 3, 1001, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_focus_pipeline_base_rf_max_negative_offset = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 3, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_focus_pipeline_base_rf_max_positive_offset = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 3, 5},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_focus_pipeline_base_iq_corrections = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_focus_pipeline_base_iq_corrections_amplitude = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 4, 1001},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_focus_pipeline_base_iq_corrections_amplitude_value = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 4, 1001, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_focus_pipeline_base_iq_corrections_amplitude_coarse_delta = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 4, 1001, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_focus_pipeline_base_iq_corrections_amplitude_fine_delta = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 4, 1001, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_focus_pipeline_base_iq_corrections_amplitude_use_fine = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 4, 1001, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_focus_pipeline_base_iq_corrections_phase = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 4, 1002},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_focus_pipeline_base_iq_corrections_phase_value = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 4, 1002, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_focus_pipeline_base_iq_corrections_phase_coarse_delta = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 4, 1002, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_focus_pipeline_base_iq_corrections_phase_fine_delta = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 4, 1002, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_focus_pipeline_base_iq_corrections_phase_use_fine = SettingDescriptor(
    SettingPath{1, 1, 10, 1, 4, 1002, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_focus_pipeline_mute = SettingDescriptor(
    SettingPath{1, 1, 10, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_focus_pipeline_agc_speed = SettingDescriptor(
    SettingPath{1, 1, 10, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_a = SettingDescriptor(
    SettingPath{1, 1, 11},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_a_base = SettingDescriptor(
    SettingPath{1, 1, 11, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_a_base_mode_request = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 1},
    AutoCompleteTrigger::MODE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_a_base_mode = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_a_base_mode_type = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 2, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_a_base_mode_name = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 2, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_a_base_mode_label = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 2, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_a_base_mode_lo_cut = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 2, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_a_base_mode_hi_cut = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 2, 5},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_a_base_mode_offset = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 2, 6},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_a_base_rf = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_a_base_rf_frequency = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 3, 1001},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_a_base_rf_frequency_value = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 3, 1001, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_a_base_rf_frequency_coarse_delta = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 3, 1001, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_a_base_rf_frequency_fine_delta = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 3, 1001, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_a_base_rf_frequency_use_fine = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 3, 1001, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_a_base_rf_max_negative_offset = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 3, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_a_base_rf_max_positive_offset = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 3, 5},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_a_base_iq_corrections = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_a_base_iq_corrections_amplitude = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 4, 1001},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_a_base_iq_corrections_amplitude_value = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 4, 1001, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_a_base_iq_corrections_amplitude_coarse_delta = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 4, 1001, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_a_base_iq_corrections_amplitude_fine_delta = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 4, 1001, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_a_base_iq_corrections_amplitude_use_fine = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 4, 1001, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_a_base_iq_corrections_phase = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 4, 1002},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_a_base_iq_corrections_phase_value = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 4, 1002, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_a_base_iq_corrections_phase_coarse_delta = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 4, 1002, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_a_base_iq_corrections_phase_fine_delta = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 4, 1002, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_a_base_iq_corrections_phase_use_fine = SettingDescriptor(
    SettingPath{1, 1, 11, 1, 4, 1002, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_a_mute = SettingDescriptor(
    SettingPath{1, 1, 11, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_a_agc_speed = SettingDescriptor(
    SettingPath{1, 1, 11, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_b = SettingDescriptor(
    SettingPath{1, 1, 12},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_b_base = SettingDescriptor(
    SettingPath{1, 1, 12, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_b_base_mode_request = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 1},
    AutoCompleteTrigger::MODE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_b_base_mode = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_b_base_mode_type = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 2, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_b_base_mode_name = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 2, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_b_base_mode_label = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 2, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_b_base_mode_lo_cut = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 2, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_b_base_mode_hi_cut = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 2, 5},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_b_base_mode_offset = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 2, 6},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_b_base_rf = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_b_base_rf_frequency = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 3, 1001},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_b_base_rf_frequency_value = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 3, 1001, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_b_base_rf_frequency_coarse_delta = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 3, 1001, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_b_base_rf_frequency_fine_delta = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 3, 1001, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_b_base_rf_frequency_use_fine = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 3, 1001, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_b_base_rf_max_negative_offset = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 3, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_b_base_rf_max_positive_offset = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 3, 5},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_b_base_iq_corrections = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_b_base_iq_corrections_amplitude = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 4, 1001},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_b_base_iq_corrections_amplitude_value = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 4, 1001, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_b_base_iq_corrections_amplitude_coarse_delta = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 4, 1001, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_b_base_iq_corrections_amplitude_fine_delta = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 4, 1001, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_b_base_iq_corrections_amplitude_use_fine = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 4, 1001, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_b_base_iq_corrections_phase = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 4, 1002},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_b_base_iq_corrections_phase_value = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 4, 1002, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_b_base_iq_corrections_phase_coarse_delta = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 4, 1002, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_b_base_iq_corrections_phase_fine_delta = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 4, 1002, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_b_base_iq_corrections_phase_use_fine = SettingDescriptor(
    SettingPath{1, 1, 12, 1, 4, 1002, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_b_mute = SettingDescriptor(
    SettingPath{1, 1, 12, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_pipeline_b_agc_speed = SettingDescriptor(
    SettingPath{1, 1, 12, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/**/
const SettingDescriptor active_bands_band_1_is_multi_pipeline = SettingDescriptor(
    SettingPath{1, 1, 13},
    AutoCompleteTrigger::NONE,
    false
);
/**/
/**/
const SettingDescriptor active_bands_band_1_focus_pipeline_id = SettingDescriptor(
    SettingPath{1, 1, 14},
    AutoCompleteTrigger::NONE,
    false
);
/**/
/*
const SettingDescriptor active_bands_band_1_tx_pipeline = SettingDescriptor(
    SettingPath{1, 1, 15},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_tx_pipeline_base = SettingDescriptor(
    SettingPath{1, 1, 15, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_tx_pipeline_base_mode_request = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 1},
    AutoCompleteTrigger::MODE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_tx_pipeline_base_mode = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_tx_pipeline_base_mode_type = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 2, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_tx_pipeline_base_mode_name = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 2, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_tx_pipeline_base_mode_label = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 2, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_tx_pipeline_base_mode_lo_cut = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 2, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_tx_pipeline_base_mode_hi_cut = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 2, 5},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_tx_pipeline_base_mode_offset = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 2, 6},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_tx_pipeline_base_rf = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_tx_pipeline_base_rf_frequency = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 3, 1001},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_tx_pipeline_base_rf_frequency_value = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 3, 1001, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_tx_pipeline_base_rf_frequency_coarse_delta = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 3, 1001, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_tx_pipeline_base_rf_frequency_fine_delta = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 3, 1001, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_tx_pipeline_base_rf_frequency_use_fine = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 3, 1001, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_tx_pipeline_base_rf_max_negative_offset = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 3, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_tx_pipeline_base_rf_max_positive_offset = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 3, 5},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_tx_pipeline_base_iq_corrections = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_tx_pipeline_base_iq_corrections_amplitude = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 4, 1001},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_tx_pipeline_base_iq_corrections_amplitude_value = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 4, 1001, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_tx_pipeline_base_iq_corrections_amplitude_coarse_delta = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 4, 1001, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_tx_pipeline_base_iq_corrections_amplitude_fine_delta = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 4, 1001, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_tx_pipeline_base_iq_corrections_amplitude_use_fine = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 4, 1001, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_tx_pipeline_base_iq_corrections_phase = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 4, 1002},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_tx_pipeline_base_iq_corrections_phase_value = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 4, 1002, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_tx_pipeline_base_iq_corrections_phase_coarse_delta = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 4, 1002, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_tx_pipeline_base_iq_corrections_phase_fine_delta = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 4, 1002, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_1_tx_pipeline_base_iq_corrections_phase_use_fine = SettingDescriptor(
    SettingPath{1, 1, 15, 1, 4, 1002, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/**/
const SettingDescriptor active_bands_band_1_tx_pipeline_id = SettingDescriptor(
    SettingPath{1, 1, 16},
    AutoCompleteTrigger::NONE,
    false
);
/**/
/*
const SettingDescriptor active_bands_band_2 = SettingDescriptor(
    SettingPath{1, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_band_request = SettingDescriptor(
    SettingPath{1, 2, 1},
    AutoCompleteTrigger::BAND,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_band = SettingDescriptor(
    SettingPath{1, 2, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_band_name = SettingDescriptor(
    SettingPath{1, 2, 2, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_band_label = SettingDescriptor(
    SettingPath{1, 2, 2, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_band_lowest_frequency = SettingDescriptor(
    SettingPath{1, 2, 2, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_band_highest_frequency = SettingDescriptor(
    SettingPath{1, 2, 2, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_band_landing_frequency = SettingDescriptor(
    SettingPath{1, 2, 2, 5},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_band_default_fine_step = SettingDescriptor(
    SettingPath{1, 2, 2, 6},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_band_default_coarse_step = SettingDescriptor(
    SettingPath{1, 2, 2, 7},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_band_default_mode = SettingDescriptor(
    SettingPath{1, 2, 2, 8},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_band_default_mode_type = SettingDescriptor(
    SettingPath{1, 2, 2, 8, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_band_default_mode_name = SettingDescriptor(
    SettingPath{1, 2, 2, 8, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_band_default_mode_label = SettingDescriptor(
    SettingPath{1, 2, 2, 8, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_band_default_mode_lo_cut = SettingDescriptor(
    SettingPath{1, 2, 2, 8, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_band_default_mode_hi_cut = SettingDescriptor(
    SettingPath{1, 2, 2, 8, 5},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_band_default_mode_offset = SettingDescriptor(
    SettingPath{1, 2, 2, 8, 6},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_rf = SettingDescriptor(
    SettingPath{1, 2, 5},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_rf_frequency = SettingDescriptor(
    SettingPath{1, 2, 5, 1001},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_rf_frequency_value = SettingDescriptor(
    SettingPath{1, 2, 5, 1001, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_rf_frequency_coarse_delta = SettingDescriptor(
    SettingPath{1, 2, 5, 1001, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_rf_frequency_fine_delta = SettingDescriptor(
    SettingPath{1, 2, 5, 1001, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_rf_frequency_use_fine = SettingDescriptor(
    SettingPath{1, 2, 5, 1001, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_rf_gain = SettingDescriptor(
    SettingPath{1, 2, 5, 1002},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_rf_gain_value = SettingDescriptor(
    SettingPath{1, 2, 5, 1002, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_rf_gain_coarse_delta = SettingDescriptor(
    SettingPath{1, 2, 5, 1002, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_rf_gain_fine_delta = SettingDescriptor(
    SettingPath{1, 2, 5, 1002, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_rf_gain_use_fine = SettingDescriptor(
    SettingPath{1, 2, 5, 1002, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_if = SettingDescriptor(
    SettingPath{1, 2, 6},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_if_gain = SettingDescriptor(
    SettingPath{1, 2, 6, 1001},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_if_gain_value = SettingDescriptor(
    SettingPath{1, 2, 6, 1001, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_if_gain_coarse_delta = SettingDescriptor(
    SettingPath{1, 2, 6, 1001, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_if_gain_fine_delta = SettingDescriptor(
    SettingPath{1, 2, 6, 1001, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_if_gain_use_fine = SettingDescriptor(
    SettingPath{1, 2, 6, 1001, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_if_bandwidth = SettingDescriptor(
    SettingPath{1, 2, 6, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_focus_pipeline = SettingDescriptor(
    SettingPath{1, 2, 10},
    AutoCompleteTrigger::NONE,
    true
);
*/
/*
const SettingDescriptor active_bands_band_2_focus_pipeline_base = SettingDescriptor(
    SettingPath{1, 2, 10, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_focus_pipeline_base_mode_request = SettingDescriptor(
    SettingPath{1, 2, 10, 1, 1},
    AutoCompleteTrigger::MODE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_focus_pipeline_base_mode = SettingDescriptor(
    SettingPath{1, 2, 10, 1, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_focus_pipeline_base_mode_type = SettingDescriptor(
    SettingPath{1, 2, 10, 1, 2, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_focus_pipeline_base_mode_name = SettingDescriptor(
    SettingPath{1, 2, 10, 1, 2, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_focus_pipeline_base_mode_label = SettingDescriptor(
    SettingPath{1, 2, 10, 1, 2, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_focus_pipeline_base_mode_lo_cut = SettingDescriptor(
    SettingPath{1, 2, 10, 1, 2, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_focus_pipeline_base_mode_hi_cut = SettingDescriptor(
    SettingPath{1, 2, 10, 1, 2, 5},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_focus_pipeline_base_mode_offset = SettingDescriptor(
    SettingPath{1, 2, 10, 1, 2, 6},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_focus_pipeline_base_rf = SettingDescriptor(
    SettingPath{1, 2, 10, 1, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_focus_pipeline_base_rf_frequency = SettingDescriptor(
    SettingPath{1, 2, 10, 1, 3, 1001},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_focus_pipeline_base_rf_frequency_value = SettingDescriptor(
    SettingPath{1, 2, 10, 1, 3, 1001, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_focus_pipeline_base_rf_frequency_coarse_delta = SettingDescriptor(
    SettingPath{1, 2, 10, 1, 3, 1001, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_focus_pipeline_base_rf_frequency_fine_delta = SettingDescriptor(
    SettingPath{1, 2, 10, 1, 3, 1001, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_focus_pipeline_base_rf_frequency_use_fine = SettingDescriptor(
    SettingPath{1, 2, 10, 1, 3, 1001, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_focus_pipeline_base_rf_max_negative_offset = SettingDescriptor(
    SettingPath{1, 2, 10, 1, 3, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_focus_pipeline_base_rf_max_positive_offset = SettingDescriptor(
    SettingPath{1, 2, 10, 1, 3, 5},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_focus_pipeline_base_iq_corrections = SettingDescriptor(
    SettingPath{1, 2, 10, 1, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_focus_pipeline_base_iq_corrections_amplitude = SettingDescriptor(
    SettingPath{1, 2, 10, 1, 4, 1001},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_focus_pipeline_base_iq_corrections_amplitude_value = SettingDescriptor(
    SettingPath{1, 2, 10, 1, 4, 1001, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_focus_pipeline_base_iq_corrections_amplitude_coarse_delta = SettingDescriptor(
    SettingPath{1, 2, 10, 1, 4, 1001, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_focus_pipeline_base_iq_corrections_amplitude_fine_delta = SettingDescriptor(
    SettingPath{1, 2, 10, 1, 4, 1001, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_focus_pipeline_base_iq_corrections_amplitude_use_fine = SettingDescriptor(
    SettingPath{1, 2, 10, 1, 4, 1001, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_focus_pipeline_base_iq_corrections_phase = SettingDescriptor(
    SettingPath{1, 2, 10, 1, 4, 1002},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_focus_pipeline_base_iq_corrections_phase_value = SettingDescriptor(
    SettingPath{1, 2, 10, 1, 4, 1002, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_focus_pipeline_base_iq_corrections_phase_coarse_delta = SettingDescriptor(
    SettingPath{1, 2, 10, 1, 4, 1002, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_focus_pipeline_base_iq_corrections_phase_fine_delta = SettingDescriptor(
    SettingPath{1, 2, 10, 1, 4, 1002, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_focus_pipeline_base_iq_corrections_phase_use_fine = SettingDescriptor(
    SettingPath{1, 2, 10, 1, 4, 1002, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_focus_pipeline_mute = SettingDescriptor(
    SettingPath{1, 2, 10, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_focus_pipeline_agc_speed = SettingDescriptor(
    SettingPath{1, 2, 10, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_a = SettingDescriptor(
    SettingPath{1, 2, 11},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_a_base = SettingDescriptor(
    SettingPath{1, 2, 11, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_a_base_mode_request = SettingDescriptor(
    SettingPath{1, 2, 11, 1, 1},
    AutoCompleteTrigger::MODE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_a_base_mode = SettingDescriptor(
    SettingPath{1, 2, 11, 1, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_a_base_mode_type = SettingDescriptor(
    SettingPath{1, 2, 11, 1, 2, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_a_base_mode_name = SettingDescriptor(
    SettingPath{1, 2, 11, 1, 2, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_a_base_mode_label = SettingDescriptor(
    SettingPath{1, 2, 11, 1, 2, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_a_base_mode_lo_cut = SettingDescriptor(
    SettingPath{1, 2, 11, 1, 2, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_a_base_mode_hi_cut = SettingDescriptor(
    SettingPath{1, 2, 11, 1, 2, 5},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_a_base_mode_offset = SettingDescriptor(
    SettingPath{1, 2, 11, 1, 2, 6},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_a_base_rf = SettingDescriptor(
    SettingPath{1, 2, 11, 1, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_a_base_rf_frequency = SettingDescriptor(
    SettingPath{1, 2, 11, 1, 3, 1001},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_a_base_rf_frequency_value = SettingDescriptor(
    SettingPath{1, 2, 11, 1, 3, 1001, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_a_base_rf_frequency_coarse_delta = SettingDescriptor(
    SettingPath{1, 2, 11, 1, 3, 1001, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_a_base_rf_frequency_fine_delta = SettingDescriptor(
    SettingPath{1, 2, 11, 1, 3, 1001, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_a_base_rf_frequency_use_fine = SettingDescriptor(
    SettingPath{1, 2, 11, 1, 3, 1001, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_a_base_rf_max_negative_offset = SettingDescriptor(
    SettingPath{1, 2, 11, 1, 3, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_a_base_rf_max_positive_offset = SettingDescriptor(
    SettingPath{1, 2, 11, 1, 3, 5},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_a_base_iq_corrections = SettingDescriptor(
    SettingPath{1, 2, 11, 1, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_a_base_iq_corrections_amplitude = SettingDescriptor(
    SettingPath{1, 2, 11, 1, 4, 1001},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_a_base_iq_corrections_amplitude_value = SettingDescriptor(
    SettingPath{1, 2, 11, 1, 4, 1001, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_a_base_iq_corrections_amplitude_coarse_delta = SettingDescriptor(
    SettingPath{1, 2, 11, 1, 4, 1001, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_a_base_iq_corrections_amplitude_fine_delta = SettingDescriptor(
    SettingPath{1, 2, 11, 1, 4, 1001, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_a_base_iq_corrections_amplitude_use_fine = SettingDescriptor(
    SettingPath{1, 2, 11, 1, 4, 1001, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_a_base_iq_corrections_phase = SettingDescriptor(
    SettingPath{1, 2, 11, 1, 4, 1002},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_a_base_iq_corrections_phase_value = SettingDescriptor(
    SettingPath{1, 2, 11, 1, 4, 1002, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_a_base_iq_corrections_phase_coarse_delta = SettingDescriptor(
    SettingPath{1, 2, 11, 1, 4, 1002, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_a_base_iq_corrections_phase_fine_delta = SettingDescriptor(
    SettingPath{1, 2, 11, 1, 4, 1002, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_a_base_iq_corrections_phase_use_fine = SettingDescriptor(
    SettingPath{1, 2, 11, 1, 4, 1002, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_a_mute = SettingDescriptor(
    SettingPath{1, 2, 11, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_a_agc_speed = SettingDescriptor(
    SettingPath{1, 2, 11, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_b = SettingDescriptor(
    SettingPath{1, 2, 12},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_b_base = SettingDescriptor(
    SettingPath{1, 2, 12, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_b_base_mode_request = SettingDescriptor(
    SettingPath{1, 2, 12, 1, 1},
    AutoCompleteTrigger::MODE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_b_base_mode = SettingDescriptor(
    SettingPath{1, 2, 12, 1, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_b_base_mode_type = SettingDescriptor(
    SettingPath{1, 2, 12, 1, 2, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_b_base_mode_name = SettingDescriptor(
    SettingPath{1, 2, 12, 1, 2, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_b_base_mode_label = SettingDescriptor(
    SettingPath{1, 2, 12, 1, 2, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_b_base_mode_lo_cut = SettingDescriptor(
    SettingPath{1, 2, 12, 1, 2, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_b_base_mode_hi_cut = SettingDescriptor(
    SettingPath{1, 2, 12, 1, 2, 5},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_b_base_mode_offset = SettingDescriptor(
    SettingPath{1, 2, 12, 1, 2, 6},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_b_base_rf = SettingDescriptor(
    SettingPath{1, 2, 12, 1, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_b_base_rf_frequency = SettingDescriptor(
    SettingPath{1, 2, 12, 1, 3, 1001},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_b_base_rf_frequency_value = SettingDescriptor(
    SettingPath{1, 2, 12, 1, 3, 1001, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_b_base_rf_frequency_coarse_delta = SettingDescriptor(
    SettingPath{1, 2, 12, 1, 3, 1001, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_b_base_rf_frequency_fine_delta = SettingDescriptor(
    SettingPath{1, 2, 12, 1, 3, 1001, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_b_base_rf_frequency_use_fine = SettingDescriptor(
    SettingPath{1, 2, 12, 1, 3, 1001, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_b_base_rf_max_negative_offset = SettingDescriptor(
    SettingPath{1, 2, 12, 1, 3, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_b_base_rf_max_positive_offset = SettingDescriptor(
    SettingPath{1, 2, 12, 1, 3, 5},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_b_base_iq_corrections = SettingDescriptor(
    SettingPath{1, 2, 12, 1, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_b_base_iq_corrections_amplitude = SettingDescriptor(
    SettingPath{1, 2, 12, 1, 4, 1001},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_b_base_iq_corrections_amplitude_value = SettingDescriptor(
    SettingPath{1, 2, 12, 1, 4, 1001, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_b_base_iq_corrections_amplitude_coarse_delta = SettingDescriptor(
    SettingPath{1, 2, 12, 1, 4, 1001, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_b_base_iq_corrections_amplitude_fine_delta = SettingDescriptor(
    SettingPath{1, 2, 12, 1, 4, 1001, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_b_base_iq_corrections_amplitude_use_fine = SettingDescriptor(
    SettingPath{1, 2, 12, 1, 4, 1001, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_b_base_iq_corrections_phase = SettingDescriptor(
    SettingPath{1, 2, 12, 1, 4, 1002},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_b_base_iq_corrections_phase_value = SettingDescriptor(
    SettingPath{1, 2, 12, 1, 4, 1002, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_b_base_iq_corrections_phase_coarse_delta = SettingDescriptor(
    SettingPath{1, 2, 12, 1, 4, 1002, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_b_base_iq_corrections_phase_fine_delta = SettingDescriptor(
    SettingPath{1, 2, 12, 1, 4, 1002, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_b_base_iq_corrections_phase_use_fine = SettingDescriptor(
    SettingPath{1, 2, 12, 1, 4, 1002, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_b_mute = SettingDescriptor(
    SettingPath{1, 2, 12, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_pipeline_b_agc_speed = SettingDescriptor(
    SettingPath{1, 2, 12, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/**/
const SettingDescriptor active_bands_band_2_is_multi_pipeline = SettingDescriptor(
    SettingPath{1, 2, 13},
    AutoCompleteTrigger::NONE,
    false
);
/**/
/**/
const SettingDescriptor active_bands_band_2_focus_pipeline_id = SettingDescriptor(
    SettingPath{1, 2, 14},
    AutoCompleteTrigger::NONE,
    false
);
/**/
/*
const SettingDescriptor active_bands_band_2_tx_pipeline = SettingDescriptor(
    SettingPath{1, 2, 15},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_tx_pipeline_base = SettingDescriptor(
    SettingPath{1, 2, 15, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_tx_pipeline_base_mode_request = SettingDescriptor(
    SettingPath{1, 2, 15, 1, 1},
    AutoCompleteTrigger::MODE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_tx_pipeline_base_mode = SettingDescriptor(
    SettingPath{1, 2, 15, 1, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_tx_pipeline_base_mode_type = SettingDescriptor(
    SettingPath{1, 2, 15, 1, 2, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_tx_pipeline_base_mode_name = SettingDescriptor(
    SettingPath{1, 2, 15, 1, 2, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_tx_pipeline_base_mode_label = SettingDescriptor(
    SettingPath{1, 2, 15, 1, 2, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_tx_pipeline_base_mode_lo_cut = SettingDescriptor(
    SettingPath{1, 2, 15, 1, 2, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_tx_pipeline_base_mode_hi_cut = SettingDescriptor(
    SettingPath{1, 2, 15, 1, 2, 5},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_tx_pipeline_base_mode_offset = SettingDescriptor(
    SettingPath{1, 2, 15, 1, 2, 6},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_tx_pipeline_base_rf = SettingDescriptor(
    SettingPath{1, 2, 15, 1, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_tx_pipeline_base_rf_frequency = SettingDescriptor(
    SettingPath{1, 2, 15, 1, 3, 1001},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_tx_pipeline_base_rf_frequency_value = SettingDescriptor(
    SettingPath{1, 2, 15, 1, 3, 1001, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_tx_pipeline_base_rf_frequency_coarse_delta = SettingDescriptor(
    SettingPath{1, 2, 15, 1, 3, 1001, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_tx_pipeline_base_rf_frequency_fine_delta = SettingDescriptor(
    SettingPath{1, 2, 15, 1, 3, 1001, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_tx_pipeline_base_rf_frequency_use_fine = SettingDescriptor(
    SettingPath{1, 2, 15, 1, 3, 1001, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_tx_pipeline_base_rf_max_negative_offset = SettingDescriptor(
    SettingPath{1, 2, 15, 1, 3, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_tx_pipeline_base_rf_max_positive_offset = SettingDescriptor(
    SettingPath{1, 2, 15, 1, 3, 5},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_tx_pipeline_base_iq_corrections = SettingDescriptor(
    SettingPath{1, 2, 15, 1, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_tx_pipeline_base_iq_corrections_amplitude = SettingDescriptor(
    SettingPath{1, 2, 15, 1, 4, 1001},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_tx_pipeline_base_iq_corrections_amplitude_value = SettingDescriptor(
    SettingPath{1, 2, 15, 1, 4, 1001, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_tx_pipeline_base_iq_corrections_amplitude_coarse_delta = SettingDescriptor(
    SettingPath{1, 2, 15, 1, 4, 1001, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_tx_pipeline_base_iq_corrections_amplitude_fine_delta = SettingDescriptor(
    SettingPath{1, 2, 15, 1, 4, 1001, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_tx_pipeline_base_iq_corrections_amplitude_use_fine = SettingDescriptor(
    SettingPath{1, 2, 15, 1, 4, 1001, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_tx_pipeline_base_iq_corrections_phase = SettingDescriptor(
    SettingPath{1, 2, 15, 1, 4, 1002},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_tx_pipeline_base_iq_corrections_phase_value = SettingDescriptor(
    SettingPath{1, 2, 15, 1, 4, 1002, 1},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_tx_pipeline_base_iq_corrections_phase_coarse_delta = SettingDescriptor(
    SettingPath{1, 2, 15, 1, 4, 1002, 2},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_tx_pipeline_base_iq_corrections_phase_fine_delta = SettingDescriptor(
    SettingPath{1, 2, 15, 1, 4, 1002, 3},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_band_2_tx_pipeline_base_iq_corrections_phase_use_fine = SettingDescriptor(
    SettingPath{1, 2, 15, 1, 4, 1002, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/**/
const SettingDescriptor active_bands_band_2_tx_pipeline_id = SettingDescriptor(
    SettingPath{1, 2, 16},
    AutoCompleteTrigger::NONE,
    false
);
/**/
/*
const SettingDescriptor active_bands_focus_band_id = SettingDescriptor(
    SettingPath{1, 4},
    AutoCompleteTrigger::NONE,
    false
);
*/
/**/
const SettingDescriptor active_bands_tx_band_id = SettingDescriptor(
    SettingPath{1, 5},
    AutoCompleteTrigger::NONE,
    false
);
/**/
/*
const SettingDescriptor active_bands_rx_band_id = SettingDescriptor(
    SettingPath{1, 6},
    AutoCompleteTrigger::NONE,
    false
);
*/
/*
const SettingDescriptor active_bands_is_split = SettingDescriptor(
    SettingPath{1, 7},
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
/**/
const SettingDescriptor ptt = SettingDescriptor(
    SettingPath{4},
    AutoCompleteTrigger::NONE,
    false
);
/**/
