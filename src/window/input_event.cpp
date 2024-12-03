#include "./input_event.hpp"

peekie::window::InputEvent::InputEvent() {}

peekie::window::InputEvent::InputEvent(const peekie::window::InputEvent& event) {
    width = event.width;
    height = event.height;
}

int peekie::window::InputEvent::get_width() const { return width; }

int peekie::window::InputEvent::get_height() const { return height; }