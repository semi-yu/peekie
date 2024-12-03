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

peekie::keyboard::Button peekie::keyboard::InputEvent::get_button() const { return button; }

peekie::keyboard::Scancode peekie::keyboard::InputEvent::get_scancode() const { return scancode; }

peekie::keyboard::Action peekie::keyboard::InputEvent::get_action() const { return action; }

peekie::keyboard::Modifier peekie::keyboard::InputEvent::get_modifier() const { return modifier; }