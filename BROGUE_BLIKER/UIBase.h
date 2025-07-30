#pragma once

#include <string>
#include "ObjectModel.h"

namespace BROGUE_BLIKER
{
	class UI : public Object
	{
	protected:
		Point2D pos;
	public:
		void Draw() override {}
		void Update(int crrentTime) override {}
		void Remove() override {}
	};

	class Hover : public UI
	{
	private:
		ViewModel window;
		Point2D cursorHoverAreaBegin;
		Point2D cursorHoverAreaEnd;
	public:
		Hover(Point2D begin, Point2D end, Point2D size, int layer, Color color);
		void Draw() override;
		void Update(int crrentTime) override;
		void Remove() override;
	};

	class Button : public UI
	{

	};

	class Text : public UI
	{

	};
}