#ifndef __INTERFACE_WINDOW_SUBSCRIBER_CPP__
#define __INTERFACE_WINDOW_SUBSCRIBER_CPP__

#include <memory>

#include "./input_event.cpp"

namespace peekie::window {
    class ISubscriber {
    public:
        virtual void notify_window_input_event(std::shared_ptr<peekie::window::InputEvent> event) = 0; 
    };
}

#endif