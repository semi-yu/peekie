#ifndef __WINDOW_INPUT_EVENT_HANDLER_HPP__
#define __WINDOW_INPUT_EVENT_HANDLER_HPP__

#include <vector>

#include <GLFW/glfw3.h>

#include "./input_event.hpp"
#include "./interface_window_subscriber.hpp"

namespace peekie::window {
    class InputEventHandler {
        std::vector<std::shared_ptr<peekie::window::ISubscriber>> subscribers;

        peekie::window::InputEvent last_event;
    public:
        void update_last_event();

        void resize_callback(int width, int height);

        void register_subscriber(std::shared_ptr<peekie::window::ISubscriber> subscriber);
    };
}

#endif