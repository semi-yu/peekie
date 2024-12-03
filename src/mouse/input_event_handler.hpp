#ifndef __MOUSE_INPUT_EVENT_HANDLER_HPP__
#define __MOUSE_INPUT_EVENT_HANDLER_HPP__

#include <vector>
#include <memory>

#include <fmt/core.h>

class peekie::mouse::ISubscriber;
class peekie::mouse::InputEvent;

namespace peekie::mouse {
    class InputEventHandler {
        std::vector<std::shared_ptr<peekie::mouse::ISubscriber>> subscribers;

        std::shared_ptr<peekie::mouse::InputEvent> event = std::make_shared<peekie::mouse::InputEvent>();

    public:
        void notify_event();

        void button_callback(int button, int action, int mod);

        void move_callback(double pos_x, double pos_y);

        void scroll_callback(double offset_x, double offset_y);

        void enter_callback(int entered);

        void register_subscriber(std::shared_ptr<peekie::mouse::ISubscriber> subscriber);
    };
}

#endif