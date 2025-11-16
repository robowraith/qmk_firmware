/* Copyright 2020 Shulin Huang <mumu@x-bows.com>
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
#include "color.h"
#include "keycode.h"
#include "keycodes.h"
#include "quantum_keycodes.h"
#include "usb_device_state.h"
#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "features/achordion.h"

enum layer_names {
    _BASE,
    _SYMBOLS,
    _NUMBERS,
    _NAVIGATION,
};

// Home-Row-Mod- and Thumb-Keys
enum custom_keycodes {
    // Mod Taps on eft hand
    RW_C = LGUI_T(DE_C),
    RW_R = LALT_T(DE_R),
    RW_I = LCTL_T(DE_I),
    RW_E = LSFT_T(DE_E),
    // Mod taps on right hand
    RW_N = RSFT_T(DE_N),
    RW_T = RCTL_T(DE_T),
    RW_S = LALT_T(DE_S),
    RW_H = RGUI_T(DE_H),
    // Home Row Super Mods
    RW_O = HYPR_T(DE_O),
    RW_M = HYPR_T(DE_M),
    // Other
    LCON  = LSG(DE_L),
    LCOFF = LGUI(LCTL(DE_L)),
    SSS = LGUI(LCTL(DE_S)),
    LTOSLR,
    LTOSLL,
};

enum tap_dance_keys {
    F1_1,
    F2_2,
    F3_3,
    F4_4,
    F5_5,
    F6_6,
    F7_7,
    F8_8,
    F9_9,
    F10_PL,
    F11_DO,
    F12_CO,
    DISM,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [F1_1] = ACTION_TAP_DANCE_DOUBLE(DE_1, KC_F1),
    [F2_2] = ACTION_TAP_DANCE_DOUBLE(DE_2, KC_F2),
    [F3_3] = ACTION_TAP_DANCE_DOUBLE(DE_3, KC_F3),
    [F4_4] = ACTION_TAP_DANCE_DOUBLE(DE_4, KC_F4),
    [F5_5] = ACTION_TAP_DANCE_DOUBLE(DE_5, KC_F5),
    [F6_6] = ACTION_TAP_DANCE_DOUBLE(DE_6, KC_F6),
    [F7_7] = ACTION_TAP_DANCE_DOUBLE(DE_7, KC_F7),
    [F8_8] = ACTION_TAP_DANCE_DOUBLE(DE_8, KC_F8),
    [F9_9] = ACTION_TAP_DANCE_DOUBLE(DE_9, KC_F9),
    [F10_PL] = ACTION_TAP_DANCE_DOUBLE(DE_PLUS, KC_F10),
    [F11_DO] = ACTION_TAP_DANCE_DOUBLE(DE_DOT, KC_F11),
    [F12_CO] = ACTION_TAP_DANCE_DOUBLE(DE_COMM, KC_F12),
    [DISM] = ACTION_TAP_DANCE_DOUBLE(G(C(DE_D)), LSG(C(DE_D))),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        default:
            return TAPPING_TERM;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 /*                      BASE LAYOUT
 * ┌───┬───┬───┬───┬───┐            ┌───┬───┬───┬───┬───┐
 * │ J │ L │ U │ A │ Q │            │ W │ B │ D │ G │ Y │
 * ├───┼───┼───┼───┼───┤            ├───┼───┼───┼───┼───┤
 * │ C │ R │ I │ E │ O │            │ M │ N │ T │ S │ H │
 * ├───┼───┼───┼───┼───┤            ├───┼───┼───┼───┼───┤
 * │ V │ X │ Ü │ Ä │ Ö │            │ P │ F │ Z │ ß │ K │
 * └───┴───┴───┴───┴───┘            └───┴───┴───┴───┴───┘
 *           ┌───┐                        ┌───┐
 *           │ESC├───┐                ┌───┤Tab│
 *           └───┤Bsp├──────┐  ┌──────┤Spa├───┘
 *               └───┤LTOSLL│  │LTOSLR├───┘
 *                   └──────┘  └──────┘
 */
[_BASE] = LAYOUT_split_3x5_3(
      DE_J,     DE_L,     DE_U,     DE_A,     DE_Q,                       DE_W,     DE_B,     DE_D,      DE_G,      DE_Y,
      RW_C,     RW_R,     RW_I,     RW_E,     RW_O,                       RW_M,     RW_N,     RW_T,      RW_S,      RW_H,
      DE_V,     DE_X,     DE_UDIA,  DE_ADIA,  DE_ODIA,                    DE_P,     DE_F,     DE_Z,      DE_SS,     DE_K,
                                    KC_ESC,   KC_BSPC,  LTOSLL, LTOSLR,   KC_SPC,   KC_TAB),

