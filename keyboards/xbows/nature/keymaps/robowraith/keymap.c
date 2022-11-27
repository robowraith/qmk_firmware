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
#include "action_layer.h"
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
    // Mod Taps on left hand on _BASE layer
    RW_C = LGUI_T(DE_C),
    RW_R = LALT_T(DE_R),
    RW_I = LCTL_T(DE_I),
    RW_E = LSFT_T(DE_E),
    // Mod Taps on eft hand on _SYMBOLS layer
    RW_QUOT = LGUI_T(DE_QUOT),
    RW_BSLS = LALT_T(DE_BSLS),
    RW_COLN = LCTL_T(DE_COLN),
    RW_COMM = LSFT_T(DE_COMM),
    // Mod taps on right hand on _BASE layer
    RW_N = RSFT_T(DE_N),
    RW_T = RCTL_T(DE_T),
    RW_S = RALT_T(DE_S),
    RW_H = RGUI_T(DE_H),
    // Mod taps on right hand on _SYMBOLS layer
    RW_DOT = RSFT_T(DE_DOT),
    RW_SCLN = RCTL_T(DE_SCLN),
    RW_SLSH = RALT_T(DE_SLSH),
    RW_DQUO = RGUI_T(DE_DQUO),
    // Other
    LTOSLR,
    LTOSLL,
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
    PREV,
    NEXT,
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
        default:
            return TAPPING_TERM;
    }
}



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap VANILLA: (Base Layer) Default Layer
   *
   * |---------------------------------------------------------------------------------------------------------------------------------|
   * | Esc |  F1  |  F2  |  F3  |  F4  |      F5  |  F6  |  F7  |  F8  |      F9  |  F10 |  F11 |  F12 |   Delete   |    Prtsc    |
   * |---------------------------------------------------------------------------------------------------------------------------------|
   * |  ~  |     1   |   2   |   3   |   4   |    5      |       6    |    7    |    8   |   9  |   0  |   -  |  =  |  Backspace  |
   * |---------------------------------------------------------------------------------------------------------------------------------|
   * | Tab |   Q    |    W   |   E  |   R  |   T  |            |    Y   |    U   |    I  |   O  |   P  |   [  |  ]  |   \  | PgUp |
   * |---------------------------------------------------------------------------------------------------------------------------------|
   * | Ctl |   A   |   S   |   D  |   F  |   G  |      Bksp      |    H  |    J   |   K  |   L  |   ;  |  '"  |    Enter   | PgDn |
   * |---------------------------------------------------------------------------------------------------------------------------------|
   * |Shift|   Z  |   X  |   C  |   V  |   B  |       Enter       |    N  |    M   |  ,  |   .  |  /?  | Shift|      |  Up |
   * |---------------------------------------------------------------------------------------------------------------------------------|
   * |Ctrl | GUI |     Alter   |    Space   |   Ctrl   |   Shift   |     Space     |    Alter   |  FN  | Ctrl | Lft  |  Dn |  Rig |
   * |---------------------------------------------------------------------------------------------------------------------------------|
   */
  [_BASE] = LAYOUT(
      XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX,
      TD(VOLD),  TD(VOLU), KC_NO,    KC_NO,    KC_NO,    KC_PSCR,             TD(DISM), KC_COPY,  KC_PASTE,  KC_CUT,    KC_NO,     KC_NO,     XXXXXXX,  XXXXXXX,
      TD(PREV),  TD(NEXT), DE_L,     DE_U,     DE_A,     DE_Q,                DE_W,     DE_B,     DE_D,      DE_G,      KC_NO,     KC_NO,     XXXXXXX,  XXXXXXX,  XXXXXXX,
      KC_J,      RW_C,     RW_R,     RW_I,     RW_E,     DE_O,      KC_ESC,   DE_M,     RW_N,     RW_T,      RW_S,      RW_H,      DE_Y,      KC_ENTER,           KC_BSPC,
      KC_NO,     DE_V,     DE_X,     DE_UDIA,  DE_ADIA,  DE_ODIA,   KC_TAB,   DE_P,     DE_F,     DE_Z,      DE_SS,     DE_K,      KC_NO,               KC_UP,
      XXXXXXX,   XXXXXXX,  KC_ESC,   KC_BSPC,            LTOSLL,              LTOSLR,             KC_SPC,    KC_TAB,    KC_NO,     XXXXXXX,   KC_LEFT,  KC_DOWN,  KC_RGHT),
  [_SYMBOLS] = LAYOUT(
      XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX,
      KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,               KC_NO,    KC_NO,    KC_NO,     KC_NO,     KC_NO,     KC_NO,     XXXXXXX,  XXXXXXX,
      KC_NO,     KC_NO,    DE_LBRC,  DE_LCBR,  DE_LPRN,  DE_LABK,             DE_RABK,  DE_RPRN,  DE_RCBR,   DE_RBRC,   KC_NO,     KC_NO,     XXXXXXX,  XXXXXXX,  XXXXXXX,
      DE_EURO,   RW_QUOT,  RW_BSLS,  RW_COLN,  RW_COMM,  DE_QUES,   KC_NO,    DE_EXLM,  RW_DOT,   RW_SCLN,   RW_SLSH,   RW_DQUO,   KC_NO,     XXXXXXX,            XXXXXXX,
      RESET,     DE_PERC,  DE_GRV,   DE_DLR,   DE_UNDS,  DE_HASH,   KC_NO,    DE_ASTR,  DE_MINS,  DE_PIPE,   DE_TILD,   DE_AMPR,   RESET,               XXXXXXX,
      XXXXXXX,   XXXXXXX,  KC_NO,    DE_EQL,             TG(_SYMBOLS),        TG(_SYMBOLS),       DE_CIRC,   KC_NO,     XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX),
 [_NUMBERS] = LAYOUT(
      XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX,
      KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,               KC_NO,    KC_NO,    KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,    KC_NO,
      KC_NO,     KC_NO,    RALT(DE_1),RALT(DE_3),KC_MUTE,KC_VOLU,             DE_MINS,  TD(F7_7), TD(F8_8),  TD(F9_9),  KC_NO,     KC_NO,     XXXXXXX,  XXXXXXX,  XXXXXXX,
      RALT(DE_2),KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  KC_VOLD,   KC_NO,    DE_SLSH,  TD(F4_4), TD(F5_5),  TD(F6_6),  TD(F11_DO),TD(F10_PL),XXXXXXX,            XXXXXXX,
      KC_NO,     KC_NO,    KC_NO,    KC_MPRV,  KC_MNXT,  KC_MPLY,   KC_NO,    DE_COLN,  TD(F1_1), TD(F2_2),  TD(F3_3),  TD(F12_CO),KC_NO,               XXXXXXX,
      XXXXXXX,   XXXXXXX,  KC_NO,    KC_NO,              KC_NO,               DE_0,               KC_ENTER,  KC_NO,     TG(_BASE), XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX),
  [_NAVIGATION] = LAYOUT(
      XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX,
      KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,               KC_NO,    KC_NO,    KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,    KC_NO,
	    KC_NO,     KC_PASTE, KC_HOME,  KC_UP,    KC_END,   KC_PGUP,             G(KC_1),  G(KC_2),  G(KC_3),   G(KC_4),   KC_NO,     KC_NO,     XXXXXXX,  XXXXXXX,  XXXXXXX,
	    KC_PASTE,  KC_COPY,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_PGDN,   KC_NO,    KC_NO,    KC_RSFT,  KC_RCTL,   KC_RALT,   KC_RGUI,   G(KC_5),   XXXXXXX,            XXXXXXX,
	    KC_NO,     KC_CUT,   KC_NO,    KC_NO,    KC_NO,    KC_NO,     KC_NO,    G(KC_6),  G(KC_7),  G(KC_8),   G(KC_9),   G(KC_0),   KC_NO,               XXXXXXX,
	    XXXXXXX,   XXXXXXX,  KC_NO,    KC_DEL,             KC_NO,               KC_NO,              KC_ENT,    KC_NO,     TG(_BASE), XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX),
};

