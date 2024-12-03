#ifndef __WINDOW_INPUT_EVENT_HPP__
#define __WINDOW_INPUT_EVENT_HPP__

namespace peekie::window {
    struct InputEvent {
        int width, height;

        InputEvent();

        InputEvent(const peekie::window::InputEvent& event);

        int get_width() const;
        int get_height() const;
    };
}

#endif