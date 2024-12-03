#include "./input_event_flag.hpp"

peekie::mouse::Button peekie::mouse::get_button_flag(int button) {
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
    if (result == button_flag.end()) return peekie::mouse::Button::none;
    return result->second;
}

peekie::mouse::Action peekie::mouse::get_action_flag(int action) {
    static const std::unordered_map<int, peekie::mouse::Action> action_flag = {
        { 0, peekie::mouse::Action::release },
        { 1, peekie::mouse::Action::press },
        { 2, peekie::mouse::Action::repeat },
        { -1, peekie::mouse::Action::unknown }
    };

    auto result = action_flag.find(action);
    if (result == action_flag.end()) return peekie::mouse::Action::none;
    return result->second;
}

peekie::mouse::Modifier peekie::mouse::get_modifier_flag(int modifier) {
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
    if (result == modifier_flag.end()) return peekie::mouse::Modifier::none;
    return result->second;
}