#pragma once
#include "UI.h"
#include "Text.h"

namespace BROGUE_BLIKER
{
	class Button : public UIElement
	{
	protected:
		enum State { NORMAL, HOVER, CLICK, DISABLE };
		State state = NORMAL;
		Point2D cursorHoverAreaBegin;
		Point2D cursorHoverAreaEnd;
		std::function<void()> clickEvent;

		virtual void OnMouse();
		virtual void OffMouse();
		virtual void Click();
	public:
		Button(Point2D position, Point2D size, std::vector<ViewModel>, std::vector<Text> text, std::function<void()> clickEvent, int layer, bool isMove = false);
		void Update(int crrentTime) override;
		void Enable();
		void Disable();
		std::shared_ptr<UIElement> Clone() override;
	};
}