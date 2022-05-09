#include QMK_KEYBOARD_H
#include "my_keycodes.h"

enum layers {
  _COLEMAK,
  _NAV,
  _NUMBER,
  _MOUSE,
  _SYM1,
  _SYM2,
  _FKEYS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak DH
 * ,---------------------------------------------------------------------------------------------------.
 * |   Q  |   W  |   F  |   P     |   B     |              |   J       |   L      |   U  |   Y  |  ;   |
 * |------+------+------+---------+---------+--------------+-----------+----------+------+------+------|
 * |HOME_A|HOME_R|HOME_S| HOME_T  |   G     |              |   M       | HOME_N   |HOME_E|HOME_I|HOME_O|
 * |------+------+------+---------+---------+--------------+-----------+----------+------+------+------|
 * |   Z  |  X   |  C   |   D     |   V     |              |   K       |   H      |   ,  |   .  |  /   |
 * |------+------+------+---------+---------+--------------+-----------+----------+------+------+------|
 * |      |      |      | NAV/ENT | NUM/SPC |              | SYM1/BSPC | SYM2/ESC |      |      |      |
 * `---------------------------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT(
KC_Q,   KC_W,         KC_F,         KC_P,            KC_B,              KC_J,               KC_L,             KC_U,            KC_Y,           KC_SCLN,
HOME_A, HOME_R,       HOME_S,       HOME_T,          LT(_MOUSE, KC_G),  KC_M,               HOME_N,           HOME_E,          HOME_I,         HOME_O,
KC_Z,   KC_X,         KC_C, KC_D,   KC_V,            KC_K,              KC_H,               KC_COMM,          KC_DOT,          KC_SLSH,
                                    LT(_NAV,KC_ENT), LT(_NUMBER, KC_SPC),  LT(_SYM1, KC_BSPC), LT(_SYM2, KC_ESC)
),

/* Navigation 
 * ,----------------------------------------------------------------------------------------.
 * |Reset |      |      |        |       |              |       |      |      |      |      |
 * |------+------+------+--------+-------+--------------+-------+------+------+------+------|
 * |      |      |      |        |       |              | LEFT  | DOWN | UP   | RIGHT|      |
 * |------+------+------+--------+-------+--------------+-------+------+------+------+------|
 * |      |      |      |        |       |              | PREV  | VOL- | PLAY | VOL+ | NEXT |
 * |------+------+------+--------+-------+--------------+-------+------+------+------+------|
 * |      |      |      |        |       |              |       |      |      |      |      |
 * `----------------------------------------------------------------------------------------'
 */
[_NAV] = LAYOUT(
RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______,
_______, _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_MPLY, KC_VOLU,  KC_MNXT,
                            _______, _______, _______, _______
),

/* Number 
 * ,-----------------------------------------------------------------------------------------.
 * |      |      |      |        |       |              |       |  7    |  8   |  9   |  .   |
 * |------+------+------+--------+-------+--------------+-------+-------+------+------+------|
 * | GUI  | Ctrl | Alt  | Shift  |       |              | TAB   |  4    |  5   |  6   |  0   |
 * |------+------+------+--------+-------+--------------+-------+-------+------+------+------|
 * |      |      |      |        |       |              | CAPS  |  1    |  2   |  3   |  ,   |
 * |------+------+------+--------+-------+--------------+-------+-------+------+------+------|
 * |      |      |      |        |       |              | FKEYS | Caps |
 * `-----------------------------------------------------------------------------------------'
 */
[_NUMBER] = LAYOUT(
_______, _______, _______, _______, _______, _______,     KC_7,    KC_8, KC_9, KC_DOT,
KC_LGUI, KC_LCTL, KC_LALT, KC_LSFT, _______, KC_TAB,      KC_4,    KC_5, KC_6, KC_0,
_______, _______, _______, _______, _______, KC_CAPSLOCK, KC_1,    KC_2, KC_3, KC_COMM,
                           _______, _______, MO(_FKEYS),  KC_CAPSLOCK
),

/* F-Keys 
 * ,-----------------------------------------------------------------------------------------.
 * |      |      |      |        |       |              |       | F7    |  F8  |  F9  | F12  |
 * |------+------+------+--------+-------+--------------+-------+-------+------+------+------|
 * | GUI  | Ctrl | Alt  | Shift  |       |              |       | F4    |  F5  |  F6  | F11  |
 * |------+------+------+--------+-------+--------------+-------+-------+------+------+------|
 * |      |      |      |        |       |              |       | F1    |  F2  |  F3  | F10  |
 * |------+------+------+--------+-------+--------------+-------+-------+------+------+------|
 * |      |      |      |        |       |              |       |       |
 * `-----------------------------------------------------------------------------------------'
 */
[_FKEYS] = LAYOUT(
_______, _______, _______, _______, _______, _______,  KC_F7,    KC_F8, KC_F9, KC_F12,
KC_LGUI, KC_LCTL, KC_LALT, KC_LSFT, _______, _______,  KC_F4,    KC_F5, KC_F6, KC_F11,
_______, _______, _______, _______, _______, _______,  KC_F1,    KC_F2, KC_F3, KC_F10,
                           _______, _______, _______, _______
),

/* Mouse 
 * ,------------------------------------------------------------------------------------------.
 * |      |      |      |        |       |              |       | WLEFT | WUP   |WRIGHT|      |
 * |------+------+------+--------+-------+--------------+-------+-------+-------+------+------|
 * | GUI  | Ctrl | Alt  | Shift  |       |              | LEFT  | DOWN  | UP    | RIGHT|      |
 * |------+------+------+--------+-------+--------------+-------+-------+-------+------+------|
 * |      |      |      |        |       |              |       | WLEFT | WDOWN |WRIGHT|      |
 * |------+------+------+--------+-------+--------------+-------+-------+-------+------+------|
 * |      |      |      |        |       |              | BTN1  | BTN2  |                     |
 * `------------------------------------------------------------------------------------------'
 */
[_MOUSE] = LAYOUT(
_______, _______, _______, _______, _______, _______, KC_WH_L, KC_WH_U, KC_WH_R, _______,  
KC_LGUI, KC_LCTL, KC_LALT, KC_LSFT, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,  
_______, _______, _______, _______, _______, _______, KC_WH_L, KC_WH_D, KC_WH_R, _______,  
                           _______, _______, KC_BTN1, KC_BTN2
),

/* Sym1 
 * ,-----------------------------------------------------------------------------------------.
 * | %    |  ^   |  &   |   *    |  +    |              |       |       |      |      |      |
 * |------+------+------+--------+-------+--------------+-------+-------+------+------+------|
 * | !    | `    |  \   |   -    |  =    |              |       | Shift | Alt  | Ctrl | GUI  |
 * |------+------+------+--------+-------+--------------+-------+-------+------+------+------|
 * | @    | ~    |  |   |   _    |  $    |              |       |       |      |      |      |
 * |------+------+------+--------+-------+--------------+-------+-------+------+------+------|
 * |      |      |      |   '    | FKEYS |              |       |       |      |      |      |
 * `-----------------------------------------------------------------------------------------'
 */
[_SYM1] = LAYOUT(
KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR,    KC_PLUS, _______, _______, KC_8,    KC_9,    KC_DOT,
KC_EXLM, KC_GRV,  KC_BSLS, KC_MINS,    KC_EQL,  _______, KC_LSFT, KC_LALT, KC_LCTL, KC_LGUI,
KC_AT,   KC_TILD, KC_PIPE, KC_UNDS,    KC_DLR, _______, _______,  KC_2,    KC_3,    KC_COMM,
                  KC_QUOT, MO(_FKEYS), _______, _______
),

/* Sym2 
 * ,-----------------------------------------------------------------------------------------.
 * |      |      |      |   {    |  }    |              |       |       |      |      |      |
 * |------+------+------+--------+-------+--------------+-------+-------+------+------+------|
 * |      |      |  #   |   (    |  )    |              |       | Shift | Alt  | Ctrl | GUI  |
 * |------+------+------+--------+-------+--------------+-------+-------+------+------+------|
 * |      |      |      |   [    |  ]    |              |       |       |      |      |      |
 * |------+------+------+--------+-------+--------------+-------+-------+------+------+------|
 * |      |      |      |        |       |              |       |       |      |      |      |
 * `-----------------------------------------------------------------------------------------'
 */
[_SYM2] = LAYOUT(
_______, _______, _______, KC_LCBR, KC_RCBR, _______, _______, _______, _______, _______,
_______, _______, KC_HASH, KC_LPRN, KC_RPRN, _______, KC_LSFT, KC_LALT, KC_LCTL, KC_LGUI, 
_______, _______, _______, KC_LBRC, KC_RBRC, _______, _______, _______, _______, _______,
                           _______, _______, _______, _______
),
};
