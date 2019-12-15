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


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_7, KC_8,    KC_9,      KC_SLASH,   KC_KP_ASTERISK,
        KC_4, KC_5,    KC_6,      KC_MINUS,   KC_COPY,
        KC_1, KC_2,    KC_3,      KC_KP_PLUS, KC_PASTE,
        KC_0, KC_DOT,  KC_ENTER,  KC_EQUAL,   TG(_FN)
    ),
    [_FN] = LAYOUT(
        KC_BTN1, KC_MS_U,  KC_BTN2,  KC_WH_U,  KC_NO,
        KC_MS_L, KC_BTN5,  KC_MS_R,  KC_WH_D,  KC_NO,
        KC_BTN3, KC_MS_D,  KC_BTN4,  KC_NO,    KC_NO,
        KC_NO,   KC_NO,    KC_NO,    KC_NO,    TG(_BASE)
    )
};


/*
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool led_update_user(led_t led_state) {
    return true;
}
*/
