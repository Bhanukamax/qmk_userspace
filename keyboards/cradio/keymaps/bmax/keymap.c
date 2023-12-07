/* Copyright 2018-2021
 * ENDO Katsuhiro <ka2hiro@curlybracket.co.jp>
 * David Philip Barr <@davidphilipbarr>
 * Pierre Chevalier <pierrechevalier83@gmail.com>
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



/* Base layer 0 layout uses home row mods. See the following guide for details:
 * https://precondition.github.io/home-row-mods
 */

#define _DVORAK 0
#define _APTMAK 1
#define _SYS    2
#define _SYM1   3
#define _SYM0   4
#define _NUMBER 5
#define _FN     6
#define _MUS    7

#define XX _______
#define BASE TO(_DVORAK)

#define lhmr(one, two, three, four, five) LSFT_T(one), LCTL_T(two), LALT_T(three), LGUI_T(four), five
#define rhmr(one, two, three, four, five) one, RGUI_T(two), RALT_T(three), RCTL_T(four), RSFT_T(five)

// Shifted row
#define SROW(one, two, three, four, five) S(one), S(two), S(three), S(four), S(five)
#define GROW(one, two, three, four, five) G(one), G(two), G(three), G(four), G(five)

#define BRLL(one, two, three) LT(_NUMBER, one), LT(_SYM1, two), LT(_SYS, three)
#define BRLR(one, two, three) LT(_SYS, one),  LT(_SYM1, two), LT(_NUMBER, three)

// TODO:
// - Remove LT and GT from other layers only leaving them in sym1
// - Add SCLN (semi colon) and colon to some place
#define ____EMPTY______ XX, XX, XX, XX, XX
#define ____SYS_R2_____ rhmr(KC_LT, KC_BSPC, KC_UP, KC_ESC, XX)
#define ____SYS_R3_____ XX, KC_LEFT, KC_DOWN, KC_RIGHT, XX
#define ____SYS_L2_____ lhmr(XX, KC_ESC, XX, KC_TAB, XX)
#define ____SYS_L3_____ XX, KC_HOME, KC_DEL, KC_END, XX

#define ____SYM1_L2_____ lhmr(KC_LT, KC_PLUS, KC_MINUS, KC_SLASH, XX)
#define ____SYM1_L3_____ KC_LT, KC_EQL, KC_UNDS, S(KC_SLASH), XX
#define ____SYM1_R2_____ rhmr(XX, KC_BSLS,  KC_LBRC, KC_RBRC,  KC_GT)
#define ____SYM1_R3_____ XX, S(KC_BSLS),  S(KC_LBRC), S(KC_RBRC), KC_GT

#define ____NOMBER_L1_____ KC_1, KC_2, KC_3, KC_4,  KC_5
#define ____NOMBER_L2_____ KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,  KC_SLASH
#define ____NOMBER_L3_____ KC_PLUS,  KC_EQL, KC_UNDS, KC_MINUS, S(KC_SLASH)

#define ____NOMBER_R1_____ rhmr(KC_6, KC_7, KC_8, KC_9, KC_0)
#define ____NOMBER_R2_____ rhmr(KC_DOT, KC_4, KC_5, KC_6, KC_0)
#define ____NOMBER_R3_____ S(KC_GRV), KC_1, KC_2, KC_3, KC_0

#define ____DVORAK_L1____ KC_QUOT, KC_COMM, KC_L, KC_P, KC_Y
#define ____DVORAK_L2____ lhmr(KC_A, KC_O, KC_E, KC_U, LT(_MUS, KC_I))
#define __DVORAK_L2_SWEEP lhmr(KC_A, KC_O, KC_E, KC_U, LT(_MUS, KC_I))
#define ____DVORAK_L3____ KC_SCLN, BRLL(KC_Q, KC_J, KC_K), KC_X

// NOTE: KC_SPC  IT'S BAT TO ADD MOD-TAP ETC TO SPACE KEY BECAUSE YOU NEED TO TAP AND HOLD IT IN GRAPHICS PROGRAMS
// #define __DVORAK_MOD_L__  LT(_SYM0, KC_ESC), KC_SPC /* <- DO NOT CHANGE KC_SPC */
#define __DVORAK_MOD_L__  LT(_NUMBER, KC_SPC), LT(_SYM0, KC_SPC)

