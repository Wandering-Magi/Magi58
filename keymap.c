#include QMK_KEYBOARD_H

/* Custom Keycodes */
#define NO_SYM DF(NOSYM)
#define LC_NAV LT(NAV, KC_A)
#define LC_SYM LT(SYMBOL, KC_T)
#define GAMING DF(GAMEPAD)
#define DMFDGP DF(DMFD)
#define STRCFT DF(STRCFT2)
#define STRMOV LT(STRCFTMOV, KC_SPC)
#define F_KEYS MO(FKEYS)

enum layer_number {
    ENGRAM = 0,
    NOSYM,
    FKEYS,
    NAV,
    SYMBOL,
    GAMEPAD,
    LSELCT,
    DMFD,
    PSO,
    STRCFT2,
    STRCFTMOV,
};

/* TEMPLATE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
/*
[TEMPLATE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______, _______, _______, _______
),
[TEMPLATE] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* ENGRAM
  * ,-----------------------------------------.                    ,-----------------------------------------.
  * | ESC  |   1  |   2  |   3  |  4   |  5{  |                    |  6}  |  7   |   8  |   9  |   0  | DEL  |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * | TAB  |   B  |   Y  |   O  |   U  |  '[  |                    |  "]  |   L  |   D  |   W  |   V  |  Z   |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * | ENTER|   C  |   I  |   E  |   A  |  ,(  |-------.    ,-------|  .)  |   H  |   T  |   S  |   N  |  Q   |
  * |------+------+------+------+------+------| LOWER |    | RAISE |------+------+------+------+------+------|
  * |      |   G  |   X  |   J  |   K  |  -_  |-------|    |-------|  ?!  |   R  |   M  |   F  |   P  |      |
  * `-----------------------------------------/       /     \      \-----------------------------------------'
  *                   |      | LALT | LCTRL| /Space  /       \LSHIFT\  |BackSP|SUPER |      |
  *                   |      |      |      |/       /         \      \ |      |      |      |
  *                   `----------------------------'           '------''--------------------'
  */
    [ENGRAM] = LAYOUT(
        KC_ESC , KC_1  , KC_2   , KC_3   , KC_4   , KC_5   ,                       KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_DEL ,
        KC_TAB , KC_B  , KC_Y   , KC_O   , KC_U   , KC_QUOT,                       KC_DQUO, KC_L   , KC_D   , KC_W   , KC_V   , KC_Z   ,
        KC_ENT , KC_C  , KC_I   , KC_E   , LC_NAV , KC_COMM,                       KC_DOT , KC_H   , LC_SYM , KC_S   , KC_N   , KC_Q   ,
        XXXXXXX, KC_G  , KC_X   , KC_J   , KC_K   , KC_MINS, NO_SYM ,  DF(LSELCT), KC_QUES, KC_R   , KC_M   , KC_F   , KC_P   , F_KEYS ,
                         KC_LGUI, KC_LALT, KC_LCTL, KC_SPC , KC_LSFT,  KC_BSPC   , KC_LGUI, XXXXXXX
    ),

    /**
     * ENGRAM without the symbol or navigation layer shortcuts. Used primarily for gaming
     */
    [NOSYM] = LAYOUT(
        KC_ESC , KC_1  , KC_2   , KC_3   , KC_4   , KC_5   ,                       KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_DEL ,
        KC_TAB , KC_B  , KC_Y   , KC_O   , KC_U   , KC_QUOT,                       KC_DQUO, KC_L   , KC_D   , KC_W   , KC_V   , KC_Z   ,
        KC_ENT , KC_C  , KC_I   , KC_E   , KC_A   , KC_COMM,                       KC_DOT , KC_H   , KC_T   , KC_S   , KC_N   , KC_Q   ,
        XXXXXXX, KC_G  , KC_X   , KC_J   , KC_K   , KC_MINS,DF(ENGRAM), DF(LSELCT),KC_QUES, KC_R   , KC_M   , KC_F   , KC_P   , F_KEYS ,
                                  KC_LGUI, KC_LALT, KC_LCTL, KC_SPC,    KC_LSFT,   KC_BSPC, KC_LGUI, XXXXXXX
    ),

    /**
     * Function keys layers
     */
    [FKEYS] = LAYOUT(
        KC_GRV , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                   KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, KC_F12 ,
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______
    ),
    /**
     * Navigation keys for when arrows are needed
     */
    [NAV] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                   KC_PGUP, KC_HOME, KC_UP  , KC_END , _______, _______,
        _______, _______, _______, _______, _______, _______,                   KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_INS , _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______
    ),

/* SYMBOL
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   ~  |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   ~  |   ^  |   %  |   &  |  `   |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   $  |   @  |   #  |   /  |  ;   |-------.    ,-------|      |   :  |      |   \  |   |  |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |   =  |   *  |  +   |-------|    |-------|      |   ~  |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
    [SYMBOL] = LAYOUT(
        KC_TILD, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, KC_TILD, KC_CIRC, KC_PERC, KC_AMPR, KC_GRV ,                   _______, _______, _______, _______, _______, _______,
        _______, KC_DLR , KC_AT  , KC_HASH, KC_SLSH, KC_SCLN,                   _______, KC_COLN, _______, KC_BSLS, KC_PIPE, _______,
        _______, _______, _______, KC_EQL , KC_ASTR, KC_PLUS, _______, _______, _______, KC_TILD, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /**
     * The master gaming layer, always a WIP
     */
    [GAMEPAD] = LAYOUT(
        KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0   , _______,
        KC_TAB , KC_T   , KC_A   , KC_W   , KC_D   , KC_R   ,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P   , _______,
        KC_ENT , KC_G   , KC_Q   , KC_S   , KC_E   , KC_F   ,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LGUI, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , DF(ENGRAM), _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, F_KEYS ,
                                   KC_LALT, KC_LCTL, KC_LSFT, KC_SPC , KC_RSFT, KC_BSPC, _______, _______
    ),

