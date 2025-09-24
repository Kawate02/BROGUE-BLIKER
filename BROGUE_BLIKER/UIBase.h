#pragma once

#include <vector>
#include <memory>

#include "Button.h"

namespace BROGUE_BLIKER
{
	class UI
	{
	private:
		std::vector<std::shared_ptr<UIElement>> elements;
	public:
		void Draw();
		void Update(int crrentTime);
		void Remove();
		
	};
}