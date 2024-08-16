#include "viterbi.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define BASE 0
#define ALT  1

/* #define KC_ECTRL LCTL_T(KC_ESC) */
#define KC_FN1   MO(1)
#define KC___    KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_ortho_5x14(
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_ESC,   KC_BSLS,  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_EQL,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_LBRC,  KC_RBRC,  KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_MINS,
    KC_LCTRL, KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_LPRN,  KC_RPRN,  KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_LCBR,  KC_RCBR,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
    KC_VOLD,  KC_MPLY,  KC_VOLU,  KC_LALT,  KC_LGUI,  KC_SPC,   KC_BSPC,  KC_ENT,   KC_SPC,   KC_FN1,   KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT
  ),

  [ALT] = LAYOUT_ortho_5x14(
    KC___,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC___,    KC_PSCR,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F12,
    KC___,    KC_WH_D,  KC_MS_U,  KC_WH_U,  KC_ACL0,  KC___,    KC___,    KC___,    KC___,    KC___,    KC___,    KC___,    KC_PSCR,  KC_F11,
    KC_CAPS,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_ACL1,  KC___,    KC___,    KC___,    KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, KC_SCRL,  KC___,
    KC___,    KC___,    KC___,    KC___,    KC_ACL2,  KC___,    KC___,    KC___,    KC___,    KC___,    KC___,    KC___,    KC_P7,    KC___,
    KC_MPRV,  KC_MUTE,  KC_MNXT,  KC___,    KC_BTN2,  KC_BTN1,  KC_DEL,   KC___,    KC___,    KC_TRNS,  KC___,    KC___,    KC___,    KC___
  )
};
