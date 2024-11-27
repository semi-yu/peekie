/*

 * It senses if an user pressed left or right mouse button.

 */

#include <memory>

#include <GLFW/glfw3.h>
#include <fmt/core.h>
#include <fmt/color.h>

#include "../core/input_handler.cpp"
#include "../mouse/interface_mouse_button_subscriber.cpp"
#include "../mouse/button_input_event.cpp"
#include "../mouse/button_input_event_flag.cpp"

namespace other {
    class Thing : public peekie::mouse::IMouseButtonSubscriber {
    public:
        void act_when_mouse_button_input_event(std::shared_ptr<peekie::mouse::ButtonInputEvent> event) {
            if (event->button == peekie::mouse::Button::left 
                && event->action == peekie::mouse::Action::press)
                fmt::print(bg(fmt::color::yellow), "[input] Mouse left clicked!\n");

            else if (event->button == peekie::mouse::Button::right
                &&event->action == peekie::mouse::Action::press)
                fmt::print(bg(fmt::color::yellow), "[input] Mouse right clicked!\n");
        }
    };
}

int main() {
    fmt::print(bg(fmt::color::green), "Program starts...\n");

    glfwInit();
    GLFWwindow* window = glfwCreateWindow(800, 800, "my input", NULL, NULL);

    glfwMakeContextCurrent(window);

    auto input_handler = peekie::core::InputHandler(window);
    input_handler.set_mouse_button_input_event_handler(window);

    auto object = std::make_shared<other::Thing>();
    input_handler.register_mouse_button_input_event_subscriber(object);
    
    while(!glfwWindowShouldClose(window)) {
        
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    fmt::print(bg(fmt::color::green), "This message ensures normal termination of a process.\n");
    return 0;
}