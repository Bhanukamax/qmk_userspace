
#define bake_duel_combo(cname, key1, key2)			\
  const uint16_t PROGMEM cname[] = {key1, key2, COMBO_END}

#define bake_three_combo(cname, key1, key2, key3) \
    const uint16_t PROGMEM cname[] = {key1, key2, key3, COMBO_END}

/*  0  1  2  3  4     5  6  7  8  9 */
/* 10 11 12 13 14    15 16 17 18 19 */
/* 20 21 22 23 24    25 26 27 28 29 */
/*          30 31    32 33 */

bake_three_combo(comb_jkl_ENT, KC_J, KC_K, KC_L);
bake_three_combo(comb_sdf_ENT, KC_S, KC_D, KC_F);
bake_duel_combo(comb_jk_BSPC , KC_J, KC_K);
bake_duel_combo(comb_cv_BSPC , KC_C, KC_V);
bake_duel_combo(comb_df_ESC , KC_D, KC_F);
bake_duel_combo(comb_UI_CAPSWORD , KC_U, KC_I);
bake_duel_combo(comb_sd_TAB,   LCTL_T(KC_S), KC_D);

combo_t key_combos[] = {
    COMBO(comb_jkl_ENT,     KC_ENT),
    COMBO(comb_sdf_ENT,     KC_ENT),
    COMBO(comb_jk_BSPC, KC_BSPC),
    COMBO(comb_cv_BSPC, KC_DEL),
    COMBO(comb_df_ESC, KC_ESC),
    COMBO(comb_UI_CAPSWORD,  CW_TOGG),
    COMBO(comb_sd_TAB,  KC_TAB),

};
