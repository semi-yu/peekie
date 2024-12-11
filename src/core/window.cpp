#include "window.hpp"

peekie::Window::Window() {
    
}

peekie::Window::~Window() {
    for (auto& name: window_names) {
        auto window = windows.find(name);
        glfwDestoryWindow(window);
    }
}

void peekie::Window::initilaize_context() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    // For macos compatability:
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
}

void peekie::Window::create_window(
    std::string name, 
    int width, int height, 
    std::string title) {
    window_names.push_back(name);
    
    windows.insert({ name, glfwCreateWindow(width, height, title, NULL, NULL); });
}

void peekie::Window::application_looping() {
    while (keep_loop()) {
        
        glfwPollEvents();
        glfwSwapBuffers();
    }
}

bool peekie::Window::keep_loop() {
    return !glfwWindowShouldClose();
}

virtual void main_loop() {
    return;
}