#define ____DVORAK_R1____ KC_F, KC_G, KC_C, KC_R, KC_DOT
#define ____DVORAK_R2____ rhmr(KC_D, KC_H, KC_T, KC_N, KC_S)
#define ____DVORAK_R3____ KC_B, BRLR(KC_M, KC_W, KC_V), KC_Z
#define __DVORAK_MOD_R__  LT(_NUMBER, KC_E), OSM(MOD_RSFT)

#define ____DVORAK_L1_MOD KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y
#define ____DVORAK_L3_MOD KC_SCLN, BRLL(KC_Q, KC_J, KC_K), KC_X
#define ____DVORAK_R1_MOD KC_F, KC_G, KC_C, KC_R, KC_L
#define ____DVORAK_R3_MOD KC_B, BRLR(KC_M, KC_W, KC_V), KC_Z

#define ____APTMAK_L1____ KC_V, KC_W, KC_F, KC_P, KC_B
#define ____APTMAK_L2____ lhmr(KC_R, KC_S, KC_T, KC_H, LT(_MUS, KC_K))
#define ____APTMAK_L3____ KC_SCLN, BRLL(KC_C, KC_G, KC_D), KC_DEL

#define ____APTMAK_R1____ KC_J, KC_L, KC_U, KC_Y, KC_QUOT
#define ____APTMAK_R2____ rhmr(KC_X, KC_N, KC_A, KC_I, KC_O)
#define ____APTMAK_R3____ KC_BSPC, BRLR(KC_M, KC_COMM, KC_DOT), KC_Z

#define __APTMAK_MOD_L__  LT(_NUMBER, KC_SPC), LT(_SYM0, KC_SPC)
#define __APTMAK_MOD_R__  LT(_NUMBER, KC_E), OSM(MOD_RSFT)

#define ____SYM_L1____ SROW(KC_1, KC_2,  KC_3, KC_4, KC_5)
#define ____SYM_L2____ C(KC_A), LCTL_T(KC_GRV), LALT_T(S(KC_GRV)), LT(_MUS, C(KC_U)), KC_SLASH
#define ____SYM_L3____ C(KC_Z), C(KC_X), C(KC_C), C(KC_V), S(KC_SLASH)
#define __SYM_MOD_L__  XX,  XX

#define ____SYM_R1____ SROW(KC_6, KC_7, KC_8, KC_9, KC_0)
#define ____SYM_R2____ rhmr(KC_BSLS, KC_UNDS, KC_EQL, KC_LBRC, KC_RBRC)
#define ____SYM_R3____ S(KC_BSLS), KC_MINUS, KC_PLUS, S(KC_LBRC), S(KC_RBRC)
#define __SYM_MOD_R__  XX,  XX
#define __SYM_MOD_R__p XX,  XX,  XX

#define ____MUS_L1____ S(KC_1),     S(KC_2),            S(KC_3),            S(KC_4),            S(KC_5)
#define ____MUS_L2____ XX, XX, XX, C(KC_U), XX
#define ____MUS_L3____ XX, KC_ACL2, KC_ACL1, KC_ACL0, XX
#define __MUS_MOD_L__ XX, XX

#define ____MUS_R1____ XX, XX, XX, XX, KC_BTN3
#define ____MUS_R2____ S(KC_6), KC_WH_U, KC_MS_U, KC_WH_D, KC_BTN2
#define ____MUS_R3____ C(KC_D), KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1

#define __MUS_MOD_R__ XX, XX
#define __MUS_MOD_R__p XX, XX, XX

#define ____FN_L1____ KC_F1,  KC_F2, KC_F3, KC_F4,  KC_F5
#define ____FN_L2____ TO(_DVORAK), TO(_APTMAK), KC_MPRV, KC_F4, KC_F5
#define ____FN_L3____ KC_VOLD,  KC_VOLU, KC_F3, KC_BRID, KC_BRIU

