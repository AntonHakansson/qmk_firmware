#pragma once

enum layers {
    _COLEMAK_DH = 0,
    _NAV,
    _SYM,
    _FUNCTION,
    _SWAP,
};

//- Readability Aliases
#define SYM      MO(_SYM)
#define NAV      MO(_NAV)
#define FKEYS    MO(_FUNCTION)
#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define LALT_TAB  MT(MOD_LALT, KC_TAB)
#define LALT_BSPC  MT(MOD_LALT, KC_BSPC)
#define LCTL_SPC  MT(MOD_LCTL, KC_SPC)
#define RSFT_ENT  MT(MOD_LSFT, KC_ENT)
#define OS_LSFT  OSM(MOD_LSFT)
#define OS_RSFT  OSM(MOD_RSFT)

//- Layout_split_5x3_3
#define __________________ROW_L1__________________ KC_Q  ,  KC_W  ,  KC_F    ,  KC_P   , KC_B
#define __________________ROW_L2__________________ KC_A  ,  KC_R  ,  KC_S    ,  KC_T   , KC_G
#define __________________ROW_L3__________________ KC_Z  ,  KC_X  ,  KC_C    ,  KC_D   , KC_V

#define __________________ROW_R1__________________ KC_J  ,  KC_L  ,  KC_U    ,  KC_Y   , KC_SCLN
#define __________________ROW_R2__________________ KC_M  ,  KC_N  ,  KC_E    ,  KC_I   , KC_O
#define __________________ROW_R3__________________ KC_K  ,  KC_H  , KC_COMM  , KC_DOT  , KC_SLSH

#define __________________THUMB_L__________________ LALT_TAB,LCTL_SPC, NAV
#define __________________THUMB_R__________________ SYM     ,RSFT_ENT,LALT_BSPC
