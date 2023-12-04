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

#define  _DVORAK 0
#define  _APTMAK 1
#define  _NAV 2
#define _NUM 3
#define _FN 4
#define _MUS 5
#define _GAME 6
#define _SYS 7
#define _SYM1 8
#define _NUM1 9
//#define _PLANCK_NAV 7
//#define _CTRL 8

#define HM_A LSFT_T(KC_A)
#define HM_O LCTL_T(KC_O)
#define HM_E LALT_T(KC_E)
#define HM_U LGUI_T(KC_U)

#define HM_S RSFT_T(KC_S)
#define HM_N RCTL_T(KC_N)
#define HM_T RALT_T(KC_T)
#define HM_H RGUI_T(KC_H)


#define HM_L_P LSFT_T(KC_A)
#define HM_L_R LCTL_T(KC_R)
#define HM_L_M LALT_T(KC_S)
#define HM_L_I LGUI_T(KC_T)

#define HM_R_P LSFT_T(KC_O)
#define HM_R_R LCTL_T(KC_I)
#define HM_R_M LALT_T(KC_E)
#define HM_R_I LGUI_T(KC_N)


#define G_LBRC LGUI_T(KC_LBRC)
#define G_RBRC LGUI_T(KC_RBRC)

#define AL_MINS LALT_T(KC_MINS)
#define AL_EQL RALT_T(KC_EQL)

#define CTL_DEL LCTL_T(KC_DEL)
#define NAV MO(_NAV)
#define NUM_BSPC LT(_NUM, KC_BSPC)
#define CTL_SPC LCTL_T(KC_SPC)
#define SHFT_TAB LSFT_T(KC_TAB)
#define NAV_ESC LT(_NAV, KC_ESC)

#define XX _______
#define BASE TO(_DVORAK)

#define lhmr(one, two, three, four, five) LSFT_T(one), LCTL_T(two), LALT_T(three), LGUI_T(four), five
#define rhmr(one, two, three, four, five) one, RGUI_T(two), RALT_T(three), RCTL_T(four), RSFT_T(five)

// Shifted row
#define SROW(one, two, three, four, five) S(one), S(two), S(three), S(four), S(five)
#define GROW(one, two, three, four, five) G(one), G(two), G(three), G(four), G(five)

#define BRLL(one, two, three) LT(_NAV, one), LT(_SYM1, two), LT(_SYS, three)
#define BRLR(one, two, three) LT(_SYS, one),  LT(_SYM1, two), LT(_NAV, three)

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

//#define ____NUM1_L2_____ lhmr(S(KC_GRV), KC_1, KC_2, KC_3, XX)
//#define ____NUM1_L3_____ S(KC_GRV), KC_COMM, KC_4, KC_5, KC_GRV
#define ____NUM1_L1_____ KC_1, KC_2, KC_3, KC_4,  KC_5
#define ____NUM1_L2_____ KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,  KC_SLASH
#define ____NUM1_L3_____ KC_PLUS,  KC_EQL, KC_UNDS, KC_MINUS, S(KC_SLASH)

#define ____NUM1_R1_____ rhmr(KC_6, KC_7, KC_8, KC_9, KC_0)
#define ____NUM1_R2_____ rhmr(KC_DOT, KC_4, KC_5, KC_6, KC_0)
#define ____NUM1_R3_____ S(KC_GRV), KC_1, KC_2, KC_3, KC_0


#define ___SNUM1_L2_____ S(KC_GRV), S(KC_1), S(KC_2), S(KC_3), XX
#define ___SNUM1_L3_____ S(KC_GRV), S(KC_SCLN), S(KC_4), S(KC_5), KC_GRV
#define ___SNUM1_R2_____ XX, S(KC_6), S(KC_7), S(KC_8), KC_Z
#define ___SNUM1_R3_____ S(KC_GRV), S(KC_9), S(KC_0), KC_SCLN, KC_Z

#define ____PLANCK_GROW_L___ GROW(KC_1, KC_2,KC_3,KC_4, KC_5)
#define ____PLANCK_GROW_R___ GROW(KC_6, KC_7,KC_8,KC_9, KC_0)

