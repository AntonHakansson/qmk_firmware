#include QMK_KEYBOARD_H
#include "hk_keymap.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: Colemak DH
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  | ;  : | {      |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   R  |   S  |   T  |   G  |                              |   M  |   N  |   E  |   I  |   O  |Ctrl/' "|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   D  |   V  | [ {  |CapsLk|  |F-keys|  ] } |   K  |   H  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |Adjust| LGUI | LAlt/|LShift| Nav  |  | Sym  |RShift| AltGr| RGUI | Menu |
 *                        |      |      | Enter| Space|      |  |      | Bksp | Enter|      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_COLEMAK_DH] = LAYOUT(
     KC_TAB  , KC_Q ,  KC_W   ,  KC_F  ,   KC_P ,   KC_B ,                                           KC_J,   KC_L ,  KC_U ,   KC_Y ,KC_SCLN, LSFT(KC_LBRC),
     CTL_ESC , KC_A ,  KC_R   ,  KC_S  ,   KC_T ,   KC_G ,                                           KC_M,   KC_N ,  KC_E ,   KC_I ,  KC_O , CTL_QUOT,
     KC_LSFT , KC_Z ,  KC_X   ,  KC_C  ,   KC_D ,   KC_V , KC_LBRC,KC_CAPS,     FKEYS , KC_RBRC,     KC_K,   KC_H ,KC_COMM, KC_DOT ,KC_SLSH, KC_RSFT,
                                 ADJUST, KC_LGUI, ALT_ENT,LSFT_SPC, NAV   ,     SYM   ,RSFT_BSPC,RALT_ENT, KC_RGUI, KC_APP
    ),

