// vim:fdm=marker

#include QMK_KEYBOARD_H
#include "bootloader.h"
#include "lufa.h"
#include "split_util.h"
#include "ssd1306.h"

extern rgblight_config_t rgblight_config;
extern uint8_t is_master;

// {{{ Layer Configuration

enum layer_number {
    _QWERTY = 0,
    _RAISE,
};

#define KC_FN1 MO(1)

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    RAISE,
};

// }}}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// {{{ Layer QWERTY

/* Qwerty
* ,-----------------------------------------.             ,-----------------------------------------.
* | Esc  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  |  =   |
* |------+------+------+------+------+------|             |------+------+------+------+------+------|
* | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |  -   |
* |------+------+------+------+------+------|             |------+------+------+------+------+------|
* | Ctrl |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  '   |
* |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
* |Shift |   Z  |   X  |   C  |   V  |   B  |   [  |   ]  |   N  |   M  |   ,  |   .  |   /  |Shift |
* |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
* | Vol- | Play | Vol+ | Alt  | Gui  |Space |Bkspc |Enter |Space | Fn1  | Left | Down |  Up  |Right |
* `-------------------------------------------------------------------------------------------------'
*/

[_QWERTY] = LAYOUT( \
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,  \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS, \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_LBRC, KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    KC_VOLD, KC_MPLY, KC_VOLU, KC_LALT, KC_LGUI, KC_SPC, KC_BSPC,  KC_ENT,  KC_SPC,  KC_FN1,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),

// }}}

// {{{ Layer RAISE

/* Raise
* ,-----------------------------------------.             ,-----------------------------------------.
* |   `  |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |  F7  |  F8  |  F9  | F10  | F12  |
* |------+------+------+------+------+------|             |------+------+------+------+------+------|
* |      |      |      |      |RGBTog|Reset |             |      |      |      |      |      |  F11 |
* |------+------+------+------+------+------|             |------+------+------+------+------+------|
* |      |      |      |      |HueDn |HueUp |             | Left | Down | Up   |Right |  |   |  \   |
* |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
* | CAPS |      |      |      |SatDn |SatUp |      |      |      |      |      |      |      |      |
* |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |ValDn |ValUp | Del  | Pscr | Slck | Trns | Home | PgDn | PgUp | End  |
* `-------------------------------------------------------------------------------------------------'
*/

[_RAISE] = LAYOUT( \
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F12,  \
    _______, _______, _______, _______, RGB_TOG, RESET,                     _______, _______,  _______, _______, _______, KC_F11,  \
    _______, _______, _______, _______, RGB_HUD, RGB_HUI,                   KC_LEFT, KC_DOWN,  KC_UP,   KC_RGHT, KC_BSLS, KC_PIPE, \
    KC_CAPS, _______, _______, _______, RGB_SAD, RGB_SAI, KC_LPRN, KC_RPRN, _______,  _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, RGB_VAD, RGB_VAI, KC_DEL,  KC_PSCR, KC_SLCK, KC_TRNS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END   \
),

// }}}

};

// {{{ Layer Switch Handling

bool toggle_status = false;
int current_rgb_mode;

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                persistent_default_layer_set(1UL<<_QWERTY);
            }
            return false;
            break;

        case RAISE:
            if (record->event.pressed) {
                if (!toggle_status) {
                    toggle_status = !toggle_status;
                    rgblight_mode(RGBLIGHT_MODE_SNAKE);
                }
                layer_on(_RAISE);
            } else {
                rgblight_mode(current_rgb_mode);  // revert RGB to initial mode prior to RGB mode change
                layer_off(_RAISE);
                toggle_status = false;
            }
            return false;
            break;
    }
    return true;
}

// }}}

// {{{ Matrix Loop (Handles Screen)

void matrix_init_user(void) {
    current_rgb_mode = rgblight_config.mode;
    iota_gfx_init(!has_usb());   // turns on the display
}

