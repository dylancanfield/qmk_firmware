#include "planck.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _MOVE 1
#define _SYMB 2
#define _FUNC 3
#define _I3 4

enum planck_keycodes {
  BASE = SAFE_RANGE,
  MOVE,
  SYMB,
  FUNC,
  I3
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* BASE
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  |  -   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Bksp |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |Alt_L |Supr_L|dmenu | Move |Space |Enter | Symb | I3   |Supr_R|Ctrl_R|Func  |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_MINS},
  {KC_BSPC, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT},
  {KC_LCTL, KC_LGUI, KC_LALT, LALT(KC_S),  MOVE,    KC_SPC,  KC_ENT,  SYMB,    I3,      KC_RALT, KC_RCTL, FUNC}
},

/* MOVE
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |      | Home |  Up  | End  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |      | Left | Down |Right |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |Pg Up |Pg Dn |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOVE] = {
  {KC_ESC,  XXXXXXX, KC_HOME,   KC_UP,  KC_END, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX },
  {KC_DEL,  XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {_______, XXXXXXX, XXXXXXX, KC_PGUP, KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* SYMB
 * ,-----------------------------------------------------------------------------------.
 * |  Esc |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Esc  |
 * |-----------------------------------------------------------------------------------.
 * |  Del |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   <  |   ~  |   |  |   +  |   [  |   {  |  }   |   ]  |   =  |   \  |   `  |  >   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMB] = {
  {KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_ESC },
  {KC_DEL,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL },
  {KC_LABK, KC_TILD, KC_PIPE, KC_PLUS, KC_LBRC, KC_LCBR, KC_RCBR, KC_RBRC, KC_EQL,  KC_BSLS, KC_GRV,  KC_RABK},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* FUNC
 * ,-----------------------------------------------------------------------------------.
 * | F12  |  F1  |  F2  |  F3  |  Fia  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |-----------------------------------------------------------------------------------.
 * |      | Play | Prev | Next | Vol+ |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | Mute |      |      | Vol- |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Reset |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNC] = {
  {KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11 },
  {_______, KC_MPLY, KC_MPRV, KC_MNXT, KC_VOLU, _______, _______, _______, _______, _______, _______, _______},
  {_______, KC_MUTE, _______, _______, KC_VOLD, _______, _______, _______, _______, _______, _______, _______},
  {RESET, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},


/* Layer for I3 shortcuts */
[_I3] = {
    {_______, LALT(KC_1), LALT(KC_2), LALT(KC_3), LALT(KC_4), LALT(KC_5), LALT(KC_6), LALT(KC_7) ,LALT(KC_8), LALT(KC_9) ,LALT(KC_0), LALT(KC_MINS)},
    {_______, XXXXXXX , XXXXXXX, LALT(KC_S), LALT(KC_ENT), XXXXXXX, LALT(KC_H), LALT(KC_N), LALT(KC_E), LALT(KC_I), LALT(KC_O), XXXXXXX},
    {_______, XXXXXXX , XXXXXXX, LALT(KC_C), LALT(KC_V), XXXXXXX, XXXXXXX, LALT(KC_M),XXXXXXX, XXXXXXX ,XXXXXXX, _______},
    {_______, _______ ,_______,  _______,_______, _______, _______, _______ ,_______, _______ ,_______, _______},
}


};


void persistant_default_layer_set(uint16_t default_layer) {                     
  eeconfig_update_default_layer(default_layer);                                 
  default_layer_set(default_layer);                                             
}  

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MOVE:
      if (record->event.pressed) {
        layer_on(_MOVE);
        update_tri_layer(_MOVE, _SYMB, _FUNC);
      } else {
        layer_off(_MOVE);
        update_tri_layer(_MOVE, _SYMB, _FUNC);
      }
      return false;
      break;
    case SYMB:
      if (record->event.pressed) {
        layer_on(_SYMB);
        update_tri_layer(_MOVE, _SYMB, _FUNC);
      } else {
        layer_off(_SYMB);
        update_tri_layer(_MOVE, _SYMB, _FUNC);
      }
      return false;
      break;
    case FUNC:
      if (record->event.pressed) {
        layer_on(_FUNC);
      } else {
        layer_off(_FUNC);
      }
      return false;
      break;
    case I3:
      if (record->event.pressed) {
        layer_on(_I3);
      } else {
        layer_off(_I3);
      }
      return false;
      break;
  }
  return true;
}
