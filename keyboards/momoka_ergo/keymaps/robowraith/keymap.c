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
#include "features/select_word.h"
extern rgblight_config_t rgblight_config;

enum layer_names {
    _AEIOU,
    _SYMBOLS,
    _SYMBOLS_2,
    _KEYPAD,
    _NAVIGATION,
    _GAMING,
};

// Home-Row-Mod-Keys for Bone
enum custom_keycodes {
    JK_U = LGUI_T(DE_U),
    JK_O = LALT_T(DE_O),
    JK_I = LCTL_T(DE_I),
    JK_E = LSFT_T(DE_E),
    JK_T = RSFT_T(DE_T),
    JK_R = RCTL_T(DE_R),
    JK_N = RALT_T(DE_N),
    JK_S = RGUI_T(DE_S),
    JK_ESC = LT(_SYMBOLS, KC_ESC),
    JK_BSPC = LT(_SYMBOLS, KC_BSPC),
    JK_DEL = LT(_SYMBOLS, KC_DEL),
    JK_TAB = LT(_SYMBOLS, KC_TAB),
    JK_ENT = LT(_NAVIGATION, KC_ENT),
    JK_SPC = LT(_SYMBOLS, KC_SPC),
    SELWRD = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_AEIOU] = LAYOUT(
        XXXXXXX,  XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,         /**/         XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,
        XXXXXXX,  DE_UDIA,    DE_ODIA,   DE_K,      DE_Y,      DE_ADIA,         /**/         DE_V,      DE_G,      DE_C,      DE_L,       DE_W,       XXXXXXX,
        XXXXXXX,  JK_U,       JK_O,      JK_I,      JK_E,      DE_A,            /**/         DE_D,      JK_T,      JK_R,      JK_N,       JK_S,       XXXXXXX,
        XXXXXXX,  DE_Z,       DE_Q,      DE_M,      DE_H,      DE_X,            /**/         DE_J,      DE_P,      DE_B,      DE_F,       DE_SS,      RESET,
        XXXXXXX,  XXXXXXX,    XXXXXXX,   XXXXXXX,   JK_ESC,                     /**/                    JK_TAB,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,
                                                               XXXXXXX, XXXXXXX,/**/XXXXXXX, XXXXXXX,
                                                                        XXXXXXX,/**/XXXXXXX,
                                                    JK_BSPC,   JK_DEL,  XXXXXXX,/**/XXXXXXX, JK_ENT,    JK_SPC
    ),
    [_SYMBOLS] = LAYOUT(
        XXXXXXX,  XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,         /**/         XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,
        XXXXXXX,  KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,           /**/         DE_LPRN,   DE_RPRN,   DE_MINS,   DE_UNDS,    DE_PLUS,    XXXXXXX,
        XXXXXXX,  KC_LGUI,    KC_LALT,   KC_LCTL,   KC_LSFT,   KC_NO,           /**/         DE_AT,     DE_DOT,    DE_COMM,   DE_EXLM,    DE_QUES,    XXXXXXX,
        XXXXXXX,  KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,           /**/         DE_COLN,   DE_SCLN,   DE_DQUO,   DE_QUOT,    DE_GRV,     RESET,
        XXXXXXX,  XXXXXXX,    XXXXXXX,   XXXXXXX,   KC_NO,                      /**/                    KC_NO,     XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,
                                                               XXXXXXX, XXXXXXX,/**/XXXXXXX, XXXXXXX,
                                                                        XXXXXXX,/**/XXXXXXX,
                                                    KC_NO,     KC_NO,   XXXXXXX,/**/XXXXXXX, KC_NO,    KC_NO
    ),
    [_SYMBOLS_2] = LAYOUT(
        XXXXXXX,  XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,         /**/         XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,
        XXXXXXX,  KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,           /**/         KC_NO,     KC_NO,     KC_NO,     KC_NO,      KC_NO,      XXXXXXX,
        XXXXXXX,  KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,           /**/         KC_NO,     KC_NO,     KC_NO,     KC_NO,      KC_NO,      XXXXXXX,
        XXXXXXX,  KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,           /**/         KC_NO,     KC_NO,     KC_NO,     KC_NO,      KC_NO,      RESET,
        XXXXXXX,  XXXXXXX,    XXXXXXX,   XXXXXXX,   KC_NO,                      /**/                    KC_NO,     XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,
                                                               XXXXXXX, XXXXXXX,/**/XXXXXXX, XXXXXXX,
                                                                        XXXXXXX,/**/XXXXXXX,
                                                    KC_NO,     KC_NO,   XXXXXXX,/**/XXXXXXX, KC_NO,    KC_NO
    ),
    [_KEYPAD] = LAYOUT(
        XXXXXXX,  XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,         /**/         XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,
        XXXXXXX,  KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,           /**/         KC_NO,     KC_NO,     KC_NO,     KC_NO,      KC_NO,      XXXXXXX,
        XXXXXXX,  KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,           /**/         KC_NO,     KC_NO,     KC_NO,     KC_NO,      KC_NO,      XXXXXXX,
        XXXXXXX,  KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,           /**/         KC_NO,     KC_NO,     KC_NO,     KC_NO,      KC_NO,      RESET,
        XXXXXXX,  XXXXXXX,    XXXXXXX,   XXXXXXX,   KC_NO,                      /**/                    KC_NO,     XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,
                                                               XXXXXXX, XXXXXXX,/**/XXXXXXX, XXXXXXX,
                                                                        XXXXXXX,/**/XXXXXXX,
                                                    KC_NO,     KC_NO,   XXXXXXX,/**/XXXXXXX, KC_NO,    KC_NO
    ),
    [_NAVIGATION] = LAYOUT(
        XXXXXXX,  XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,         /**/         XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,
        XXXXXXX,  KC_NO,      KC_CUT,    KC_PASTE,  KC_COPY,   KC_NO,           /**/         KC_NO,     KC_NO,     KC_NO,     KC_NO,      KC_NO,      XXXXXXX,
        XXXXXXX,  KC_LEFT,    KC_DOWN,   KC_UP,     KC_RIGHT,  CAPSWRD,         /**/         KC_NO,     KC_RSFT,   KC_RCTL,   KC_RALT,    KC_RGUI,     XXXXXXX,
        XXXXXXX,  KC_HOME,    KC_PGDN,   KC_PGUP,   KC_END,    KC_NO,           /**/         KC_NO,     KC_NO,     KC_NO,     KC_NO,      KC_NO,      RESET,
        XXXXXXX,  XXXXXXX,    XXXXXXX,   XXXXXXX,   KC_NO,                      /**/                    KC_NO,     XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,
                                                               XXXXXXX, XXXXXXX,/**/XXXXXXX, XXXXXXX,
                                                                        XXXXXXX,/**/XXXXXXX,
                                                    KC_NO,     KC_NO,   XXXXXXX,/**/XXXXXXX, KC_NO,    KC_NO
    ),
    [_GAMING] = LAYOUT(
        XXXXXXX,  XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,         /**/         XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,
        XXXXXXX,  KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,           /**/         KC_NO,     KC_NO,     KC_NO,     KC_NO,      KC_NO,      XXXXXXX,
        XXXXXXX,  KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,           /**/         KC_NO,     KC_NO,     KC_NO,     KC_NO,      KC_NO,      XXXXXXX,
        XXXXXXX,  KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,           /**/         KC_NO,     KC_NO,     KC_NO,     KC_NO,      KC_NO,      RESET,
        XXXXXXX,  XXXXXXX,    XXXXXXX,   XXXXXXX,   KC_NO,                      /**/                    KC_NO,     XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,
                                                               XXXXXXX, XXXXXXX,/**/XXXXXXX, XXXXXXX,
                                                                        XXXXXXX,/**/XXXXXXX,
                                                    KC_NO,     KC_NO,   XXXXXXX,/**/XXXXXXX, KC_NO,    KC_NO
    )
};
