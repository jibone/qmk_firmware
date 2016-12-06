/*
 * Jibone Planck Layout
 */

#include "planck.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Symbolic names for each layers
#define _QWERTY   0
#define _LOWER    1
#define _RAISE    2
#define _SPACE    3

// Shortcuts
#define QWERTY   M(_QWERTY)
#define LOWER    M(_LOWER)
#define RAISE    M(_RAISE)
#define SPACE    M(_SPACE)

// Func macro definitions
#define SFT_ENT   FUNC(0) // Tap for Enter, hold for Shift
#define LWR_PGDN  FUNC(1) // Tap for PgDn, hold for LOWER
#define RSE_PGUP  FUNC(2) // Tap for PgDn, hold for LOWER

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Enable these functions using FUNC(n) macro.
const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_ENT),
  [1] = ACTION_LAYER_TAP_KEY(_LOWER, KC_PGDN),
  [2] = ACTION_LAYER_TAP_KEY(_RAISE, KC_PGUP)
};

// Keyboard layout
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | Entr |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shft |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Shft |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ADJT | Esc  | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
  [_QWERTY] = {
    { KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC },
    { KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT  },
    { KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_ENT },
    { KC_LCTL, KC_ESC,  KC_LALT, KC_LGUI, LOWER,   LT(SPACE, KC_SPC),  LT(SPACE, KC_SPC),  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT }
  },

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |      |   "  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
  [_LOWER] = {
    { KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC },
    { KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE },
    { _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, KC_DQUO, _______ },
    { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ }
  },

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |      |   '  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
  [_RAISE] = {
    { KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC },
    { KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS },
    { _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, _______, KC_QUOT, _______ },
    { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ }
  },

/* Specials
 * ,-----------------------------------------------------------------------------------.
 * |      | MsUp |      |      |      | MsWU | MsB1 | MsB2 | MsB3 | MsB4 | MsB5 |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | MsLt | MsDn | MsRt |      |      | MsWD | Left | Down | Up   | Right|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | MsWL | MsWR |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Slp  |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
  [_SPACE] = {
    { _______, _______, KC_MS_U, _______, _______, KC_WH_D, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, KC_BTN5, _______ },
    { _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, KC_WH_U, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______ },
    { _______, _______, _______, _______, _______, KC_WH_L, KC_WH_R, _______, _______, _______, _______, _______ },
    { KC_SLEP, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY }
  },

};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _SPACE);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _SPACE);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _SPACE);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _SPACE);
      }
      return false;
      break;
    case SPACE:
      if (record->event.pressed) {
        layer_on(_SPACE);
        update_tri_layer(_LOWER, _RAISE, _SPACE);
      } else {
        layer_off(_SPACE);
        update_tri_layer(_LOWER, _RAISE, _SPACE);
      }
      return false;
      break;
  };
  return true;
}
