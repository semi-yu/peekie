#ifndef __MOUSE_INPUT_EVENT_HANDLER_CPP__
#define __MOUSE_INPUT_EVENT_HANDLER_CPP__

#include <vector>
#include <memory>

#include <fmt/core.h>

#include "./input_event.cpp"
#include "./input_event_flag.cpp"
#include "./interface_mouse_subscriber.cpp"

namespace peekie::mouse {
    class InputEventHandler {
        std::vector<std::shared_ptr<peekie::mouse::ISubscriber>> subscribers;

        std::shared_ptr<peekie::mouse::InputEvent> event = std::make_shared<peekie::mouse::InputEvent>();

    public:
        void notify_event() {
            for(auto& subscriber: subscribers) {
                subscriber->notify_mouse_input_event(event);
            }
        }

        void button_callback(int button, int action, int mod) {
            event->button = peekie::mouse::get_button_flag(button);
            event->action = peekie::mouse::get_action_flag(action);
            event->modifier = peekie::mouse::get_modifier_flag(mod);

            if (event->get_action() == peekie::mouse::Action::release) {
                event->dragging = false;
            }

            notify_event();
        }

        void move_callback(double pos_x, double pos_y) {
            event->cursor_pos_x = pos_x;
            event->cursor_pos_y = pos_y;

            if (event->get_action() == peekie::mouse::Action::press) {
                event->dragging = true;
            } else if (event->get_action() == peekie::mouse::Action::release) {
                event->dragging = false;
            }

            notify_event();
        }

        void scroll_callback(double offset_x, double offset_y) {
            event->scroll_offset_x = offset_x;
            event->scroll_offset_y = offset_y;

            notify_event();
        }

        void enter_callback(int entered) {
            event->entered = entered;

            notify_event();
        }

        void register_subscriber(std::shared_ptr<peekie::mouse::ISubscriber> subscriber) {
            subscribers.push_back(subscriber);
        }
    };
}

#endif