void matrix_scan_user(void) {
     iota_gfx_task();  // this is what updates the display continuously
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
    if (memcmp(dest->display, source->display, sizeof(dest->display))) {
        memcpy(dest->display, source->display, sizeof(dest->display));
        dest->dirty = true;
    }
}

// }}}

// {{{ Screen

//assign the right code to your layers for OLED display
#define L_BASE 0
#define L_RAISE (1<<_RAISE)

static void render_logo(struct CharacterMatrix *matrix) {
    static const char helix_logo[] PROGMEM ={
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,
        0};
    matrix_write_P(matrix, helix_logo);
    //matrix_write_P(&matrix, PSTR(" Split keyboard kit"));
}

static void render_rgbled_status(bool full, struct CharacterMatrix *matrix) {
    char buf[30];
    if (RGBLIGHT_MODES > 1 && rgblight_config.enable) {
        if (full) {
            snprintf(buf, sizeof(buf), " LED %2d: %d,%d,%d ",
                    rgblight_config.mode,
                    rgblight_config.hue/RGBLIGHT_HUE_STEP,
                    rgblight_config.sat/RGBLIGHT_SAT_STEP,
                    rgblight_config.val/RGBLIGHT_VAL_STEP);
        } else {
            snprintf(buf, sizeof(buf), "[%2d] ",rgblight_config.mode);
        }
        matrix_write(matrix, buf);
    }
}

static void render_layer_status(struct CharacterMatrix *matrix) {
    // Define layers here, Have not worked out how to have text displayed for each layer. Copy down the number you see and add a case for it below
    char buf[10];
    matrix_write_P(matrix, PSTR("Layer: "));
    switch (layer_state) {
        case L_BASE:
            matrix_write_P(matrix, PSTR("Default"));
            break;
        case L_RAISE:
            matrix_write_P(matrix, PSTR("Raise"));
            break;
        default:
            matrix_write_P(matrix, PSTR("Undef-"));
            snprintf(buf,sizeof(buf), "%ld", layer_state);
            matrix_write(matrix, buf);
    }
}

void render_status(struct CharacterMatrix *matrix) {
    // Render to mode icon
    static const char os_logo[][2][3] PROGMEM = {
        {{0x95,0x96,0},{0xb5,0xb6,0}},{{0x97,0x98,0},{0xb7,0xb8,0}}
    };

    if (keymap_config.swap_lalt_lgui == false) {
        matrix_write_P(matrix, os_logo[0][0]);
        matrix_write_P(matrix, PSTR("\n"));
        matrix_write_P(matrix, os_logo[0][1]);
    } else {
        matrix_write_P(matrix, os_logo[1][0]);
        matrix_write_P(matrix, PSTR("\n"));
        matrix_write_P(matrix, os_logo[1][1]);
    }

    matrix_write_P(matrix, PSTR(" "));
    render_layer_status(matrix);
    matrix_write_P(matrix, PSTR("\n"));

    // Host Keyboard LED Status
    matrix_write_P(matrix, (host_keyboard_leds() & (1<<USB_LED_NUM_LOCK)) ? PSTR("NUMLOCK") : PSTR("       "));
    matrix_write_P(matrix, (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) ? PSTR("CAPS") : PSTR("    "));
    matrix_write_P(matrix, (host_keyboard_leds() & (1<<USB_LED_SCROLL_LOCK)) ? PSTR("SCLK") : PSTR("    "));
    matrix_write_P(matrix, PSTR("\n"));
    render_rgbled_status(true, matrix);
}

// }}}

// {{{ Matrix / Screen Update Loop

void iota_gfx_task_user(void) {
    struct CharacterMatrix matrix;

    matrix_clear(&matrix);
    if (is_master) {
        render_status(&matrix);
    } else {
        render_logo(&matrix);
        render_rgbled_status(false, &matrix);
        render_layer_status(&matrix);
    }
    matrix_update(&display, &matrix);
}

// }}}