#define ____DVORAK_L1____ KC_QUOT, KC_COMM, KC_L, KC_P, KC_Y
#define ____DVORAK_L2____ lhmr(KC_A, KC_O, KC_E, KC_U, LT(_MUS, KC_I))
#define __DVORAK_L2_SWEEP lhmr(KC_A, KC_O, KC_E, KC_U, LT(_MUS, KC_I))
#define ____DVORAK_L3____ KC_SCLN, BRLL(KC_Q, KC_J, KC_K), KC_X

// NOTE: KC_SPC  IT'S BAT TO ADD MOD-TAP ETC TO SPACE KEY BECAUSE YOU NEED TO TAP AND HOLD IT IN GRAPHICS PROGRAMS
// #define __DVORAK_MOD_L__  LT(_NUM, KC_ESC), KC_SPC /* <- DO NOT CHANGE KC_SPC */
#define __DVORAK_MOD_L__  LT(_NAV, KC_SPC), LT(_NUM, KC_SPC)

#define ____DVORAK_R1____ KC_F, KC_G, KC_C, KC_R, KC_DOT
#define ____DVORAK_R2____ rhmr(KC_D, KC_H, KC_T, KC_N, KC_S)
#define ____DVORAK_R3____ KC_B, BRLR(KC_M, KC_W, KC_V), KC_Z
#define __DVORAK_MOD_R__  LT(_NAV, KC_E), OSM(MOD_RSFT)

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

#define __M_APTMAK_R1____ KC_B, KC_P, KC_F, KC_W, KC_V
#define __M_APTMAK_R2____ rhmr(KC_B, KC_H, KC_T, KC_S, KC_R)
#define __M_APTMAK_R3____ KC_K, BRLL(KC_D, KC_G, KC_C), KC_SCLN
#define __M_APTMAK_L1____ KC_QUOT, KC_Y, KC_U, KC_L, KC_J
#define __M_APTMAK_L2____ lhmr(KC_O, KC_I, KC_A, KC_N, KC_J)
#define __M_APTMAK_L3____ KC_Z, BRLR(KC_COMM, KC_DOT, KC_M), KC_X

#define __APTMAK_MOD_L__  LT(_NAV, KC_SPC), LT(_NUM, KC_SPC)
#define __APTMAK_MOD_R__  LT(_NAV, KC_E), OSM(MOD_RSFT)


#define NUM_ROW_L KC_1, KC_2, KC_3, KC_4, KC_5
#define NUM_ROW_R KC_6, KC_7, KC_8, KC_9, KC_0

#define ____NAV_L1____ KC_1, KC_2,  KC_3, KC_4, KC_5
#define ____NAV_L2____ KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,  KC_SLASH
#define ____NAV_L3____ KC_PLUS,  KC_EQL, KC_UNDS, KC_MINUS, S(KC_SLASH)
// #define ____NAV_L3____ C(KC_Z), C(KC_X),         C(KC_C),         C(KC_V),         XX
#define __NAV_MOD_L__  LT(_FN, KC_SPC), LT(_FN, KC_SPC)

#define ____NAV_R1____ KC_6, KC_7, KC_8, KC_9, KC_0
#define ____NAV_R2____ KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSPC
#define ____NAV_R3____ KC_HOME, KC_PGUP, KC_PGDN, KC_END,  KC_BSPC
#define __NAV_MOD_R__  KC_BSPC, MO(_FN)
#define __NAV_MOD_R__p KC_BSPC, KC_BSPC, MO(_FN)

#define ____NUM_L1____ SROW(KC_1, KC_2,  KC_3, KC_4, KC_5)
#define ____NUM_L2____ C(KC_A), LCTL_T(KC_GRV), LALT_T(S(KC_GRV)), LT(_MUS, C(KC_U)), KC_SLASH
#define ____NUM_L3____ C(KC_Z), C(KC_X), C(KC_C), C(KC_V), S(KC_SLASH)
#define __NUM_MOD_L__  XX,  XX

