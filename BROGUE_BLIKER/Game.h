#pragma once
#include "Title.h"
#include "StageSelect.h"
#include "InGame.h"

namespace BROGUE_BLIKER
{
	class GameManager
	{
	private:
		Display* crrentState;
		DisplayState crrentStateTag;
		TitleDisplay title;
		StageSelect select;
		InGameDisplay ingame;

		Stage::StageId selectedStage;

		bool CanChangeState(DisplayState nextState);

	public:
		void Init();
		void Update();
		void ChangeState(DisplayState state);
		bool GameEndFlag();
	};
}