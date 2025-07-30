#pragma once
#include "Title.h"
#include "StageSelect.h"
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
		StageSelect select;
		InGameDisplay ingame;

		Stage::StageId selectedStage;

	public:
		void Init();
		void Update();
		void ChangeState(DisplayState state);
		bool GameEndFlag();
	};
}