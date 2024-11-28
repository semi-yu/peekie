#ifndef __KEYBOARD_INPUT_EVENT_FLAG_CPP__
#define __KEYBOARD_INPUT_EVENT_FLAG_CPP__

namespace peekie::keyboard {
    enum class Button {
        none,
        space,
        apostrophe,
        comma,
        minus,
        period,
        slash,
        number_0,
        number_1,
        number_2,
        number_3,
        number_4,
        number_5,
        number_6,
        number_7,
        number_8,
        number_9,
        semicolon,
        equal,
        a,
        b,
        c,
        d,
        e,
        f,
        g,
        h,
        i,
        j,
        k,
        l,
        m,
        n,
        o,
        p,
        q,
        r,
        s,
        t,
        u,
        v,
        w,
        x,
        y,
        z,
        left_bracket, // [
        backslash,
        right_bracket, // ]
        grave_accent, // `
        world_1, //
        world_2, //
        escape,
        enter,
        tab,
        backspace,
        insert,
        deletee,
        right,
        left,
        down,
        up,
        page_up,
        page_down,
        home,
        end,
        caps_lock,
        scroll_lock,
        num_lock,
        print_screen,
        pause,
        f1,
        f2,
        f3,
        f4,
        f5,
        f6,
        f7,
        f8,
        f9,
        f10,
        f11,
        f12
    };

    peekie::keyboard::Button get_button_flag(int button) {
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

    enum class Scancode {
        none
    };

    peekie::keyboard::Scancode get_scancode_flag(int scancode) {
        return peekie::keyboard::Scancode::none;
    }

    enum class Action {
        none,
        release,
        press,
        repeat,
        unknown
    };

    peekie::keyboard::Action get_action_flag(int action) {
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

    enum class Modifier {
        none,
        shift,
        control,
        alt,
        super,
        capslock,
        numlock
    };

    peekie::keyboard::Modifier get_modifier_flag(int modifier) {
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
}

#endif