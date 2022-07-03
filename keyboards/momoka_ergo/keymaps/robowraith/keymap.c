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
    _BASE,
    _SYMBOLS,
    _SYMBOLS_2,
    _KEYPAD,
    _NAVIGATION,
    _FUNCTIONS,
    _I3,
    _GAMING,
};

// Home-Row-Mod-Keys for Bone
enum custom_keycodes {
    RW_U = LGUI_T(DE_U),
    RW_A = LALT_T(DE_A),
    RW_I = LCTL_T(DE_I),
    RW_E = LSFT_T(DE_E),
    RW_T = RSFT_T(DE_T),
    RW_R = RCTL_T(DE_R),
    RW_N = RALT_T(DE_N),
    RW_S = RGUI_T(DE_S),
    RW_ESC  = LT(_KEYPAD, KC_ESC),
    RW_BSPC = LT(_SYMBOLS, KC_BSPC),
    RW_DEL  = LT(_FUNCTIONS, KC_DEL),
    RW_TAB  = LT(_NAVIGATION, KC_TAB),
    RW_ENT  = LT(_I3, KC_ENT),
    RW_SPC  = LT(_SYMBOLS_2, KC_SPC),
    SELWRD  = SAFE_RANGE
};

// define combo names
enum combos {
    COMBO_ä,
    COMBO_ü,
    COMBO_ö,
    COMBO_Ä,
    COMBO_Ü,
    COMBO_Ö,
    COMBO_ß,
    COMBO_LENGTH // nifty trick to avoid manually specifying how many combos you have
};

uint16_t COMBO_LEN = COMBO_LENGTH; // nifty trick continued

// define keys that make up combos
const uint16_t PROGMEM ae_combo[] = {RW_A, RW_E, COMBO_END};
const uint16_t PROGMEM ue_combo[] = {DE_U, RW_E, COMBO_END};
const uint16_t PROGMEM oe_combo[] = {DE_O, RW_E, COMBO_END};
const uint16_t PROGMEM AE_combo[] = {RW_A, RW_E, RW_T, COMBO_END};
const uint16_t PROGMEM UE_combo[] = {DE_U, RW_E, RW_T, COMBO_END};
const uint16_t PROGMEM OE_combo[] = {DE_O, RW_E, RW_T, COMBO_END};
const uint16_t PROGMEM sz_combo[] = {RW_S, DE_Z, COMBO_END};

