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

// Home-Row-Mod-Keys for Bone
enum custom_keycodes {
    BO_C = LGUI_T(DE_C),
    BO_T = LALT_T(DE_T),
    BO_I = LCTL_T(DE_I),
    BO_E = LSFT_T(DE_E),
    BO_N = RSFT_T(DE_N),
    BO_R = RCTL_T(DE_R),
    BO_S = RALT_T(DE_S),
    BO_G = RGUI_T(DE_G),
    SELWRD = SAFE_RANGE,
    LTOSLR,
    LTOSLL
};

enum layer_names {
    _BONE,
    _SHIFTED,
    _UTILITY_RIGHT,
    _UTILITY_LEFT,
    _GAMING,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BONE] = LAYOUT(
        KC_CUT,   DE_1,       DE_2,      DE_3,      DE_4,      DE_5,            /**/         DE_6,      DE_7,      DE_8,      DE_9,       DE_0,      TO(3),
        KC_COPY,  DE_J,       DE_D,      DE_U,      DE_A,      DE_X,            /**/         DE_P,      DE_H,      DE_L,      DE_M,       DE_W,      DE_SS,
        KC_PASTE, BO_C,       BO_T,      BO_I,      BO_E,      DE_O,            /**/         DE_B,      BO_N,      BO_R,      BO_S,       BO_G,      DE_Q,
        CAPSWRD,  DE_F,       DE_V,      DE_UDIA,   DE_ADIA,   DE_ODIA,         /**/         DE_Y,      DE_Z,      DE_COMM,   DE_DOT,     DE_K,      KC_NO,
        SELWRD,   KC_BRID,    KC_BRIU,   MO(3),     LTOSLR,                     /**/                    LTOSLL,    MO(2),     KC_VOLD,    KC_VOLU,   KC_MUTE,
                                                               KC_NO,   KC_PSCR,/**/KC_RGUI, KC_NO,
                                                                        KC_NO,  /**/KC_APP,
                                                    KC_BSPC,   KC_DEL,  KC_ESC, /**/KC_TAB,  KC_ENT,    KC_SPC
    ),
    [_SHIFTED] = LAYOUT(
        KC_F1,    KC_F2,      KC_F3,     KC_F4,     KC_F5,     KC_F6,           /**/         KC_F7,     KC_F8,     KC_F9,     KC_F10,     KC_F11,     KC_F12,
        KC_NO,    DE_DEG,     DE_UNDS,   DE_LBRC,   DE_RBRC,   DE_CIRC,         /**/         DE_EXLM,   DE_LABK,   DE_RABK,   DE_EQL,     DE_AMPR,    DE_EURO,
        KC_NO,    DE_BSLS,    DE_SLSH,   DE_LCBR,   DE_RCBR,   DE_ASTR,         /**/         DE_QUES,   DE_LPRN,   DE_RPRN,   DE_MINS,    DE_COLN,    DE_AT,
        KC_NO,    DE_HASH,    DE_DLR,    DE_PIPE,   DE_TILD,   DE_GRV,          /**/         DE_PLUS,   DE_PERC,   DE_DQUO,   DE_QUOT,    DE_SCLN,    KC_NO,
        KC_NO,    KC_NO,      KC_NO,     KC_NO,     KC_NO,                      /**/                    KC_NO,     KC_NO,     KC_NO,      KC_NO,      KC_NO,
                                                               KC_LCTL, KC_LALT,/**/KC_RGUI, KC_RCTL,
                                                                        KC_HOME,/**/KC_PGUP,
                                                    KC_BSPC,   KC_DEL,  KC_ESC, /**/KC_TAB,  KC_ENT,    KC_SPC
    ),
    [_UTILITY_RIGHT] = LAYOUT(
        KC_NO,    KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,           /**/         LGUI(KC_6),LGUI(KC_7),LGUI(KC_8),LGUI(KC_9), LGUI(KC_0), KC_NO,
        KC_NO,    KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,           /**/         KC_NUM,    KC_KP_7,   KC_KP_8,   KC_KP_9,    KC_PPLS,    KC_PAST,
        KC_NO,    KC_LGUI,    KC_LALT,   KC_LCTL,   KC_LSFT,   KC_NO,           /**/         KC_NO,     KC_KP_4,   KC_KP_5,   KC_KP_6,    KC_PMNS,    KC_PSLS,
        KC_NO,    KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,           /**/         KC_NO,     KC_KP_1,   KC_KP_2,   KC_KP_3,    KC_NO,      RESET,
        TO(0),    KC_NO,      KC_NO,     KC_NO,     KC_NO,                      /**/                    KC_SPC,    KC_NO,     KC_MPRV,    KC_MNXT,    KC_MPLY,
                                                               KC_NO,   KC_NO,  /**/KC_NO,   KC_NO,
                                                                        KC_NO,  /**/KC_NO,
                                                    KC_NO,     KC_NO,   KC_NO,  /**/KC_NO,   KC_ENT,    KC_KP_0
    ),
    [_UTILITY_LEFT] = LAYOUT(
        KC_NO,    LGUI(KC_1), LGUI(KC_2),LGUI(KC_3),LGUI(KC_4),LGUI(KC_5),      /**/         KC_NO,     KC_NO,     KC_NO,     KC_NO,      KC_NO,      KC_NO,
        KC_NO,    KC_NO,      KC_HOME,   KC_UP,     KC_END,    KC_PGUP,         /**/         KC_NO,     KC_NO,     KC_NO,     KC_NO,      KC_NO,      KC_NO,
        KC_CAPS,  KC_NO,      KC_LEFT,   KC_DOWN,   KC_RIGHT,  KC_PGDN,         /**/         KC_NO,     KC_RSFT,   KC_RCTL,   KC_RALT,    KC_RGUI,    KC_NO,
        RESET,    KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,           /**/         KC_NO,     KC_NO,     KC_NO,     KC_NO,      KC_NO,      KC_NO,
        TO(0),    KC_NO,      KC_NO,     KC_NO,     KC_NO,                      /**/                    KC_NO,     KC_NO,     KC_NO,      KC_NO,      KC_NO,
                                                               KC_NO,   KC_NO,  /**/KC_NO,   KC_NO,
                                                                        KC_NO,  /**/KC_NO,
                                                    KC_BSPC,   KC_DEL,  KC_NO,  /**/KC_NO,   KC_NO,     KC_NO
    ),
    [_GAMING] = LAYOUT(
        KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_6,            /**/         KC_F1,     KC_F2,     KC_F3,     KC_F4,      KC_F5,      KC_F6,
        KC_TAB,    KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,            /**/         KC_Y,      KC_KP_7,   KC_KP_8,   KC_KP_9,    KC_PAST,    KC_F7,
        KC_CAPS,   KC_A,      KC_S,      KC_D,      KC_F,      KC_G,            /**/         KC_H,      KC_KP_4,   KC_KP_5,   KC_KP_6,    KC_PSLS,    KC_F8,
        KC_LSFT,   KC_C,      KC_V,      KC_B,      KC_N,      KC_Z,            /**/         KC_X,      KC_KP_1,   KC_KP_2,   KC_KP_3,    KC_PMNS,    KC_F9,
        KC_LCTL,   KC_I,      KC_O,      KC_P,      KC_J,                       /**/                    KC_U,      KC_P,      KC_F12,     KC_F11,     KC_F10,
                                                               KC_L,    KC_M,   /**/RGB_MOD, RGB_TOG,
                                                                        TO(0),  /**/KC_VOLU,
                                                    KC_SPC,    KC_ENT,  KC_ESC, /**/KC_VOLD, KC_MUTE,   KC_KP_0
    )
};

