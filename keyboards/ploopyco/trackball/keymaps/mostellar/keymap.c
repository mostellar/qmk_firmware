/* Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
 * Copyright 2020 Ploopy Corporation
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Tap Dance keycodes
// enum td_keycodes {
//     BTN5_LAYER
// };

// Define a type containing as many tapdance states as you need
// typedef enum {
//     TD_NONE,
//     TD_UNKNOWN,
//     TD_SINGLE_TAP,
//     TD_SINGLE_HOLD,
//     TD_DOUBLE_SINGLE_TAP
// } td_state_t;

// Create a global instance of the tapdance state type
// static td_state_t td_state;

// Declare your tapdance functions:

// Function to determine the current tapdance state
// td_state_t cur_dance(qk_tap_dance_state_t *state);

// `finished` and `reset` functions for each tapdance keycode
void td_btnlayer_finished(qk_tap_dance_state_t *state, void *user_data);
void td_btnlayer_reset(qk_tap_dance_state_t *state, void *user_data);

//Layout: Left button, Scroll click, Right button, Button just right of ball, Button far right of ball
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( KC_BTN1, DRAG_SCROLL, KC_BTN2, KC_BTN3, KC_BTN5 ),
    [1] = LAYOUT( KC_BTN1, KC_BTN4, KC_BTN3, KC_BTN2, TD(BTN5_LAYER) ),
    [2] = LAYOUT( DF(0), DRAG_SCROLL, DF(1), DPI_CONFIG, _______ ),
    [3] = LAYOUT( _______, _______, _______, _______, _______ ),
    [4] = LAYOUT( _______, _______, _______, _______, _______ ),
    [5] = LAYOUT( _______, _______, _______, _______, _______ ),
    [6] = LAYOUT( _______, _______, _______, _______, _______ ),
    [7] = LAYOUT( _______, _______, _______, _______, _______ )
};


// Determine the tapdance state to return
// td_state_t cur_dance(qk_tap_dance_state_t *state) {
//     if (state->count == 1) {
//         if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
//         else return TD_SINGLE_HOLD;
//     }

//     if (state->count == 2) return TD_DOUBLE_SINGLE_TAP;
//     else return TD_UNKNOWN; // Any number higher than the maximum state value you return above
// }


// // Handle the possible states for each tapdance keycode you define:

// void td_btnlayer_finished(qk_tap_dance_state_t *state, void *user_data) {
//     td_state = cur_dance(state);
//     switch (td_state) {
//         case TD_SINGLE_TAP:
//             register_code16(KC_BTN5);
//             break;
//         case TD_SINGLE_HOLD:
//             layer_on(2); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
//             break;
//         case TD_DOUBLE_SINGLE_TAP: // Allow nesting of 2 parens `((` within tapping term
//             tap_code16(KC_BTN5);
//             register_code16(KC_BTN5);
//             break;
//         default:
//             break;
//     }
// }

// void td_btnlayer_reset(qk_tap_dance_state_t *state, void *user_data) {
//     switch (td_state) {
//         case TD_SINGLE_TAP:
//             unregister_code16(KC_BTN5);
//             break;
//         case TD_SINGLE_HOLD:
//             layer_off(2); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
//             break;
//         case TD_DOUBLE_SINGLE_TAP:
//             unregister_code16(KC_BTN5);
//             break;
//         default:
//             break;
//     }
// }

// // Define `ACTION_TAP_DANCE_FN_ADVANCED()` for each tapdance keycode, passing in `finished` and `reset` functions
// qk_tap_dance_action_t tap_dance_actions[] = {
//     [BTN5_LAYER] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_btnlayer_finished, td_btnlayer_reset)
// };