// map combo names to their keys and the key they trigger
combo_t key_combos[] = {
    [COMBO_ä] = COMBO(ae_combo, DE_ADIA),
    [COMBO_ü] = COMBO(ue_combo, DE_UDIA),
    [COMBO_ö] = COMBO(oe_combo, DE_ODIA),
    [COMBO_Ä] = COMBO(AE_combo, S(DE_ADIA)),
    [COMBO_Ü] = COMBO(UE_combo, S(DE_UDIA)),
    [COMBO_Ö] = COMBO(OE_combo, S(DE_ODIA)),
    [COMBO_ß] = COMBO(sz_combo, DE_SS),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        XXXXXXX,  XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,         /**/         XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,
        XXXXXXX,  DE_K,       DE_DOT,    DE_O,      DE_COMM,   DE_Y,            /**/         DE_V,      DE_G,      DE_C,      DE_L,       DE_Z ,      XXXXXXX,
        XXXXXXX,  RW_U,       RW_A,      RW_I,      RW_E,      DE_H,            /**/         DE_D,      RW_T,      RW_R,      RW_N,       RW_S,       XXXXXXX,
        XXXXXXX,  DE_X,       KC_NO,     DE_W,      DE_Q,      DE_F,            /**/         DE_B,      DE_P,      DE_M,      KC_NO,      DE_J,       RESET,
        XXXXXXX,  XXXXXXX,    XXXXXXX,   XXXXXXX,   RW_ESC,                     /**/                    RW_TAB,    XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,
                                                               XXXXXXX, XXXXXXX,/**/XXXXXXX, XXXXXXX,
                                                                        XXXXXXX,/**/XXXXXXX,
                                                    RW_BSPC,   RW_DEL,  XXXXXXX,/**/XXXXXXX, RW_ENT,    RW_SPC
    ),
    [_SYMBOLS] = LAYOUT(
        XXXXXXX,  XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,         /**/         XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,
        XXXXXXX,  RESET,      KC_NO,     KC_NO,     KC_NO,     KC_NO,           /**/         DE_EXLM,   DE_LABK,   DE_RABK,   DE_EQL,     DE_AMPR,    XXXXXXX,
        XXXXXXX,  KC_LGUI,    KC_LALT,   KC_LCTL,   KC_LSFT,   KC_NO,           /**/         DE_QUES,   DE_LPRN,   DE_RPRN,   DE_MINS,    DE_COLN,    XXXXXXX,
        XXXXXXX,  KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,           /**/         DE_PLUS,   DE_PERC,   DE_DQUO,   DE_QUOT,    DE_SCLN,    RESET,
        XXXXXXX,  XXXXXXX,    XXXXXXX,   XXXXXXX,   KC_NO,                      /**/                    DE_AT,     XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,
                                                               XXXXXXX, XXXXXXX,/**/XXXXXXX, XXXXXXX,
                                                                        XXXXXXX,/**/XXXXXXX,
                                                    KC_NO,     KC_NO,   XXXXXXX,/**/XXXXXXX, DE_DOT,    DE_COMM
    ),
    [_SYMBOLS_2] = LAYOUT(
        XXXXXXX,  XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,         /**/         XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,
        XXXXXXX,  DE_DEG,     DE_UNDS,   DE_LBRC,   DE_RBRC,   DE_CIRC,         /**/         KC_NO,     KC_NO,     KC_NO,     KC_NO,      RESET,      XXXXXXX,
        XXXXXXX,  DE_BSLS,    DE_SLSH,   DE_LCBR,   DE_RCBR,   DE_ASTR,         /**/         KC_NO,     KC_RSFT,   KC_RCTL,   KC_RALT,    KC_RGUI,    XXXXXXX,
        XXXXXXX,  DE_HASH,    DE_DLR,    DE_PIPE,   DE_TILD,   DE_GRV,          /**/         KC_NO,     KC_NO,     KC_NO,     KC_NO,      KC_NO,      RESET,
        XXXXXXX,  XXXXXXX,    XXXXXXX,   XXXXXXX,   DE_EURO,                    /**/                    KC_NO,     XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,
                                                               XXXXXXX, XXXXXXX,/**/XXXXXXX, XXXXXXX,
                                                                        XXXXXXX,/**/XXXXXXX,
                                                    CAPSWRD,   SELWRD,  XXXXXXX,/**/XXXXXXX, KC_NO,    KC_NO
    ),
    [_KEYPAD] = LAYOUT(
        XXXXXXX,  XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,         /**/         XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,
        XXXXXXX,  RESET,      KC_NO,     KC_NO,     KC_NO,     KC_NO,           /**/         KC_NO,     DE_7,      DE_8,      DE_9,       KC_PLUS,    XXXXXXX,
        XXXXXXX,  KC_LGUI,    KC_LALT,   KC_LCTL,   KC_LSFT,   KC_NO,           /**/         KC_ASTR,   DE_4,      DE_5,      DE_6,       KC_MINS,    XXXXXXX,
        XXXXXXX,  KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,           /**/         KC_SLSH,   DE_1,      DE_2,      DE_3,       KC_EQL,     RESET,
        XXXXXXX,  XXXXXXX,    XXXXXXX,   XXXXXXX,   KC_NO,                      /**/                    KC_0,      XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,
                                                               XXXXXXX, XXXXXXX,/**/XXXXXXX, XXXXXXX,
                                                                        XXXXXXX,/**/XXXXXXX,
                                                    KC_NO,     KC_NO,   XXXXXXX,/**/XXXXXXX, KC_ENT,    KC_NO
    ),
    [_NAVIGATION] = LAYOUT(
        XXXXXXX,  XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,         /**/         XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,
        XXXXXXX,  KC_PSCR,    KC_UP,     KC_UP,     KC_END,    KC_PGUP,         /**/         KC_NO,     KC_NO,     KC_NO,     KC_NO,      RESET,      XXXXXXX,
        XXXXXXX,  KC_NO,      KC_LEFT,   KC_DOWN,   KC_RIGHT,  KC_PGDN,         /**/         KC_NO,     KC_RSFT,   KC_RCTL,   KC_RALT,    KC_RGUI,    XXXXXXX,
        XXXXXXX,  SELWRD,     KC_CUT,    KC_PASTE,  KC_COPY,   CAPSWRD,         /**/         KC_NO,     KC_NO,     KC_NO,     KC_NO,      KC_NO,      RESET,
        XXXXXXX,  XXXXXXX,    XXXXXXX,   XXXXXXX,   KC_NO,                      /**/                    KC_NO,     XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,
                                                               XXXXXXX, XXXXXXX,/**/XXXXXXX, XXXXXXX,
                                                                        XXXXXXX,/**/XXXXXXX,
                                                    KC_NO,     KC_NO,   XXXXXXX,/**/XXXXXXX, KC_NO,    KC_NO
    ),
    [_FUNCTIONS] = LAYOUT(
        XXXXXXX,  XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,         /**/         XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,
        XXXXXXX,  RESET,      KC_NO,     KC_NO,     KC_NO,     KC_NO,           /**/         KC_NO,     KC_F7,     KC_F8,     KC_F9,      KC_F11,     XXXXXXX,
        XXXXXXX,  KC_LGUI,    KC_LALT,   KC_LCTL,   KC_LSFT,   KC_NO,           /**/         KC_NO,     KC_F4,     KC_F5,     KC_F6,      KC_F12,     XXXXXXX,
        XXXXXXX,  KC_NO,      KC_NO,     KC_MPRV,   KC_MNXT,   KC_MPLY,         /**/         KC_NO,     KC_F1,     KC_F2,     KC_F3,      KC_NO,      RESET,
        XXXXXXX,  XXXXXXX,    XXXXXXX,   XXXXXXX,   KC_NO,                      /**/                    KC_F10,    XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,
                                                               XXXXXXX, XXXXXXX,/**/XXXXXXX, XXXXXXX,
                                                                        XXXXXXX,/**/XXXXXXX,
                                                    KC_NO,     KC_NO,   XXXXXXX,/**/XXXXXXX, KC_NO,    KC_NO
    ),
    [_I3] = LAYOUT(
        XXXXXXX,  XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,         /**/         XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,
        XXXXXXX,  G(KC_1),    G(KC_2),   G(KC_3),   G(KC_4),   G(KC_5),         /**/         KC_NO,     KC_NO,     KC_NO,     KC_NO,      RESET,      XXXXXXX,
        XXXXXXX,  G(KC_LEFT), G(KC_DOWN),G(KC_UP), G(KC_RIGHT),G(KC_X),         /**/         KC_NO,     KC_RSFT,   KC_RCTL,   KC_RALT,    KC_RGUI,    XXXXXXX,
        XXXXXXX,  G(KC_6),    G(KC_7),   G(KC_8),   G(KC_9),   G(KC_0),         /**/         KC_MUTE,   KC_VOLD,   KC_VOLU,   KC_NO,      KC_NO,      RESET,
        XXXXXXX,  XXXXXXX,    XXXXXXX,   XXXXXXX,   KC_NO,                      /**/                    KC_NO,     XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,
                                                               XXXXXXX, XXXXXXX,/**/XXXXXXX, XXXXXXX,
                                                                        XXXXXXX,/**/XXXXXXX,
                                                    KC_NO,     KC_NO,   XXXXXXX,/**/XXXXXXX, KC_NO,    KC_NO
    ),
    [_GAMING ] = LAYOUT(
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

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_select_word(keycode, record, SELWRD)) { return false; }
  return true;
}

