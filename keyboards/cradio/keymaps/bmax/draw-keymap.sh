qmk c2json ~/qmk_userspace/keyboards/cradio/keymaps/bmax/keymap.c | keymap parse -c 10 -q - >sweep_keymap.yaml
keymap draw sweep_keymap.yaml >sweep.svg
