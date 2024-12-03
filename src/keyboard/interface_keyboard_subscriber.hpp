#ifndef __INTERFACE_KEYBOARD_SUBSCRIBER_HPP__
#define __INTERFACE_KEYBOARD_SUBSCRIBER_HPP__

#include <memory>

#include "./input_event.hpp"

namespace peekie::keyboard {
    class ISubscriber {
    public:
        virtual void notify_keyboard_input_event(std::shared_ptr<peekie::keyboard::InputEvent> event) = 0; 
    };
}

#endif