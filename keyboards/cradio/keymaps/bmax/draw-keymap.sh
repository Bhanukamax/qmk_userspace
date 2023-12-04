L_NAMES="_DVORAK _APTMAK _SYS _SYM1 _NUM _NUM1 _NAV _FN _GAME _MUS" #
#qmk c2json ~/qmk_userspace/keyboards/cradio/keymaps/bmax/keymap.c | keymap parse --layer-names $(echo $L_NAMES) -c 10 -q - >sweep_keymap.yaml
qmk c2json ~/qmk_userspace/keyboards/cradio/keymaps/bmax/keymap.c | keymap -c my_config.yaml parse --layer-names $(echo $L_NAMES) -c 10 -q - >sweep_keymap.yaml
keymap -c my_config.yaml draw sweep_keymap.yaml >sweep.svg
