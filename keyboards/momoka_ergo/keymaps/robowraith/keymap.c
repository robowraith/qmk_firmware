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
extern rgblight_config_t rgblight_config;

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
    VOLU,
    VOLD,
    NEXT,
    PREV,
    DISM,
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
    [VOLU] = ACTION_TAP_DANCE_DOUBLE(KC_VOLU, KC_MUTE),
    [VOLD] = ACTION_TAP_DANCE_DOUBLE(KC_VOLD, KC_MUTE),
    [NEXT] = ACTION_TAP_DANCE_DOUBLE(KC_MNXT, KC_MPLY),
    [PREV] = ACTION_TAP_DANCE_DOUBLE(KC_MPRV, KC_MPLY),
    [DISM] = ACTION_TAP_DANCE_DOUBLE(G(C(DE_D)), LSG(C(DE_D))),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
         case RW_I:
            return TAPPING_TERM - 20;
         case RW_N:
            return TAPPING_TERM - 20;
        default:
            return TAPPING_TERM;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        TD(VOLD),   TD(VOLU),   KC_NO,      KC_NO,      KC_NO,      KC_PSCR,    /**/    TD(DISM),   KC_COPY,    KC_PASTE,   KC_CUT,     KC_NO,      KC_NO,
        TD(PREV),   TD(NEXT),   DE_L,       DE_U,       DE_A,       DE_Q,       /**/    DE_W,       DE_B,       DE_D,       DE_G,       KC_NO,      KC_NO,
        DE_J,       RW_C,       RW_R,       RW_I,       RW_E,       DE_O,       /**/    DE_M,       RW_N,       RW_T,       RW_S,       RW_H,       DE_Y,
        KC_NO,      DE_V,       DE_X,       DE_UDIA,    DE_ADIA,    DE_ODIA,    /**/    DE_P,       DE_F,       DE_Z,       DE_SS,      DE_K,       KC_NO,
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_ESC,                 /**/                KC_TAB,     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
                                                        XXXXXXX,    XXXXXXX,    /**/    XXXXXXX,    XXXXXXX,
                                                                    KC_NO,      /**/    XXXXXXX,
                                            KC_BSPC,    LTOSLL,     KC_NO,      /**/    XXXXXXX,    LTOSLR,     KC_SPC
    ),
    [_SYMBOLS] = LAYOUT(
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      /**/    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,      KC_NO,      DE_LBRC,    DE_LCBR,    DE_LPRN,    DE_LABK,    /**/    DE_RABK,    DE_RPRN,    DE_RCBR,    DE_RBRC,    KC_NO,      KC_NO,
        DE_EURO,    DE_QUOT,    DE_BSLS,    DE_COLN,    DE_COMM,    DE_QUES,    /**/    DE_EXLM,    DE_DOT,     DE_SCLN,    DE_SLSH,    DE_DQUO,    DE_AT,
        RESET,      DE_PERC,    DE_GRV,     DE_DLR,     DE_UNDS,    DE_HASH,    /**/    DE_ASTR,    DE_MINS,    DE_PIPE,    DE_TILD,    DE_AMPR,    RESET,
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_NO,                  /**/                KC_NO,      XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
                                                        XXXXXXX,    XXXXXXX,    /**/    XXXXXXX,    XXXXXXX,
                                                                    KC_NO,      /**/    XXXXXXX,
                                            DE_EQL,     KC_NO,      KC_NO,      /**/    XXXXXXX,    KC_NO,      DE_CIRC
    ),
    [_NUMBERS] = LAYOUT(
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      /**/    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,      RALT(DE_1), RALT(DE_2), RALT(DE_3), KC_MUTE,    KC_VOLU,    /**/    DE_MINS,    TD(F7_7),   TD(F8_8),   TD(F9_9),   KC_NO,      KC_NO,
        KC_NO,      KC_LGUI,    KC_LALT,    KC_LCTL,    KC_LSFT,    KC_VOLD,    /**/    DE_SLSH,    TD(F4_4),   TD(F5_5),   TD(F6_6),   TD(F11_DO), TD(F10_PL),
        KC_NO,      KC_NO,      KC_NO,      KC_MPRV,    KC_MNXT,    KC_MPLY,    /**/    DE_COLN,    TD(F1_1),   TD(F2_2),   TD(F3_3),   TD(F12_CO), KC_NO,
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_NO,                  /**/                DE_0,       XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
                                                        XXXXXXX,    XXXXXXX,    /**/    XXXXXXX,    XXXXXXX,
                                                                    KC_NO,      /**/    XXXXXXX,
                                            KC_NO,      KC_NO,      KC_NO,      /**/    XXXXXXX,    KC_NO,      KC_ENT
  ),
    [_NAVIGATION] = LAYOUT(
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      /**/    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,      KC_PASTE,   KC_HOME,    KC_UP,      KC_END,     KC_PGUP,    /**/    G(KC_1),    G(KC_2),    G(KC_3),    G(KC_4),    G(KC_5),    KC_NO,
        KC_NO,      KC_COPY,    KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_PGDN,    /**/    KC_NO,      KC_RSFT,    KC_RCTL,    KC_RALT,    KC_RGUI,    KC_NO,
        KC_NO,      KC_CUT,     KC_NO,      KC_NO,      KC_PSCR,    XXXXXXX,    /**/    G(KC_6),    G(KC_7),    G(KC_8),    G(KC_9),    G(KC_0),    KC_NO,
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_NO,                  /**/                KC_NO,      XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
                                                        XXXXXXX,    XXXXXXX,    /**/    XXXXXXX,    XXXXXXX,
                                                                    KC_NO,      /**/    XXXXXXX,
                                              KC_DEL,    KC_NO,     KC_NO,      /**/    XXXXXXX,    KC_NO,      KC_NO
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

void keyboard_post_init_user(void) {
    rgblight_mode(22);
    rgblight_sethsv(HSV_RED);
   };

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t layer = biton32(state);
    switch (layer) {
        case _BASE:
            rgblight_sethsv_noeeprom(HSV_BLUE);
            rgblight_mode_noeeprom(1);
            break;
        case _SYMBOLS:
            rgblight_sethsv_noeeprom(HSV_GREEN);
            rgblight_mode_noeeprom(1);
            break;
       case _NUMBERS:
            rgblight_sethsv_noeeprom(HSV_RED);
            rgblight_mode_noeeprom(1);
            break;
        case _NAVIGATION:
            rgblight_sethsv_noeeprom(HSV_YELLOW);
            rgblight_mode_noeeprom(1);
            break;
    }
    return state;
   };

void caps_word_set_user(bool active) {
    if (active) {
        rgblight_sethsv_noeeprom(HSV_WHITE);
        rgblight_mode_noeeprom(5);
    } else {
        rgblight_mode_noeeprom(1);
        rgblight_sethsv_noeeprom(HSV_BLUE);
    }
};