void keyboard_post_init_user(void) {
    rgblight_mode(22);
    rgblight_sethsv(HSV_RED);
   };

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t layer = biton32(state);
    switch (layer) {
        case _BASE:
            rgblight_sethsv_noeeprom(HSV_WHITE);
            rgblight_mode_noeeprom(1);
            break;
        case _SYMBOLS:
            rgblight_sethsv_noeeprom(HSV_BLUE);
            rgblight_mode_noeeprom(1);
            break;
         case _SYMBOLS_2:
            rgblight_sethsv_noeeprom(HSV_BLUE);
            rgblight_mode_noeeprom(1);
            break;
       case _KEYPAD:
            rgblight_sethsv_noeeprom(HSV_GREEN);
            rgblight_mode_noeeprom(1);
            break;
        case _NAVIGATION:
            rgblight_sethsv_noeeprom(HSV_GREEN);
            rgblight_mode_noeeprom(1);
            break;
        case _FUNCTIONS:
            rgblight_sethsv_noeeprom(HSV_RED);
            rgblight_mode_noeeprom(1);
            break;
        case _I3:
            rgblight_sethsv_noeeprom(HSV_RED);
            rgblight_mode_noeeprom(1);
            break;
         case _GAMING:
            rgblight_sethsv_noeeprom(HSV_CYAN);
            rgblight_mode_noeeprom(14);
            break;
    }
    return state;
   };

void caps_word_set_user(bool active) {
    if (active) {
        rgblight_sethsv_noeeprom(HSV_RED);
        rgblight_mode_noeeprom(5);
    } else {
        rgblight_mode_noeeprom(1);
        rgblight_sethsv_noeeprom(HSV_WHITE);
    }
};

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case DE_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
};