/*===================================================================================================================================
 *===================================================================================================================================
 *                 GAME SPECIFIC LAYERS (Shit gets weird)
 *===================================================================================================================================
 *===================================================================================================================================
 */
    /**
     * Layer selection layer
     */
    //TODO add function and utility layers
    [LSELCT] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, GAMING , STRCFT , XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, DMFDGP , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    /**
     * Custom layer for Dragon Marked for Death
     * Could also be used for other controller based games
     */
    [DMFD] = LAYOUT(
        KC_ESC , KC_P1  , KC_P2  , KC_P3  , KC_P4  , KC_P5  ,                      KC_P6  , KC_P7  , KC_P8  , KC_P9  , KC_P0  , XXXXXXX,
        XXXXXXX, XXXXXXX, KC_A   , KC_W   , KC_D   , KC_R   ,                      KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , XXXXXXX,
        KC_ENT , XXXXXXX, KC_Q   , KC_S   , KC_E   , KC_F   ,                      KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DF(ENGRAM), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   XXXXXXX, KC_B   , KC_Q   , KC_Y      , KC_U   , KC_E   , KC_V   , XXXXXXX
    ),

    [STRCFT2] = LAYOUT(
        KC_ESC , KC_1  , KC_2   , KC_3   , KC_4   , KC_5   ,                       KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_DEL ,
        KC_TAB , KC_B  , KC_Y   , KC_O   , KC_U   , KC_QUOT,                       KC_DQUO, KC_L   , KC_D   , KC_W   , KC_V   , KC_Z   ,
        KC_ENT , KC_C  , KC_I   , KC_E   , KC_A   , KC_COMM,                       KC_DOT , KC_H   , KC_T   , KC_S   , KC_N   , KC_Q   ,
        KC_LSFT, KC_G  , KC_X   , KC_J   , KC_K   , KC_MINS, DF(ENGRAM), DF(LSELCT),KC_QUES, KC_R   , KC_M   , KC_F   , KC_P   , XXXXXXX,
                                  KC_LGUI, KC_LALT, KC_LCTL, STRMOV,   KC_LSFT,   KC_BSPC, KC_LGUI, XXXXXXX
    ),
    [STRCFTMOV] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, KC_LEFT, KC_UP  , KC_RGHT, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_DOWN, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [PSO] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, KC_A   , KC_W   , KC_D   , _______,                   _______, KC_LEFT, KC_UP  , KC_RGHT, _______, _______,
        _______, _______, _______, KC_S   , _______, _______,                   _______, KC_HOME, KC_DOWN, KC_END , KC_INS , _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, DF(ENGRAM),
        _______, _______, _______, _______, KC_ENT , _______, _______, _______
    )
};


/**
  KEY OVERRIDES
**/
#define LAYER_MASK 0b1
const key_override_t QUES_EXC = ko_make_with_layers( MOD_MASK_SHIFT, KC_QUES, KC_EXLM, LAYER_MASK );
const key_override_t COMM_LPAREN = ko_make_with_layers( MOD_MASK_SHIFT, KC_COMM, KC_LPRN, LAYER_MASK );
const key_override_t DOT_RPAREN = ko_make_with_layers( MOD_MASK_SHIFT, KC_DOT, KC_RPRN, LAYER_MASK );
const key_override_t QUOT_LBRAC = ko_make_with_layers( MOD_MASK_SHIFT, KC_QUOT, KC_LBRC, LAYER_MASK );
const key_override_t DQUO_RBRAC = ko_make_with_layers( MOD_MASK_SHIFT, KC_DQUO, KC_RBRC, LAYER_MASK );
const key_override_t N5_LCBR = ko_make_with_layers( MOD_MASK_SHIFT, KC_5, KC_LCBR, LAYER_MASK );
const key_override_t N6_LCBR = ko_make_with_layers( MOD_MASK_SHIFT, KC_6, KC_RCBR, LAYER_MASK );
const key_override_t N4_LABK = ko_make_with_layers( MOD_MASK_SHIFT, KC_4, KC_LABK, LAYER_MASK );
const key_override_t N7_RABK = ko_make_with_layers( MOD_MASK_SHIFT, KC_7, KC_RABK, LAYER_MASK );

// THIS GLOBALLY DEFINES ALL KEY OVERRIDES TO BE USED
const key_override_t *key_overrides[] = {
  &QUES_EXC,
  &COMM_LPAREN,
  &DOT_RPAREN,
  &QUOT_LBRAC,
  &DQUO_RBRAC,
  &N5_LCBR,
  &N6_LCBR,
  &N4_LABK,
  &N7_RABK
};


/**
* DEFAULT SETTINGS
*/

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}
