#include "./input_event_handler.hpp"

void peekie::keyboard::InputEventHandler::button_callback(int key, int scancode, int action, int mods) {
    last_event.button = peekie::keyboard::get_button_flag(key);
    last_event.scancode = peekie::keyboard::get_scancode_flag(scancode);
    last_event.action = peekie::keyboard::get_action_flag(action);
    last_event.modifier = peekie::keyboard::get_modifier_flag(mods);

    auto event = std::make_shared<InputEvent>(last_event);
    for(auto& subscriber: subscribers) {
        subscriber->notify_keyboard_input_event(event);
    }
}

void peekie::keyboard::InputEventHandler::register_subscriber(
    std::shared_ptr<peekie::keyboard::ISubscriber>subscriber
    ) {
    subscribers.push_back(subscriber);
}