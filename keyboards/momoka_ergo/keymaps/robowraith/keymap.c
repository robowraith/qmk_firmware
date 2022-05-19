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
        rgblight_sethsv_noeeprom(HSV_RED);
        rgblight_mode_noeeprom(RGBLIGHT_MODE_KNIGHT + 2);
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
#define BO_SR LT(1, KC_BSPC)
#define BO_SL LT(2, KC_SPC)
#define BO_UR LT(3, KC_DEL)
#define BO_UL LT(4, KC_ENT)

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BO_SL:
            return TAPPING_TERM + 50;
        case BO_SR:
            return TAPPING_TERM + 50;
        case BO_UL:
            return TAPPING_TERM + 50;
        case BO_UR:
            return TAPPING_TERM + 50;
        default:
            return TAPPING_TERM;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Bone for Linux */
    [0] = LAYOUT(
        KC_NO,    DE_1,       DE_2,      DE_3,      DE_4,      DE_5,            /**/         DE_6,      DE_7,      DE_8,      DE_9,       DE_0,      KC_NO,
        KC_CUT,   DE_J,       DE_D,      DE_U,      DE_A,      DE_X,            /**/         DE_P,      DE_H,      DE_L,      DE_M,       DE_W,      DE_SS,
        KC_COPY,  BO_C,       BO_T,      BO_I,      BO_E,      DE_O,            /**/         DE_B,      BO_N,      BO_R,      BO_S,       BO_G,      DE_Q,
        KC_PASTE, DE_F,       DE_V,      DE_UDIA,   DE_ADIA,   DE_ODIA,         /**/         DE_Y,      DE_Z,      DE_COMM,   DE_DOT,     DE_K,      KC_NO,
        KC_CAPS,  KC_BRID,    KC_BRIU,   MO(4),     MO(2),                      /**/                    MO(1),     MO(3),     KC_VOLD,    KC_VOLU,   KC_MUTE,
                                                               KC_NO,   KC_PSCR,/**/KC_RGUI, KC_NO,
                                                                        KC_NO,  /**/KC_APP,
                                                    BO_SR,      BO_UR,  KC_ESC, /**/KC_TAB,  BO_UL,     BO_SL
    ),
    /* Shifted right layer for Linux */
    [1] = LAYOUT(
        KC_NO,    DE_1,       DE_2,      DE_3,      DE_4,      DE_5,            /**/         KC_F7,     KC_F8,     KC_F9,     KC_F10,     KC_F11,     KC_F12,
        KC_CUT,   DE_J,       DE_D,      DE_U,      DE_A,      DE_X,            /**/         DE_EXLM,   DE_LABK,   DE_RABK,   DE_EQL,     DE_AMPR,    DE_EURO,
        KC_COPY,  BO_C,       BO_T,      BO_I,      BO_E,      DE_O,            /**/         DE_QUES,   DE_LPRN,   DE_RPRN,   DE_MINS,    DE_COLN,    DE_AT,
        KC_PASTE, DE_F,       DE_V,      DE_UDIA,   DE_ADIA,   DE_ODIA,         /**/         DE_PLUS,   DE_PERC,   DE_DQUO,   DE_QUOT,    DE_SCLN,    KC_NO,
        KC_CAPS,  KC_BRID,    KC_BRIU,   MO(4),     MO(2),                      /**/                    KC_NO,     KC_NO,     KC_MPRV,    KC_MNXT,    KC_MPLY,
                                                               KC_NO,   KC_PSCR,/**/KC_RGUI, KC_NO,
                                                                        KC_NO,  /**/KC_NO,
                                                    KC_BSPC,   KC_DEL,  KC_ESC, /**/KC_TAB,  KC_ENT,    KC_SPC
    ),
     /* Shifted left layer for Linux */
    [2] = LAYOUT(
        KC_F1,    KC_F2,      KC_F3,     KC_F4,     KC_F5,     KC_F6,           /**/         DE_6,      DE_7,      DE_8,      DE_9,       DE_0,      KC_NO,
        KC_NO,    DE_DEG,     DE_UNDS,   DE_LBRC,   DE_RBRC,   DE_CIRC,         /**/         DE_P,      DE_H,      DE_L,      DE_M,       DE_W,      DE_SS,
        KC_NO,    DE_BSLS,    DE_SLSH,   DE_LCBR,   DE_RCBR,   DE_ASTR,         /**/         DE_B,      BO_N,      BO_R,      BO_S,       BO_G,      DE_Q,
        KC_NO,    DE_HASH,    DE_DLR,    DE_PIPE,   DE_TILD,   DE_GRV,          /**/         DE_Y,      DE_Z,      DE_COMM,   DE_DOT,     DE_K,      KC_NO,
        KC_NO,    KC_NO,      KC_NO,     KC_NO,     KC_NO,                      /**/                    MO(1),     MO(3),     KC_VOLD,    KC_VOLU,   KC_MUTE,
                                                               KC_NO,   KC_NO,  /**/KC_RGUI, KC_NO,
                                                                        KC_NO,  /**/KC_APP,
                                                    KC_BSPC,   KC_DEL,  KC_ESC, /**/KC_TAB,  KC_ENT,    KC_SPC
    ),
   /* Utility right */
    [3] = LAYOUT(
        KC_NO,    KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,           /**/         LCA(KC_F7),LCA(KC_F8),LCA(KC_F9),LCA(KC_F10),LCA(KC_F11),KC_MPLY,
        KC_NO,    KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,           /**/         KC_NO,     KC_KP_7,   KC_KP_8,   KC_KP_9,    KC_KP_PLUS, KC_MNXT,
        KC_NO,    KC_LGUI,    KC_LALT,   KC_LCTL,   KC_LSFT,   KC_NO,           /**/         KC_NO,     KC_KP_4,   KC_KP_5,   KC_KP_6,    KC_KP_MINUS,KC_MPRV,
        RESET,    KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,           /**/         KC_NO,     KC_KP_1,   KC_KP_2,   KC_KP_3,    KC_NO,      RESET,
        TO(0),    KC_NO,      KC_NO,     KC_NO,     KC_NO,                      /**/                    KC_KP_0,   KC_NO,     KC_NO,      KC_NO,      TO(0),
                                                               KC_NO,   KC_NO,  /**/KC_NO,   KC_NO,
                                                                        KC_NO,  /**/KC_NO,
                                                    KC_BSPC,   KC_DEL,  KC_NO,  /**/KC_NO,   KC_ENT,    KC_SPC
    ),
    /* Utility left */
    [4] = LAYOUT(
        LCA(KC_F1),LCA(KC_F2),LCA(KC_F3),LCA(KC_F4),LCA(KC_F5),LCA(KC_F6),      /**/         KC_NO,     KC_NO,     KC_NO,     KC_NO,      KC_NO,      KC_MUTE,
        KC_NO,     KC_NO,     KC_HOME,   KC_UP,     KC_END,    KC_PGUP,         /**/         KC_NO,     KC_NO,     KC_NO,     KC_NO,      KC_NO,      KC_VOLU,
        KC_NO,     KC_NO,     KC_LEFT,   KC_DOWN,   KC_RIGHT,  KC_PGDN,         /**/         KC_NO,     KC_RSFT,   KC_RCTL,   KC_RALT,    KC_RGUI,    KC_VOLD,
        RESET,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,           /**/         KC_TAB,    KC_NO,     KC_NO,     KC_NO,      KC_NO,      RESET,
        TO(0),     KC_NO,     KC_NO,     KC_NO,     KC_NO,                      /**/                    KC_NO,     KC_NO,     KC_NO,      KC_NO,      TO(0),
                                                               KC_NO,   DT_PRNT,/**/KC_NO,   RGB_TOG,
                                                                        DT_UP,  /**/KC_NO,
                                                    KC_BSPC,   KC_DEL,  DT_DOWN,/**/KC_NO,   KC_ENT,    KC_SPC
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t layer = biton32(state);
    switch (layer) {
        case 0: // Bone (Linux)
            rgblight_sethsv_noeeprom(HSV_BLUE);
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            break;
        case 1: // Shifted Layer (Linux)
            rgblight_sethsv_noeeprom(HSV_CYAN);
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            break;
        case 2: // Shifted Layer (Linux)
            rgblight_sethsv_noeeprom(HSV_CYAN);
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            break;
        case 3: // Utility
            rgblight_sethsv_noeeprom(HSV_WHITE);
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            break;
        case 4: // Utility
            rgblight_sethsv_noeeprom(HSV_WHITE);
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            break;
    }

    return state;

   };

bool led_update_user(led_t led_state) {
    if (led_state.caps_lock) {  //if caps lock is on
        rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3);
    } else {
        rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    }
    return true;
}
