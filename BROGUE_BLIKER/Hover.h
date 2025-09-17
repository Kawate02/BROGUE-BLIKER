#pragma once
#include "UI.h"

namespace BROGUE_BLIKER
{
	class Hover : public UIElement
	{
	private:
		Point2D cursorHoverAreaBegin;
		Point2D cursorHoverAreaEnd;
	public:
		Hover(Point2D begin, Point2D end, Point2D size, int layer, Color color);
		void Draw() override;
		void Update(int crrentTime) override;
		void Remove() override;
	};
}
