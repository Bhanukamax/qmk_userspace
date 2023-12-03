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
	CASE_MOD_TAP(LSFT_T, S(KC_GRV));

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

combo_t key_combos[] = {
    COMBO(comb_gh,      KC_ENT),
    COMBO(comb_mwv,     KC_ENT),
    COMBO(comb_mcommdot_ENT,     KC_ENT),
    COMBO(comb_htn_ENT,     KC_ENT),
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

    [_SNUM1] = LAYOUT_bmax_wrapper(
	____EMPTY______, ____EMPTY______,
	___SNUM1_L2_____, ___SNUM1_R2_____,
	___SNUM1_L3_____, ___SNUM1_R3_____,
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
