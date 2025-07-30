#include "InGame.h"
#include "Input.h"

namespace BROGUE_BLIKER
{
	void InGameDisplay::Init()
	{
		crrentState = READY;
		crrentStage = GenerateStage(crrentId);
		stageExitFlag = false;
	}
	void InGameDisplay::Update()
	{
		switch (crrentState)
		{
		case DOING:
			if (Input::KeyDown(ESCAPE))
			{
				crrentState = PAUSE;
			}
			if (crrentStage->stageEndFlag)
			{
				crrentState = RESULT;
			}
			crrentStage->Update();
			break;
		case READY:
			if (Input::KeyDown(MOUSE_LEFT))
			{
				crrentState = DOING;
			}
			break;
		case PAUSE:
			if (Input::KeyDown(ESCAPE))
			{
				crrentState = DOING;
			}
			break;
		case RESULT:
			if (Input::KeyDown(SPACE))
			{
				stageExitFlag = true;
			}
			break;
		default:
			break;
		}
	}
	void InGameDisplay::Remove()
	{
		crrentStage->DestroyStage();
	}
	void InGameDisplay::SetStage(Stage::StageId stage)
	{
		crrentId = stage;
	}
	GameState InGameDisplay::GetState()
	{
		return crrentState;
	}
}