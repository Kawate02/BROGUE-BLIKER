#pragma once
#include "Title.h"
#include "InGame.h"

namespace BROGUE_BLIKER
{
	enum DisplayState
	{
		TITLE = 0x00,
		SELECT_STAGE,
		INGAME,
	};

	class GameManager
	{
	private:
		Display* crrentState;
		TitleDisplay title;
		InGameDisplay ingame;

		Stage::StageId selectedStage = Stage::TEST;

	public:
		GameManager();
		void Update();
		void ChangeState(DisplayState state);
	};
}