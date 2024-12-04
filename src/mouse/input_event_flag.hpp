#ifndef __MOUSE_INPUT_EVENT_FLAG_HPP__
#define __MOUSE_INPUT_EVENT_FLAG_HPP__

#include <unordered_map>

namespace peekie::mouse {
    enum class Button {
        none,
        left,
        right,
        scroll,
        button4,
        button5,
        button6,
        button7,
        button8
    };

    enum class Action {
        none,
        release,
        press,
        repeat,
        unknown
    };

    enum class Modifier {
        none,
        shift,
        control,
        alt,
        super,
        capslock,
        numlock
    };

    peekie::mouse::Button get_button_flag(int button);
    peekie::mouse::Action get_action_flag(int action);
    peekie::mouse::Modifier get_modifier_flag(int modifier);
}

#endif