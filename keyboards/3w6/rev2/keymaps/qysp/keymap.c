/*
Copyright 2021 weteor

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "pimoroni_trackball.h"

enum layers
{
    _ALPHA_QWERTY = 0,
    _ALPHA_COLEMAK_DH,
    _SYM,
    _NAV,
    _NUM,
    _WM,
    _MISC,
};

enum custom_keycodes
{
    BALL_SCR = SAFE_RANGE,
    COPY,
    PASTE,
};

#define DF_QWRT DF(_ALPHA_QWERTY)
#define DF_CLMK DF(_ALPHA_COLEMAK_DH)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_ALPHA_QWERTY] = LAYOUT(
        KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,                                    KC_Y,         KC_U,          KC_I,         KC_O,         KC_P,
        // -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,                                    KC_H,         RSFT_T(KC_J),  RCTL_T(KC_K), LALT_T(KC_L), RGUI_T(KC_SCLN),
        // -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,                                    KC_N,         KC_M,          KC_COMM,      KC_DOT,       KC_SLSH,
        // -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                              RALT_T(KC_ESC), LT(_NAV, KC_TAB), LT(_NUM, KC_SPC),               KC_ENT, LT(_SYM, KC_BSPC), XXXXXXX
        // -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    ),
    [_ALPHA_COLEMAK_DH] = LAYOUT(
        KC_Q,         KC_W,         KC_F,         KC_P,         KC_B,                                    KC_J,         KC_L,          KC_U,         KC_Y,         KC_SCLN,
        // -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_G,                                    KC_M,         RSFT_T(KC_N),  RCTL_T(KC_E), LALT_T(KC_I), RGUI_T(KC_O),
        // -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        KC_Z,         KC_X,         KC_C,         KC_D,         KC_V,                                    KC_K,         KC_H,          KC_COMM,      KC_DOT,       KC_SLSH,
        // -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                              RALT_T(KC_ESC), LT(_NAV, KC_TAB), LT(_NUM, KC_SPC),               KC_ENT, LT(_SYM, KC_BSPC), XXXXXXX
        // -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    ),
    [_SYM] = LAYOUT(
        KC_EXLM,      KC_AT,        KC_HASH,      KC_DLR,       KC_PERC,                                 KC_CIRC,      KC_AMPR,       KC_ASTR,      XXXXXXX,      KC_GRV,
        // -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        KC_SLSH,      KC_LBRC,      KC_LCBR,      SC_LSPO,      KC_EQL,                                  KC_MINS,      SC_RSPC,       KC_RCBR,      KC_RBRC,      KC_QUOT,
        // -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,                                 XXXXXXX,      OSM(MOD_RALT), XXXXXXX,      XXXXXXX,      KC_BSLS,
        // -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                         KC_ESC, LM(_WM, MOD_LGUI), LCTL(KC_SPC),               XXXXXXX, XXXXXXX, XXXXXXX
        // -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    ),
    [_NAV] = LAYOUT(
        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,                                 XXXXXXX,      KC_HOME,       KC_END,       KC_PGDN,      KC_PGUP,
        // -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        BALL_SCR,     KC_LALT,      KC_LCTL,      KC_LSFT,      XXXXXXX,                                 KC_LEFT,      KC_DOWN,       KC_UP,        KC_RGHT,      XXXXXXX,
        // -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,                                 XXXXXXX,      COPY,          PASTE,        XXXXXXX,      XXXXXXX,
        // -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                       XXXXXXX, XXXXXXX, XXXXXXX,               KC_DEL, MO(_MISC), XXXXXXX
        // -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    ),
    [_NUM] = LAYOUT(
        KC_NUM,       KC_F9,        KC_F10,       KC_F11,       KC_F12,                                  KC_PPLS,      KC_P7,         KC_P8,        KC_P9,        KC_PSLS,
        // -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        XXXXXXX,      KC_F5,        KC_F6,        KC_F7,        KC_F8,                                   KC_P0,        KC_P4,         KC_P5,        KC_P6,        KC_PDOT,
        // -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        XXXXXXX,      KC_F1,        KC_F2,        KC_F3,        KC_F4,                                   KC_PMNS,      KC_P1,         KC_P2,        KC_P3,        KC_PAST,
        // -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                       XXXXXXX, XXXXXXX, XXXXXXX,               KC_PEQL, KC_PENT, XXXXXXX
        // -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    ),
    [_WM] = LAYOUT(
        KC_Q,         RGUI(KC_7),   RGUI(KC_8),   RGUI(KC_9),   KC_T,                                    KC_Y,         KC_U,          KC_I,         KC_O,         KC_P,
        // -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        KC_A,         RGUI(KC_4),   RGUI(KC_5),   RGUI(KC_6),   KC_ENTER,                                KC_H,         KC_J,          KC_K,         KC_L,         XXXXXXX,
        // -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        KC_LSFT,      RGUI(KC_1),   RGUI(KC_2),   RGUI(KC_3),   KC_B,                                    KC_N,         KC_M,          XXXXXXX,      XXXXXXX,      KC_RSFT,
        // -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                        XXXXXXX, XXXXXXX, XXXXXXX,              XXXXXXX, XXXXXXX, XXXXXXX
        // -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    ),
    [_MISC] = LAYOUT(
        XXXXXXX,      KC_VOLD,      KC_MUTE,      KC_VOLU,      XXXXXXX,                                 XXXXXXX,      XXXXXXX,       XXXXXXX,    DF_QWRT,    DF_CLMK,
        // -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        XXXXXXX,      KC_MPRV,      KC_MSTP,      KC_MNXT,      KC_MPLY,                                 XXXXXXX,      KC_BTN1,       KC_BTN2,    XXXXXXX,    XXXXXXX,
        // -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        XXXXXXX,      DT_DOWN,      DT_PRNT,      DT_UP,        XXXXXXX,                                 XXXXXXX,      XXXXXXX,       XXXXXXX,    XXXXXXX,    XXXXXXX,
        // -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                       XXXXXXX, XXXXXXX, XXXXXXX,               XXXXXXX, XXXXXXX, XXXXXXX
        // -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case BALL_SCR:
        if(record->event.pressed)
            trackball_set_scrolling(true);
        else
            trackball_set_scrolling(false);
        break;
    case COPY:
        if (record->event.pressed)
            SEND_STRING(SS_LCTL("c"));
        break;
    case PASTE:
        if (record->event.pressed)
            SEND_STRING(SS_LCTL("v"));
        break;
    }

    return true;
}
