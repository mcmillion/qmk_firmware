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
  [BASE] = LAYOUT_kc(
    GRV,   1,     2,     3,     4,     5,     ESC,   BSLS,  6,     7,     8,     9,     0,     EQL,
    TAB,   Q,     W,     E,     R,     T,     LBRC,  RBRC,  Y,     U,     I,     O,     P,     MINS,
    LCTRL, A,     S,     D,     F,     G,     LPRN,  RPRN,  H,     J,     K,     L,     SCLN,  QUOT,
    LSFT,  Z,     X,     C,     V,     B,     LCBR,  RCBR,  N,     M,     COMM,  DOT,   SLSH,  RSFT,
    VOLD,  MPLY,  VOLU,  LALT,  LGUI,  SPC,   BSPC,  ENT,   SPC,   FN1,   LEFT,  DOWN,  UP,    RIGHT
  ),

  [ALT] = LAYOUT_kc(
    __,    F1,    F2,    F3,    F4,    F5,    __,    PSCR,  F6,    F7,    F8,    F9,    F10,   F12,
    __,    WH_D,  MS_U,  WH_U,  ACL0,  __,    __,    __,    __,    __,    __,    __,    __,    F11,
    __,    MS_L,  MS_D,  MS_R,  ACL1,  __,    __,    __,    LEFT,  DOWN,  UP,    RIGHT, __,    __,
    __,    __,    __,    __,    ACL2,  __,    __,    __,    __,    __,    __,    __,    __,    __,
    MPRV,  MUTE,  MNXT,  __,    BTN2,  BTN1,  DEL,   __,    __,    TRNS,  __,    __,    __,    __
  )
};
