#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

#include "hk_keymap.h"

#define LAYOUT_wrapper(...) LAYOUT_split_3x6_5(__VA_ARGS__)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK_DH] = LAYOUT_wrapper(
     KC_TAB,  __________________ROW_L1__________________,                __________________ROW_R1__________________, KC_LCBR,
     CTL_ESC, __________________ROW_L2__________________,                __________________ROW_R2__________________, CTL_QUOT,
     OS_LSFT, __________________ROW_L3__________________,_______,_______,_______,_______,__________________ROW_R3__________________, OS_RSFT,
     _______, KC_LGUI, __________________THUMB_L__________________, __________________THUMB_R__________________, KC_RGUI, KC_APP
  ),
  [_NAV] = LAYOUT(
      _______, _______, RALT(KC_W), RALT(KC_Q), RALT(KC_P), _______,                            _______, LCTL(KC_LEFT), KC_UP, LCTL(KC_RIGHT), KC_VOLU, KC_DEL,
      _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                                     _______, KC_LEFT, KC_DOWN,   KC_RGHT, KC_VOLD, KC_INS,
      _______, _______, KC_LPRN, KC_LBRC, KC_LCBR, _______, _______, KC_SCRL, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_MUTE, KC_PSCR,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
  [_SYM] = LAYOUT(
     KC_GRV ,   KC_1 ,   KC_2 ,   KC_3 ,   KC_4 ,   KC_5 ,                                       KC_6 ,   KC_7 ,   KC_8 ,   KC_9 ,   KC_0 , KC_EQL ,
     KC_TILD, KC_EXLM,  KC_AT , KC_HASH,  KC_DLR, KC_PERC,                                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,
     _______, KC_BSLS, KC_COLN, KC_SCLN, KC_MINS, KC_LBRC, KC_LCBR, _______, _______, KC_RCBR, KC_RBRC, KC_UNDS, KC_COMM,  KC_DOT, KC_SLSH, KC_QUES,
                                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
  [_FUNCTION] = LAYOUT(
      _______,  KC_F9 ,  KC_F10,  KC_F11,  KC_F12, _______,                                     _______, _______, _______, _______, _______, _______,
      _______,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 , _______,                                     _______, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, _______,
      _______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
  [_SWAP] = LAYOUT_wrapper(
     KC_TAB,  __________________ROW_R1__________________,                __________________ROW_L1__________________, KC_LCBR,
     CTL_ESC, __________________ROW_R2__________________,                __________________ROW_L2__________________, CTL_QUOT,
     OS_LSFT, __________________ROW_R3__________________,_______,_______,_______,_______,__________________ROW_L3__________________, OS_RSFT,
     _______, KC_LGUI, __________________THUMB_R__________________, __________________THUMB_L__________________, KC_RGUI, KC_APP
  ),
};


enum combo_events {
  // ". <one-shot-shift>" i.e. dot, space and capitalize next letter.
  // This helps to quickly end a sentence and begin another one
  // without having to hit shift.
  C_SENTENCE_END,

  // steno-lite combos
#define COMB(name, ...) name,
#define SUBS(name, ...) name,
#include "combos.def"
#undef SUBS
#undef COMB
};

const uint16_t PROGMEM COMMA_DOT_COMBO[] = {KC_COMMA,  KC_DOT,  COMBO_END};

#define COMB(name, str, ...) const uint16_t PROGMEM name##_COMBO[] = { __VA_ARGS__, COMBO_END };
#define SUBS(name, str, ...) const uint16_t PROGMEM name##_COMBO[] = { __VA_ARGS__, COMBO_END };
#include "combos.def"
#undef SUBS
#undef COMB

combo_t key_combos[] = {
  [C_SENTENCE_END]  = COMBO_ACTION(COMMA_DOT_COMBO),

#define COMB(name, combo, ...) [name] = COMBO(name##_COMBO, combo),
#define SUBS(name, str, ...) [name] = COMBO_ACTION(name##_COMBO),
#include "combos.def"
#undef SUBS
#undef COMB
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
  case C_SENTENCE_END:
    if (pressed) {
      tap_code(KC_DOT);
      tap_code(KC_SPC);
      add_oneshot_mods(MOD_BIT(KC_LEFT_SHIFT));
    } break;
#define COMB(...)
#define SUBS(name, str, ...) case name: if (pressed) { SEND_STRING(str); } break;
#include "combos.def"
#undef SUBS
#undef COMB
  }
}


/* Local Variables: */
/* compile-command: "nix run nixpkgs#qmk -- compile -e CONVERT_TO=elite_pi -kb kyria -km hk" */
/* End: */
