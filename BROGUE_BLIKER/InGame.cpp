#include "InGame.h"
#include "Input.h"

namespace BROGUE_BLIKER
{
	void InGameDisplay::Init()
	{
		crrentState = READY;
		crrentStage = GenerateStage(crrentId);
	}
	void InGameDisplay::Update()
	{
		switch (crrentState)
		{
		case DOING:
			crrentStage->Update();
			break;
		case READY:
			if (Input::MouseDown(MOUSE_LEFT))
			{
				crrentState = DOING;
			}
			break;
		case PAUSE:
			break;
		case RESULT:
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
}