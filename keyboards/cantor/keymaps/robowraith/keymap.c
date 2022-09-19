// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H
#include "keymap_german.h"

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
    RW_S = RALT_T(DE_S),
    RW_H = RGUI_T(DE_H),
    // Other
    SELWRD  = SAFE_RANGE,
    LTOSLR,
    LTOSLL
};

enum tap_dance_keys{
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
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
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
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        default:
            return TAPPING_TERM;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
        XXXXXXX,  DE_J,       DE_L,      DE_U,      DE_A,      DE_Q,    /**/ DE_W,      DE_B,      DE_D,      DE_G,       DE_Y,       XXXXXXX,
        XXXXXXX,  RW_C,       RW_R,      RW_I,      RW_E,      DE_O,    /**/ DE_M,      RW_N,      RW_T,      RW_S,       RW_H,       XXXXXXX,
        XXXXXXX,  DE_V,       DE_X,      DE_UDIA,   DE_ADIA,   DE_ODIA, /**/ DE_P,      DE_F,      DE_Z,      DE_SS,      DE_K,       XXXXXXX,
                                         KC_ESC,    KC_BSPC,   LTOSLL,  /**/ LTOSLR,    KC_SPC,    KC_TAB
    ),
    [_SYMBOLS] = LAYOUT_split_3x6_3(
        XXXXXXX,  DE_EURO,    DE_LBRC,   DE_LCBR,   DE_LPRN,   DE_LABK, /**/ DE_RABK,   DE_RPRN,   DE_RCBR,   DE_RBRC,    DE_AT,      XXXXXXX,
        XXXXXXX,  DE_QUOT,    DE_BSLS,   DE_COLN,   DE_COMM,   DE_QUES, /**/ DE_EXLM,   DE_DOT,    DE_SCLN,   DE_SLSH,    DE_DQUO,    XXXXXXX,
        XXXXXXX,  DE_PERC,    DE_GRV,    DE_DLR,    DE_UNDS,   DE_HASH, /**/ DE_ASTR,   DE_MINS,   DE_PIPE,   DE_TILD,    DE_AMPR,    XXXXXXX,
                                         KC_NO,     DE_EQL,    KC_ESC,  /**/ KC_NO,     DE_CIRC,   KC_NO

    ),
    [_NUMBERS] = LAYOUT_split_3x6_3(
        XXXXXXX,  RESET,      KC_NO,     KC_NO,     KC_MUTE,   KC_VOLU, /**/ DE_MINS,   TD(F7_7),  TD(F8_8),  TD(F9_9),   TD(F10_PL), XXXXXXX,
        XXXXXXX,  KC_LGUI,    KC_LALT,   KC_LCTL,   KC_LSFT,   KC_VOLD, /**/ DE_SLSH,   TD(F4_4),  TD(F5_5),  TD(F6_6),   TD(F11_DO), XXXXXXX,
        XXXXXXX,  KC_NO,      KC_NO,     KC_MPRV,   KC_MNXT,   KC_MPLY, /**/ DE_COLN,   TD(F1_1),  TD(F2_2),  TD(F3_3),   TD(F12_CO), XXXXXXX,
                                         KC_NO,     KC_DEL,    KC_NO,   /**/ KC_NO,     KC_ENT,    DE_0
    ),
    [_NAVIGATION] = LAYOUT_split_3x6_3(
        XXXXXXX,  KC_PASTE,   KC_HOME,   KC_UP,     KC_END,    KC_PGUP, /**/ G(KC_1),   G(KC_2),   G(KC_3),   G(KC_4),    G(KC_5),    XXXXXXX,
        XXXXXXX,  KC_COPY,    KC_LEFT,   KC_DOWN,   KC_RIGHT,  KC_PGDN, /**/ KC_NO,     KC_RSFT,   KC_RCTL,   KC_RALT,    KC_RGUI,    XXXXXXX,
        XXXXXXX,  KC_CUT,     KC_NO,     KC_NO,     KC_PSCR,   KC_TAB,  /**/ G(KC_6),   G(KC_7),   G(KC_8),   G(KC_9),    G(KC_0),    XXXXXXX,
                                         KC_NO,     KC_NO,     KC_NO,   /**/ KC_NO,     KC_NO,      KC_NO
    )
};

static uint8_t ltoslr_state = 0;
static uint8_t ltosll_state = 0;
#define LTOSLR_MO_LAYER  _NAVIGATION // Layer to activate when holding.
#define LTOSLR_OSL_LAYER _SYMBOLS    // Layer to activate as an OSL when tapped.
#define LTOSLL_MO_LAYER  _NUMBERS    // Layer to activate when holding.
#define LTOSLL_OSL_LAYER _SYMBOLS    // Layer to activate as an OSL when tapped.
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (keycode == LTOSLR) {
    static uint32_t tap_deadline = 0;
    if (record->event.pressed) {  // On pressed.
      tap_deadline = timer_read32() + 200;  // Set 200 ms tap deadline.
      layer_on(LTOSLR_MO_LAYER);
      ltoslr_state = 1;  // Set undetermined state.
    } else {  // On release.
      layer_off(LTOSLR_MO_LAYER);
      if (ltoslr_state && !timer_expired32(timer_read32(), tap_deadline)) {
        // LTOSLR was released without pressing another key within 200 ms.
        layer_on(LTOSLR_OSL_LAYER);
        ltoslr_state = 2;  // Acting like OSL.
      }
    }
    return false;
  }
  if (keycode == LTOSLL) {
    static uint32_t tap_deadline = 0;
    if (record->event.pressed) {  // On pressed.
      tap_deadline = timer_read32() + 200;  // Set 200 ms tap deadline.
      layer_on(LTOSLL_MO_LAYER);
      ltosll_state = 1;  // Set undetermined state.
    } else {  // On release.
      layer_off(LTOSLL_MO_LAYER);
      if (ltosll_state && !timer_expired32(timer_read32(), tap_deadline)) {
        // LTOSLL was released without pressing another key within 200 ms.
        layer_on(LTOSLL_OSL_LAYER);
        ltosll_state = 2;  // Acting like OSL.
      }
    }
  return false;
  }
return true;
};

void post_process_record_user(uint16_t keycode, keyrecord_t* record) {
  // Turn off the layer if another key is pressed while acting like OSL. The
  // `(ltosl_state >>= 1)` both tests that state = 2 and shifts it toward zero.
  if (keycode != LTOSLR && (ltoslr_state >>= 1)) {
    layer_off(LTOSLR_OSL_LAYER);
  }
  if (keycode != LTOSLL && (ltosll_state >>= 1)) {
    layer_off(LTOSLL_OSL_LAYER);
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
