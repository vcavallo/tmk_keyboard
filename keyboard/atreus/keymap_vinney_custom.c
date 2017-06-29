#include "keymap_common.h"

/* The default Atreus layout. First layer is normal keys, second
   (momentary fn layer) is numbers, most punctuation, and
   arrows. Third (modal, persistent) layer is function keys and other
   rarely-used keys. */

#define AC_TAP(layer, key)  ACTION_LAYER_TAP_KEY(layer, AC_##key)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: mostly letters */
  KEYMAP(KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, \
         KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_BSPC, \
         KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_RSHIFT, \
         KC_LCTL, KC_LSHIFT, KC_LALT, KC_FN1, KC_SPC, KC_LGUI, \
         KC_RGUI, KC_SPC, KC_FN0, KC_SCOLON, KC_SLASH, KC_ENT), \
  /* 1: punctuation and numbers */
  KEYMAP(KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, \
         KC_TAB, KC_GRAVE, SHIFT(KC_9), SHIFT(KC_0), KC_NO, KC_NO, KC_QUOTE, KC_MINUS, KC_SCOLON, KC_BSPACE, \
         KC_NO, KC_NO, KC_LBRACKET, KC_RBRACKET, KC_NO, KC_NO, KC_EQUAL, SHIFT(KC_COMMA), SHIFT(KC_DOT), KC_RSHIFT, \
         KC_LCTL, KC_LSHIFT, KC_LALT, KC_NO, KC_SPC, KC_LGUI, \
         KC_RGUI, KC_SPC, KC_FN0, KC_LBRACKET, KC_RBRACKET, KC_BSLASH), \
  /* 2: arrows and function keys */
  KEYMAP(KC_ESCAPE, KC_NO, KC_NO, KC_NO, KC_FN4, KC_FN3, KC_PGDOWN, KC_PGUP, KC_EQUAL, SHIFT(KC_EQUAL), \
         KC_NO, KC_FN5, KC_FN6, KC_FN7, KC_FN8, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_LBRACKET, \
         KC_NO, KC_FN9, KC_FN10, KC_FN11, KC_FN12, KC_NO, KC_NO, KC_NO, KC_NO, KC_RSHIFT, \
         KC_LCTL, KC_LSHIFT, KC_NO, KC_FN1, KC_SPC, KC_LGUI, \
         KC_RGUI, KC_SPC, KC_NO, KC_NO, KC_NO, KC_NO)
};

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay
  [1] = ACTION_LAYER_MOMENTARY(2),  // switch to layer 2
  // [1] = ACTION_LAYER_ON(2, 1),  // switch to layer 2
  [2] = ACTION_LAYER_OFF(2, 1),  // switch back to layer 0
  [3] = ACTION_FUNCTION(BOOTLOADER)
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  if (id == BOOTLOADER) {
    bootloader();
  }
}
