#ifndef __BUTTON_INPUT_EVENT_FLAG_CPP__
#define __BUTTON_INPUT_EVENT_FLAG_CPP__

#include <unordered_map>
#include <stdexcept>
#include <string>

#include <fmt/core.h>

#include <GLFW/glfw3.h>

namespace peekie::mouse {
    enum class Button {
        left,
        right,
        scroll,
        button4,
        button5,
        button6,
        button7,
        button8
    };

    peekie::mouse::Button get_button_flag(int button) {
        static const std::unordered_map<int, peekie::mouse::Button> button_flag = {
            { 0, peekie::mouse::Button::left },
            { 1, peekie::mouse::Button::right },
            { 2, peekie::mouse::Button::scroll },
            { 3, peekie::mouse::Button::button4 },
            { 4, peekie::mouse::Button::button5 },
            { 5, peekie::mouse::Button::button6 },
            { 6, peekie::mouse::Button::button7 },
            { 7, peekie::mouse::Button::button8 }
        };

        auto result = button_flag.find(button);
        if (result == button_flag.end()) throw std::invalid_argument(fmt::format("wrong button {}\n", button));
        return result->second;
    }

    enum class Action {
        release,
        press,
        repeat,
        unknown
    };

    peekie::mouse::Action get_action_flag(int action) {
        static const std::unordered_map<int, peekie::mouse::Action> action_flag = {
            { 0, peekie::mouse::Action::release },
            { 1, peekie::mouse::Action::press },
            { 2, peekie::mouse::Action::repeat },
            { -1, peekie::mouse::Action::unknown }
        };

        auto result = action_flag.find(action);
        if (result == action_flag.end()) throw std::invalid_argument(fmt::format("wrong action {}\n", action));
        return result->second;
    }

    enum class Modifier {
        none,
        shift,
        control,
        alt,
        super,
        capslock,
        numlock
    };

    peekie::mouse::Modifier get_modifier_flag(int modifier) {
        static const std::unordered_map<int, peekie::mouse::Modifier> modifier_flag = {
            { 0x0000, peekie::mouse::Modifier::none },
            { 0x0001, peekie::mouse::Modifier::shift },
            { 0x0002, peekie::mouse::Modifier::control },
            { 0x0004, peekie::mouse::Modifier::alt },
            { 0x0008, peekie::mouse::Modifier::super },
            { 0x0010, peekie::mouse::Modifier::capslock },
            { 0x0020, peekie::mouse::Modifier::numlock },
        };

        auto result = modifier_flag.find(modifier);
        if (result == modifier_flag.end()) throw std::invalid_argument(fmt::format("wrong modifier {}\n", modifier));
        return result->second;
    }
}

#endif