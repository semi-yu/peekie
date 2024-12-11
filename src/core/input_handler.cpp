#include "./input_handler.hpp"

/**
 * @details 인풋 핸들러를 초기화합니다.
 * @param[in] window GLFWwindow 포인터 객체.
 * @warning  glfwCreateWindow()가 정상적으로 되어야 함. 정상 생성 여부를 확인하지 않습니다.
 */
peekie::core::InputHandler::InputHandler(GLFWwindow* window) {
    this->window = window;
    glfwSetWindowUserPointer(window, this);

    mouse_input_event_handler = std::make_unique<peekie::mouse::InputEventHandler>();
    keyboard_input_event_handler = std::make_unique<peekie::keyboard::InputEventHandler>();
    window_input_event_handler = std::make_unique<peekie::window::InputEventHandler>();

    set_mouse_button_input_event_handler();
    set_mouse_move_input_event_hanlder();
    set_mouse_scroll_input_event_handler();
    set_mouse_window_enter_input_event_handler();
    set_keyboard_input_event_handler();
    set_window_input_event_handler();
}

/**
 * @details 마우스 버튼 이벤트에 대한 콜백 함수를 등록합니다.
 * @return void
 */
void peekie::core::InputHandler::set_mouse_button_input_event_handler() {
    auto callback = [](GLFWwindow* window, int button, int action, int mod) {
        auto instance = static_cast<InputHandler*>(glfwGetWindowUserPointer(window));
        if (instance) {
            instance->mouse_input_event_handler->button_callback(button, action, mod);
        }
    };

    glfwSetInputMode(window, GLFW_STICKY_MOUSE_BUTTONS, GLFW_TRUE);
    glfwSetMouseButtonCallback(window, callback);
}

/**
 * @details 마우스 커서 위치 이벤트에 대한 콜백 함수를 등록합니다.
 * @return void
 */
void peekie::core::InputHandler::set_mouse_move_input_event_hanlder() {
    auto callback = [](GLFWwindow* window, double pos_x, double pos_y) {
        auto instance = static_cast<InputHandler*>(glfwGetWindowUserPointer(window));
        if (instance) {
            instance->mouse_input_event_handler->move_callback(pos_x, pos_y);
        }
    };

    glfwSetCursorPosCallback(window, callback);
}

/**
 * @details 마우스 휠 이벤트에 대한 콜백 함수를 등록합니다.
 * @return void
 */
void peekie::core::InputHandler::set_mouse_scroll_input_event_handler() {
    auto callback = [](GLFWwindow* window, double offset_x, double offset_y) {
        auto instance = static_cast<InputHandler*>(glfwGetWindowUserPointer(window));
        if (instance) {
            instance->mouse_input_event_handler->scroll_callback(offset_x, offset_y);
        }
    };

    glfwSetScrollCallback(window, callback);
}

/**
 * @details 마우스 커서가 윈도우에 들어감 여부의 이벤트에 대한 콜백 함수를 등록합니다.
 * @return void
 */
void peekie::core::InputHandler::set_mouse_window_enter_input_event_handler() {
    auto callback = [](GLFWwindow* window, int entered) {
        auto instance = static_cast<InputHandler*>(glfwGetWindowUserPointer(window));
        if (instance) {
            instance->mouse_input_event_handler->enter_callback(entered);
        }
    };

    glfwSetCursorEnterCallback(window, callback);
}

/**
 * @details 키보드 버튼 이벤트에 대한 콜백 함수를 등록합니다.
 * @return void
 */
void peekie::core::InputHandler::set_keyboard_input_event_handler() {
    auto callback = [](GLFWwindow* window, int key, int scancode, int action, int mods) {
        auto instance = static_cast<InputHandler*>(glfwGetWindowUserPointer(window));
        if (instance) {
            instance->keyboard_input_event_handler->button_callback(key, scancode, action, mods);
        }
    };

    glfwSetKeyCallback(window, callback);
}

/**
 * @details 윈도우 크기 조정 이벤트에 대한 콜백 함수를 등록합니다.
 * @return void
 */
void peekie::core::InputHandler::set_window_input_event_handler() {
    auto callback = [](GLFWwindow* window, int width, int height) {
        auto instance = static_cast<InputHandler*>(glfwGetWindowUserPointer(window));
        if (instance) {
            instance->window_input_event_handler->resize_callback(width, height);
        }
    };

    glfwSetFramebufferSizeCallback(window, callback);
}

void peekie::core::InputHandler::register_mouse_input_event_subscriber(
    std::shared_ptr<peekie::mouse::ISubscriber> subscriber
) {
    mouse_input_event_handler->register_subscriber(subscriber);
}

void peekie::core::InputHandler::register_keyboard_input_event_subscriber(
    std::shared_ptr<peekie::keyboard::ISubscriber> subscriber
) {
    keyboard_input_event_handler->register_subscriber(subscriber);
}

void peekie::core::InputHandler::register_window_input_event_subscriber(
    std::shared_ptr<peekie::window::ISubscriber> subscriber
) {
    window_input_event_handler->register_subscriber(subscriber);
}