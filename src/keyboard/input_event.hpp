#ifndef __KEYBOARD_INPUT_EVENT_HPP__
#define __KEYBOARD_INPUT_EVENT_HPP__

#include "./input_event_flag.hpp"

namespace peekie::keyboard {
    struct InputEvent {
        peekie::keyboard::Button button;
        peekie::keyboard::Scancode scancode;
        peekie::keyboard::Action action;
        peekie::keyboard::Modifier modifier;

        InputEvent();

        InputEvent(const InputEvent& event);

        peekie::keyboard::Button get_button() const;

        peekie::keyboard::Scancode get_scancode() const;

        peekie::keyboard::Action get_action() const;

        peekie::keyboard::Modifier get_modifier() const;
    };
}

#endif