//
// Input class
// Keeps track of keyboard state
//

#include <Input.h>

// This function gets called at the beginning of each new frame
// to reset the keys that are no longer relevant

void Input::BeginNewFrame()
{
	this->_PressedKeys.clear();
	this->_ReleasedKeys.clear();
}

// This function is called when a key has been pressed

void Input::KeyDownEvent(const SDL_Event& event)
{
	this->_PressedKeys[event.key.keysym.scancode] = true;
	this->_HeldKeys[event.key.keysym.scancode] = true;
}

// This function is called when a key has been released

void Input::KeyUpEvent(const SDL_Event& event)
{
	this->_ReleasedKeys[event.key.keysym.scancode] = true;
	this->_HeldKeys[event.key.keysym.scancode] = false;
}

// Check if a certain key was pressed during current frame

bool Input::WasKeyPressed(SDL_Scancode key)
{
	return this->_PressedKeys[key];
}

// Check if a certain key was released during current frame

bool Input::WasKeyReleased(SDL_Scancode key)
{
	return this->_ReleasedKeys[key];
}

// Check if a certain key was held during current frame

bool Input::IsKeyHeld(SDL_Scancode key)
{
	return this->_HeldKeys[key];
}
