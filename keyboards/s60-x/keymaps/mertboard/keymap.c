#include "s60-x.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Base Qwertyish
  LEGACY_KEYMAP(
    ESC,     1,    2,   3,   4,   5,   6,   7,   8,    9,    0, MINS,  EQL,   NO, BSPC, \
    TAB,     Q,    W,   E,   R,   T,   Y,   U,   I,    O,    P, LBRC, RBRC, BSLS,       \
    LCTL,    A,    S,   D,   F,   G,   H,   J,   K,    L, SCLN, QUOT,   NO,  ENT,       \
    LSFT,   NO,    Z,   X,   C,   V,   B,   N,   M, COMM,  DOT, SLSH,   NO, RSFT,   NO, \
    FN0,  LALT, LGUI,                SPC,                 RGUI, RALT, PGDN, PGUP),

  // Fn Overlay
  LEGACY_KEYMAP(
    GRV,    F1,   F2,   F3,   F4,   F5,   F6,   F7,   F8,   F9,  F10,  F11,  F12, TRNS, DEL,  \
    TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       \
    CAPS, TRNS, TRNS, TRNS, TRNS, TRNS, LEFT, DOWN,   UP, RGHT, TRNS, TRNS, TRNS, TRNS,       \
    TRNS, TRNS, MPRV, MPLY, MNXT, MUTE, VOLD, VOLU, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
    TRNS, TRNS, TRNS,                   TRNS,                   TRNS, TRNS,  END, HOME),
};

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_MOMENTARY(1),
};
