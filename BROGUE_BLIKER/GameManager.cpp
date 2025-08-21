#include "Game.h"
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

	bool GameManager::CanChangeState(DisplayState nextState)
	{
		if (nextState == NONE) return false;
		if (crrentState == nullptr) return false;

		switch (crrentStateTag)
		{
		case TITLE:
			if (nextState == SELECT_STAGE) return true;
			break;
		case SELECT_STAGE:
			if (nextState == INGAME && select.stageGenerateFlag || nextState == TITLE) return true;
			break;
		case INGAME:
			if (nextState == TITLE || nextState == SELECT_STAGE) return true;
			break;
		default:
			break;
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
		if (CanChangeState(crrentState->nextState))
		{
			ChangeState(crrentState->nextState);
		}
		crrentState->nextState = NONE;
	}

	void GameManager::ChangeState(DisplayState state)
	{
		if (crrentState != nullptr) crrentState->Remove();
		switch (state)
		{
		case TITLE:
			crrentState = &title;
			crrentStateTag = TITLE;
			crrentState->Init();
			break;
		case SELECT_STAGE:
			crrentState = &select;
			crrentStateTag = SELECT_STAGE;
			crrentState->Init();
			break;
		case INGAME:
			crrentState = &ingame;
			crrentStateTag = INGAME;
			ingame.SetStage(select.GetStageId());
			crrentState->Init();
			break;
		default:
			break;
		}
	}
}