/*
 * Nav Layer: Media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              | PgUp | Home |   ↑  | End  | VolUp| Delete |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  GUI |  Alt | Ctrl | Shift|      |                              | PgDn |  ←   |   ↓  |   →  | VolDn| Insert |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |ScLck |  |      |      | Pause|M Prev|M Play|M Next|VolMut| PrtSc  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAV] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_VOLU, KC_DEL,
      _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                                     KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD, KC_INS,
      _______, _______, _______, _______, _______, _______, _______, KC_SCRL, _______, _______,KC_PAUSE, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_PSCR,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Sym Layer: Numbers and symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |    `   |  1   |  2   |  3   |  4   |  5   |                              |   6  |  7   |  8   |  9   |  0   |   =    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |    ~   |  !   |  @   |  #   |  $   |  %   |                              |   ^  |  &   |  *   |  (   |  )   |   +    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |    |   |   \  |  :   |  ;   |  -   |  [   |  {   |      |  |      |   }  |   ]  |  _   |  ,   |  .   |  /   |   ?    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYM] = LAYOUT(
      KC_GRV ,   KC_1 ,   KC_2 ,   KC_3 ,   KC_4 ,   KC_5 ,                                       KC_6 ,   KC_7 ,   KC_8 ,   KC_9 ,   KC_0 , KC_EQL ,
     KC_TILD , KC_EXLM,  KC_AT , KC_HASH,  KC_DLR, KC_PERC,                                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,
     KC_PIPE , KC_BSLS, KC_COLN, KC_SCLN, KC_MINS, KC_LBRC, KC_LCBR, _______, _______, KC_RCBR, KC_RBRC, KC_UNDS, KC_COMM,  KC_DOT, KC_SLSH, KC_QUES,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Function Layer: Function keys
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  F9  | F10  | F11  | F12  |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  F5  |  F6  |  F7  |  F8  |      |                              |      | Shift| Ctrl |  Alt |  GUI |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_FUNCTION] = LAYOUT(
      _______,  KC_F9 ,  KC_F10,  KC_F11,  KC_F12, _______,                                     _______, _______, _______, _______, _______, _______,
      _______,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 , _______,                                     _______, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, _______,
      _______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Adjust Layer: Default layer settings, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              | TOG  | SAI  | HUI  | VAI  | MOD  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |Colmak|      |      |      |      |  |      |      |      | SAD  | HUD  | VAD  | RMOD |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
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
  SENTENCE_END,

  // Backspace steno-lite combos
  STENO_AND,
  STENO_THE,
  STENO_HAVE,
  STENO_HAVENT,
  STENO_WHAT,
  STENO_WHICH,
  STENO_BECAUSE,
  STENO_ABOUT,
  STENO_YOU,
  STENO_WITHOUT,
  STENO_IN_THE,

  STENO_OULD,
  STENO_MENT,
  STENO_TION,
  STENO_ING,
  STENO_OUGH,
  STENO_QUE,
};

const uint16_t PROGMEM COMMA_DOT_COMBO[] = {KC_COMMA,  KC_DOT,  COMBO_END};

const uint16_t PROGMEM BSPC_A_COMBO[]    = {RSFT_BSPC,  KC_A,  COMBO_END};
const uint16_t PROGMEM BSPC_T_COMBO[]    = {RSFT_BSPC,  KC_T,  COMBO_END};
const uint16_t PROGMEM BSPC_H_COMBO[]    = {RSFT_BSPC,  KC_H,  COMBO_END};
const uint16_t PROGMEM BSPC_W_COMBO[]    = {RSFT_BSPC,  KC_W,  COMBO_END};
const uint16_t PROGMEM BSPC_S_COMBO[]    = {RSFT_BSPC,  KC_S,  COMBO_END};
const uint16_t PROGMEM BSPC_C_COMBO[]    = {RSFT_BSPC,  KC_C,  COMBO_END};
const uint16_t PROGMEM BSPC_B_COMBO[]    = {RSFT_BSPC,  KC_B,  COMBO_END};
const uint16_t PROGMEM BSPC_U_COMBO[]    = {RSFT_BSPC,  KC_U,  COMBO_END};
const uint16_t PROGMEM BSPC_W_O_COMBO[]    = {RSFT_BSPC, KC_W, KC_O,  COMBO_END};
const uint16_t PROGMEM BSPC_H_T_COMBO[]  = {RSFT_BSPC,  KC_H,  KC_T,  COMBO_END};
const uint16_t PROGMEM BSPC_I_T_COMBO[]  = {RSFT_BSPC,  KC_I,  KC_T,  COMBO_END};

const uint16_t PROGMEM BSPC_D_COMBO[]    = {RSFT_BSPC,  KC_D,  COMBO_END};
const uint16_t PROGMEM BSPC_M_COMBO[]    = {RSFT_BSPC,  KC_M,  COMBO_END};
const uint16_t PROGMEM BSPC_I_COMBO[]    = {RSFT_BSPC,  KC_I,  COMBO_END};
const uint16_t PROGMEM BSPC_G_COMBO[]    = {RSFT_BSPC,  KC_G,  COMBO_END};
const uint16_t PROGMEM BSPC_O_COMBO[]    = {RSFT_BSPC,  KC_O,  COMBO_END};
const uint16_t PROGMEM BSPC_Q_COMBO[]    = {RSFT_BSPC,  KC_Q,  COMBO_END};

combo_t key_combos[] = {
  [SENTENCE_END]  = COMBO_ACTION(COMMA_DOT_COMBO),
  [STENO_AND]     = COMBO_ACTION(BSPC_A_COMBO),
  [STENO_THE]     = COMBO_ACTION(BSPC_T_COMBO),
  [STENO_HAVE]    = COMBO_ACTION(BSPC_H_COMBO),
  [STENO_HAVENT]  = COMBO_ACTION(BSPC_H_T_COMBO),
  [STENO_WHAT]    = COMBO_ACTION(BSPC_W_COMBO),
  [STENO_WHICH]   = COMBO_ACTION(BSPC_S_COMBO),
  [STENO_BECAUSE] = COMBO_ACTION(BSPC_C_COMBO),
  [STENO_ABOUT]   = COMBO_ACTION(BSPC_B_COMBO),
  [STENO_YOU]   = COMBO_ACTION(BSPC_U_COMBO),
  [STENO_WITHOUT] = COMBO_ACTION(BSPC_W_O_COMBO),
  [STENO_IN_THE]  = COMBO_ACTION(BSPC_I_T_COMBO),
  [STENO_OULD]    = COMBO_ACTION(BSPC_D_COMBO),
  [STENO_MENT]    = COMBO_ACTION(BSPC_M_COMBO),
  [STENO_TION]    = COMBO_ACTION(BSPC_I_COMBO),
  [STENO_ING]     = COMBO_ACTION(BSPC_G_COMBO),
  [STENO_OUGH]   = COMBO_ACTION(BSPC_O_COMBO),
  [STENO_QUE]     = COMBO_ACTION(BSPC_Q_COMBO),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
  case SENTENCE_END:
    if (pressed) {
      tap_code(KC_DOT);
      tap_code(KC_SPC);
      add_oneshot_mods(MOD_BIT(KC_LEFT_SHIFT));
    } break;
  case STENO_AND:     if (pressed) { SEND_STRING("and "); } break;
  case STENO_THE:     if (pressed) { SEND_STRING("the "); } break;
  case STENO_HAVE:    if (pressed) { SEND_STRING("have "); } break;
  case STENO_HAVENT:  if (pressed) { SEND_STRING("haven't "); } break;
  case STENO_WHAT:    if (pressed) { SEND_STRING("what "); } break;
  case STENO_WHICH:   if (pressed) { SEND_STRING("which "); } break;
  case STENO_BECAUSE: if (pressed) { SEND_STRING("because "); } break;
  case STENO_ABOUT:   if (pressed) { SEND_STRING("about "); } break;
  case STENO_YOU:     if (pressed) { SEND_STRING("you "); } break;
  case STENO_WITHOUT: if (pressed) { SEND_STRING("without "); } break;
  case STENO_IN_THE:  if (pressed) { SEND_STRING("in the "); } break;

  case STENO_OULD:    if (pressed) { SEND_STRING("ould "); } break;
  case STENO_MENT:    if (pressed) { SEND_STRING("ment "); } break;
  case STENO_TION:    if (pressed) { SEND_STRING("tion "); } break;
  case STENO_ING:     if (pressed) { SEND_STRING("ing "); } break;
  case STENO_OUGH:    if (pressed) { SEND_STRING("ough"); } break;
  case STENO_QUE:     if (pressed) { SEND_STRING("que"); } break;
  }
}


/* Local Variables: */
/* compile-command: "nix run nixpkgs#qmk -- compile -e CONVERT_TO=elite_pi" */
/* End: */
