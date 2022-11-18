/*
Additiional cnofigurations
*/

/* Set Tapping Toggle */
#define TAPPING_TOGGLE 2

// default but used in macros
#undef TAPPING_TERM
 #define TAPPING_TERM 180
#define TAPPING_TERM_PER_KEY

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

/* Enable lighting layers */
// #define RGBLIGHT_LAYERS
// #define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF

// CAPSWORD
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

// Possible fix for wakeup issue
#define USB_SUSPEND_WAKEUP_DELAY 200
