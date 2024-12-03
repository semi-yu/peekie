#include "./input_event_handler.hpp"

void peekie::mouse::InputEventHandler::notify_event() {
    for(auto& subscriber: subscribers) {
        subscriber->notify_mouse_input_event(event);
    }
}

void peekie::mouse::InputEventHandler::button_callback(int button, int action, int mod) {
    event->button = peekie::mouse::get_button_flag(button);
    event->action = peekie::mouse::get_action_flag(action);
    event->modifier = peekie::mouse::get_modifier_flag(mod);
    if (event->get_action() == peekie::mouse::Action::release) {
        event->dragging = false;
    }
    notify_event();
}

void peekie::mouse::InputEventHandler::move_callback(double pos_x, double pos_y) {
    event->cursor_pos_x = pos_x;
    event->cursor_pos_y = pos_y;
    if (event->get_action() == peekie::mouse::Action::press) {
        event->dragging = true;
    } else if (event->get_action() == peekie::mouse::Action::release) {
        event->dragging = false;
    }
    notify_event();
}

void peekie::mouse::InputEventHandler::scroll_callback(double offset_x, double offset_y) {
    event->scroll_offset_x = offset_x;
    event->scroll_offset_y = offset_y;
    notify_event();
}

void peekie::mouse::InputEventHandler::enter_callback(int entered) {
    event->entered = entered;
    notify_event();
}

void peekie::mouse::InputEventHandler::register_subscriber(
    std::shared_ptr<peekie::mouse::ISubscriber> subscriber
    ) {
    subscribers.push_back(subscriber);
}