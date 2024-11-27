#ifndef __BUTTON_INPUT_EVENT_CPP__
#define __BUTTON_INPUT_EVENT_CPP__

#include "./button_input_event_flag.cpp"

namespace peekie::mouse {
    struct ButtonInputEvent {
        peekie::mouse::Button button;
        peekie::mouse::Action action;
        peekie::mouse::Modifier modifier;

        ButtonInputEvent(
            int button,
            int action,
            int modifier
        ) {
            this->button = peekie::mouse::get_button_flag(button);
            this->action = peekie::mouse::get_action_flag(action);
            this->modifier = peekie::mouse::get_modifier_flag(modifier);
        }
    };
}

#endif