[_SYMBOLS] = LAYOUT_split_3x5_3(
      DE_EURO,  DE_LBRC,  DE_LCBR,  DE_LPRN,  DE_LABK,                    DE_RABK,  DE_RPRN,  DE_RCBR,   DE_RBRC,   DE_AT,
      DE_QUOT,  DE_BSLS,  DE_COLN,  DE_COMM,  DE_QUES,                    DE_EXLM,  DE_DOT,   DE_SCLN,   DE_SLSH,   DE_DQUO,
      DE_PERC,  DE_GRV,   DE_DLR,   DE_UNDS,  DE_HASH,                    DE_ASTR,  DE_MINS,  DE_PIPE,   DE_TILD,   DE_AMPR,
                                    KC_NO,    DE_EQL,   KC_NO,  KC_NO,    DE_CIRC,  KC_NO),

[_NUMBERS] = LAYOUT_split_3x5_3(
      RALT(DE_1),RALT(DE_2),RALT(DE_3),KC_MUTE,KC_VOLU,                   DE_MINS,  TD(F7_7), TD(F8_8),  TD(F9_9),  TD(F10_PL),
      KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  KC_VOLD,                    DE_SLSH,  TD(F4_4), TD(F5_5),  TD(F6_6),  TD(F11_DO),
      LCOFF,    LCON,     KC_MPRV,  KC_MNXT,  KC_MPLY,                    DE_COLN,  TD(F1_1), TD(F2_2),  TD(F3_3),  TD(F12_CO),
                                    QK_BOOT,  SSS,      KC_NO,   DE_EQL,  KC_ENTER, DE_0),

[_NAVIGATION] = LAYOUT_split_3x5_3(
      TD(DISM), KC_HOME,  KC_UP,    KC_END,   KC_PGUP,                    KC_NO,    KC_COPY,  KC_PASTE,  KC_CUT,    KC_NO,
      KC_COPY,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_PGDN,                    KC_HYPR,  KC_LSFT,  KC_LCTL,   KC_LALT,   KC_LGUI,
      KC_PASTE, KC_CUT,   KC_NO,    KC_NO,    KC_PSCR,                    KC_NO,    KC_NO,    KC_NO,     KC_RALT,   KC_NO,
                                    KC_NO,    KC_DEL,   KC_NO,   KC_NO,   KC_ENT,   QK_BOOT),
};

void matrix_scan_user(void) {
    achordion_task();
}

static uint8_t ltosl_state = 0;
#define LTOSLR_MO_LAYER _NAVIGATION // Layer to activate when holding.
#define LTOSLL_MO_LAYER _NUMBERS    // Layer to activate when holding.
#define LTOSL_OSL_LAYER _SYMBOLS    // Layer to activate as an OSL when tapped.
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_achordion(keycode, record)) {
        return false;
    }

    if (keycode == LTOSLR) {
        static uint32_t tap_deadline = 0;
        if (record->event.pressed) {             // On pressed.
            tap_deadline = timer_read32() + 200; // Set 200 ms tap deadline.
            layer_on(LTOSLR_MO_LAYER);
            ltosl_state = 1; // Set undetermined state.
        } else {             // On release.
            layer_off(LTOSLR_MO_LAYER);
            if (ltosl_state && !timer_expired32(timer_read32(), tap_deadline)) {
                // LTOSLR was released without pressing another key within 200 ms.
                layer_on(LTOSL_OSL_LAYER);
                ltosl_state = 2; // Acting like OSL.
            }
        }
        return false;
    }
    if (keycode == LTOSLL) {
        static uint32_t tap_deadline = 0;
        if (record->event.pressed) {             // On pressed.
            tap_deadline = timer_read32() + 200; // Set 200 ms tap deadline.
            layer_on(LTOSLL_MO_LAYER);
            ltosl_state = 1; // Set undetermined state.
        } else {             // On release.
            layer_off(LTOSLL_MO_LAYER);
            if (ltosl_state && !timer_expired32(timer_read32(), tap_deadline)) {
                // LTOSLL was released without pressing another key within 200 ms.
                layer_on(LTOSL_OSL_LAYER);
                ltosl_state = 2; // Acting like OSL.
            }
        }
        return false;
    }
    return true;
};

void post_process_record_user(uint16_t keycode, keyrecord_t* record) {
    // Turn off the layer if another key is pressed while acting like OSL. The
    // `(ltosl_state >>= 1)` both tests that state = 2 and shifts it toward zero.
    if (keycode != LTOSLR && (ltosl_state >>= 1)) {
        layer_off(LTOSL_OSL_LAYER);
    }
    if (keycode != LTOSLL && (ltosl_state >>= 1)) {
        layer_off(LTOSL_OSL_LAYER);
    }
};

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case DE_ADIA:
        case DE_ODIA:
        case DE_UDIA:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case DE_UNDS:
            return true;

        default:
            return false; // Deactivate Caps Word.
    }
};