#define ____NUM_R1____ SROW(KC_6, KC_7, KC_8, KC_9, KC_0)
#define ____NUM_R2____ rhmr(KC_BSLS, KC_UNDS, KC_EQL, KC_LBRC, KC_RBRC)
#define ____NUM_R3____ S(KC_BSLS), KC_MINUS, KC_PLUS, S(KC_LBRC), S(KC_RBRC)
#define __NUM_MOD_R__  XX,  XX
#define __NUM_MOD_R__p XX,  XX,  XX

#define ____MUS_L1____ S(KC_1),     S(KC_2),            S(KC_3),            S(KC_4),            S(KC_5)
#define ____MUS_L2____ XX, XX, XX, C(KC_U), XX
#define ____MUS_L3____ XX, KC_ACL2, KC_ACL1, KC_ACL0, XX
#define __MUS_MOD_L__ XX, XX

#define ____MUS_R1____ XX, XX, XX, XX, KC_BTN3
#define ____MUS_R2____ S(KC_6), KC_WH_U, KC_MS_U, KC_WH_D, KC_BTN2
#define ____MUS_R3____ C(KC_D), KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1

#define __MUS_MOD_R__ XX, XX
#define __MUS_MOD_R__p XX, XX, XX

#define ____GAME_L1____ KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R
#define ____GAME_L2____ KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F
#define ____GAME_L3____ KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V
#define __GAME_MOD_L__ XX, KC_SPC

#define ____GAME_R1____ XX, XX, XX, XX, BASE
#define ____GAME_R2____ XX, XX, XX, XX, XX
#define ____GAME_R3____ XX, XX, XX, XX, XX
#define __GAME_MOD_R__ XX, XX

#define ____FN_L1____ KC_F1,  KC_F2, KC_F3, KC_F4,  KC_F5
#define ____FN_L2____ TO(_DVORAK), TO(_APTMAK), KC_MPRV, KC_F4, KC_F5
#define ____FN_L3____ KC_VOLD,  KC_VOLU, KC_F3, KC_BRID, KC_BRIU

#define ____FN_R1____ KC_F6, KC_F7, KC_F8, KC_F9, KC_F10
#define ____FN_R2____ KC_DEL, KC_MEDIA_PLAY_PAUSE, KC_MNXT, KC_F11, KC_F12
#define ____FN_R3____ KC_F6,  TO(_GAME), RGB_TOG, KC_BRID, KC_BRIU


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
        case LT(_NUM, KC_SPC):
        case LT(_NAV, KC_BSPC):
        case LT(_NUM1, KC_BSPC):
        case LCTL_T(KC_O):
            return 0;
        default:
            return QUICK_TAP_TERM;
    }
}

#define bake_duel_combo(cname, key1, key2) \
  const uint16_t PROGMEM cname[] = {key1, key2, COMBO_END}

#define bake_three_combo(cname, key1, key2, key3) \
    const uint16_t PROGMEM cname[] = {key1, key2, key3, COMBO_END}


bake_three_combo(comb_mwv, LT(_SYS, KC_M),  LT(_SYM1, KC_W), LT(_NUM1, KC_V));
bake_three_combo(comb_mcommdot_ENT, LT(_SYS, KC_M),  LT(_SYM1, KC_COMM), LT(_NUM1, KC_DOT));
bake_three_combo(comb_htn_ENT, RGUI_T(KC_H), RALT_T(KC_T), RCTL_T(KC_N));
bake_three_combo(comb_nai_ENT, RGUI_T(KC_N), RALT_T(KC_A), RCTL_T(KC_I));

bake_duel_combo(comb_uh_CAPSWORD, LGUI_T(KC_U),  RGUI_T(KC_H));

bake_duel_combo(comb_ht_BSPC, RGUI_T(KC_H), RALT_T(KC_T));
bake_duel_combo(comb_na_BSPC, RGUI_T(KC_N), RALT_T(KC_A));
bake_duel_combo(comb_pu,    KC_P,               LGUI_T(KC_U));
bake_duel_combo(comb_gh,    KC_G,                RGUI_T(KC_H));
bake_duel_combo(comb_nl,    KC_L,                RGUI_T(KC_N));
bake_duel_combo(comb_quot_a, LT(_NAV, KC_QUOT),  LSFT_T(KC_A));


