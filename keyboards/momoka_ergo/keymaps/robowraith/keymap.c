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

// Home-Row-Mod-Keys for QWERTZ and Bone
#define QZ_A LGUI_T(DE_A)
#define QZ_S LALT_T(DE_S)
#define QZ_D LCTL_T(DE_D)
#define QZ_F LSFT_T(DE_F)
#define QZ_J RSFT_T(DE_J)
#define QZ_K RCTL_T(DE_K)
#define QZ_L RALT_T(DE_L)
#define QZ_OE RGUI_T(DE_ODIA)
#define BO_C LGUI_T(DE_C)
#define BO_T LALT_T(DE_T)
#define BO_I LCTL_T(DE_I)
#define BO_E LSFT_T(DE_E)
#define BO_N RSFT_T(DE_N)
#define BO_R RCTL_T(DE_R)
#define BO_S RALT_T(DE_S)
#define BO_G RGUI_T(DE_G)

// Modifier-keys for QWERTZ and Bone
#define QZ_MO3L LT(_SLL, DE_G)
#define QZ_MO3R LT(_SLL, DE_H)
#define QZ_MO5L LT(_UTIL, DE_V)
#define QZ_MO5R LT(_UTIL, DE_M)
#define BO_MO3L LT(_SLL, DE_O)
#define BO_MO3R LT(_SLL, DE_B)
#define BO_MO4L LT(_SLM, DE_O)
#define BO_MO4R LT(_SLM, DE_B)
#define BO_MO5L LT(_UTIL, DE_ADIA)
#define BO_MO5R LT(_UTIL, DE_Z)

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BONEL,
    _SLL,
    _SLM,
    _UTIL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BONEL] = LAYOUT(
        KC_ESC,   DE_1,    DE_2,    DE_3,    DE_4,    DE_5,                                           DE_6,    DE_7,    DE_8,    DE_9,    DE_0,    KC_BSPC,
        KC_TAB,   DE_J,    DE_D,    DE_U,    DE_A,    DE_X,                                           DE_P,    DE_H,    DE_L,    DE_M,    DE_W,    DE_SS,
        KC_CAPS,  BO_C,    BO_T,    BO_I,    BO_E,    BO_MO3L,                                        BO_MO3R, BO_N,    BO_R,    BO_S,    BO_G,    DE_Q,
        KC_LSFT,  DE_F,    DE_V,    DE_UDIA, BO_MO5L, DE_ODIA,                                        DE_Y,    BO_MO5R, DE_COMM, DE_DOT,  DE_K,    KC_RSFT,
        TT(_UTIL),KC_GRV,  KC_EQL,  KC_LEFT, KC_RGHT,                                                          KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC, TT(_UTIL),
                                                               KC_LCTL, KC_LALT,    KC_RGUI, KC_RCTL,
                                                                        KC_HOME,    KC_PGUP,
                                                      KC_BSPC, KC_DEL,  KC_END,     KC_PGDN, KC_ENT,  KC_SPC
    ),
    [_SLL] = LAYOUT(
        KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                                          KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,
        KC_NO,    DE_DEG,  DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC,                                        DE_EXLM, DE_LABK, DE_RABK,  DE_EQL,  DE_AMPR, DE_EURO,
        KC_NO,    DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR,                                        DE_QUES, DE_LPRN, DE_RPRN,  DE_MINS, DE_COLN, DE_AT,
        KC_NO,    DE_HASH, DE_DLR,  DE_PIPE, DE_TILD, DE_GRV,                                         DE_PLUS, DE_PERC, DE_DQUO,  DE_QUOT, DE_SCLN, KC_NO,
        KC_NO,    KC_NO,   KC_NO,   KC_NO,   C(DE_X),                                                          C(DE_X), KC_NO,    KC_NO,   KC_NO,   KC_NO,
                                                               KC_LCTL, KC_LALT,    KC_RGUI, KC_RCTL,
                                                                        KC_HOME,    KC_PGUP,
                                                      C(DE_C), C(DE_V),  KC_END,     KC_PGDN, C(DE_V),  C(DE_C)

    ),
    [_UTIL] = LAYOUT(
        KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                                          KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,
        _______,  _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP,                                        _______, KC_KP_7, KC_KP_8,  KC_KP_9, KC_KP_PLUS, KC_PAST,
        _______,  KC_LSFT, KC_LEFT, KC_DOWN, KC_RIGHT,KC_PGDN,                                        _______, KC_KP_4, KC_KP_5,  KC_KP_6, KC_KP_MINUS,KC_PSLS,
        RESET,    _______, _______, _______, _______, _______,                                        _______, KC_KP_1, KC_KP_2,  KC_KP_3, RGB_TOG, RESET,
        _______,  _______, KC_MUTE, KC_VOLD, KC_VOLU,                                                          RGB_VAI, RGB_VAD,  RGB_SAI, RGB_SAD, KC_TRNS,
                                                               _______, _______,    RGB_MOD, RGB_TOG,
                                                                        _______,    RGB_HUI,
                                                      _______, _______, _______,    RGB_HUD, _______, KC_KP_0
    )
};
