#ifndef __INPUT_HANDLER_HPP__
#define __INPUT_HANDLER_HPP__

#include <memory>

#include <GLFW/glfw3.h>

#include "../mouse/input_event_handler.hpp"
#include "../keyboard/input_event_handler.hpp"
#include "../window/input_event_handler.hpp"

namespace peekie::core {
    class InputHandler {
        GLFWwindow* window;

        std::unique_ptr<peekie::mouse::InputEventHandler> mouse_input_event_handler;
        std::unique_ptr<peekie::keyboard::InputEventHandler> keyboard_input_event_handler;
        std::unique_ptr<peekie::window::InputEventHandler> window_input_event_handler;

    public:
        InputHandler(GLFWwindow* window);

        void set_mouse_button_input_event_handler();

        void set_mouse_move_input_event_hanlder();

        void set_mouse_scroll_input_event_handler();

        void set_mouse_window_enter_input_event_handler();

        void set_keyboard_input_event_handler();

        void set_window_input_event_handler();

        void register_mouse_input_event_subscriber(
            std::shared_ptr<peekie::mouse::ISubscriber> subscriber
        );

        void register_keyboard_input_event_subscriber(
            std::shared_ptr<peekie::keyboard::ISubscriber> subscriber
        );

        void register_window_input_event_subscriber(
            std::shared_ptr<peekie::window::ISubscriber> subscriber
        );
    };
}

#endif