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

enum custom_keycodes {
    SELWRD = SAFE_RANGE,
    LTOSL
};

// define combo names
enum combos {
    // left hand
    COMBO_LSFT,
    COMBO_LCTL,
    COMBO_LGUI,
    COMBO_LALT,
    COMBO_LSG,
    COMBO_LSC,
    COMBO_LCG,
    // right hand
    COMBO_RSFT,
    COMBO_RCTL,
    COMBO_RGUI,
    COMBO_RALT,
    COMBO_RSG,
    COMBO_RSC,
    COMBO_RCG,
    COMBO_LENGTH // nifty trick to avoid manually specifying how many combos you have
};

uint16_t COMBO_LEN = COMBO_LENGTH; // nifty trick continued

// define keys that make up combos
// left hand
const uint16_t PROGMEM oe_combo[] = {DE_O, DE_E, COMBO_END};
const uint16_t PROGMEM ei_combo[] = {DE_E, DE_I, COMBO_END};
const uint16_t PROGMEM et_combo[] = {DE_E, DE_T, COMBO_END};
const uint16_t PROGMEM tc_combo[] = {DE_T, DE_C, COMBO_END};
const uint16_t PROGMEM ec_combo[] = {DE_E, DE_C, COMBO_END};
const uint16_t PROGMEM oi_combo[] = {DE_O, DE_I, COMBO_END};
const uint16_t PROGMEM ic_combo[] = {DE_I, DE_C, COMBO_END};
// right hand
const uint16_t PROGMEM bn_combo[] = {DE_B, DE_N, COMBO_END};
const uint16_t PROGMEM nr_combo[] = {DE_N, DE_R, COMBO_END};
const uint16_t PROGMEM ns_combo[] = {DE_N, DE_S, COMBO_END};
const uint16_t PROGMEM sg_combo[] = {DE_S, DE_G, COMBO_END};
const uint16_t PROGMEM ng_combo[] = {DE_N, DE_G, COMBO_END};
const uint16_t PROGMEM br_combo[] = {DE_B, DE_R, COMBO_END};
const uint16_t PROGMEM rg_combo[] = {DE_R, DE_G, COMBO_END};

// map combo names to their keys and the key they trigger
combo_t key_combos[] = {
    // left hand
    [COMBO_LSFT] = COMBO(oe_combo, KC_LSFT),
    [COMBO_LCTL] = COMBO(et_combo, KC_LCTL),
    [COMBO_LGUI] = COMBO(ei_combo, KC_LGUI),
    [COMBO_LALT] = COMBO(tc_combo, KC_LALT),
    [COMBO_LSG] = COMBO(ec_combo, LSFT(KC_LGUI)),
    [COMBO_LSC] = COMBO(oi_combo, LSFT(KC_LCTL)),
    [COMBO_LCG] = COMBO(ic_combo, LCTL(KC_LGUI)),
    // right hand
    [COMBO_RSFT] = COMBO(bn_combo, KC_RSFT),
    [COMBO_RCTL] = COMBO(ns_combo, KC_RCTL),
    [COMBO_RGUI] = COMBO(nr_combo, KC_RGUI),
    [COMBO_RALT] = COMBO(sg_combo, KC_RALT),
    [COMBO_RSG] = COMBO(ng_combo, RSFT(KC_RGUI)),
    [COMBO_RSC] = COMBO(br_combo, RSFT(KC_RCTL)),
    [COMBO_RCG] = COMBO(rg_combo, RCTL(KC_RGUI)),
};

#define LTOSL_MO_LAYER 2
#define LTOSL_OSL_LAYER 1

