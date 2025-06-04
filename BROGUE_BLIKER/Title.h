#pragma once
#include "Display.h"

namespace BROGUE_BLIKER
{
	class TitleDisplay : public Display
	{
	public:
		void Init() override;
		void Update() override;
		void Remove() override;
	};
}