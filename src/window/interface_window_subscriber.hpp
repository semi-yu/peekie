#ifndef __INTERFACE_WINDOW_SUBSCRIBER_HPP__
#define __INTERFACE_WINDOW_SUBSCRIBER_HPP__

#include <memory>

#include "./input_event.hpp"

namespace peekie::window {
    class ISubscriber {
    public:
        virtual void notify_window_input_event(std::shared_ptr<peekie::window::InputEvent> event) = 0; 
    };
}

#endif