enum layer_names {
    _BONE,
    _SHIFTED,
    _UTILITY,
    _GAMING,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BONE] = LAYOUT(
        KC_CUT,   DE_1,       DE_2,      DE_3,      DE_4,      DE_5,            /**/         DE_6,      DE_7,      DE_8,      DE_9,       DE_0,      TO(3),
        KC_COPY,  DE_J,       DE_D,      DE_U,      DE_A,      DE_X,            /**/         DE_P,      DE_H,      DE_L,      DE_M,       DE_W,      DE_SS,
        KC_PASTE, DE_C,       DE_T,      DE_I,      DE_E,      DE_O,            /**/         DE_B,      DE_N,      DE_R,      DE_S,       DE_G,      DE_Q,
        KC_NO,    DE_F,       DE_V,      DE_UDIA,   DE_ADIA,   DE_ODIA,         /**/         DE_Y,      DE_Z,      DE_COMM,   DE_DOT,     DE_K,      RESET,
        SELWRD,   KC_BRID,    KC_BRIU,   KC_NO,     LTOSL,                      /**/                    LTOSL,     KC_NO,     KC_VOLD,    KC_VOLU,   KC_MUTE,
                                                               KC_NO,   KC_PSCR,/**/KC_RGUI, KC_NO,
                                                                        KC_NO,  /**/KC_APP,
                                                    KC_BSPC,   KC_DEL,  KC_ESC, /**/KC_TAB,  KC_ENT,    KC_SPC
    ),
    [_SHIFTED] = LAYOUT(
        KC_F1,    KC_F2,      KC_F3,     KC_F4,     KC_F5,     KC_F6,           /**/         KC_F7,     KC_F8,     KC_F9,     KC_F10,     KC_F11,     KC_F12,
        KC_NO,    DE_DEG,     DE_UNDS,   DE_LBRC,   DE_RBRC,   DE_CIRC,         /**/         DE_EXLM,   DE_LABK,   DE_RABK,   DE_EQL,     DE_AMPR,    DE_EURO,
        KC_NO,    DE_BSLS,    DE_SLSH,   DE_LCBR,   DE_RCBR,   DE_ASTR,         /**/         DE_QUES,   DE_LPRN,   DE_RPRN,   DE_MINS,    DE_COLN,    DE_AT,
        KC_NO,    DE_HASH,    DE_DLR,    DE_PIPE,   DE_TILD,   DE_GRV,          /**/         DE_PLUS,   DE_PERC,   DE_DQUO,   DE_QUOT,    DE_SCLN,    KC_NO,
        KC_NO,    KC_BRID,    KC_BRIU,   KC_NO,     KC_NO,                      /**/                    KC_NO,     KC_NO,     KC_NO,      KC_NO,      KC_NO,
                                                               KC_LCTL, KC_LALT,/**/KC_RGUI, KC_RCTL,
                                                                        KC_HOME,/**/KC_PGUP,
                                                    KC_BSPC,   KC_DEL,  KC_ESC, /**/KC_TAB,  KC_ENT,    KC_SPC
    ),
    [_UTILITY] = LAYOUT(
        KC_NO,    KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,           /**/         KC_NO,     KC_NO,     KC_NO,     KC_NO,      KC_NO,      KC_NO,
        KC_NO,    KC_NO,      KC_HOME,   KC_UP,     KC_END,    KC_PGUP,         /**/         KC_NUM,    KC_KP_7,   KC_KP_8,   KC_KP_9,    KC_KP_PLUS, KC_NO,
        KC_NO,    KC_NO,      KC_LEFT,   KC_DOWN,   KC_RIGHT,  KC_PGDN,         /**/         KC_NO,     KC_KP_4,   KC_KP_5,   KC_KP_6,    KC_KP_MINUS,KC_NO,
        RESET,    KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,           /**/         KC_NO,     KC_KP_1,   KC_KP_2,   KC_KP_3,    KC_NO,      RESET,
        TO(0),    KC_NO,      KC_NO,     KC_NO,     KC_NO,                      /**/                    KC_SPC,    KC_NO,     KC_MPRV,    KC_MNXT,    KC_MPLY,
                                                               KC_NO,   KC_NO,  /**/KC_NO,   KC_NO,
                                                                        TO(0),  /**/KC_NO,
                                                    KC_SPC,    KC_ENT,  KC_NO,  /**/KC_NO,   KC_ENT,    KC_KP_0
    ),
    [_GAMING] = LAYOUT(
        KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_6,            /**/         KC_F1,     KC_F2,     KC_F3,     KC_F4,      KC_F5,      KC_F6,
        KC_TAB,    KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,            /**/         KC_Y,      KC_KP_7,   KC_KP_8,   KC_KP_9,KC_KP_ASTERISK, KC_F7,
        KC_CAPS,   KC_A,      KC_S,      KC_D,      KC_F,      KC_G,            /**/         KC_H,      KC_KP_4,   KC_KP_5,   KC_KP_6,    KC_KP_SLASH,KC_F8,
        KC_LSFT,   KC_C,      KC_V,      KC_B,      KC_N,      KC_Z,            /**/         KC_X,      KC_KP_1,   KC_KP_2,   KC_KP_3,    KC_KP_MINUS,KC_F9,
        KC_LCTL,   KC_I,      KC_O,      KC_P,      KC_J,                       /**/                    KC_U,      KC_P,      KC_F12,     KC_F11,     KC_F10,
                                                               KC_L,    KC_M,   /**/RGB_MOD, RGB_TOG,
                                                                        TO(0),  /**/KC_VOLU,
                                                    KC_SPC,    KC_ENT,  KC_ESC, /**/KC_VOLD, KC_MUTE,   KC_KP_0
    )
};

static uint8_t ltosl_state = 0;

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (keycode == LTOSL) {
    static uint32_t tap_deadline = 0;
    if (record->event.pressed) {  // On pressed.
      tap_deadline = timer_read32() + 200;  // Set 200 ms tap deadline.
      layer_on(LTOSL_MO_LAYER);
      ltosl_state = 1;  // Set undetermined state.
    } else {  // On release.
      layer_off(LTOSL_MO_LAYER);
      if (ltosl_state && !timer_expired32(timer_read32(), tap_deadline)) {
        // LTOSL was released without pressing another key within 200 ms.
        layer_on(LTOSL_OSL_LAYER);
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
  if (keycode != LTOSL && (ltosl_state >>= 1)) {
    layer_off(LTOSL_OSL_LAYER);
  }
}

void keyboard_post_init_user(void) {
    rgblight_mode(RGBLIGHT_MODE_KNIGHT + 2);
    rgblight_sethsv(HSV_RED);
   };

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t layer = biton32(state);
    switch (layer) {
        case _BONE:
            rgblight_sethsv_noeeprom(HSV_WHITE);
            rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
            break;
        case _SHIFTED:
            rgblight_sethsv_noeeprom(HSV_BLUE);
            rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
            break;
        case _UTILITY:
            rgblight_sethsv_noeeprom(HSV_GREEN);
            rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
            break;
         case _GAMING:
            rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL + 5);
            break;
    }
    return state;
   };
