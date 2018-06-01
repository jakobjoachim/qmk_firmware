/* Copyright 2017 Wunder
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
#include "xd75.h"

// Layer shorthand
#define _QW 0
#define _FN 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | P*     | P-     | P+     | DEL    | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | =      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | P7     | P8     | P9     | Q      | Q      | W      | E      | R      | T      | Y      | U      | I      | O      | P      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | P4     | P5     | P6     | D      | A      | S      | D      | F      | G      | H      | J      | K      | L      | ;      | '      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | P1     | P2     | P3     | SHIFT  | Z      | X      | C      | V      | B      | N      | M      | ,      | .      | /      | RSHIFT |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | P0     | P/     | PENTER | FN     | LCTRL  |        | ALT    | WIN    | SPACE  | ENTER  | LEFT   | DOWN   | UP     | RIGHT  | RCTRL  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_QW] = { /* QWERTY */
  { KC_KP_ASTERISK, KC_KP_MINUS,  KC_KP_PLUS,  KC_DEL,    KC_1,    KC_2,     KC_3,    KC_4,   KC_5,   KC_6,    KC_7,    KC_8, KC_9,   KC_0,     KC_EQUAL },
  {          KC_P7,       KC_P8,       KC_P9,  KC_TAB,    KC_Q,    KC_W,     KC_E,    KC_R,   KC_T,   KC_Y,    KC_U,    KC_I, KC_O,   KC_P,     KC_BSPC  },
  {          KC_P4,       KC_P5,       KC_P6,  KC_ESC,    KC_A,    KC_S,     KC_D,    KC_F,   KC_G,   KC_H,    KC_J,    KC_K, KC_L,   KC_SCLN,  KC_QUOTE },
  {          KC_P1,       KC_P2,       KC_P3, KC_LSFT,    KC_Z,    KC_X,     KC_C,    KC_V,   KC_B,   KC_N,    KC_M, KC_COMM, KC_DOT, KC_SLSH,  KC_RSFT  },
  {          KC_P0, KC_KP_SLASH, KC_KP_ENTER, MO(_FN), KC_LCTL, _______,  KC_LALT, KC_LGUI, KC_SPC, KC_ENT, KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, KC_RCTL  },
 },

/* FUNCTION
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        | RESET  | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | MUTE   | PLAY   |        | {      |  }     |        |        |        |        |        |        |        |        | F12    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | VOL+   | NEXT   |        | [      |  ]     |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | VOL-   | PREV   |        | -      |  _     |  \     |   |    |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        | FN     | CALC   | PC     |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_FN] = { /* FUNCTION */
  { _______, _______, _______,   RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_F11  },
  { _______, KC_MUTE, KC_MPLY, _______, KC_LCBR, KC_RCBR, _______, _______, _______, _______, _______, _______, _______, _______, KC_F12  },
  { _______, KC_VOLU, KC_MNXT, _______, KC_LBRC, KC_RBRC, KC_NUBS, KC_TILD, _______, _______, _______, _______, _______, _______, _______ },
  { _______, KC_VOLD, KC_MPRV, _______, KC_MINS, KC_UNDS, KC_NUHS, KC_PIPE, _______, _______, _______, _______, _______, _______, _______ },
  { _______, _______, _______, MO(_FN), KC_CALC, KC_MYCM, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
 }
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};
