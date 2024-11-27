#ifndef __INTERFACE_MOUSE_BUTTON_SUBSCRIBER_CPP__
#define __INTERFACE_MOUSE_BUTTON_SUBSCRIBER_CPP__

#include <memory>

#include "./button_input_event.cpp"

namespace peekie::mouse {
    class IMouseButtonSubscriber {
    public:
        virtual void act_when_mouse_button_input_event(std::shared_ptr<ButtonInputEvent> event) = 0; 
    };
}

#endif