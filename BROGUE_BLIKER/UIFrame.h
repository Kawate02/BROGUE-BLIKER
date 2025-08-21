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
		std::vector<std::shared_ptr<UserInterface>> elements;
		void TurnEnableJustFaceButton();
	public:
		UIFrame();
		UIFrame(std::vector<UserInterface> elements);
		void Draw();
		void Update(int currentTime);
		void Remove();
		void AddElement(UserInterface element);
		void Move(Point2D pos);
	};
}