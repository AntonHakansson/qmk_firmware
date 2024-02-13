#pragma once

enum layers {
    _COLEMAK_DH = 0,
    _NAV,
    _SYM,
    _FUNCTION,
    _ADJUST,
};

// Aliases for readability
#define COLEMAK  DF(_COLEMAK_DH)

#define SYM      MO(_SYM)
#define NAV      MO(_NAV)
#define FKEYS    MO(_FUNCTION)
#define ADJUST   MO(_ADJUST)

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define LALT_TAB  MT(MOD_LALT, KC_TAB)
#define LALT_BSPC  MT(MOD_LALT, KC_BSPC)
#define LCTL_SPC  MT(MOD_LCTL, KC_SPC)
#define RSFT_ENT  MT(MOD_LSFT, KC_ENT)
#define OS_LSFT  OSM(MOD_LSFT)
#define OS_RSFT  OSM(MOD_RSFT)