static uint8_t ltosl_state = 0;
#define LTOSLR_MO_LAYER 2   // Layer to activate when holding.
#define LTOSLR_OSL_LAYER 1  // Layer to activate as an OSL when tapped.
#define LTOSLL_MO_LAYER 3   // Layer to activate when holding.
#define LTOSLL_OSL_LAYER 1  // Layer to activate as an OSL when tapped.
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (keycode == LTOSLR) {
    static uint32_t tap_deadline = 0;
    if (record->event.pressed) {  // On pressed.
      tap_deadline = timer_read32() + 200;  // Set 200 ms tap deadline.
      layer_on(LTOSLR_MO_LAYER);
      ltosl_state = 1;  // Set undetermined state.
    } else {  // On release.
      layer_off(LTOSLR_MO_LAYER);
      if (ltosl_state && !timer_expired32(timer_read32(), tap_deadline)) {
        // LTOSLR was released without pressing another key within 200 ms.
        layer_on(LTOSLR_OSL_LAYER);
        ltosl_state = 2;  // Acting like OSL.
      }
    }
    return false;
  }
  if (keycode == LTOSLL) {
    static uint32_t tap_deadline = 0;
    if (record->event.pressed) {  // On pressed.
      tap_deadline = timer_read32() + 200;  // Set 200 ms tap deadline.
      layer_on(LTOSLL_MO_LAYER);
      ltosl_state = 1;  // Set undetermined state.
    } else {  // On release.
      layer_off(LTOSLL_MO_LAYER);
      if (ltosl_state && !timer_expired32(timer_read32(), tap_deadline)) {
        // LTOSLL was released without pressing another key within 200 ms.
        layer_on(LTOSLL_OSL_LAYER);
        ltosl_state = 2;  // Acting like OSL.
      }
    }
  return false;
  }

  if (!process_select_word(keycode, record, SELWRD)) { return false; }

  return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t* record) {
  // Turn off the layer if another key is pressed while acting like OSL. The
  // `(ltosl_state >>= 1)` both tests that state = 2 and shifts it toward zero.
  if (keycode != LTOSLR && (ltosl_state >>= 1)) {
    layer_off(LTOSLR_OSL_LAYER);
  }
  if (keycode != LTOSLL && (ltosl_state >>= 1)) {
    layer_off(LTOSLL_OSL_LAYER);
  }
}

void keyboard_post_init_user(void) {
    rgblight_mode(22);
    rgblight_sethsv(HSV_RED);
   };

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t layer = biton32(state);
    switch (layer) {
        case _BONE:
            rgblight_sethsv_noeeprom(HSV_WHITE);
            rgblight_mode_noeeprom(1);
            break;
        case _SHIFTED:
            rgblight_sethsv_noeeprom(HSV_BLUE);
            rgblight_mode_noeeprom(1);
            break;
        case _UTILITY_RIGHT:
            rgblight_sethsv_noeeprom(HSV_GREEN);
            rgblight_mode_noeeprom(1);
            break;
        case _UTILITY_LEFT:
            rgblight_sethsv_noeeprom(HSV_GREEN);
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
