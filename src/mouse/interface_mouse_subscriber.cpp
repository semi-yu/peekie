#ifndef __INTERFACE_MOUSE_SUBSCRIBER_CPP__
#define __INTERFACE_MOUSE_SUBSCRIBER_CPP__

#include <memory>

#include "./input_event.cpp"

namespace peekie::mouse {
    class ISubscriber {
    public:
        virtual void notify_mouse_input_event(std::shared_ptr<peekie::mouse::InputEvent> event) = 0; 
    };
}

#endif