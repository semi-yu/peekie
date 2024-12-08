#include "./input_event_handler.hpp"

/**
 * @details GLFW 키보드 버튼눌림 이벤트가 발생시 이를 등록된 구독자에게 알립니다.  
 * @param[in] key GLFW 키보드 이벤트의 버튼 플래그
 * @param[in] scancode GLFW 키보드 이벤트의 스캔코드 플래그
 * @param[in] action GLFW 키보드 이벤트의 액션 플래그
 * @param[in] mods GLFW 키보드 이벤트의 모디파이어 플래그
 * @return void
 * @warning 이 멤버 함수는 GLFW에 키보드 버튼 이벤트를 위하여 만들어졌으므로, GLFW에 종속합니다. 함수 시그니쳐와 반환형은 고정되어야 합니다.
 */
void peekie::keyboard::InputEventHandler::button_callback(int key, int scancode, int action, int mods) {
    last_event.button = peekie::keyboard::get_button_flag(key);
    last_event.scancode = peekie::keyboard::get_scancode_flag(scancode);
    last_event.action = peekie::keyboard::get_action_flag(action);
    last_event.modifier = peekie::keyboard::get_modifier_flag(mods);

    auto event = std::make_shared<InputEvent>(last_event);
    for(auto& subscriber: subscribers) {
        subscriber->notify_keyboard_input_event(event);
    }
}

/**
 * @details GLFW 키보드 버튼눌림 이벤트를 고지받고 싶어하는 구독자를 추가합니다.
 * @param[in] subscriber 구독자
 * @return void
 */
void peekie::keyboard::InputEventHandler::register_subscriber(
    std::shared_ptr<peekie::keyboard::ISubscriber>subscriber
    ) {
    subscribers.push_back(subscriber);
}