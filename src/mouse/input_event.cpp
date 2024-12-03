#include "./input_event.hpp"

peekie::mouse::InputEvent::InputEvent() {}

peekie::mouse::InputEvent::InputEvent(
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

peekie::mouse::Button peekie::mouse::InputEvent::get_button() const { return button; }

peekie::mouse::Action peekie::mouse::InputEvent::get_action() const { return action; }

peekie::mouse::Modifier peekie::mouse::InputEvent::get_modifier() const { return modifier; }

double peekie::mouse::InputEvent::get_cursor_x() const { return cursor_pos_x; }

double peekie::mouse::InputEvent::get_cursor_y() const { return cursor_pos_y; }

double peekie::mouse::InputEvent::get_scroll_offset_x() const { return scroll_offset_x; }

double peekie::mouse::InputEvent::get_scroll_offset_y() const { return scroll_offset_y; }

int peekie::mouse::InputEvent::cursor_over_window() const { return entered; }

bool peekie::mouse::InputEvent::is_dragging() const { return dragging; }

bool peekie::mouse::InputEvent::is_pressing(peekie::mouse::Button button) const {
    return get_action() == peekie::mouse::Action::press
    && get_button() == button; 
}

bool peekie::mouse::InputEvent::is_releasing(peekie::mouse::Button button) const {
    return get_action() == peekie::mouse::Action::release
    && get_button() == button;
}

bool peekie::mouse::InputEvent::is_dragging(peekie::mouse::Button button) const {
    return get_button() == button && dragging;
}