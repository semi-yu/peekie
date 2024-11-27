#ifndef __BUTTON_INPUT_EVENT_HANDLER_CPP__
#define __BUTTON_INPUT_EVENT_HANDLER_CPP__

#include <vector>
#include <memory>

#include <GLFW/glfw3.h>

#include <fmt/core.h>

#include "./button_input_event.cpp"
#include "./interface_mouse_button_subscriber.cpp"

namespace peekie::mouse {
    class ButtonInputEventHandler {
        std::vector<std::shared_ptr<peekie::mouse::IMouseButtonSubscriber>> subscribers;
        
    public:
        void callback(int button, int action, int mod) {            
            auto event = std::make_shared<ButtonInputEvent>(button, action, mod);

            for(auto& subscriber: subscribers) {
                subscriber->act_when_mouse_button_input_event(event);
            }
        }

        void register_subscriber(std::shared_ptr<peekie::mouse::IMouseButtonSubscriber> subscriber) {
            subscribers.push_back(subscriber);
        }
    };
}

#endif