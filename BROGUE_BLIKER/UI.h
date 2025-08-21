#pragma once

#include <string>
#include <functional>
#include "ObjectModel.h"
#include "Text.h"

namespace BROGUE_BLIKER
{
	class UserInterface : public Object
	{
	protected:
		std::vector<ViewModel> viewModels;
		std::vector<Text> texts;
	public:
		UserInterface();
		UserInterface(Point2D pos, std::vector<ViewModel> viewModels, std::vector<Text> texts, int layer, bool isMove);
		void Draw() override;
		void Update(int crrentTime) override;
		void Remove() override;
		bool moveable;
		bool deleteMyself = false;
	};
}