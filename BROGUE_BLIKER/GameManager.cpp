#include "Game.h"
#include "DxLib.h"
#include "Input.h"

#include "StageGenerator.h"

namespace BROGUE_BLIKER
{
	bool GameManager::GameEndFlag()
	{
		if (title.endFlag)
		{
			return true;
		}
		return false;
	}

	void GameManager::Init()
	{
		ChangeState(TITLE);
	}

	void GameManager::Update()
	{
		crrentState->Update();
		if (Input::KeyDown(SPACE) && crrentState == &title)
		{
			ChangeState(SELECT_STAGE);
		}
		if (select.stageGenerateFlag && crrentState == &select)
		{
			selectedStage = select.GetStageId();
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
			crrentState = &select;
			crrentState->Init();
			break;
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