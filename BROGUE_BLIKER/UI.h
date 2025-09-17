#pragma once

#include <string>
#include <functional>
#include "ObjectModel.h"
#include "Text.h"

namespace BROGUE_BLIKER
{
	class UIElement : public Object
	{
	protected:
		std::vector<ViewModel> viewModels;
		std::vector<Text> texts;
	public:
		UIElement();
		UIElement(Point2D pos, std::vector<ViewModel> viewModels, std::vector<Text> texts, int layer, bool isMove);
		void Draw() override;
		void Update(int crrentTime) override;
		void Remove() override;
		virtual std::shared_ptr<UIElement> Clone();
		bool moveable;
		bool deleteMyself = false;
		int id = -1;
	};
}