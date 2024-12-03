#ifndef __KEYBOARD_INPUT_EVENT_HANDLER_HPP__
#define __KEYBOARD_INPUT_EVENT_HANDLER_HPP__

#include <vector>
#include <memory>

#include <GLFW/glfw3.h>

#include <fmt/core.h>

#include "./input_event.hpp"
#include "./interface_keyboard_subscriber.hpp"

namespace peekie::keyboard {
    class InputEventHandler {
        std::vector<std::shared_ptr<peekie::keyboard::ISubscriber>> subscribers;

        peekie::keyboard::InputEvent last_event;

    public:
        void button_callback(int key, int scancode, int action, int mods);

        void register_subscriber(std::shared_ptr<peekie::keyboard::ISubscriber> subscriber);
    };
}

#endif