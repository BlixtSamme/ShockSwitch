#include <stdint.h>


/* Note: This struct would suffice with only a bit index that specifies the specific bit the button starts.
   Including the byte index to make implementation a little more intuitive
*/
typedef struct button_index {
    uint8_t byte_index;
    uint8_t bit_index;
    uint8_t bit_size; 
} button_index;



/* POSITIONS FOR DUALSHOCK 4 IN HID MESSAGE */

//Sticks x and y values

button_index LEFT_STICK_X = {
    .byte_index = 2,
    .bit_index = 0,
    .bit_size = 8,
};

button_index LEFT_STICK_Y = {
    .byte_index = 3,
    .bit_index = 0,
    .bit_size = 8,
};

button_index RIGHT_STICK_X = {
    .byte_index = 4,
    .bit_index = 0,
    .bit_size = 8,
};

button_index RIGHT_STICK_Y = {
    .byte_index = 5,
    .bit_index = 0,
    .bit_size = 8,
};

//Buttons

button_index POS_TRIANGLE = {
    .byte_index = 6,
    .bit_index = 7,
    .bit_size = 1,
};

button_index POS_CIRCLE = {
    .byte_index = 6,
    .bit_index = 6,
    .bit_size = 1,
};

button_index POS_CROSS = {
    .byte_index = 6,
    .bit_index = 5,
    .bit_size = 1,
};

button_index POS_SQUARE = {
    .byte_index = 6,
    .bit_index = 4,
    .bit_size = 1,
};

//D-Pad

button_index POS_D_PAD = {
    .byte_index = 6,
    .bit_index = 0,
    .bit_size = 4,
};

//Right and Left buttons

button_index POS_R3 = {
    .byte_index = 7,
    .bit_index = 7,
    .bit_size = 1,
};

button_index POS_L3 = {
    .byte_index = 7,
    .bit_index = 6,
    .bit_size = 1,
};

//Option and Sharing
button_index POS_OPT = {
    .byte_index = 7,
    .bit_index = 5,
    .bit_size = 1,
};

button_index POS_SHARE = {
    .byte_index = 7,
    .bit_index = 4,
    .bit_size = 1,
};

// Back buttons, does not include the adaptive readings of R2 and L2

button_index POS_R2 = {
    .byte_index = 7,
    .bit_index = 3,
    .bit_size = 1,
};

button_index POS_L2 = {
    .byte_index = 7,
    .bit_index = 2,
    .bit_size = 1,
};

button_index POS_R1 = {
    .byte_index = 7,
    .bit_index = 1,
    .bit_size = 1,
};

button_index POS_L1 = {
    .byte_index = 7,
    .bit_index = 0,
    .bit_size = 1,
};

//TOOD Dont now what this counter does

button_index POS_COUNTER = {
    .byte_index = 8,
    .bit_index = 2,
    .bit_size = 6,
};

//TODO Dont know what this button is

button_index POS_T_PAD = {
    .byte_index = 8,
    .bit_index = 1,
    .bit_size = 1,
};

//Playstation button

button_index POS_PS_BUTTON = {
    .byte_index = 8,
    .bit_index = 0,
    .bit_size = 1,
};

//Adaptive Triggers

button_index POS_LEFT_TRIGGER = {
    .byte_index = 9,
    .bit_index = 0,
    .bit_size = 8,
};

button_index POS_RIGHT_TRIGGER = {
    .byte_index = 10,
    .bit_index = 0,
    .bit_size = 8,
};