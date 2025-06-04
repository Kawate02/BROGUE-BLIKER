#pragma once
#include "Stage.h"
#include "ViewModel.h"
#include "const.h"

namespace BROGUE_BLIKER
{
	class TestStage : public Stage
	{
	public:
		TestStage();
		void GenerateStage() override;
		void Update() override;
		void DestroyStage() override;
	};
}