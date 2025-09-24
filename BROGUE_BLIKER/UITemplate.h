#pragma once
#include <memory>
#include "Macro.h"
#include "Button.h"
#include "Hover.h"

namespace BROGUE_BLIKER
{
	class UITemplate
	{
	public:
		virtual void Init() = 0;
		virtual void Update() = 0;
		virtual void Draw() = 0;
		virtual void Remove() = 0;
	};
}