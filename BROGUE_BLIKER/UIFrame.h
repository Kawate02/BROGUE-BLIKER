#pragma once
#include <memory>

#include "Macro.h"
#include "Button.h"
#include "Hover.h"


namespace BROGUE_BLIKER
{
	class UIFrame
	{
	private:
		std::vector<std::shared_ptr<UIElement>> elements;
		void TurnEnableJustFaceButton();
	public:
		UIFrame();
		UIFrame(std::vector<UIElement> elements);
		void Draw();
		void Update(int currentTime);
		void Remove();
		void Clear();
		template <typename T, typename... Args>
		void AddElement(Args ...args) 
		{
			this->elements.emplace_back(std::make_shared<T>(args...)); 
			this->elements.back()->id = elements.size() - 1;
		}
		void AddElements(std::vector<std::shared_ptr<UIElement>> elements);
		void Move(Point2D pos);
		int GetSize() { return elements.size(); }
	};
}