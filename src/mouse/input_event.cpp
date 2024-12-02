#ifndef __MOUSE_INPUT_EVENT_CPP__
#define __MOUSE_INPUT_EVENT_CPP__

#include "./input_event_flag.cpp"

namespace peekie::mouse {
    struct InputEvent {
        peekie::mouse::Button button = peekie::mouse::Button::none;
        peekie::mouse::Action action = peekie::mouse::Action::none;
        peekie::mouse::Modifier modifier = peekie::mouse::Modifier::none;

        double cursor_pos_x = 0.0, cursor_pos_y = 0.0;
        double scroll_offset_x = 0.0, scroll_offset_y = 0.0;

        int entered = false;

        bool dragging = false;

        InputEvent() {}

        InputEvent(
            const InputEvent& event
        ) {
            button = event.button;
            action = event.action;
            modifier = event.modifier;

            cursor_pos_x = event.cursor_pos_x;
            cursor_pos_y = event.cursor_pos_y;

            scroll_offset_x = event.scroll_offset_x;
            scroll_offset_y = event.scroll_offset_y;

            entered = event.entered;

            dragging = event.dragging;
        }

        peekie::mouse::Button get_button() const { return button; }

        peekie::mouse::Action get_action() const { return action; }

        peekie::mouse::Modifier get_modifier() const { return modifier; }

        double get_cursor_x() const { return cursor_pos_x; }

        double get_cursor_y() const { return cursor_pos_y; }

        double get_scroll_offset_x() const { return scroll_offset_x; }

        double get_scroll_offset_y() const { return scroll_offset_y; }

        int cursor_over_window() const { return entered; }

        bool is_dragging() const { return dragging; }

        bool is_pressing(peekie::mouse::Button button) const {
            return get_action() == peekie::mouse::Action::press
            && get_button() == button; 
        }

        bool is_releasing(peekie::mouse::Button button) const {
            return get_action() == peekie::mouse::Action::release
            && get_button == button;
        }

        bool is_dragging(peekie::mouse::Button button) const {
            return get_button() == button && dragging;
        }
    };
}

#endif