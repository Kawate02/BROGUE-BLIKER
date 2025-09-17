#include "Hover.h"

namespace BROGUE_BLIKER
{
	Hover::Hover(Point2D begin, Point2D end, Point2D size, int layer, Color color) : cursorHoverAreaBegin(begin), cursorHoverAreaEnd(end)
	{
		viewModels.emplace_back(0, 0, Square(size), layer, color);
	}

	void Hover::Draw()
	{
		UIElement::Draw();
	}

	void Hover::Update(int crrentTime)
	{
		if (Input::mouse_pos[0] >= cursorHoverAreaBegin.x && Input::mouse_pos[0] <= cursorHoverAreaEnd.x &&
			Input::mouse_pos[1] >= cursorHoverAreaBegin.y && Input::mouse_pos[1] <= cursorHoverAreaEnd.y)
		{

		}
		else
		{
			Remove();
		}
		UIElement::Update(crrentTime);
	}
	void Hover::Remove()
	{
		UIElement::Remove();
	}
}