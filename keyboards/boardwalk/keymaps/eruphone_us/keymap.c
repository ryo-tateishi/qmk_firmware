/**
 * Keymaps for Eruphone US
 */
#include QMK_KEYBOARD_H
#include "keymap_jp.h"

// Layer shorthand
enum layer {
  _DEFAULT,
  _FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 /* MAIN
 * .-----------------------------------------------------------------------------------------------------------------------------.
 * | ESC    |   1    |   2    |   3    |   4    |   5    |   -    |   =    |   6    |   7    |   8    |   9    |   0    | BKSP   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | TAB    |   Q    |   W    |   E    |   R    |   T    |   [    |   ]    |   Y    |   U    |   I    |   O    |   P    |   |    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | CTRL   |   A    |   S    |   D    |   F    |   G    |   "    |   `    |   H    |   J    |   K    |   L    |   ;    | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | LSHIFT |   Z    |   X    |   C    |   V    |   B    | DELETE | BKSP   |   N    |   M    |   ,    |   .    |   /    | RSHIFT |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
 * | FN     | OPT    | COMMAND| FUNC   | EN     |      SPACE      |      ENTER      |  KANA  | COMMAND|  FN    |   ←    |   →    |
 * '-----------------------------------------------------------------------------------------------------------------------------'
 */
 [_DEFAULT] = LAYOUT_eruphone_US(
  KC_ESC , KC_1   , KC_2   , KC_3    , KC_4    , KC_5   , KC_MINUS , KC_EQL   , KC_6   , KC_7    , KC_8    , KC_9   , KC_0   , KC_BSPC, \
  KC_TAB , KC_Q   , KC_W   , KC_E    , KC_R    , KC_T   , KC_LBRC  , KC_RBRC  , KC_Y   , KC_U    , KC_I    , KC_O   , KC_P   , JP_YEN , \
  KC_LCTL, KC_A   , KC_S   , KC_D    , KC_F    , KC_G   , KC_QUOT  , KC_GRAVE , KC_H   , KC_J    , KC_K    , KC_L   , KC_SCLN, KC_ENT , \
  KC_LSFT, KC_Z   , KC_X   , KC_C    , KC_V    , KC_B   , KC_DEL   , KC_BSPC  , KC_N   , KC_M    , KC_COMM , KC_DOT , KC_SLSH, KC_RSFT, \
  MO(_FN), KC_LALT, KC_LGUI, KC_F12  , JP_MEISU,       KC_SPC      ,       KC_ENT      , JP_MKANA, KC_RGUI , MO(_FN), KC_LEFT, KC_RGHT  \
 ),

/* FUNCTION
 * .-----------------------------------------------------------------------------------------------------------------------------.
 * |        |  F1    |  F2    |  F3    |  F4    |  F5    |  F6    |  F7    |  F8    |  F9    |  F10   |  F11   |  F12   |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |        |        |        |        |        |        |        |        |        | UP     |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |        |        |        |        |        |        |        |        |  LEFT  | DOWN   | RIGHT  |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        | HOME   | END    |
 * '-----------------------------------------------------------------------------------------------------------------------------'
 */
 [_FN] = LAYOUT_eruphone(
  _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP  , _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______         , _______         , _______, _______, _______, _______, KC_HOME, KC_END
 )
};
