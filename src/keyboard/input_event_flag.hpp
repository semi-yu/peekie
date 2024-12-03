#ifndef __KEYBOARD_INPUT_EVENT_FLAG_HPP__
#define __KEYBOARD_INPUT_EVENT_FLAG_HPP__

#include <unordered_map>
#include <string>

#include <fmt/core.h>

#include <GLFW/glfw3.h>

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

    enum class Scancode {
        none
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

    peekie::keyboard::Button get_button_flag(int button);
    peekie::keyboard::Scancode get_scancode_flag(int scancode);
    peekie::keyboard::Action get_action_flag(int action);
    peekie::keyboard::Modifier get_modifier_flag(int modifier);
}

#endif