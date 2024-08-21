#include <stdbool.h>
#include <stdint.h>

struct controller_report {
    // Buttons
    bool up_button;
    bool down_button;
    bool left_button; 
    bool right_button;

    // D-Pad
    bool d_pad_up;
    bool d_pad_down;
    bool d_pad_left;
    bool da_pad_right;

    // Triggers
    uint8_t right_trigger;
    uint8_t left_trigger;
    
    // Shoulder Button
    bool left_shoulder;
    bool right_shoulder;
    
    // Sticks
    uint8_t left_stick;
    uint8_t right_stick;
};