#ifndef __BUTTON_INPUT_EVENT_CPP__
#define __BUTTON_INPUT_EVENT_CPP__

#include "./input_event_flag.cpp"

namespace peekie::mouse {
    struct InputEvent {
        peekie::mouse::Button button;
        peekie::mouse::Action action;
        peekie::mouse::Modifier modifier;

        double cursor_pos_x = 0.0, cursor_pos_y = 0.0;

        InputEvent() {}

        InputEvent(
            const InputEvent& event
        ) {
            button = event.button;
            action = event.action;
            modifier = event.modifier;

            cursor_pos_x = event.cursor_pos_x;
            cursor_pos_y = event.cursor_pos_y;
        }

        peekie::mouse::Button get_button() const { return button; }
        peekie::mouse::Action get_action() const { return action; }
        peekie::mouse::Modifier get_modifier() const { return modifier; }
        double get_cursor_x() const { return cursor_pos_x; }
        double get_cursor_y() const { return cursor_pos_y; }
    };
}

#endif