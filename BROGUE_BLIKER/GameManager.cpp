#include "Game.h"
#include "DxLib.h"
#include "Input.h"

#include "StageGenerator.h"

namespace BROGUE_BLIKER
{
	GameManager::GameManager()
	{
		ChangeState(TITLE);
	}

	void GameManager::Update()
	{
		crrentState->Update();
		if (Input::KeyDown(SPACE))
		{
			ChangeState(INGAME);
		}
	}

	void GameManager::ChangeState(DisplayState state)
	{
		if (crrentState != nullptr) crrentState->Remove();
		switch (state)
		{
		case TITLE:
			crrentState = &title;
			crrentState->Init();
			break;
		case SELECT_STAGE:

		case INGAME:
			crrentState = &ingame;
			ingame.SetStage(selectedStage);
			crrentState->Init();
			break;
		default:
			break;
		}
	}
}