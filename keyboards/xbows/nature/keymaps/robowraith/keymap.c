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
#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "rgblight_list.h"

// Home-Row-Mod-Keys for QWERTZ and Bone
#define QZ_A LGUI_T(DE_A)
#define QZ_S LALT_T(DE_S)
#define QZ_D LCTL_T(DE_D)
#define QZ_F LSFT_T(DE_F)
#define QZ_J RSFT_T(DE_J)
#define QZ_K RCTL_T(DE_K)
#define QZ_L RALT_T(DE_L)
#define QZ_OE RGUI_T(DE_ODIA)
#define BO_C LGUI_T(DE_C)
#define BO_T LALT_T(DE_T)
#define BO_I LCTL_T(DE_I)
#define BO_E LSFT_T(DE_E)
#define BO_N RSFT_T(DE_N)
#define BO_R RCTL_T(DE_R)
#define BO_S RALT_T(DE_S)
#define BO_G RGUI_T(DE_G)

// Modifier-keys for QWERTZ and Bone
#define QZ_MO3L LT(3, DE_G)
#define QZ_MO3R LT(3, DE_H)
#define QZ_MO5L LT(5, DE_V)
#define QZ_MO5R LT(5, DE_M)
#define BO_MO3L LT(3, DE_O)
#define BO_MO3R LT(3, DE_B)
#define BO_MO4L LT(4, DE_O)
#define BO_MO4R LT(4, DE_B)
#define BO_MO5L LT(5, DE_ADIA)
#define BO_MO5R LT(5, DE_Z)


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
  [0] = LAYOUT(
      // Bone Linux
      KC_ESC,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,      KC_F12,    KC_DEL,     KC_PSCR,
      KC_CIRC,    DE_1,       DE_2,       DE_3,       DE_4,       DE_5,                   DE_6,       DE_7,       DE_8,       DE_9,       DE_0,        DE_MINS,   DE_PLUS,    KC_BSPC,
      KC_TAB,     DE_J,       DE_D,       DE_U,       DE_A,       DE_X,                   DE_P,       DE_H,       DE_L,       DE_M,       DE_W,        DE_SS,     DE_PLUS,    DE_HASH,    KC_PGUP,
      MO(5),      BO_C,       BO_T,       BO_I,       BO_E,       BO_MO3L,    KC_ESC,     BO_MO3R,    BO_N,       BO_R,       BO_S,       BO_G,        DE_Q,      KC_ENT,                 KC_PGDN,
      KC_LSFT,    DE_F,       DE_V,       DE_UDIA,    BO_MO5L,    DE_ODIA,    KC_TAB,     DE_Y,       BO_MO5R,    DE_COMM,    DE_DOT,     DE_K,        KC_RSFT,               KC_UP,
      KC_LCTL,    KC_LGUI,    KC_LALT,    KC_BSPC,                KC_DEL,                 KC_ENT,                 KC_SPC,     KC_RALT,    TT(5),       KC_RCTL,   KC_LEFT,    KC_DOWN,    KC_RGHT),
  [1] = LAYOUT(
      // Bone Mac
      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    DE_MINS,    DE_PLUS,    KC_TRNS,
      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    BO_MO4L,    KC_TRNS,    BO_MO4R,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                KC_TRNS,
      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                KC_TRNS,
      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS),
  [2] = LAYOUT(
      // QWERTZ
      KC_ESC,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,      KC_F12,    KC_DEL,     KC_PSCR,
      KC_CIRC,    DE_1,       DE_2,       DE_3,       DE_4,       DE_5,                   DE_6,       DE_7,       DE_8,       DE_9,       DE_0,        DE_SS,     DE_ACUT,    KC_BSPC,
      KC_TAB,     DE_Q,       DE_W,       DE_E,       DE_R,       DE_T,                   DE_Z,       DE_U,       DE_I,       DE_O,       DE_P,        DE_UDIA,   DE_PLUS,    DE_HASH,    KC_PGUP,
      MO(5),      QZ_A,       QZ_S,       QZ_D,       QZ_F,       QZ_MO3L,    KC_ESC,     QZ_MO3R,    QZ_J,       QZ_K,       QZ_L,       QZ_OE,       DE_ADIA,   KC_ENT,                 KC_PGDN,
      KC_LSFT,    DE_Y,       DE_X,       DE_C,       QZ_MO5L,    DE_B,       KC_TAB,     DE_N,       QZ_MO5R,    DE_COMM,    DE_DOT,     DE_MINS,     KC_RSFT,               KC_UP,
      KC_LCTL,    KC_LGUI,    KC_LALT,    KC_BSPC,                KC_DEL,                 KC_ENT,                 KC_SPC,     KC_RALT,    TT(5),       KC_RCTL,   KC_LEFT,    KC_DOWN,    KC_RGHT),
  [3] = LAYOUT(
      // Shifted Layer Linux
      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
      KC_NO,      KC_NO,      DE_SUP2,    DE_SUP3,    KC_NO,      KC_NO,                  KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
      KC_NO,      DE_DEG,     DE_UNDS,    DE_LBRC,    DE_RBRC,    DE_CIRC,                DE_EXLM,    DE_LABK,    DE_RABK,    DE_EQL,     DE_AMPR,    KC_NO,      KC_NO,      KC_NO,      KC_NO,
      KC_NO,      DE_BSLS,    DE_SLSH,    DE_LCBR,    DE_RCBR,    DE_ASTR,    KC_NO,      DE_QUES,    DE_LPRN,    DE_RPRN,    DE_MINS,    DE_COLN,    DE_AT,      KC_NO,                  KC_NO,
      KC_NO,      DE_HASH,    DE_DLR,     DE_PIPE,    DE_TILD,    DE_GRV,     KC_NO,      DE_PLUS,    DE_PERC,    DE_DQUO,    DE_QUOT,    DE_SCLN,    KC_NO,                  KC_NO,
      KC_NO,      KC_NO,      C(DE_X),    C(DE_C),                S(KC_INS),              S(KC_INS),              C(DE_C),    C(DE_X),    MO(5),      KC_NO,      KC_NO,      KC_NO,      KC_NO),
  [4] = LAYOUT(
      // Shifted Layer Mac
      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
      KC_NO,      KC_NO,      DE_SUP2,    DE_SUP3,    KC_NO,      KC_NO,                  KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
      KC_NO,      DE_DEG,     DE_UNDS,    A(DE_5),    A(DE_6),    DE_CIRC,                DE_EXLM,    DE_LABK,    DE_RABK,    DE_EQL,     DE_AMPR,    KC_NO,      KC_NO,      KC_NO,      KC_NO,
      KC_NO,      LSA(DE_7),  DE_SLSH,    A(DE_8),    A(DE_9),    DE_ASTR,    KC_NO,      DE_QUES,    DE_LPRN,    DE_RPRN,    DE_MINS,    DE_COLN,    DE_AT,      KC_NO,                  KC_NO,
      KC_NO,      DE_HASH,    DE_DLR,     A(DE_7),    A(DE_N),    DE_GRV,     KC_NO,      DE_PLUS,    DE_PERC,    DE_DQUO,    DE_QUOT,    DE_SCLN,    KC_NO,                  KC_NO,
      KC_NO,      KC_NO,      G(DE_X),    G(DE_C),                G(DE_V),                G(DE_V),                G(DE_C),    G(DE_X),    KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO),
  [5] = LAYOUT(
      // Utillity
      KC_ESC,     TG(1),      TG(2),      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      RGB_TOG,    NK_TOGG,    EEP_RST,
      KC_CIRC,    DE_1,       DE_2,       DE_3,       DE_4,       DE_5,                   DE_6,       DE_7,       DE_8,       DE_9,       DE_0,       KC_NO,      KC_NO,      RESET,
      KC_TAB,     KC_NO,      KC_HOME,    KC_UP,      KC_END,     KC_PGUP,                KC_NLCK,    KC_KP_7,    KC_KP_8,    KC_KP_9,    KC_KP_PLUS, KC_PAST,    KC_NO,      KC_NO,      KC_HOME,
      KC_NO,      KC_LSFT,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_PGDN,    KC_NO,      KC_NO,      KC_KP_4,    KC_KP_5,    KC_KP_6,    KC_KP_MINUS,KC_PSLS,    KC_ENTER,               KC_END,
      KC_NO,      KC_LCTL,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_KP_1,    KC_KP_2,    KC_KP_3,    KC_NO,      KC_MUTE,                KC_VOLU,
      KC_NO,      KC_NO,      KC_NO,      KC_LCTRL,               KC_LGUI,                KC_LSFT,                KC_KP_0,    DE_COMM,    KC_TRNS,    KC_MPLY,    KC_MPRV,    KC_VOLD,    KC_MNXT),
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
    set_key_color(AlphakeysSize, keysAlphakeys, RGB_BLUE);
    set_key_color(FkeysSize, keysFkeys, RGB_WHITE);
    set_key_color(NumkeysSize, keysNumkeys, RGB_BLUE);
    set_key_color(HomekeysSize, keysHomekeys, RGB_GREEN);
    set_key_color(ForwardkeysSize, keysForwardkeys, RGB_GREEN);
    set_key_color(BackkeysSize, keysBackkeys, RGB_RED);
    set_key_color(ShiftkeysSize, keysShiftkeys, RGB_YELLOW);
    set_key_color(ArrowkeysSize, keysArrowkeys, RGB_BLUE);
};

