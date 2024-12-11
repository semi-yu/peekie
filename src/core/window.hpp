#ifndef __PEEKIE_WINDOW_HPP__
#define __PEEKIE_WINDOW_HPP__

#include <string>
#include <vector>
#include <unordered_map>

#include <GLFW/glfw3.h>

namespace peekie {
    class Window {
        std::vector<std::string> window_names;
        std::unordered_map<std::string, GLFWwindow*> windows;

        int width, height;
        std::string title;

    public:
        Window();

        ~Window();
        
    protected:
        void initilaize_context();

        void create_window(std::string name, int width, int height, std::string title);

        void application_loop();
    };
}

#endif