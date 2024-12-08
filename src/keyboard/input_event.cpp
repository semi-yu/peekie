#include "./input_event.hpp"

peekie::keyboard::InputEvent::InputEvent() {}

peekie::keyboard::InputEvent::InputEvent(
    const InputEvent& event
) {
    this->button = event.button;
    this->scancode = event.scancode;
    this->action = event.action;
    this->modifier = event.modifier;
}

/**
 * @details 이벤트에서 눌린 버튼을 반환합니다.
 * @return peekie::keyboard::Button
 */
peekie::keyboard::Button peekie::keyboard::InputEvent::get_button() const { return button; }

/**
 * @details 이벤트에서 눌린 버튼을 반환합니다.
 * @return peekie::keyboard::Scancode
 * @warning 키보드 눌림 이벤트 변환 함수가 항상 none을 반환하도록 되어있으므로 이 함수는 항상 none을 반환합니다. 
 * @see 항상적 none 반환은 현재 의도적입니다. 다음을 참고하십시오. peekie::keyboard::get_scancode_flag()
 */
peekie::keyboard::Scancode peekie::keyboard::InputEvent::get_scancode() const { return scancode; }

/**
 * @details 이벤트에서 버튼의 액션을 반환합니다.
 * @return peekie::keyboard::Action
 */
peekie::keyboard::Action peekie::keyboard::InputEvent::get_action() const { return action; }

/**
 * @details 이벤트에서 버튼 모디파이어를 반환합니다.
 * @return peekie::keyboard::Modifier
 */
peekie::keyboard::Modifier peekie::keyboard::InputEvent::get_modifier() const { return modifier; }