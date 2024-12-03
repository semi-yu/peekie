#ifndef __INTERFACE_MOUSE_SUBSCRIBER_HPP__
#define __INTERFACE_MOUSE_SUBSCRIBER_HPP__

#include <memory>

class peekie::mouse::InputEvent;

namespace peekie::mouse {
    class ISubscriber {
    public:
        virtual void notify_mouse_input_event(std::shared_ptr<peekie::mouse::InputEvent> event) = 0; 
    };
}

#endif