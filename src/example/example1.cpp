/*

 * It senses if an user pressed left or right mouse button.

 */

#include <memory>

#include <GLFW/glfw3.h>
#include <fmt/core.h>
#include <fmt/color.h>

#include "../core/input_handler.cpp"
#include "../mouse/interface_mouse_subscriber.cpp"
#include "../keyboard/interface_keyboard_subscriber.cpp"
#include "../window/interface_window_subscriber.cpp"

namespace other {
    class Thing
    : public peekie::mouse::ISubscriber,
      public peekie::keyboard::ISubscriber,
      public peekie::window::ISubscriber {
    public:
        void notify_mouse_input_event(std::shared_ptr<peekie::mouse::InputEvent> event) {
            if (event->cursor_over_window()) {
                fmt::print(bg(fmt::color::yellow), "[input] Mouse cursor enterd!\n");
            }

            fmt::print(bg(fmt::color::yellow), "[input] Mouse moved at {} {}!\n", event->cursor_pos_x, event->cursor_pos_y);
            fmt::print(bg(fmt::color::yellow), "[input] Mouse scrolled at {} {}\n", event->get_scroll_offset_x(), event->get_scroll_offset_y());

            if (event->button == peekie::mouse::Button::left 
                && event->action == peekie::mouse::Action::press)
                fmt::print(bg(fmt::color::yellow), "[input] Mouse left clicked!\n");

            else if (event->button == peekie::mouse::Button::right
                &&event->action == peekie::mouse::Action::press)
                fmt::print(bg(fmt::color::yellow), "[input] Mouse right clicked!\n");

            else if (event->button == peekie::mouse::Button::scroll
                &&event->action == peekie::mouse::Action::press)
                fmt::print(bg(fmt::color::yellow), "[input] Mouse scroll clicked!\n");
        }

        void notify_keyboard_input_event(std::shared_ptr<peekie::keyboard::InputEvent> event) {
            if (event->get_button() == peekie::keyboard::Button::a
                && event->get_action() == peekie::keyboard::Action::press) {
                fmt::print(bg(fmt::color::yellow), "[input] Key a pressed!\n");
            }
            else if (event->get_button() == peekie::keyboard::Button::a
                && event->get_action() == peekie::keyboard::Action::release) {
                fmt::print(bg(fmt::color::yellow), "[input] key a released!\n");
            }
        }

        void notify_window_input_event(std::shared_ptr<peekie::window::InputEvent> event) {
            fmt::print(bg(fmt::color::yellow), "[window] window resized to {} {}\n", event->get_width(), event->get_height());
        }
    };
}

int main() {
    fmt::print(bg(fmt::color::green), "Program starts...\n");

    glfwInit();
    GLFWwindow* window = glfwCreateWindow(800, 800, "my input", NULL, NULL);

    glfwMakeContextCurrent(window);

    auto input_handler = peekie::core::InputHandler(window);

    auto object = std::make_shared<other::Thing>();
    input_handler.register_mouse_input_event_subscriber(object);
    input_handler.register_keyboard_input_event_subscriber(object);
    input_handler.register_window_input_event_subscriber(object);

    while(!glfwWindowShouldClose(window)) {
        
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    fmt::print(bg(fmt::color::green), "This message ensures normal termination of a process.\n");
    return 0;
}