void rgb_matrix_indicators_user(void) {
    uint8_t layer = biton32(layer_state);
    switch (layer) {
       case 0: // Bone (Linux)
            rgb_matrix_set_color_all(RGB_WHITE);
            default_color_scheme();
            rgb_matrix_set_color(logoKey, RGB_BLUE );
            break;
        case 1: // Bone (Mac)
            rgb_matrix_set_color_all(RGB_WHITE);
            default_color_scheme();
            rgb_matrix_set_color(logoKey, RGB_RED );
            break;
        case 2: // QWERTZ
            rgb_matrix_set_color_all(RGB_WHITE);
            default_color_scheme();
            rgb_matrix_set_color(logoKey, RGB_GREEN );
            break;
        case 3: // Shifted (Linux)
            rgb_matrix_set_color_all(RGB_BLACK);
            set_key_color(AlphakeysSize, keysAlphakeys, RGB_BLUE);
            set_key_color(HomekeysSize, keysHomekeys, RGB_GREEN);
            set_key_color(CutkeysSize, keysCutkeys, RGB_RED);
            set_key_color(CopykeysSize, keysCopykeys, RGB_GREEN);
            set_key_color(PastekeysSize, keysPastekeys, RGB_YELLOW);
            rgb_matrix_set_color(logoKey, RGB_CYAN );
            break;
        case 4: // Shifted (Mac)
            rgb_matrix_set_color_all(RGB_BLACK);
            set_key_color(AlphakeysSize, keysAlphakeys, RGB_BLUE);
            set_key_color(HomekeysSize, keysHomekeys, RGB_GREEN);
            set_key_color(CutkeysSize, keysCutkeys, RGB_RED);
            set_key_color(CopykeysSize, keysCopykeys, RGB_GREEN);
            set_key_color(PastekeysSize, keysPastekeys, RGB_YELLOW);
            rgb_matrix_set_color(logoKey, RGB_ORANGE );
            break;
        case 5: // Utility
            rgb_matrix_set_color_all(RGB_BLACK);
            rgb_matrix_set_color(0, RGB_YELLOW );
            rgb_matrix_set_color(1, RGB_RED );
            rgb_matrix_set_color(2, RGB_GREEN );
            set_key_color(NumkeysSize, keysNumkeys, RGB_BLUE);
            set_key_color(NavkeysSize, keysNavkeys, RGB_BLUE);
            set_key_color(QMKkeysSize, keysQMKkeys, RGB_MAGENTA);
            rgb_matrix_set_color(30, RGB_YELLOW );
            rgb_matrix_set_color(32, RGB_GREEN );
            rgb_matrix_set_color(34, RGB_GREEN );
            rgb_matrix_set_color(46, RGB_YELLOW );
            rgb_matrix_set_color(51, RGB_WHITE );
            set_key_color(NumpadkeysSize, keysNumpadkeys, RGB_BLUE);
            set_key_color(NumpadoperatorkeysSize, keysNumpadoperatorkeys, RGB_YELLOW);
            rgb_matrix_set_color(58, RGB_GREEN);
            set_key_color(MMPluskeysSize, keysMMPluskeys, RGB_GREEN);
            set_key_color(MMMinuskeysSize, keysMMMinuskeys, RGB_RED);
            rgb_matrix_set_color(77, RGB_YELLOW );
            rgb_matrix_set_color(78, RGB_YELLOW );
            rgb_matrix_set_color(logoKey, RGB_WHITE );
           break;
    }
};
