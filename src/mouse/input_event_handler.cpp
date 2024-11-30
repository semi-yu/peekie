#ifndef __BUTTON_INPUT_EVENT_HANDLER_CPP__
#define __BUTTON_INPUT_EVENT_HANDLER_CPP__

#include <vector>
#include <memory>

#include <GLFW/glfw3.h>

#include <fmt/core.h>

#include "./input_event.cpp"
#include "./interface_mouse_subscriber.cpp"

namespace peekie::mouse {
    class InputEventHandler {
        std::vector<std::shared_ptr<peekie::mouse::ISubscriber>> subscribers;

        peekie::mouse::InputEvent last_event;

    public:
        void notify_event() {
            auto event = std::make_shared<peekie::mouse::InputEvent>(last_event);

            for(auto& subscriber: subscribers) {
                subscriber->notify_mouse_input_event(event);
            }
        }

        void button_callback(int button, int action, int mod) {
            last_event.button = peekie::mouse::get_button_flag(button);
            last_event.action = peekie::mouse::get_action_flag(action);
            last_event.modifier = peekie::mouse::get_modifier_flag(mod);

            notify_event();
        }

        void move_callback(double pos_x, double pos_y) {
            last_event.cursor_pos_x = pos_x;
            last_event.cursor_pos_y = pos_y;

            notify_event();
        }

        void scroll_callback(double offset_x, double offset_y) {
            last_event.scroll_offset_x = offset_x;
            last_event.scroll_offset_y = offset_y;

            notify_event();
        }

        void enter_callback(int entered) {
            last_event.entered = entered;

            notify_event();
        }

        void register_subscriber(std::shared_ptr<peekie::mouse::ISubscriber> subscriber) {
            subscribers.push_back(subscriber);
        }
    };
}

#endif