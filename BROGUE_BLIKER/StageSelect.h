#pragma once
#include "Display.h"
#include "Stage.h"

namespace BROGUE_BLIKER
{
	class StageSelect : public Display
	{
	private:
		Stage::StageId crrentId;

	public:
		bool stageGenerateFlag = false;
		void Init() override;
		void Update() override;
		void Remove() override;
		void SetStage(Stage::StageId stage);
		Stage::StageId GetStageId();
	};
}