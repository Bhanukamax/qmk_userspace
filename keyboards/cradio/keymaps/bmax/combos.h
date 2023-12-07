#define bake_duel_combo(cname, key1, key2) \
  const uint16_t PROGMEM cname[] = {key1, key2, COMBO_END}

#define bake_three_combo(cname, key1, key2, key3) \
    const uint16_t PROGMEM cname[] = {key1, key2, key3, COMBO_END}

/*  0  1  2  3  4     5  6  7  8  9 */
/* 10 11 12 13 14    15 16 17 18 19 */
/* 20 21 22 23 24    25 26 27 28 29 */
/*          30 31    32 33 */

bake_three_combo(comb_mwv, LT(_SYS, KC_M),  LT(_SYM1, KC_W), LT(_NUMBER, KC_V));
bake_three_combo(comb_mcommdot_ENT, LT(_SYS, KC_M),  LT(_SYM1, KC_COMM), LT(_NUMBER, KC_DOT));
bake_three_combo(comb_htn_ENT, RGUI_T(KC_H), RALT_T(KC_T), RCTL_T(KC_N));
bake_three_combo(comb_nai_ENT, RGUI_T(KC_N), RALT_T(KC_A), RCTL_T(KC_I));

bake_duel_combo(comb_uh_CAPSWORD, LGUI_T(KC_U),  RGUI_T(KC_H));

bake_duel_combo(comb_ht_BSPC, RGUI_T(KC_H), RALT_T(KC_T));
bake_duel_combo(comb_na_BSPC, RGUI_T(KC_N), RALT_T(KC_A));
bake_duel_combo(comb_nl,    KC_L,                RGUI_T(KC_N));
bake_duel_combo(comb_quot_a, LT(_NUMBER, KC_QUOT),  LSFT_T(KC_A));

bake_duel_combo(comb_RN,    KC_R,                RCTL_T(KC_N));
bake_duel_combo(comb_le,    LALT_T(KC_E),        KC_L);
bake_duel_combo(atp_comb_lu,    KC_L,        KC_U);
bake_duel_combo(atp_comb_pf,    KC_P,        KC_F);

bake_duel_combo(comb_oe_TAB,    LCTL_T(KC_O), LALT_T(KC_E));
bake_duel_combo(comb_eu_ESC,    LALT_T(KC_E), LGUI_T(KC_U));
bake_duel_combo(comb_jk_DEL,    KC_J,         KC_K);
bake_three_combo(comb_oeu_ENT,  LCTL_T(KC_O), LALT_T(KC_E), LGUI_T(KC_U));


bake_duel_combo(comb_gh_s0,       KC_G,                RGUI_T(KC_H));
bake_duel_combo(comb_pu_s9,       KC_P,                LGUI_T(KC_U));
bake_duel_combo(comb_dote_slbrc,  KC_DOT,              LALT_T(KC_E));
bake_duel_combo(comb_ct_srbrc,    KC_C,                RALT_T(KC_T));
bake_duel_combo(comb_commo_lbrc,  KC_COMM,             LCTL_T(KC_O));
bake_duel_combo(comb_rn_rbrc,     KC_R,                RCTL_T(KC_N));

combo_t key_combos[] = {
    COMBO(comb_gh_s0,      S(KC_0)),
    COMBO(comb_pu_s9,      S(KC_9)),
    COMBO(comb_dote_slbrc,    S(KC_LBRC)),
    COMBO(comb_ct_srbrc,    S(KC_RBRC)),
    COMBO(comb_commo_lbrc,  KC_LBRC),
    COMBO(comb_rn_rbrc,     KC_RBRC),

    COMBO(comb_mwv,     KC_ENT),
    COMBO(comb_mcommdot_ENT,     KC_ENT),
    COMBO(comb_htn_ENT,     KC_ENT),
    COMBO(comb_nai_ENT,     KC_ENT),
    COMBO(comb_nl,      KC_ENT),
    COMBO(comb_quot_a,   KC_TAB),

    COMBO(comb_le,   KC_SCLN),

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
