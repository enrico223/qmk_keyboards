#include QMK_KEYBOARD_H


enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

typedef struct {
  bool is_press_action;
  int state;
} tap;

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  DOUBLE_SINGLE_TAP = 5
};

//Tap dance enums
enum {
  LW_CTLSFT = 0
};

int cur_dance (tap_dance_state_t *state);

//for the x tap dance. Put it here so it can be used in any keymap
void x_finished (tap_dance_state_t *state, void *user_data);
void x_reset (tap_dance_state_t *state, void *user_data);

#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
     KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,    KC_GRV,          KC_EQL, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_LCTL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LBRC,          KC_RBRC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+;--------+--------+--------+--------+--------+--------|
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_TAB,           KC_ENT,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_TAB, ADJUST, KC_RALT, KC_LGUI,  LOWER,   KC_SPC,                     KC_BSPC,  RAISE,            KC_ENT, KC_RGUI,  KC_RALT, KC_LALT
  //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
  ),

  [_LOWER] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
	  KC_TILD, KC_EXLM, C(KC_W), KC_HASH, C(KC_R),  C(KC_T), KC_VOLU,          KC_PGUP, C(KC_Y), C(KC_U), C(KC_I), C(KC_O), C(KC_P), KC_EQL,
  //,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
	KC_TILD, KC_EXLM,  KC_AT,   KC_HASH, KC_DLR,  KC_PERC,   KC_VOLD,          KC_PGDN,  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,
	//,--------+--------+--------+--------+--------+--------+--------.      ,--------+--------+--------+--------+--------+--------+--------.
	 KC_TRNS, C(KC_Z), C(KC_X),  C(KC_C) ,C(KC_V), C(KC_B) , KC_TRNS,        KC_DEL,  KC_LBRC, KC_LBRC, KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,
  //,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
	  KC_CAPS, KC_TRNS,  KC_TRNS, KC_TRNS,			KC_TRNS, KC_BSPC,         C(KC_BSPC), LSG_T(KC_TRNS), KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY

  ),

  [_RAISE] = LAYOUT(

//,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
  KC_ESC,  KC_1,    KC_2,  KC_3,   KC_4,    KC_5,     KC_COPY,			    KC_BRIU,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
//,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
   KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,  KC_PASTE,          KC_BRID,  KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,  KC_TRNS, KC_TRNS,
//,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS,          KC_TRNS,   KC_TRNS,   KC_NUHS, KC_NUBS, KC_MUTE, KC_TRNS, KC_BSLS,
//,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
  KC_TRNS, KC_COMM, KC_0,  KC_DOT, KC_TRNS, KC_BSPC,                                 KC_BSPC, KC_TRNS, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY

  ),

  [_ADJUST] = LAYOUT(
//,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
  KC_ESC,  KC_1,    KC_2,  KC_3,   KC_4,    KC_5,     KC_COPY,			    KC_BRIU,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
//,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
   KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS,  KC_TRNS, RGB_RMOD, RGB_VAD, RGB_SAD, RGB_HUD, RGB_TOG,
//,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
   KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, BL_STEP,
//,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS,         KC_TRNS,  KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, QK_BOOT
  )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
};

int cur_dance (tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed)  return SINGLE_TAP;
    //key has not been interrupted, but they key is still held. Means you want to send a 'HOLD'.
    else return SINGLE_HOLD;
  }
  else if (state->count == 2) {
    /*
     * DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
     * action when hitting 'pp'. Suggested use case for this return value is when you want to send two
     * keystrokes of the key, and not the 'double tap' action/macro.
    */
    if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  else return 8; //magic number. At some point this method will expand to work for more presses
}

//instanalize an instance of 'tap' for the 'x' tap dance.
static tap xtap_state = {
  .is_press_action = true,
  .state = 0
};

void x_finished (tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP: register_code16(LOWER); break;
    case SINGLE_HOLD: register_code16(LOWER); break;
    case DOUBLE_TAP: register_code16(C(KC_LSFT)); break;
    case DOUBLE_HOLD: register_code16(C(KC_LSFT)); break;
  }
}

void x_reset (tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP: unregister_code16(LOWER); break;
    case SINGLE_HOLD: unregister_code16(LOWER); break;
    case DOUBLE_TAP: unregister_code16(C(KC_LSFT)); break;
    case DOUBLE_HOLD: unregister_code16(C(KC_LSFT)); break;
  }
  xtap_state.state = 0;
}

tap_dance_action_t tap_dance_actions[] = {
  [LW_CTLSFT]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL,x_finished, x_reset)
};
