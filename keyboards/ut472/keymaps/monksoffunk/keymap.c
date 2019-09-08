/*
 * Keymap.c for UT47.2
 * mainly customised for Japanese IME operation
 *
 * Copyright 2019 monksoffunk
 * Copyright 2018 Carlos Filoteo
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
#include QMK_KEYBOARD_H
extern keymap_config_t keymap_config;
#define TAB_CTL LCTL_T(KC_TAB)

enum custom_keycodes {
  KANA = SAFE_RANGE,
  EISU,
  ADJ
  };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Base Layer
   * ,-------------------------------------------------------------------------.
   * | Esc |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |Bspace |
   * |-------------------------------------------------------------------------+
   * |Tab/Ctl|  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  | Ent |
   * |-------------------------------------------------------------------------+
   * | Shift |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |Sh/En|
   * |-------------------------------------------------------------------------+
   * | Ctrl| L3 | Alt | Gui  |  L2  |   Space   |  L1  | Left| Down|  Up |Right|
   * `-------------------------------------------------------------------------'
   */

LAYOUT(
  KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  TAB_CTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
  KC_LCTL, MO(3),  KC_LALT,  KC_LGUI, MO(2),      KC_SPC,        MO(1),   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

  /* FN Layer 1 Right Raise
   * ,-------------------------------------------------------------------------.
   * | ` ~ |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  | Delete|
   * |-------------------------------------------------------------------------+
   * |      |     |     |     |     |     |     |  -  |  =  |  [  |  ]  |   "  |
   * |-------------------------------------------------------------------------+
   * |       |    |     |     |     |     |     |     |     |     |  \  |      |
   * |-------------------------------------------------------------------------+
   * |     |     |     |Capsl|      |          |       | Home| PgDn| PgUp| End |
   * `-------------------------------------------------------------------------'
   */

LAYOUT( /* Right */
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DELETE,
  _______, RGB_TOG, RGB_MOD, RGB_VAI, RGB_VAD, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, S(KC_QUOT),
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSLS, _______,
  _______, _______, _______, KC_CAPS, _______,     _______,      _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
),

  /* FN Layer 2 Left Lower
   * ,-------------------------------------------------------------------------.
   * |   ~  |  !  |  @  |  #  |  $  |  %  |  ^  |  &  |  *  |  (  |  )  |Delete|
   * |-------------------------------------------------------------------------+
   * |      |  F1 |  F2 | F3  | F4  |  F5 |     |  _  |  +  |  { |  }  |   '   |
   * |-------------------------------------------------------------------------+
   * |       | F6  | F7  | F8  | F9  | F10 | F11  | F12  |    |    |  |  |     |
   * |-------------------------------------------------------------------------+
   * |     |     |     |Capsl|      |          |       | Home| PgDn| PgUp| End |
   * `-------------------------------------------------------------------------'
   */

LAYOUT( /* Left */
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_QUOT,
  _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, KC_PIPE, _______,
  _______, _______, _______, KC_CAPS, _______,     _______,      _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
),

  /* FN Layer 3 Adj
   * ,-------------------------------------------------------------------------.
   * | Esc | Calc|Webhm| Mail| Comp|     |     |     |     |     |PrtSc|       |
   * |-------------------------------------------------------------------------+
   * |       |     |     |     |     |     |     |     |     |     |     |     |
   * |-------------------------------------------------------------------------+
   * |       |    |     |     |     |     |     |     | Mac | Win |      |     |
   * |-------------------------------------------------------------------------+
   * |     |     | L4  |     | Eisu |          | Kana  |MousL|MousD|MousU|MousR|
   * `-------------------------------------------------------------------------'
   */

LAYOUT( /* Adj */
  KC_ESC,  KC_CALC, KC_WHOM, KC_MAIL, KC_MYCM, _______, _______, _______, _______, _______, KC_PSCR, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, AG_NORM, AG_SWAP, _______, _______,
  _______, _______, MO(4),   _______, EISU,        _______,      KANA,    KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R
),

  /* FN Layer 4 Adj2
   * ,-------------------------------------------------------------------------.
   * |     |     |     |     |RESET|     |     |     |     |     |     |       |
   * |-------------------------------------------------------------------------+
   * |       |     |     |     |     |     |     |     |     |     |     |     |
   * |-------------------------------------------------------------------------+
   * |       |    |     |     |     |     |     |     |     |     |      |     |
   * |-------------------------------------------------------------------------+
   * |     |     |     |     |      |          |       |     |     |     |     |
   * `-------------------------------------------------------------------------'
   */

LAYOUT( /* Adj2 */
  _______, _______, _______, _______, RESET,   _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,      _______,     _______, _______, _______, _______, _______
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case EISU:
      if (record->event.pressed) {
        if(keymap_config.swap_lalt_lgui==false){
          register_code(KC_LANG2);
        }else{
          SEND_STRING(SS_LALT("`"));
        }
      } else {
        unregister_code(KC_LANG2);
      }
      return false;
      break;
    case KANA:
      if (record->event.pressed) {
        if(keymap_config.swap_lalt_lgui==false){
          register_code(KC_LANG1);
        }else{
         SEND_STRING(SS_LALT("`"));
        }
      } else {
        unregister_code(KC_LANG1);
      }
      return false;
      break;
  }
  return true;
}
