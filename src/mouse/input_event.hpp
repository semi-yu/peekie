#ifndef __MOUSE_INPUT_EVENT_HPP__
#define __MOUSE_INPUT_EVENT_HPP__

class peekie::mouse::Button;
class peekie::mouse::Action;
class peekie::mouse::Modifier;

namespace peekie::mouse {
    struct InputEvent {
        peekie::mouse::Button button = peekie::mouse::Button::none;
        peekie::mouse::Action action = peekie::mouse::Action::none;
        peekie::mouse::Modifier modifier = peekie::mouse::Modifier::none;

        double cursor_pos_x = 0.0, cursor_pos_y = 0.0;
        double scroll_offset_x = 0.0, scroll_offset_y = 0.0;

        int entered = false;

        bool dragging = false;

        InputEvent();

        InputEvent(const InputEvent& event);

        peekie::mouse::Button get_button() const;

        peekie::mouse::Action get_action() const;

        peekie::mouse::Modifier get_modifier() const;

        double get_cursor_x() const;

        double get_cursor_y() const;

        double get_scroll_offset_x() const;

        double get_scroll_offset_y() const;

        int cursor_over_window() const;

        bool is_dragging() const;

        bool is_pressing(peekie::mouse::Button button) const;

        bool is_releasing(peekie::mouse::Button button) const;

        bool is_dragging(peekie::mouse::Button button) const;
    };
}

#endif