#define ____FN_R1____ KC_F6, KC_F7, KC_F8, KC_F9, KC_F10
#define ____FN_R2____ KC_DEL, KC_MEDIA_PLAY_PAUSE, KC_MNXT, KC_F11, KC_F12
#define ____FN_R3____ KC_F6,  XX, RGB_TOG, KC_BRID, KC_BRIU


#define LAYOUT_bmax_wrapper(...) LAYOUT_split_3x5_2(__VA_ARGS__)
#define LAYOUT_wrapper(...) LAYOUT_5x6(__VA_ARGS__)
#define LAYOUT_planck_grid_wrapper(...) LAYOUT_planck_grid(__VA_ARGS__)

#define CASE_MOD_TAP(modifire, keycode)                                                 \
  case modifire(keycode):                                                               \
    if (record->tap.count && record->event.pressed) {                          \
      tap_code16(keycode);                                                         \
      return false;                                                            \
    }                                                                          \
    break

bool lctl_o_held = false;
__attribute__((weak)) bool process_record_user(uint16_t keycode,
                                               keyrecord_t* record) {
    switch (keycode) {
	CASE_MOD_TAP(LCTL_T, KC_PLUS);
	CASE_MOD_TAP(LSFT_T, KC_LT);
	CASE_MOD_TAP(RSFT_T, KC_GT);
	CASE_MOD_TAP(LALT_T, S(KC_GRV));

      return false; // Skip all further processing of this key
  }
  return true;
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(_SYM0, KC_SPC):
        case LT(_NUMBER, KC_BSPC):
        case LCTL_T(KC_O):
            return 0;
        default:
            return QUICK_TAP_TERM;
    }
}

#include "combos.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DVORAK] = LAYOUT_bmax_wrapper( // Dvorak
        ____DVORAK_L1_MOD, ____DVORAK_R1_MOD,
        __DVORAK_L2_SWEEP, ____DVORAK_R2____,
        ____DVORAK_L3_MOD, ____DVORAK_R3_MOD,
        __DVORAK_MOD_L__, __DVORAK_MOD_R__
        ),
     [_APTMAK] = LAYOUT_bmax_wrapper( // Dvorak
     ____APTMAK_L1____, ____APTMAK_R1____,
     ____APTMAK_L2____, ____APTMAK_R2____,
     ____APTMAK_L3____, ____APTMAK_R3____,
     __APTMAK_MOD_L__, __APTMAK_MOD_R__
    ),
    [_SYS] = LAYOUT_bmax_wrapper(
	____EMPTY______, ____EMPTY______,
	____SYS_L2_____, ____SYS_R2_____,
	____SYS_L3_____, ____SYS_R3_____,
	KC_ESC, _______, _______, _______),
    [_SYM1] = LAYOUT_bmax_wrapper(
	____EMPTY______, ____EMPTY______,
	____SYM1_L2_____, ____SYM1_R2_____,
	____SYM1_L3_____, ____SYM1_R3_____,
	KC_ESC, _______, _______, _______),
    [_SYM0] = LAYOUT_bmax_wrapper(
          ____SYM_L1____, ____SYM_R1____,
          ____SYM_L2____, ____SYM_R2____,
          ____SYM_L3____, ____SYM_R3____,
          KC_ESC, _______, _______, _______
          ),
    [_NUMBER] = LAYOUT_bmax_wrapper(
	____NOMBER_L1_____, ____NOMBER_R1_____,
	____NOMBER_L2_____, ____NOMBER_R2_____,
	____NOMBER_L3_____, ____NOMBER_R3_____,
        KC_TRNS, KC_TRNS, KC_BSPC, MO(_FN)),
    [_FN] = LAYOUT_bmax_wrapper( // Nav layer
        ____FN_L1____, ____FN_R1____,
        ____FN_L2____, ____FN_R2____,
        ____FN_L3____, ____FN_R3____,
        KC_TRNS, KC_TRNS, KC_BSPC, KC_TRNS),
    [_MUS] = LAYOUT_bmax_wrapper( // Nav layer
        ____MUS_L1____, ____MUS_R1____,
        ____MUS_L2____, ____MUS_R2____,
        ____MUS_L3____, ____MUS_R3____,
        KC_TRNS, KC_TRNS, KC_BSPC, MO(_FN))
};
