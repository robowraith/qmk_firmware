/* Copyright 2021 StefanGrindelwald
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
#include "keymap_german.h"

void keyboard_post_init_user(void)
{
    #ifdef RGBLIGHT_ENABLE
        rgblight_sethsv(HSV_RED);
        rgblight_mode(RGBLIGHT_MODE_KNIGHT + 2);
    #endif
}

// Home-Row-Mod-Keys for QWERTZ and Bone
#define BO_C LGUI_T(DE_C)
#define BO_T LALT_T(DE_T)
#define BO_I LCTL_T(DE_I)
#define BO_E LSFT_T(DE_E)
#define BO_N RSFT_T(DE_N)
#define BO_R RCTL_T(DE_R)
#define BO_S RALT_T(DE_S)
#define BO_G RGUI_T(DE_G)

// Modifier-keys for QWERTZ and Bone
/*
#define BO_MO1L LT(1, KC_BSPC)
#define BO_MO1R LT(1, KC_SPC)
#define BO_MO3L LT(3, KC_BSPC)
#define BO_MO3R LT(3, KC_SPC)
#define BO_MO5L LT(5, KC_DEL)
#define BO_MO5R LT(5, KC_ENT)
*/

// Defines names for use in layer keycodes and the keymap
/*
enum layer_names {
    _BONEL,
    _BONEM,
    _SLL,
    _SLM,
    _UTIL
};
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Bone for Linux */
    [0] = LAYOUT(
        KC_ESC,   DE_1,    DE_2,    DE_3,    DE_4,    DE_5,                                           DE_6,    DE_7,    DE_8,    DE_9,    DE_0,    KC_BSPC,
        KC_TAB,   DE_J,    DE_D,    DE_U,    DE_A,    DE_X,                                           DE_P,    DE_H,    DE_L,    DE_M,    DE_W,    DE_SS,
        KC_CAPS,  BO_C,    BO_T,    BO_I,    BO_E,    DE_O,                                           DE_B,    BO_N,    BO_R,    BO_S,    BO_G,    DE_Q,
        KC_LSFT,  DE_F,    DE_V,    DE_UDIA, DE_ADIA, DE_ODIA,                                        DE_Y,    DE_Z,    DE_COMM, DE_DOT,  DE_K,    KC_RSFT,
        TT(5),    KC_GRV,  KC_EQL,  MO(5),   MO(1),                                                            MO(1),   MO(5),   KC_LBRC, KC_RBRC, TT(5),
                                                               KC_LCTL, KC_LALT,    KC_RGUI, KC_RCTL,
                                                                        KC_HOME,    KC_PGUP,
                                                      KC_BSPC, KC_DEL,  KC_END,     KC_PGDN, KC_ENT,  KC_SPC
    ),
    /* Shifted Layer for Linux */
    [1] = LAYOUT(
        KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                                          KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,
        KC_NO,    DE_DEG,  DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC,                                        DE_EXLM, DE_LABK, DE_RABK,  DE_EQL,  DE_AMPR, DE_EURO,
        KC_NO,    DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR,                                        DE_QUES, DE_LPRN, DE_RPRN,  DE_MINS, DE_COLN, DE_AT,
        KC_NO,    DE_HASH, DE_DLR,  DE_PIPE, DE_TILD, DE_GRV,                                         DE_PLUS, DE_PERC, DE_DQUO,  DE_QUOT, DE_SCLN, KC_NO,
        KC_NO,    KC_NO,   KC_NO,   KC_NO,   C(DE_X),                                                          C(DE_X), KC_NO,    KC_NO,   KC_NO,   KC_NO,
                                                               KC_LCTL, KC_LALT,    KC_RGUI, KC_RCTL,
                                                                        KC_HOME,    KC_PGUP,
                                                      C(DE_C), C(DE_V), KC_END,     KC_PGDN, C(DE_V),  C(DE_C)

    ),
    /* Bone for Mac */
    [2] = LAYOUT(
        KC_ESC,   DE_1,    DE_2,    DE_3,    DE_4,    DE_5,                                           DE_6,    DE_7,    DE_8,    DE_9,    DE_0,    KC_BSPC,
        KC_TAB,   DE_J,    DE_D,    DE_U,    DE_A,    DE_X,                                           DE_P,    DE_H,    DE_L,    DE_M,    DE_W,    DE_SS,
        KC_CAPS,  BO_C,    BO_T,    BO_I,    BO_E,    DE_O,                                           DE_B,    BO_N,    BO_R,    BO_S,    BO_G,    DE_Q,
        KC_LSFT,  DE_F,    DE_V,    DE_UDIA, DE_ADIA, DE_ODIA,                                        DE_Y,    DE_Z,    DE_COMM, DE_DOT,  DE_K,    KC_RSFT,
        TT(5),    KC_GRV,  KC_EQL,  MO(5),   MO(3),                                                            MO(3),   MO(5),   KC_LBRC, KC_RBRC, TT(5),
                                                               KC_LCTL, KC_LALT,    KC_RGUI, KC_RCTL,
                                                                        KC_HOME,    KC_PGUP,
                                                      KC_BSPC, KC_DEL,  KC_END,     KC_PGDN, KC_ENT,  KC_SPC
    ),
    /* Shifted Layer for Mac */
    [3] = LAYOUT(
        KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                                          KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,
        KC_NO,    DE_DEG,  DE_UNDS, A(DE_5), A(DE_6), DE_CIRC,                                        DE_EXLM, DE_LABK, DE_RABK,  DE_EQL,  DE_AMPR, DE_EURO,
        KC_NO,    LSA(DE_7),DE_SLSH,A(DE_8), A(DE_9), DE_ASTR,                                        DE_QUES, DE_LPRN, DE_RPRN,  DE_MINS, DE_COLN, DE_AT,
        KC_NO,    DE_HASH, DE_DLR,  A(DE_7), A(DE_N), DE_GRV,                                         DE_PLUS, DE_PERC, DE_DQUO,  DE_QUOT, DE_SCLN, KC_NO,
        KC_NO,    KC_NO,   KC_NO,   KC_NO,   C(DE_X),                                                          C(DE_X), KC_NO,    KC_NO,   KC_NO,   KC_NO,
                                                               KC_LCTL, KC_LALT,    KC_RGUI, KC_RCTL,
                                                                        KC_HOME,    KC_PGUP,
                                                      C(DE_C), C(DE_V),  KC_END,     KC_PGDN, C(DE_V),  C(DE_C)
    ),
    /* Gaming */
    [4] = LAYOUT(
        KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_CAPS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                           KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        MO(5),    KC_GRV,  KC_EQL,  KC_LEFT, KC_RGHT,                                                          KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC, MO(5),
                                                               KC_LCTL, KC_LALT,    KC_RGUI, KC_RCTL,
                                                                        KC_HOME,    KC_PGUP,
                                                      KC_BSPC, KC_DEL,  KC_END,     KC_PGDN, KC_ENT,  KC_SPC
    ),
    /* Utility */
    [5] = LAYOUT(
        KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                                          KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,
        _______,  _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP,                                        TG(0),   KC_KP_7, KC_KP_8,  KC_KP_9, KC_KP_PLUS, KC_PAST,
        _______,  KC_LSFT, KC_LEFT, KC_DOWN, KC_RIGHT,KC_PGDN,                                        TG(2),   KC_KP_4, KC_KP_5,  KC_KP_6, KC_KP_MINUS,KC_PSLS,
        RESET,    _______, _______, _______, _______, _______,                                        TG(4),   KC_KP_1, KC_KP_2,  KC_KP_3, RGB_TOG, RESET,
        _______,  _______, KC_MUTE, KC_VOLD, KC_VOLU,                                                          KC_KP_0, RGB_VAD,  RGB_SAI, RGB_SAD, KC_TRNS,
                                                               _______, _______,    RGB_MOD, RGB_TOG,
                                                                        _______,    RGB_HUI,
                                                      KC_LGUI, KC_LCTL, _______,    RGB_HUD, KC_ENT,  KC_SPC
    )
};


layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t layer = biton32(state);
    switch (layer) {
        case 0: // Bone (Linux)
            rgblight_sethsv(HSV_GREEN);
            rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
            break;
        case 1: // Shifted Layer (Linux)
            rgblight_sethsv(HSV_CYAN);
            rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
            break;
        case 2: // Bone (Mac)
            rgblight_sethsv(HSV_RED);
            rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
            break;
        case 3: // Shifted (Mac)
            rgblight_sethsv(HSV_ORANGE);
            rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
            break;
        case 4: // Gaming
            rgblight_sethsv(HSV_BLUE);
            rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL + 5);
            break;
        case 5: // Utility
            rgblight_sethsv(HSV_WHITE);
            rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
            break;
    }

    return state;
};
