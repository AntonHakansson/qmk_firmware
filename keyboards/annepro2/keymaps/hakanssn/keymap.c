 /* Copyright 2021 OpenAnnePro community
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */

#ifdef TAPPING_TERM
#undef TAPPING_TERM
#endif // TAPPING_TERM
#define TAPPING_TERM 150

#include QMK_KEYBOARD_H

enum anne_pro_layers {
    BASE,
    QWERTY,
    FN1,
    FN2,
    FN3,
};

// clang-format off
const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [BASE] = LAYOUT_60_ansi(
    KC_ESC,           KC_1,    KC_2,    KC_3, KC_4, KC_5, KC_6,   KC_7, KC_8, KC_9,    KC_0,             KC_MINS,          KC_EQL,        KC_BSPC,
    LT(FN3, KC_TAB),  KC_Q,    KC_W,    KC_F, KC_P, KC_B, KC_J,   KC_L, KC_U, KC_Y,    KC_SCLN,          KC_LBRC,          KC_RBRC,       KC_BSLS,
    LT(FN1, KC_ESC),  KC_A,    KC_R,    KC_S, KC_T, KC_G, KC_M,   KC_N, KC_E, KC_I,    KC_O,             KC_QUOT,          KC_ENT,
    KC_LSFT,                   KC_X,    KC_C, KC_D, KC_V, KC_Z,   KC_K, KC_H, KC_COMM, KC_DOT,           KC_SLSH,          RSFT_T(KC_UP),
    KC_LCTL,          KC_LGUI, KC_LALT,                   KC_SPC,             KC_RALT, LT(FN1, KC_LEFT), LT(FN2, KC_DOWN), RCTL_T(KC_RGHT)
 ),
 [FN1] = LAYOUT_60_ansi(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
    _______, _______, KC_UP,   _______, _______, _______, _______, KC_PGUP, _______, _______, _______, KC_HOME, KC_END,  _______,
    _______, KC_LEFT, KC_DOWN, KC_PGDN, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSPC, LCTL(KC_BSPC), _______,
    _______,          KC_VOLU, KC_VOLD, KC_MUTE, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,  _______,
    _______, _______, _______,                            _______,                   _______, _______, MO(FN2), _______
 ),
 [FN2] = LAYOUT_60_ansi(
    _______, KC_AP2_BT1, KC_AP2_BT2, KC_AP2_BT3, KC_AP2_BT4, _______, _______, _______, _______, KC_AP_RGB_MOD, KC_AP_RGB_TOG, KC_AP_RGB_VAD, KC_AP_RGB_VAI, _______,
    MO(FN2), _______,    KC_UP,      _______,    _______,    _______, _______, _______, _______, _______,       KC_PSCR,       KC_HOME,       KC_END,        _______,
    _______, KC_LEFT,    KC_DOWN,    KC_RGHT,    _______,    _______, _______, _______, _______, _______,       KC_PGUP,       KC_PGDN,       _______,
    _______,             TO(BASE),TG(QWERTY),    _______,    _______, _______, _______, _______, _______,       KC_INS,        KC_DEL,        _______,
    _______, _______,    _______,                                     _______,                   _______,       MO(FN1),       MO(FN2),       _______
 ),
 [FN3] = LAYOUT_60_ansi(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LPRN, KC_RPRN, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_PMNS, KC_7,    KC_8,    KC_9,    KC_PPLS, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_PSLS, KC_4,    KC_5,    KC_6,    KC_PAST, KC_PENT, _______,
    _______,          _______, _______, _______, _______, _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_PDOT, _______,
    _______, _______, _______,                            _______,                   _______, _______, _______, _______
 ),
 [QWERTY] = LAYOUT_60_ansi(
    KC_ESC,           KC_1,    KC_2,    KC_3, KC_4, KC_5, KC_6,   KC_7, KC_8, KC_9,    KC_0,             KC_MINS,          KC_EQL,        KC_BSPC,
    LT(FN3, KC_TAB),  KC_Q,    KC_W,    KC_E, KC_R, KC_T, KC_Y,   KC_U, KC_I, KC_O,    KC_P,             KC_LBRC,          KC_RBRC,       KC_BSLS,
    LT(FN1, KC_ESC),  KC_A,    KC_S,    KC_D, KC_F, KC_G, KC_H,   KC_J, KC_K, KC_L,    KC_SCLN,          KC_QUOT,          KC_ENT,
    KC_LSFT,                   KC_Z,    KC_X, KC_C, KC_V, KC_B,   KC_N, KC_M, KC_COMM, KC_DOT,           KC_SLSH,          RSFT_T(KC_UP),
    KC_LCTL,          KC_LGUI, KC_LALT,                   KC_SPC,             KC_RALT, LT(FN1, KC_LEFT), LT(FN2, KC_DOWN), RCTL_T(KC_RGHT)
 ),
};
// clang-format on
