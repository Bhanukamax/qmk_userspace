L_NAMES="_DVORAK _APTMAK _SYS _SYM_WIP _SYM0 _NUMBER _FN _MUS"
#qmk c2json ~/qmk_userspace/keyboards/cradio/keymaps/bmax/keymap.c | keymap parse --layer-names $(echo $L_NAMES) -c 10 -q - >sweep_keymap.yaml
rm -rf sweep_keymap.yaml
qmk c2json ~/qmk_userspace/keyboards/cradio/keymaps/bmax/keymap.c | keymap -c my_config.yaml parse --layer-names $(echo $L_NAMES) -c 10 -q - >sweep_keymap.yaml
cat draw-combos.yaml >> sweep_keymap.yaml
keymap -c my_config.yaml draw sweep_keymap.yaml >sweep.svg


#_DVORAK _APTMAK _NAV NUM FN MUS GAME SYS SYM1 NUM1
