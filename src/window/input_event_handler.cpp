#include "./input_event_handler.hpp"

void peekie::window::InputEventHandler::update_last_event() {
    auto event = std::make_shared<peekie::window::InputEvent>(last_event);
    for(auto& subscriber: subscribers) {
        subscriber->notify_window_input_event(event);
    }
}

void peekie::window::InputEventHandler::resize_callback(int width, int height) {
    last_event.width = width;
    last_event.height = height;
    update_last_event();
}

void peekie::window::InputEventHandler::register_subscriber(
    std::shared_ptr<peekie::window::ISubscriber>subscriber
    ) {
    subscribers.push_back(subscriber);
}