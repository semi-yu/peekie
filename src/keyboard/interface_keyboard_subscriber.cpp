#ifndef __INTERFACE_KEYBOARD_SUBSCRIBER_CPP__
#define __INTERFACE_KEYBOARD_SUBSCRIBER_CPP__

#include <memory>

#include "./input_event.cpp"

namespace peekie::keyboard {
    class ISubscriber {
    public:
        virtual void notify_keyboard_input_event(std::shared_ptr<peekie::keyboard::InputEvent> event) = 0; 
    };
}

#endif