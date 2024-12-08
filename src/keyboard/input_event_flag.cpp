#include "./input_event_flag.hpp"

/**
 * @details GLFW 키보드 이벤트의 버튼 플래그를 peekie 버튼 플래그로 변환합니다. 
 * @param[in] button GLFW의 키보드 이벤트의 버튼 플래그
 * @warning 알수 없는 키의 경우에는 peekie::keyboard::Button::none을 반환합니다.
 * @return peekie::keyboard::Button
 */
peekie::keyboard::Button peekie::keyboard::get_button_flag(int button) {
    static const std::unordered_map<int, peekie::keyboard::Button> button_flag = {
        { 32, peekie::keyboard::Button::space },
        { 39, peekie::keyboard::Button::apostrophe },
        { 44, peekie::keyboard::Button::comma },
        { 45, peekie::keyboard::Button::minus },
        { 46, peekie::keyboard::Button::period },
        { 47, peekie::keyboard::Button::slash },
        { 48, peekie::keyboard::Button::number_0 },
        { 49, peekie::keyboard::Button::number_1 },
        { 50, peekie::keyboard::Button::number_2 },
        { 51, peekie::keyboard::Button::number_3 },
        { 52, peekie::keyboard::Button::number_4 },
        { 53, peekie::keyboard::Button::number_5 },
        { 54, peekie::keyboard::Button::number_6 },
        { 55, peekie::keyboard::Button::number_7 },
        { 56, peekie::keyboard::Button::number_8 },
        { 57, peekie::keyboard::Button::number_9 },
        { 59, peekie::keyboard::Button::semicolon },
        { 61, peekie::keyboard::Button::equal },
        { 65, peekie::keyboard::Button::a },
        { 66, peekie::keyboard::Button::b },
        { 67, peekie::keyboard::Button::c },
        { 68, peekie::keyboard::Button::d },
        { 69, peekie::keyboard::Button::e },
        { 70, peekie::keyboard::Button::f },
        { 71, peekie::keyboard::Button::g },
        { 72, peekie::keyboard::Button::h },
        { 73, peekie::keyboard::Button::i },
        { 74, peekie::keyboard::Button::j },
        { 75, peekie::keyboard::Button::k },
        { 76, peekie::keyboard::Button::l },
        { 77, peekie::keyboard::Button::m },
        { 78, peekie::keyboard::Button::n },
        { 79, peekie::keyboard::Button::o },
        { 80, peekie::keyboard::Button::p },
        { 81, peekie::keyboard::Button::q },
        { 82, peekie::keyboard::Button::r },
        { 83, peekie::keyboard::Button::s },
        { 84, peekie::keyboard::Button::t },
        { 85, peekie::keyboard::Button::u },
        { 86, peekie::keyboard::Button::v },
        { 87, peekie::keyboard::Button::w },
        { 88, peekie::keyboard::Button::x },
        { 89, peekie::keyboard::Button::y },
        { 90, peekie::keyboard::Button::z },
        { 91, peekie::keyboard::Button::left_bracket },
        { 92, peekie::keyboard::Button::backslash },
        { 93, peekie::keyboard::Button::right_bracket },
        { 96, peekie::keyboard::Button::grave_accent },
        { 161, peekie::keyboard::Button::world_1 },
        { 162, peekie::keyboard::Button::world_2 },
        { 256, peekie::keyboard::Button::escape },
        { 257, peekie::keyboard::Button::enter },
        { 258, peekie::keyboard::Button::tab },
        { 259, peekie::keyboard::Button::backspace },
        { 260, peekie::keyboard::Button::insert },
        { 261, peekie::keyboard::Button::deletee },
        { 262, peekie::keyboard::Button::right },
        { 263, peekie::keyboard::Button::left },
        { 264, peekie::keyboard::Button::down },
        { 265, peekie::keyboard::Button::up },
        { 266, peekie::keyboard::Button::page_up },
        { 267, peekie::keyboard::Button::page_down },
        { 268, peekie::keyboard::Button::home },
        { 269, peekie::keyboard::Button::end },
        { 280, peekie::keyboard::Button::caps_lock },
        { 281, peekie::keyboard::Button::scroll_lock },
        { 282, peekie::keyboard::Button::num_lock },
        { 283, peekie::keyboard::Button::print_screen },
        { 284, peekie::keyboard::Button::pause },
        { 290, peekie::keyboard::Button::f1 },
        { 291, peekie::keyboard::Button::f2 },
        { 292, peekie::keyboard::Button::f3 },
        { 293, peekie::keyboard::Button::f4 },
        { 294, peekie::keyboard::Button::f5 },
        { 295, peekie::keyboard::Button::f6 },
        { 296, peekie::keyboard::Button::f7 },
        { 297, peekie::keyboard::Button::f8 },
        { 298, peekie::keyboard::Button::f9 },
        { 299, peekie::keyboard::Button::f10 },
        { 300, peekie::keyboard::Button::f11 },
        { 301, peekie::keyboard::Button::f12 }
    };

    auto result = button_flag.find(button);
    if (result == button_flag.end()) return peekie::keyboard::Button::none;
    return result->second;
}

