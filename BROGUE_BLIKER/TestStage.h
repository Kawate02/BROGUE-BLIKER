#pragma once
#include "Stage.h"
#include "ViewModel.h"
#include "const.h"
#include "Text.h"

namespace BROGUE_BLIKER
{
	class TestStage : public Stage
	{
		Text title = Text(Point2D(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2), L"BLIKER", 0, L"游ゴシック", Color(white), 16);
	public:
		TestStage();
		void GenerateStage() override;
		void Update() override;
		void DestroyStage() override;
	};
}