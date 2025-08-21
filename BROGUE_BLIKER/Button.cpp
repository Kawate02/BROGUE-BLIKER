#include "Button.h"

namespace BROGUE_BLIKER
{
	Button::Button(Point2D position, Point2D size, std::vector<ViewModel> viewModels, std::vector<Text> text, std::function<void()> clickEvent)
	{
		this->position = position;
		this->size = size;
		this->viewModels = viewModels;
		this->texts = text;
		cursorHoverAreaBegin = position;
		cursorHoverAreaEnd = position + size;
		this->clickEvent = clickEvent;
	}

	void Button::OnMouse()
	{
		if (state == State::DISABLE) return;
		state = State::HOVER;
	}
	void Button::OffMouse()
	{
		if (state == State::DISABLE) return;
		state = State::NORMAL;
	}
	void Button::Click()
	{
		if (state == State::DISABLE) return;
		clickEvent();
	}
	void Button::Update(int crrentTime)
	{
		if (Input::mouse_pos[0] >= cursorHoverAreaBegin.x && Input::mouse_pos[0] <= cursorHoverAreaEnd.x &&
			Input::mouse_pos[1] >= cursorHoverAreaBegin.y && Input::mouse_pos[1] <= cursorHoverAreaEnd.y)
		{
			OnMouse();
			if (Input::KeyDown(MOUSE_LEFT))
			{
				Click();
			}
		}
		else
		{
			OffMouse();
		}
		UserInterface::Update(crrentTime);
	}
	void Button::Enable()
	{
		state = State::NORMAL;
	}
	void Button::Disable()
	{
		state = State::DISABLE;
	}
}