bake_duel_combo(comb_RN,    KC_R,                RCTL_T(KC_N));
bake_duel_combo(comb_CT,    KC_C,                RALT_T(KC_T));
bake_duel_combo(comb_le,    LALT_T(KC_E),        KC_L);
bake_duel_combo(comb_ct,    RALT_T(KC_T),        KC_C);
bake_duel_combo(atp_comb_lu,    KC_L,        KC_U);
bake_duel_combo(atp_comb_pf,    KC_P,        KC_F);

bake_duel_combo(comb_oe_TAB,    LCTL_T(KC_O), LALT_T(KC_E));
bake_duel_combo(comb_eu_ESC,    LALT_T(KC_E), LGUI_T(KC_U));
bake_duel_combo(comb_jk_DEL,    KC_J,         KC_K);
bake_three_combo(comb_oeu_ENT,  LCTL_T(KC_O), LALT_T(KC_E), LGUI_T(KC_U));

combo_t key_combos[] = {
    COMBO(comb_gh,      KC_ENT),
    COMBO(comb_mwv,     KC_ENT),
    COMBO(comb_mcommdot_ENT,     KC_ENT),
    COMBO(comb_htn_ENT,     KC_ENT),
    COMBO(comb_nai_ENT,     KC_ENT),
    COMBO(comb_nl,      KC_ENT),
    COMBO(comb_pu,      KC_ESC),
    COMBO(comb_quot_a,   KC_TAB),
    COMBO(comb_RN,   KC_L),
    COMBO(comb_CT,   KC_S),
    COMBO(comb_le,   KC_SCLN),
    COMBO(comb_ct,   KC_Z),

    COMBO(atp_comb_lu,   KC_Z),
    COMBO(atp_comb_pf,   KC_Q),

    COMBO(comb_ht_BSPC, KC_BSPC),
    COMBO(comb_na_BSPC, KC_BSPC),

    COMBO(comb_oe_TAB, KC_TAB),
    COMBO(comb_eu_ESC, KC_ESC),
    COMBO(comb_jk_DEL, KC_DEL),
    COMBO(comb_oeu_ENT, KC_ENT),

    COMBO(comb_uh_CAPSWORD, CW_TOGG),
};

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
    [_NUM] = LAYOUT_bmax_wrapper(
          ____NUM_L1____, ____NUM_R1____,
          ____NUM_L2____, ____NUM_R2____,
          ____NUM_L3____, ____NUM_R3____,
          KC_ESC, _______, _______, _______
          ),
    [_NUM1] = LAYOUT_bmax_wrapper( // Nav layer
        ____NAV_L1____, ____NAV_R1____,
        ____NAV_L2____, ____NAV_R2____,
        ____NAV_L3____, ____NAV_R3____,
        KC_TRNS, KC_TRNS, KC_BSPC, MO(_FN)),
    [_NAV] = LAYOUT_bmax_wrapper(
	____NUM1_L1_____, ____NUM1_R1_____,
	____NUM1_L2_____, ____NUM1_R2_____,
	____NUM1_L3_____, ____NUM1_R3_____,
        KC_TRNS, KC_TRNS, KC_BSPC, MO(_FN)),
    [_FN] = LAYOUT_bmax_wrapper( // Nav layer
        ____FN_L1____, ____FN_R1____,
        ____FN_L2____, ____FN_R2____,
        ____FN_L3____, ____FN_R3____,
        KC_TRNS, KC_TRNS, KC_BSPC, KC_TRNS),
    [_GAME] = LAYOUT_bmax_wrapper( // Nav layer
        ____GAME_L1____, ____GAME_R1____,
        ____GAME_L2____, ____GAME_R2____,
        ____GAME_L3____, ____GAME_R3____,
        __GAME_MOD_L__, __GAME_MOD_R__
                                   ),
   [_MUS] = LAYOUT_bmax_wrapper( // Nav layer
        ____MUS_L1____, ____MUS_R1____,
        ____MUS_L2____, ____MUS_R2____,
        ____MUS_L3____, ____MUS_R3____,
        KC_TRNS, KC_TRNS, KC_BSPC, MO(_FN))
};
