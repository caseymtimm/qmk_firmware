/* Copyright 2019 Casey Timm
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    BORK = SAFE_RANGE
};

enum unicode_names {
    BORKER,
};

const uint32_t PROGMEM unicode_map[] = {
    [BORKER]  = 0x1F436,  // ‽
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_ESC,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,           KC_0,          KC_BSPACE,
        KC_TAB,    KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,           KC_P,          KC_EQUAL,
        KC_LOCK,   KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,           KC_SCOLON,     KC_ENTER,
        KC_LSHIFT, KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMMA,   KC_DOT,         KC_SLASH,      KC_QUOTE,
        KC_LCTRL,  KC_LGUI,    KC_RALT,    KC_SPACE,   KC_SPACE,   KC_SPACE,   KC_SPACE,   KC_SPACE,   KC_MINUS,   KC_LBRACKET,    KC_RBRACKET,   MO(_FN)
    ),
    [_FN] = LAYOUT(
        KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,       KC_NO,           KC_NO,          KC_NO,
        KC_NO,     KC_NO,    KC_UP,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,       KC_NO,           KC_NO,          KC_NO,
        KC_NO,     KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,       KC_NO,           KC_NO,          KC_NO,
        KC_LSHIFT,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,       KC_NO,           KC_BSLASH,      KC_GRAVE,
        KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,       KC_NO,           KC_NO,          MO(_FN)
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BORK:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("BORK BORK");
            } else {
                // when keycode QMKBEST is released
            }
            break;
    }
    return true;
}

/*
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool led_update_user(led_t led_state) {
    return true;
}
*/
