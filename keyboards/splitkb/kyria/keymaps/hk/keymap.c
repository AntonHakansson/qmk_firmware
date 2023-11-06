#include QMK_KEYBOARD_H
#include "hk_keymap.h"

// TODO: Caps word
// TODO: X-Case?

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK_DH] = LAYOUT(
     KC_TAB  , KC_Q ,  KC_W   ,  KC_F  ,   KC_P ,   KC_B ,                                           KC_J,   KC_L ,  KC_U ,   KC_Y ,KC_SCLN, LSFT(KC_LBRC),
     CTL_ESC , KC_A ,  KC_R   ,  KC_S  ,   KC_T ,   KC_G ,                                           KC_M,   KC_N ,  KC_E ,   KC_I ,  KC_O , CTL_QUOT,
     OS_LSFT , KC_Z ,  KC_X   ,  KC_C  ,   KC_D ,   KC_V , KC_LBRC,KC_CAPS,     FKEYS , KC_RBRC,     KC_K,   KC_H ,KC_COMM, KC_DOT ,KC_SLSH, KC_RSFT,
                                 ADJUST, KC_LGUI, ALT_ENT,LSFT_SPC, NAV   ,     SYM   ,RSFT_BSPC,RALT_ENT, KC_RGUI, KC_APP
    ),
    [_NAV] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, KC_VOLU, KC_DEL,
      _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_VOLD, KC_INS,
      _______, _______, _______, _______, _______, _______, _______, KC_SCRL, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_MUTE, KC_PSCR,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_SYM] = LAYOUT(
      KC_GRV ,   KC_1 ,   KC_2 ,   KC_3 ,   KC_4 ,   KC_5 ,                                       KC_6 ,   KC_7 ,   KC_8 ,   KC_9 ,   KC_0 , KC_EQL ,
     KC_TILD , KC_EXLM,  KC_AT , KC_HASH,  KC_DLR, KC_PERC,                                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,
     KC_PIPE , KC_BSLS, KC_COLN, KC_SCLN, KC_MINS, KC_LBRC, KC_LCBR, _______, _______, KC_RCBR, KC_RBRC, KC_UNDS, KC_COMM,  KC_DOT, KC_SLSH, KC_QUES,
                                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_FUNCTION] = LAYOUT(
      _______,  KC_F9 ,  KC_F10,  KC_F11,  KC_F12, _______,                                     _______, _______, _______, _______, _______, _______,
      _______,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 , _______,                                     _______, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, _______,
      _______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_ADJUST] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                    _______, _______, _______, _______,  _______, _______,
      _______, _______, _______, _______, _______, _______,                                    RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI,  RGB_MOD, _______,
      _______, _______, _______, COLEMAK, _______, _______,_______, _______, _______, _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD, _______,
                                 _______, _______, _______,_______, _______, _______, _______, _______, _______, _______
    ),
// /*

//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

enum combo_events {
  // ". <one-shot-shift>" i.e. dot, space and capitalize next letter.
  // This helps to quickly end a sentence and begin another one
  // without having to hit shift.
  C_SENTENCE_END,

  // steno-lite combos
#define SUBS(name, ...) name,
#include "combos.def"
#undef SUBS
};

const uint16_t PROGMEM COMMA_DOT_COMBO[] = {KC_COMMA,  KC_DOT,  COMBO_END};

#define SUBS(name, str, ...) const uint16_t PROGMEM name##_COMBO[] = { __VA_ARGS__, COMBO_END };
#include "combos.def"
#undef SUBS

combo_t key_combos[] = {
  [C_SENTENCE_END]  = COMBO_ACTION(COMMA_DOT_COMBO),

#define SUBS(name, str, ...) [name] = COMBO_ACTION(name##_COMBO),
#include "combos.def"
#undef SUBS
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
  case C_SENTENCE_END:
    if (pressed) {
      tap_code(KC_DOT);
      tap_code(KC_SPC);
      add_oneshot_mods(MOD_BIT(KC_LEFT_SHIFT));
    } break;
#define SUBS(name, str, ...) case name: if (pressed) { SEND_STRING(str); } break;
#include "combos.def"
#undef SUBS
  }
}


/* Local Variables: */
/* compile-command: "nix run nixpkgs#qmk -- compile -e CONVERT_TO=elite_pi" */
/* End: */
