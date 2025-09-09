#pragma once
#include "UIFrame.h"

namespace BROGUE_BLIKER
{
	enum DisplayState
	{
		NONE = -1,
		TITLE = 0x00,
		SELECT_STAGE,
		INGAME,
	};
	class Display
	{
	protected:
		UIFrame frame;
	public:
		virtual void Init() {}
		virtual void Update() {}
		virtual void Remove() {}
		bool endFlag = false;
		DisplayState nextState = NONE;
	};
}