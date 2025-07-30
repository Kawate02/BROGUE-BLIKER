#include "StageSelect.h"

namespace BROGUE_BLIKER
{
	void StageSelect::Init()
	{
		stageGenerateFlag = false;
	}

	void StageSelect::Update()
	{
		if (Input::KeyDown(MOUSE_LEFT))
		{
			SetStage(Stage::StageId::TEST);
			stageGenerateFlag = true;
		}
	}

	void StageSelect::Remove()
	{

	}

	void StageSelect::SetStage(Stage::StageId stage)
	{
		crrentId = stage;
	}

	Stage::StageId StageSelect::GetStageId()
	{
		return crrentId;
	}
}
