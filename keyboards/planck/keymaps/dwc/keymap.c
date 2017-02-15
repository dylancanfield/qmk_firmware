#include "planck.h"
#include "action_layer.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif
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
#define _I3MOVE 5

enum planck_keycodes {
  BASE = SAFE_RANGE,
  MOVE,
  SYMB,
  FUNC,
  I3,
  I3MOVE
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
 * | Func | GUI  | Alt  | Ctrl | Symb |Space |Enter | Move | GUI  | Alt  | Ctrl |Caps  |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_MINS},
  {KC_BSPC, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT},
  {KC_LCTL, KC_LGUI, KC_LALT, I3MOVE,  MOVE,    KC_SPC,  KC_ENT,  SYMB,    I3,      KC_RALT, KC_RCTL, FUNC}
},

/* MOVE
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |      | Home |  Up  | End  |      |      | Home |  Up  | End  |      | Esc  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |      | Left | Down |Right |      |      | Left | Down |Right |      | Del  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |Pg Up |Pg Dn |      |      |Pg Dn |Pg Up |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOVE] = {
  {KC_ESC,  XXXXXXX, KC_HOME,   KC_UP,  KC_END, XXXXXXX, XXXXXXX, KC_HOME,   KC_UP,  KC_END, XXXXXXX,  KC_ESC},
  {KC_DEL,  XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,  KC_DEL},
  {_______, XXXXXXX, XXXXXXX, KC_PGUP, KC_PGDN, XXXXXXX, XXXXXXX, KC_PGDN, KC_PGUP, XXXXXXX, XXXXXXX, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* SYMB
 * ,-----------------------------------------------------------------------------------.
 * |  Esc |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Esc  |
 * |-----------------------------------------------------------------------------------.
 * |  Del |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   ~  |   |  |   +  |   [  |   {  |  }   |   ]  |   =  |   \  |   `  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMB] = {
  {KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_ESC },
  {KC_DEL,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL },
  {_______, KC_TILD, KC_PIPE, KC_PLUS, KC_LBRC, KC_LCBR, KC_RCBR, KC_RBRC, KC_EQL,  KC_BSLS, KC_GRV,  _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* FUNC
 * ,-----------------------------------------------------------------------------------.
 * | F12  |  F1  |  F2  |  F3  |  Fia  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |-----------------------------------------------------------------------------------.
 * |      | Play | Prev | Next | BL+  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | Mute | Vol- | Vol+ | BL-  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |Reset |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNC] = {
  {KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11 },
  {_______, KC_MPLY, KC_MPRV, KC_MNXT, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______},
  {_______, KC_MUTE, XXXXXXX, XXXXXXX, KC_VOLD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______},
  {RESET, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

[_I3] = {
    {_______, LALT(KC_1), LALT(KC_2), LALT(KC_3), LALT(KC_4), LALT(KC_5), LALT(KC_6), LALT(KC_7) ,LALT(KC_8), LALT(KC_9) ,LALT(KC_0), LALT(KC_MINS)},
    {_______, XXXXXXX , XXXXXXX, LALT(KC_S), LALT(KC_ENT), XXXXXXX, LALT(KC_H), LALT(KC_N), LALT(KC_E), LALT(KC_I), LALT(KC_O), XXXXXXX},
    {_______, XXXXXXX , XXXXXXX, LALT(KC_C), LALT(KC_V), XXXXXXX, XXXXXXX, LALT(KC_M),XXXXXXX, XXXXXXX ,XXXXXXX, _______},
    {_______, _______ ,_______,  _______,_______, _______, _______, _______ ,_______, _______ ,_______, _______},
},

[_I3MOVE] = {
    {_______, LALT(LSFT(KC_1)), LALT(LSFT(KC_2)), LALT(LSFT(KC_3)), LALT(LSFT(KC_4)), LALT(LSFT(KC_5)), LALT(LSFT(KC_6)), LALT(LSFT(KC_7)) ,LALT(LSFT(KC_8)), LALT(LSFT(KC_9)) ,LALT(LSFT(KC_0)), LALT(LSFT(KC_MINS))},
    {_______, LALT(LSFT(KC_Q)), XXXXXXX, XXXXXXX ,XXXXXXX, XXXXXXX, XXXXXXX, LALT(LSFT(KC_N)), LALT(LSFT(KC_E)), LALT(LSFT(KC_I)), LALT(LSFT(KC_O)), XXXXXXX},
    {_______, XXXXXXX ,XXXXXXX, XXXXXXX ,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX ,XXXXXXX, XXXXXXX ,XXXXXXX, _______},
    {_______, _______ ,_______, _______ ,_______, _______, _______, _______ ,_______, _______ ,_______, _______},
}

};

#ifdef AUDIO_ENABLE                                                             
                                                                                
float tone_startup[][2]    = SONG(STARTUP_SOUND);
float tone_goodbye[][2] = SONG(GOODBYE_SOUND);                                  

#endif

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
    case I3MOVE:
      if (record->event.pressed) {
        layer_on(_I3MOVE);
      } else {
        layer_off(_I3MOVE);
      }
      return false;
      break;
  }
  return true;
}
