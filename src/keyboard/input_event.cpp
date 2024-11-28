#ifndef __KEYBOARD_INPUT_EVENT_CPP__
#define __KEYBOARD_INPUT_EVENT_CPP__

#include "./input_event_flag.cpp"

namespace peekie::keyboard {
    struct InputEvent {
        peekie::keyboard::Button button;
        peekie::keyboard::Scancode scancode;
        peekie::keyboard::Action action;
        peekie::keyboard::Modifier modifier;

        InputEvent() {}

        InputEvent(
            const InputEvent& event
        ) {
            this->button = event.button;
            this->scancode = event.scancode;
            this->action = event.action;
            this->modifier = event.modifier;
        }

        peekie::keyboard::Button get_button() const { return button; }
        peekie::keyboard::Scancode get_scancode() const { return scancode; }
        peekie::keyboard::Action get_action() const { return action; }
        peekie::keyboard::Modifier get_modifier() const { return modifier; }
    };
}

#endif