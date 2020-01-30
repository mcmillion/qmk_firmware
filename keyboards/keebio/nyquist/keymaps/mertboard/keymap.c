#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _MOD 1

#define KC_GUIBK LGUI_T(KC_BSPC)
#define KC_FNENT LT(_MOD, KC_ENT)
#define KC_FNSPC LT(_MOD, KC_LALT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.          ,-----------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |          |   6  |   7  |   8  |   9  |   0  |  =   |
 * |------+------+------+------+------+------|          |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |          |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|          |------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |          |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|          |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |          |   N  |   M  |   ,  |   .  |   /  | Shift|
 * |------+------+------+------+------+------|          |------+------+------+------+------+------|
 * | Vol- | Play | Vol+ |  Alt | GuiBk| Space|          | Space| FnEnt| Alt  | Bspc | Home | End  |
 * `-----------------------------------------'          `-----------------------------------------'
 */
[_QWERTY] = LAYOUT( \
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,   KC_7,     KC_8,    KC_9,    KC_0,    KC_EQL,  \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,   KC_U,     KC_I,    KC_O,    KC_P,    KC_MINS, \
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,   KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,   KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
  KC_VOLD, KC_MPLY, KC_VOLU, KC_LALT, KC_GUIBK,KC_SPC,  KC_SPC, KC_FNENT, KC_RALT, KC_BSPC, KC_HOME, KC_END   \
),

/* MOD
 * ,-----------------------------------------.          ,-----------------------------------------.
 * |  `   |  F1  |  F2  |  F3  |  F4  |  F5  |          |  F6  |  F7  |  F8  |  F9  |  F0  |  +   |
 * |------+------+------+------+------+------|          |------+------+------+------+------+------|
 * |      |      |  Up  |      |      |      |          |  <   |  >   |  `   |  F11 |  F12 |  _   |
 * |------+------+------+------+------+------|          |------+------+------+------+------+------|
 * | Caps | Left | Down | Right|      | LED  |          | Left | Down |  Up  | Right|  \   |  |   |
 * |------+------+------+------+------+------|          |------+------+------+------+------+------|
 * |      |      |      |      |      |      |          |  (   |  )   |  {   |  }   |  [   |  ]   |
 * |------+------+------+------+------+------|          |------+------+------+------+------+------|
 * | Prev | Play | Next |      |  Del |      |          |      | FnEnt|      |  Del |      | Reset|
 * `-----------------------------------------'          `-----------------------------------------'
 */
[_MOD] = LAYOUT( \
  KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_PLUS, \
  _______, _______, KC_UP,   _______, _______, _______, KC_LT,   KC_GT,   KC_GRV,  KC_F11,  KC_F12,  KC_UNDS, \
  KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, _______, BL_STEP, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSLS, KC_PIPE, \
  _______, _______, _______, _______, _______, _______, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, \
  KC_MPRV, KC_MPLY, KC_MNXT, _______, KC_DEL,  _______, _______, _______, _______, KC_DEL,  _______, RESET    \
),

};
