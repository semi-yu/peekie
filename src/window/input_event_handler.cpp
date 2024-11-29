#ifndef __WINDOW_INPUT_EVENT_HANDLER_CPP__
#define __WINDOW_INPUT_EVENT_HANDLER_CPP__

#include <vector>

#include <GLFW/glfw3.h>

#include "./input_event.cpp"
#include "./interface_window_subscriber.cpp"

namespace peekie::window {
    class InputEventHandler {
        std::vector<std::shared_ptr<peekie::window::ISubscriber>> subscribers;

        peekie::window::InputEvent last_event;
    public:
        void update_last_event() {
            auto event = std::make_shared<peekie::window::InputEvent>(last_event);

            for(auto& subscriber: subscribers) {
                subscriber->notify_window_input_event(event);
            }
        }

        void resize_callback(int width, int height) {
            last_event.width = width;
            last_event.height = height;

            update_last_event();
        }

        void register_subscriber(std::shared_ptr<peekie::window::ISubscriber> subscriber) {
            subscribers.push_back(subscriber);
        }
    };
}

#endif