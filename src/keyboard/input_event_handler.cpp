#ifndef __KEYBOARD_INPUT_EVENT_HANDLER_CPP__
#define __KEYBOARD_INPUT_EVENT_HANDLER_CPP__

#include <vector>
#include <memory>

#include <GLFW/glfw3.h>

#include <fmt/core.h>

#include "./input_event.cpp"
#include "./interface_keyboard_subscriber.cpp"

namespace peekie::keyboard {
    class InputEventHandler {
        std::vector<std::shared_ptr<peekie::keyboard::ISubscriber>> subscribers;

        peekie::keyboard::InputEvent last_event;
        
    public:
        void button_callback(int key, int scancode, int action, int mods) {
            last_event.button = peekie::keyboard::get_button_flag(key);
            last_event.scancode = peekie::keyboard::get_scancode_flag(scancode);
            last_event.action = peekie::keyboard::get_action_flag(action);
            last_event.modifier = peekie::keyboard::get_modifier_flag(mods);

            auto event = std::make_shared<InputEvent>(last_event);

            for(auto& subscriber: subscribers) {
                subscriber->notify_keyboard_input_event(event);
            }
        }

        void register_subscriber(std::shared_ptr<peekie::keyboard::ISubscriber> subscriber) {
            subscribers.push_back(subscriber);
        }
    };
}

#endif