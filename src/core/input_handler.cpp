#ifndef __INPUT_HANDLER_CPP__
#define __INPUT_HANDLER_CPP__

#include <memory>

#include <GLFW/glfw3.h>

#include "../mouse/input_event_handler.cpp"
#include "../keyboard/input_event_handler.cpp"

namespace peekie::core {
    class InputHandler {
        GLFWwindow* window;
        std::unique_ptr<peekie::mouse::InputEventHandler> mouse_input_event_handler;
        std::unique_ptr<peekie::keyboard::InputEventHandler> keyboard_input_event_handler;

    public:
        InputHandler(GLFWwindow* window) {
            this->window = window;
            glfwSetWindowUserPointer(window, this);
        }

        void set_mouse_button_input_event_handler(GLFWwindow* listening_window) {
            mouse_button_input_event_handler = std::make_unique<peekie::mouse::ButtonInputEventHandler>();

            auto callback = [](GLFWwindow* window, int button, int action, int mod) {
                auto instance = static_cast<InputHandler*>(glfwGetWindowUserPointer(window));
                if (instance) {
                    instance->mouse_button_input_event_handler->callback(button, action, mod);
                }
            };

            glfwSetInputMode(window, GLFW_STICKY_MOUSE_BUTTONS, GLFW_TRUE);
            glfwSetMouseButtonCallback(window, callback);
        }

        void register_mouse_button_input_event_subscriber(
            std::shared_ptr<peekie::mouse::IMouseButtonSubscriber> subscriber
        ) {
            mouse_button_input_event_handler->register_subscriber(subscriber);
        }

        /*
        void set_mouse_move_input_event_handler(GLFWwindow* listening_window) {
            mouse_move_input_event_handler = std::make_unique<peekie::mouse::MoveInputEventHandler>();

            auto callback = [](GLFWwindow* window, double pos_x, double pos_y) {
                auto instance = static_cast<InputHandler*>(glfwGetWindowUserPointer(window));
                if (instance) {
                    instance->mouse_move_input_event_handler->callback(pos_x, pos_y);
                } 
            }

            glfwSetCursorPosCallback(window, callback);
        }

        void set_keyboard_input_event_handler() {
            auto callback = [](GLFWwindow* window, int key, int scancode, int action, int mods) {
                auto instance = static_cast<InputHandler*>(glfwGetWindowUserPointer(window));
                if (instance) {
                    instance->keyboard_input_event_handler->button_callback(key, scancode, action, mods);
                }
            };

            glfwSetKeyCallback(window, callback);
        }

        void register_mouse_input_event_subscriber(
            std::shared_ptr<peekie::mouse::ISubscriber> subscriber
        ) {
            mouse_input_event_handler->register_subscriber(subscriber);
        }

        void register_keyboard_input_event_subscriber(
            std::shared_ptr<peekie::keyboard::ISubscriber> subscriber
        ) {
            keyboard_input_event_handler->register_subscriber(subscriber);
        }
    };
}

#endif