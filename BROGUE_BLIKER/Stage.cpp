#include "Stage.h"

namespace BROGUE_BLIKER
{
	void Stage::GenerateStage()
	{
		ViewModelList::Add(&(stage.background));
		for (auto& block : stage.block)
		{
			block.Draw();
		}
		for (auto& bar : stage.bar)
		{
			bar.Draw();
		}
		for (auto& ball : stage.ball)
		{
			ball.Draw();
		}
	}

	void Stage::Update()
	{
		for (auto& block : stage.block)
		{
			block.Update();
		}
		for (auto& bar : stage.bar)
		{
			bar.Update();
		}
		for (auto& ball : stage.ball)
		{
			ball.Update();
		}
	}
	void Stage::DestroyStage()
	{
		ViewModelList::Remove(&(stage.background));
		for (auto& block : stage.block)
		{
			block.Remove();
		}
		for (auto& bar : stage.bar)
		{
			bar.Remove();
		}
		for (auto& ball : stage.ball)
		{
			ball.Remove();
		}
	}
}