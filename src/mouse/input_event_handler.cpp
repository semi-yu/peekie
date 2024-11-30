#ifndef __BUTTON_INPUT_EVENT_HANDLER_CPP__
#define __BUTTON_INPUT_EVENT_HANDLER_CPP__

#include <vector>
#include <memory>

#include <fmt/core.h>

#include "./input_event.cpp"
#include "./input_event_flag.cpp"
#include "./interface_mouse_subscriber.cpp"

namespace peekie::mouse {
    class InputEventHandler {
        std::vector<std::shared_ptr<peekie::mouse::ISubscriber>> subscribers;

        std::shared_ptr<peekie::mouse::InputEvent> curr_event = std::make_shared<peekie::mouse::InputEvent>();
        std::shared_ptr<peekie::mouse::InputEvent> last_event = std::make_shared<peekie::mouse::InputEvent>();

    public:
        void notify_event() {
            for(auto& subscriber: subscribers) {
                subscriber->notify_mouse_input_event(curr_event);
            }
            last_event = curr_event;
        }

        void button_callback(int button, int action, int mod) {
            curr_event->button = peekie::mouse::get_button_flag(button);
            curr_event->action = peekie::mouse::get_action_flag(action);
            curr_event->modifier = peekie::mouse::get_modifier_flag(mod);

            if (curr_event->get_action() == peekie::mouse::Action::release) {
                curr_event->dragging = false;
            }

            notify_event();
        }

        void move_callback(double pos_x, double pos_y) {
            curr_event->cursor_pos_x = pos_x;
            curr_event->cursor_pos_y = pos_y;

            if (curr_event->get_action() == peekie::mouse::Action::press) {
                curr_event->dragging = true;
            } else if (curr_event->get_action() == peekie::mouse::Action::release) {
                curr_event->dragging = false;
            }

            notify_event();
        }

        void scroll_callback(double offset_x, double offset_y) {
            curr_event->scroll_offset_x = offset_x;
            curr_event->scroll_offset_y = offset_y;

            notify_event();
        }

        void enter_callback(int entered) {
            curr_event->entered = entered;

            notify_event();
        }

        void register_subscriber(std::shared_ptr<peekie::mouse::ISubscriber> subscriber) {
            subscribers.push_back(subscriber);
        }
    };
}

#endif