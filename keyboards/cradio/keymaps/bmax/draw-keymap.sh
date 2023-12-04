L_NAMES="_DVORAK _APTMAK _NAV NUM FN MUS GAME SYS SYM1 NUM1 SNUM1"
qmk c2json ~/qmk_userspace/keyboards/cradio/keymaps/bmax/keymap.c | keymap parse --layer-names $(echo $L_NAMES) -c 10 -q - >sweep_keymap.yaml
keymap draw sweep_keymap.yaml >sweep.svg
