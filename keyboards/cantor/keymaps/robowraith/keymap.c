// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "features/select_word.h"

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

// Home-Row-Mod- and Thumb-Keys
enum custom_keycodes {
    // Mod Taps on eft hand
    RW_C = LGUI_T(DE_C),
    RW_R = LALT_T(DE_R),
    RW_I = LCTL_T(DE_I),
    RW_E = LSFT_T(DE_E),
    RW_ESC  = LT(_KEYPAD, KC_ESC),
    RW_BSPC = LT(_SYMBOLS, KC_BSPC),
    RW_DEL  = LT(_FUNCTIONS, KC_DEL),
    // Mod taps on right hand
    RW_N = RSFT_T(DE_N),
    RW_T = RCTL_T(DE_T),
    RW_S = RALT_T(DE_S),
    RW_H = RGUI_T(DE_H),
    RW_TAB  = LT(_NAVIGATION, KC_TAB),
    RW_ENT  = LT(_I3, KC_ENT),
    RW_SPC  = LT(_SYMBOLS_2, KC_SPC),
    // Other
    SELWRD  = SAFE_RANGE
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RW_ESC:
            return TAPPING_TERM + 50;
        case RW_BSPC:
            return TAPPING_TERM + 50;
        case RW_DEL:
            return TAPPING_TERM + 50;
        case RW_TAB:
            return TAPPING_TERM + 50;
        case RW_ENT:
            return TAPPING_TERM + 50;
        case RW_SPC:
            return TAPPING_TERM + 50;
        default:
            return TAPPING_TERM;
    }
}
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE]= LAYOUT_split_3x6_3(
        XXXXXXX,  DE_J,       DE_L,      DE_U,      DE_A,      DE_Q,            /**/         DE_W,      DE_B,      DE_D,      DE_G,       DE_Y,       XXXXXXX,
        XXXXXXX,  RW_C,       RW_R,      RW_I,      RW_E,      DE_O,            /**/         DE_M,      RW_N,      RW_T,      RW_S,       RW_H,       XXXXXXX,
        XXXXXXX,  DE_V,       DE_X,      DE_UDIA,   DE_ADIA,   DE_ODIA,         /**/         DE_P,      DE_F,      DE_Z,      DE_SS,      DE_K,       XXXXXXX,
                                         RW_ESC,    RW_BSPC,   RW_DEL,          /**/         RW_ENT,    RW_SPC,    RW_TAB
    ),
    [_SYMBOLS] = LAYOUT(
        XXXXXXX,  RESET,      KC_NO,     KC_NO,     KC_NO,     KC_NO,           /**/         DE_EXLM,   DE_LABK,   DE_RABK,   DE_EQL,     DE_AMPR,    XXXXXXX,
        XXXXXXX,  KC_LGUI,    KC_LALT,   KC_LCTL,   KC_LSFT,   KC_NO,           /**/         DE_QUES,   DE_LPRN,   DE_RPRN,   DE_MINS,    DE_COLN,    XXXXXXX,
        XXXXXXX,  KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,           /**/         DE_PLUS,   DE_PERC,   DE_DQUO,   DE_QUOT,    DE_SCLN,    RESET,
                                         KC_NO,     KC_NO,     KC_NO,           /**/         DE_DOT,    DE_COMM,   DE_AT
    ),
    [_SYMBOLS_2] = LAYOUT(
        XXXXXXX,  DE_DEG,     DE_UNDS,   DE_LBRC,   DE_RBRC,   DE_CIRC,         /**/         KC_NO,     KC_NO,     KC_NO,     KC_NO,      RESET,      XXXXXXX,
        XXXXXXX,  DE_BSLS,    DE_SLSH,   DE_LCBR,   DE_RCBR,   DE_ASTR,         /**/         KC_NO,     KC_RSFT,   KC_RCTL,   KC_RALT,    KC_RGUI,    XXXXXXX,
        XXXXXXX,  DE_HASH,    DE_DLR,    DE_PIPE,   DE_TILD,   DE_GRV,          /**/         KC_NO,     KC_NO,     KC_NO,     KC_NO,      KC_NO,      RESET,
                                         DE_EURO,   CAPSWRD,   SELWRD,          /**/         KC_NO,    KC_NO,      KC_NO
    ),
    [_KEYPAD] = LAYOUT(
        XXXXXXX,  RESET,      KC_NO,     KC_NO,     KC_NO,     KC_NO,           /**/         KC_NO,     DE_7,      DE_8,      DE_9,       DE_PLUS,    XXXXXXX,
        XXXXXXX,  KC_LGUI,    KC_LALT,   KC_LCTL,   KC_LSFT,   KC_NO,           /**/         DE_COLN,   DE_4,      DE_5,      DE_6,       DE_MINS,    XXXXXXX,
        XXXXXXX,  KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,           /**/         DE_COMM,   DE_1,      DE_2,      DE_3,       DE_DOT,     RESET,
                                         KC_NO,     KC_NO,     KC_NO,           /**/         KC_ENT,    KC_NO,     KC_0
    ),
    [_NAVIGATION] = LAYOUT(
        XXXXXXX,  KC_PSCR,    KC_CUT,    KC_COPY,   KC_PASTE,  KC_NO,           /**/         KC_NO,     KC_NO,     KC_NO,     KC_NO,      RESET,      XXXXXXX,
        XXXXXXX,  KC_LEFT,    KC_DOWN,   KC_UP,     KC_RIGHT,  KC_NO,           /**/         KC_NO,     KC_RSFT,   KC_RCTL,   KC_RALT,    KC_RGUI,    XXXXXXX,
        XXXXXXX,  KC_HOME,    KC_PGDN,   KC_PGUP,   KC_END,    KC_NO,           /**/         KC_NO,     KC_LEFT,   KC_DOWN,   KC_UP,      KC_RIGHT,   RESET,
                                         KC_NO,     KC_NO,     KC_NO,           /**/         KC_NO,    KC_NO,      KC_NO
    ),
    [_FUNCTIONS] = LAYOUT(
        XXXXXXX,  RESET,      KC_NO,     KC_NO,     KC_NO,     KC_NO,           /**/         KC_NO,     KC_F7,     KC_F8,     KC_F9,      KC_F11,     XXXXXXX,
        XXXXXXX,  KC_LGUI,    KC_LALT,   KC_LCTL,   KC_LSFT,   KC_NO,           /**/         KC_NO,     KC_F4,     KC_F5,     KC_F6,      KC_F12,     XXXXXXX,
        XXXXXXX,  KC_NO,      KC_NO,     KC_MPRV,   KC_MNXT,   KC_MPLY,         /**/         KC_NO,     KC_F1,     KC_F2,     KC_F3,      KC_NO,      RESET,
                                         KC_NO,     KC_NO,     KC_NO,           /**/         KC_NO,    KC_NO,      KC_F10
    ),
    [_I3] = LAYOUT(
        XXXXXXX,  G(KC_1),    G(KC_2),   G(KC_3),   G(KC_4),   G(KC_5),         /**/         KC_NO,     KC_NO,     KC_NO,     KC_NO,      RESET,      XXXXXXX,
        XXXXXXX,  G(KC_LEFT), G(KC_DOWN),G(KC_UP), G(KC_RIGHT),G(KC_X),         /**/         KC_NO,     KC_RSFT,   KC_RCTL,   KC_RALT,    KC_RGUI,    XXXXXXX,
        XXXXXXX,  G(KC_6),    G(KC_7),   G(KC_8),   G(KC_9),   G(KC_0),         /**/         KC_MUTE,   KC_VOLD,   KC_VOLU,   KC_NO,      KC_NO,      RESET,
                                         KC_NO,     KC_NO,     KC_NO,           /**/         KC_NO,    KC_NO,      KC_NO
    ),
    [_GAMING ] = LAYOUT(
        XXXXXXX,  KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,           /**/         KC_NO,     KC_NO,     KC_NO,     KC_NO,      KC_NO,      XXXXXXX,
        XXXXXXX,  KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,           /**/         KC_NO,     KC_NO,     KC_NO,     KC_NO,      KC_NO,      XXXXXXX,
        XXXXXXX,  KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,           /**/         KC_NO,     KC_NO,     KC_NO,     KC_NO,      KC_NO,      RESET,
                                         KC_NO,     KC_NO,     KC_NO,           /**/         KC_NO,     KC_NO,     KC_NO
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_select_word(keycode, record, SELWRD)) { return false; }
  return true;
}

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