/**
 * @details GLFW 키보드 이벤트의 스캔코드 플래그를 peekie 버튼 플래그로 변환합니다. 
 * @param[in] scancode GLFW의 키보드 이벤트의 스캔코드 플래그
 * @return peekie::keyboard::Scancode
 * @warning 현재 라이브러리는 scancode의 none만 반환하도록 하고있습니다. 이는 차후 변경됩니다.
 * @todo Scancode를 도입합니다. 
 */
peekie::keyboard::Scancode peekie::keyboard::get_scancode_flag(int scancode) {
    return peekie::keyboard::Scancode::none;
}

/**
 * @details GLFW 키보드 이벤트의 액션 플래그를 peekie 액션 플래그로 변환합니다.
 * @param[in] action GLFW 키보드 이벤트의 액션 플래그
 * @return peekie::keyboard::Action
 * @warning 알수 없는 키의 경우에는 peekie::keyboard::Action::none을 반환합니다.
 */
peekie::keyboard::Action peekie::keyboard::get_action_flag(int action) {
    static const std::unordered_map<int, peekie::keyboard::Action> action_flag = {
        { 0, peekie::keyboard::Action::release },
        { 1, peekie::keyboard::Action::press },
        { 2, peekie::keyboard::Action::repeat },
        { -1, peekie::keyboard::Action::unknown }
    };

    auto result = action_flag.find(action);
    if (result == action_flag.end()) return peekie::keyboard::Action::none;
    return result->second;
}

/**
 * @details GLFW 키보드 이벤트의 모디파이어 플래그를 peekie 모디파이어 플래그로 변환합니다.
 * @param[in] action GLFW 키보드 이벤트의 모디파이어 플래그
 * @return peekie::keyboard::Modifier
 * @warning 알수 없는 키의 경우에는 peekie::keyboard::Modifier::none을 반환합니다. Modifier란 shift, control, alt 등의 조합키를 의미합니다.
 */
peekie::keyboard::Modifier peekie::keyboard::get_modifier_flag(int modifier) {
    static const std::unordered_map<int, peekie::keyboard::Modifier> modifier_flag = {
        { 0x0000, peekie::keyboard::Modifier::none },
        { 0x0001, peekie::keyboard::Modifier::shift },
        { 0x0002, peekie::keyboard::Modifier::control },
        { 0x0004, peekie::keyboard::Modifier::alt },
        { 0x0008, peekie::keyboard::Modifier::super },
        { 0x0010, peekie::keyboard::Modifier::capslock },
        { 0x0020, peekie::keyboard::Modifier::numlock },
    };

    auto result = modifier_flag.find(modifier);
    if (result == modifier_flag.end()) return peekie::keyboard::Modifier::none;
    return result->second;
}