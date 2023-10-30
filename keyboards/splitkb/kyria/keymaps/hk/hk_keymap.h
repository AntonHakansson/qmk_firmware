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
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT  MT(MOD_LALT, KC_ENT)
#define RALT_ENT  MT(MOD_RALT, KC_ENT)
#define LSFT_SPC  MT(MOD_LSFT, KC_SPC)
#define RSFT_BSPC  MT(MOD_RSFT, KC_BSPC)
