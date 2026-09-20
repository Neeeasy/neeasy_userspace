#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _NUM,
    _NAV,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Основной слой
     * ,--------------------------------------------.  ,--------------------------------------------.
     * | Esc/Gui|  Q |  W |  E |  R |  T |            |  |  Y |  U |  I |  O |  P |   [            |
     * | Tab    |  A |  S |  D |  F |  G |            |  |  H |  J |  K |  L |  ; |   ]            |
     * | Shift  |  Z |  X |  C |  V |  B |            |  |  N |  M |  , |  . |  / |  '/Alt         |
     * `-------------------| Ctrl | L1 | Enter |  | Space | L2 | Bksp |--------------------------'
     */
    [_BASE] = LAYOUT_split_3x6_3(
        LGUI_T(KC_ESC), KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,

        KC_TAB,         KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_RBRC,

        KC_LSFT,        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
                        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, LALT_T(KC_QUOT),

                        KC_LCTL, MO(_NUM), KC_ENT,
                        KC_SPC,  MO(_NAV), KC_BSPC
    ),

    /* Цифровой и символьный слой (зажать L1 на левой половине)
     * ,--------------------------------------------.  ,--------------------------------------------.
     * |   `    |  % |  # |  $ |  ^ |  _ |            |  |  - |  7 |  8 |  9 |  + |   =            |
     * | Tab    |  @ |  ! |  & |  ( |  ) |            |  |  * |  4 |  5 |  6 |  0 |  Ctrl          |
     * | Shift  |Ins |Caps|Num |  \ |Del |            |  |  / |  1 |  2 |  3 |  , |  Alt           |
     * `-------------------| Ctrl | --- | Enter |  | Space | L2 | Bksp |--------------------------'
     */
    [_NUM] = LAYOUT_split_3x6_3(
        KC_GRV,  KC_PERC, KC_HASH, KC_DLR,  KC_CIRC, KC_UNDS,
                 KC_MINS, KC_7,    KC_8,    KC_9,    KC_PLUS, KC_EQL,

        KC_TAB,  KC_AT,   KC_EXLM, KC_AMPR, KC_LPRN, KC_RPRN,
                 KC_ASTR, KC_4,    KC_5,    KC_6,    KC_0,    KC_RCTL,

        KC_LSFT, KC_INS,  KC_CAPS, KC_NUM,  KC_BSLS, KC_DEL,
                 KC_SLSH, KC_1,    KC_2,    KC_3,    KC_COMM, KC_RALT,

                 KC_LCTL, KC_TRNS, KC_ENT,
                 KC_SPC,  KC_TRNS, KC_BSPC
    ),

    /* Слой навигации и мультимедиа (зажать L2 на правой половине)
     * ,--------------------------------------------.  ,--------------------------------------------.
     * |  Gui   | F1 | F2 | F3 | F4 |Vol+|            |  |WhUp|Home| Up |End |Bksp|  Del           |
     * | Tab    | F5 | F6 | F7 | F8 |Mute|            |  |WhDn|Left|Down|Rght|PgUp|  PrtSc         |
     * | Shift  | F9 |F10 |F11 |F12 |Vol-|            |  | -- |Prev|Play|Next|PgDn|  Alt           |
     * `-------------------| Ctrl | L1 | Enter |  | Space | --- | Bksp |-------------------------'
     */
    [_NAV] = LAYOUT_split_3x6_3(
        KC_LGUI, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_VOLU,
                 KC_NO,   KC_HOME, KC_UP,   KC_END,  KC_BSPC, KC_DEL,

        KC_TAB,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_MUTE,
                 KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, KC_PGUP, KC_PSCR,

        KC_LSFT, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_VOLD,
                 KC_NO,   KC_MPRV, KC_MPLY, KC_MNXT, KC_PGDN, KC_RALT,

                 KC_LCTL, KC_TRNS, KC_ENT,
                 KC_SPC,  KC_TRNS, KC_BSPC
    ),
};


#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_write_P(PSTR("Layer\n\n"), false);
        switch (get_highest_layer(layer_state)) {
            case _BASE:
                oled_write_P(PSTR("Base \n"), false);
                break;
            case _NUM:
                oled_write_P(PSTR("Num  \n"), false);
                break;
            case _NAV:
                oled_write_P(PSTR("Nav  \n"), false);
                break;
            default:
                oled_write_P(PSTR("Undef\n"), false);
                break;
        }

        oled_write_P(PSTR("\n\n"), false);

        led_t led_state = host_keyboard_led_state();
        oled_write_P(led_state.caps_lock ? PSTR("CAPS\n") : PSTR("    \n"), false);
    } else {
        oled_write_P(PSTR("corne\n"), false);
    }
    return false;
}

#endif
