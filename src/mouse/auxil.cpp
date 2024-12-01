#include "./input_event.cpp"

#include <memory>

namespace peekie::mouse {
    bool is_cursor_staying(
        std::shared_ptr<peekie::mouse::InputEvent> origin, 
        std::shared_ptr<peekie::mouse::InputEvent> target) {
        return origin->get_cursor_x() == target->get_cursor_y() 
        && origin->get_cursor_y() == target->get_cursor_y();
    }
}