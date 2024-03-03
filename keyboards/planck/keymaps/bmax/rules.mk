ifeq ($(strip $(AUDIO_ENABLE)), yes)
    SRC += muse.c
endif
COMBO_ENABLE = yes
RGBLIGHT_ENABLE = no
AUDIO_ENABLE = no
