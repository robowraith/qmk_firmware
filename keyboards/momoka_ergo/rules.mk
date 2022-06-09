# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu

SRC += features/select_word.c

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = yes        # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no            # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = yes        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
SPLIT_KEYBOARD = yes
DYNAMIC_TAPPING_TERM_ENABLE = yes
CAPS_WORD_ENABLE = yes
COMBO_ENABLE = yes
