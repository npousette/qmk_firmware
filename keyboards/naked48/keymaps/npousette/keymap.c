#include QMK_KEYBOARD_H

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;
// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
  _QWERTY = 0,
  _DVORAK,
  _NUM,
  _ARR,
  _L_MAC
};

enum custom_keycodes {
  RGB_RST = SAFE_RANGE,
  CTL_MUTE = LCTL_T(KC_MUTE),   // tap for volume mute, hold for left ctl
  ALT_VOLD = LALT_T(KC_VOLD),   // tap for volume down, hold for left alt
  GUI_VOLU = LGUI_T(KC_VOLU),   // tap for volume up, hold for left gui
  MAC_ESC = LT(_L_MAC, KC_ESC), // tap for esc, hold for macro layer
  SFT_CAPS = LSFT_T(KC_CAPS),    // tap for caps lock, hold for left shift
  //SPC_NUM = LT(_NUM, KC_SPC),   // tap for space, hold for num layer
  //BSPC_ARR = LT(_ARR, KC_BSPC) // tap for backspace, hold for arrows layer
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
  //,-----------------------------------------------------|                 |-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
      MAC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
     SFT_CAPS,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
           DF(_DVORAK),CTL_MUTE,ALT_VOLD,GUI_VOLU,  KC_SPC,MO(_NUM),MO(_ARR), KC_BSPC, KC_RGUI, KC_RALT, KC_RCTRL, KC_MINS
          //`------------------------------------------------------------------------------------------------------------'
  ),

  [_DVORAK] = LAYOUT(
  //,-----------------------------------------------------|                 |-----------------------------------------------------.
       KC_TAB, KC_QUOT, KC_COMM,  KC_DOT,    KC_P,    KC_Y,                      KC_F,    KC_G,    KC_C,    KC_R,    KC_L, KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
      MAC_ESC,    KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                      KC_D,    KC_H,    KC_T,    KC_N,    KC_S,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
     SFT_CAPS, KC_SCLN,    KC_Q,    KC_J,    KC_K,    KC_X,                      KC_B,    KC_M,    KC_W,    KC_V,    KC_Z, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
           DF(_QWERTY),CTL_MUTE,ALT_VOLD,GUI_VOLU,  KC_SPC,MO(_NUM),MO(_ARR), KC_BSPC, KC_RGUI, KC_RALT, KC_RCTRL, KC_SLSH
          //`------------------------------------------------------------------------------------------------------------'
  ),


  [_NUM] = LAYOUT(
  //,-----------------------------------------------------|                 |-----------------------------------------------------.
      KC_CIRC, KC_EXLM,   KC_AT, KC_HASH, KC_ASTR, KC_PERC,                   KC_PIPE,    KC_7,    KC_8,    KC_9, KC_PLUS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
      _______,  KC_DLR, KC_AMPR, KC_QUES, KC_LPRN, KC_RPRN,                    KC_DOT,    KC_4,    KC_5,    KC_6, KC_MINS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
      _______, KC_TILD,KC_GRAVE, KC_SLSH, KC_LCBR, KC_RCBR,                      KC_0,    KC_1,    KC_2,    KC_3,  KC_EQL, _______,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
               _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX 
          //`------------------------------------------------------------------------------------------------------------'
  ),

  [_ARR] = LAYOUT(
  //,-----------------------------------------------------|                 |-----------------------------------------------------.
      XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, RGB_TOG, RGB_MOD,                   XXXXXXX, KC_BRID,   KC_UP, KC_BRIU, XXXXXXX,   RESET,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
      _______, KC_LSFT,KC_LCTRL, KC_LALT, KC_LGUI, RGB_VAI,                   XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
      _______, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
               _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX 
          //`------------------------------------------------------------------------------------------------------------'
  ),

  [_L_MAC] = LAYOUT(
  //,-----------------------------------------------------|                 |-----------------------------------------------------.
      XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   RESET,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, G(KC_X), G(KC_C), G(KC_V), G(KC_Z),                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
               _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX 
          //`------------------------------------------------------------------------------------------------------------'
  )
};

int RGB_current_mode;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  bool result = false;
  switch (keycode) {
    #ifdef RGBLIGHT_ENABLE
      case RGB_MOD:
          if (record->event.pressed) {
            rgblight_mode(RGB_current_mode);
            rgblight_step();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
      case RGB_RST:
          if (record->event.pressed) {
            eeconfig_update_rgblight_default();
            rgblight_enable();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
    #endif
    default:
      result = true;
      break;
  }

  return result;
}

void matrix_init_user(void) {

}