static uint8_t ltosl_state = 0;
#define LTOSLR_MO_LAYER  _NAVIGATION // Layer to activate when holding.
#define LTOSLL_MO_LAYER  _NUMBERS    // Layer to activate when holding.
#define LTOSL_OSL_LAYER _SYMBOLS    // Layer to activate as an OSL when tapped.
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (keycode == LTOSLR) {
    static uint32_t tap_deadline = 0;
    if (record->event.pressed) {  // On pressed.
      tap_deadline = timer_read32() + 200;  // Set 200 ms tap d weadline.
      layer_on(LTOSLR_MO_LAYER);
      ltosl_state = 1;  // Set undetermined state.
    } else {  // On release.
      layer_off(LTOSLR_MO_LAYER);
      if (ltosl_state && !timer_expired32(timer_read32(), tap_deadline)) {
        // LTOSLR was released without pressing another key within 200 ms.
        layer_on(LTOSL_OSL_LAYER);
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
        layer_on(LTOSL_OSL_LAYER);
        ltosl_state = 2;  // Acting like OSL.
      }
    }
  return false;
  }
return true;
};

void post_process_record_user(uint16_t keycode, keyrecord_t* record) {
  // Turn off the layer if another key is pressed while acting like OSL. The
  // `(ltosl_state >>= 1)` both tests that state = 2 and shifts it toward zero.
  if (ltosl_state > 1) {
    switch (keycode) {
      case RW_BSLS:
      case RW_COLN:
      case RW_COMM:
      case RW_DOT:
      case RW_DQUO:
      case RW_QUOT:
      case RW_SCLN:
      case RW_SLSH:
      default:
        ltosl_state = 0;
        layer_off(LTOSL_OSL_LAYER);
    }
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

const int FkeysSize = 12;
int keysFkeys[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
const int NumkeysSize = 10;
int keysNumkeys[] = { 16, 17, 18, 19, 20, 22, 23, 24, 25, 26 };
const int AlphakeysSize = 24;
int keysAlphakeys[] = { 31, 32, 33, 34, 35, 37, 38, 39, 40, 41, 42, 50, 52, 57, 61, 62, 63, 64, 65, 67, 68, 69, 70, 71 };
const int HomekeysSize = 8;
int keysHomekeys[] = { 46, 47, 48, 49, 53, 54, 55, 56 };
int logoKey = 21;
int ForwardkeysSize = 6;
int keysForwardkeys[] = { 30, 58, 66, 77, 79, 80 };
int BackkeysSize = 3;
int keysBackkeys[] = { 13, 29, 78 };
int ShiftkeysSize = 5;
int keysShiftkeys[] = { 0, 14, 51, 60, 72 };
int ArrowkeysSize = 4;
int keysArrowkeys[] = { 73, 84, 85, 86};
int NavkeysSize = 4;
int keysNavkeys[] = { 33, 47, 48, 49 };
int NumpadkeysSize = 11;
int keysNumpadkeys[] = { 38, 39, 40, 53, 54, 55, 68, 69, 70, 80, 81 };
int NumpadoperatorkeysSize = 4;
int keysNumpadoperatorkeys[] = { 41, 42, 56, 57 };
int QMKkeysSize = 4;
int keysQMKkeys[] = { 12, 13, 14, 29 };
int CutkeysSize = 2;
int keysCutkeys[] = { 76, 81 };
int CopykeysSize = 2;
int keysCopykeys[] = { 77, 80 };
int PastekeysSize = 2;
int keysPastekeys[] = { 78, 79 };
int MMPluskeysSize = 6;
int keysMMPluskeys[] = { 34, 35, 36, 73, 83, 86 };
int MMMinuskeysSize = 6;
int keysMMMinuskeys[] = { 32, 50, 59, 72, 84, 85 };

void set_key_color(int size, int keytype[], uint8_t r, uint8_t g, uint8_t b) {
    for( int i = 0; i < size; i++) {
        rgb_matrix_set_color(keytype[i], r, g, b);
    }
};

void default_color_scheme(void) {
    set_key_color(AlphakeysSize, keysAlphakeys, RGB_WHITE);
    set_key_color(HomekeysSize, keysHomekeys, RGB_BLUE);
};

void rgb_matrix_indicators_user(void) {
    uint8_t layer = biton32(layer_state);
    switch (layer) {
        case _BASE:
            rgb_matrix_set_color_all(RGB_BLUE);
            rgb_matrix_set_color(logoKey, RGB_BLUE );
            break;
        case _SYMBOLS:
            rgb_matrix_set_color_all(RGB_GREEN);
            rgb_matrix_set_color(logoKey, RGB_GREEN );
            break;
        case _NUMBERS:
            rgb_matrix_set_color_all(RGB_RED);
            rgb_matrix_set_color(logoKey, RGB_RED );
            break;
        case  _NAVIGATION:
            rgb_matrix_set_color_all(RGB_YELLOW);
            rgb_matrix_set_color(logoKey, RGB_YELLOW );
            break;
    }
};
void caps_word_set_user(bool active) {
    if (active) {
        rgb_matrix_mode_noeeprom(5);
    } else {
        rgb_matrix_mode_noeeprom(1);
    }
};
