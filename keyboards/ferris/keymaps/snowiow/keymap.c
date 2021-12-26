#include QMK_KEYBOARD_H
#include "my_keycodes.h"

enum layers {
  _COLEMAK,
  _NAV,
  _NUMBER,
  _SYM1,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak DH
 * ,----------------------------------------------------------------------------------------.
 * |   Q  |   W  |   F  |   P    |   B   |              |   J   |   L  |   U  |   Y  |  ;   |
 * |------+------+------+--------+-------+--------------+-------+------+------+------+------|
 * |HOME_A|HOME_R|HOME_S| HOME_T |   G   |              |   M   |HOME_N|HOME_E|HOME_I|HOME_O|
 * |------+------+------+--------+-------+--------------+-------+------+------+------+------|
 * |   Z  |  X   |  C   |   D    |   V   |              |   K   |   H  |   ,  |   .  |  /   |
 * |------+------+------+--------+-------+--------------+-------+------+------+------+------|
 * |      |      |      | ESC    | SPC   |              |ESC_SYM|ENTER |      |      |      |
 * `----------------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT(
KC_Q,   KC_W,         KC_F,         KC_P,            KC_B,              KC_J,          KC_L,   KC_U,            KC_Y,           KC_SCLN,
HOME_A, HOME_R,       HOME_S,       HOME_T,          LT(_NUMBER, KC_G), KC_M,          HOME_N, HOME_E,          HOME_I,         HOME_O,
KC_Z,   LCTL_T(KC_X), LALT_T(KC_C), KC_D,            KC_V,              KC_K,          KC_H,   LALT_T(KC_COMM), LCTL_T(KC_DOT), KC_SLSH,
                                    LT(_NAV,KC_ENT), LT(_NAV, KC_SPC),  LT(_SYM1, KC_BSPC), KC_ESC
),

/* Navigation 
 * ,----------------------------------------------------------------------------------------.
 * |      |      |      |        |       |              | DOWN  |RIGHT |      |      |      |
 * |------+------+------+--------+-------+--------------+-------+------+------+------+------|
 * |      |      |      |        |       |              | PREV  | VOL- | PLAY | VOL+ | NEXT |
 * |------+------+------+--------+-------+--------------+-------+------+------+------+------|
 * |      |      |      |        |       |              | UP    | LEFT |      |      |      |
 * |------+------+------+--------+-------+--------------+-------+------+------+------+------|
 * |      |      |      |        |       |              |       |      |      |      |      |
 * `----------------------------------------------------------------------------------------'
 */
[_NAV] = LAYOUT(
_______, _______, _______, _______, _______, KC_DOWN, KC_RIGHT, _______, _______, _______,
_______, _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_MPLY, KC_VOLU,  KC_MNXT,
_______, _______, _______, _______, _______, KC_UP,   KC_LEFT, _______, _______, _______,
                            _______, _______, _______, _______
),

/* Number 
 * ,-----------------------------------------------------------------------------------------.
 * |      |      |      |        |       |              |       |  7    |  8   |  9   |  .   |
 * |------+------+------+--------+-------+--------------+-------+-------+------+------+------|
 * | GUI  | Ctrl | Alt  | Shift  |       |              |       |  4    |  5   |  6   |  0   |
 * |------+------+------+--------+-------+--------------+-------+-------+------+------+------|
 * |      |      |      |        |       |              |       |  1    |  2   |  3   |  ,   |
 * |------+------+------+--------+-------+--------------+-------+-------+------+------+------|
 * |      |      |      |        |       |              |       | Reset |      |      |      |
 * `-----------------------------------------------------------------------------------------'
 */
[_NUMBER] = LAYOUT(
_______, _______, _______, _______, _______, _______, KC_7, KC_8, KC_9, KC_DOT,
KC_LGUI, KC_LCTL, KC_LALT, KC_LSFT, _______, _______, KC_4, KC_5, KC_6, KC_0,
_______, _______, _______, _______, _______, _______, KC_1, KC_2, KC_3, KC_COMM,
                           RESET, _______, _______, _______
),
/* Sym1 
 * ,-----------------------------------------------------------------------------------------.
 * | %    |  ^   |  &   |   *    |  +    |              |       |       |      |      |      |
 * |------+------+------+--------+-------+--------------+-------+-------+------+------+------|
 * | !    | `    |  \   |   -    |  =    |              |       | Shift | Alt  | Ctrl | GUI  |
 * |------+------+------+--------+-------+--------------+-------+-------+------+------+------|
 * | @    | ~    |  |   |   _    |  $    |              |       |       |      |      |      |
 * |------+------+------+--------+-------+--------------+-------+-------+------+------+------|
 * |      |      |      |   '    |  "    |              |       |       |      |      |      |
 * `-----------------------------------------------------------------------------------------'
 */
[_SYM1] = LAYOUT(
KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_PLUS, _______, _______, KC_8,    KC_9,    KC_DOT,
KC_EXLM, KC_GRV,  KC_BSLS, KC_MINS, KC_EQL,  _______, KC_LSFT, KC_LALT, KC_LCTL, KC_LGUI,
KC_AT,   KC_TILD, KC_PIPE, KC_UNDS, KC_DLR, _______, _______,  KC_2,    KC_3,    KC_COMM,
                           KC_QUOT, KC_DQT, _______, _______
),
	[4] = LAYOUT(KC_TRNS, KC_COLN, KC_LT, KC_GT, KC_SCLN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_AT, KC_TRNS, KC_NO, KC_EQL, KC_PLUS, KC_PERC, KC_TRNS, KC_EXLM, KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_TRNS, KC_TRNS, KC_VOLU),
	[5] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_TRNS, KC_NO, LCTL(KC_LALT), KC_TRNS, KC_TRNS, KC_TRNS, KC_F4, KC_F5, KC_F6, KC_F11, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F12, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[6] = LAYOUT(KC_PSLS, KC_7, KC_8, KC_9, KC_PPLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0, KC_1, KC_2, KC_3, KC_PMNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_PAST, KC_4, KC_5, KC_6, KC_PEQL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[7] = LAYOUT(KC_TRNS, KC_TRNS, KC_COLN, KC_ESC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL, KC_TRNS, KC_PERC, KC_SLSH, KC_ENT, KC_TRNS, DF(1), KC_LGUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_EXLM, KC_TRNS, DF(0), KC_TRNS, RALT_T(KC_COMM), RCTL_T(KC_DOT), RESET, KC_TRNS, KC_TAB, KC_NO, KC_TRNS)
};
