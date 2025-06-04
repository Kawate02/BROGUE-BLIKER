#pragma once
#include "Display.h"
#include "Stage.h"
#include "StageGenerator.h"

namespace BROGUE_BLIKER
{
	enum GameState
	{
		DOING = 0x00,
		READY,
		END,
		PAUSE,
		RESULT
	};

	class InGameDisplay : public Display
	{
	private:
		GameState crrentState;
		Stage* crrentStage;
		Stage::StageId crrentId;

	public:
		void Init() override;
		void Update() override;
		void Remove() override;
		void SetStage(Stage::StageId stage);
	};
}