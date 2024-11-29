#ifndef __WINDOW_INPUT_EVENT_CPP__
#define __WINDOW_INPUT_EVENT_CPP__

namespace peekie::window {
    struct InputEvent {
        int width, height;

        InputEvent() {}

        InputEvent(const peekie::window::InputEvent& event) {
            width = event.width;
            height = event.height;
        }

        int get_width() const { return width; }
        int get_height() const { return height; }
    };
}

#endif