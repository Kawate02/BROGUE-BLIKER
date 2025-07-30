#include "Stage.h"

namespace BROGUE_BLIKER
{
	void Stage::BallBound()
	{
		for (auto i = 0; i < stage.ball.size(); i++)
		{
			std::vector<Point2D> hitPosList;
			for (auto j = 0; j < stage.bar.size(); j++)
			{
				hitPosList = CollisionCheck(stage.ball[i].GetCollision(), stage.bar[j].GetCollision());
				if (hitPosList.size() != 0)
				{
					stage.ball[i].BoundOnBar(&stage.bar[j], hitPosList);
					stage.bar[j].HitOnBall(&stage.ball[i]);
					hitPosList.clear();
					break;
				}
				hitPosList.clear();
			}
			for (auto j = 0; j < stage.block.size(); j++)
			{
				hitPosList = CollisionCheck(stage.ball[i].GetCollision(), stage.block[j].GetCollision());
				if (hitPosList.size() != 0)
				{
					stage.ball[i].BoundOnBlock(&stage.block[j], hitPosList);
					stage.block[j].Break();
					stage.block.erase(stage.block.begin() + j);
					hitPosList.clear();
					break;
				}
				hitPosList.clear();
			}
		}
	}
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
			block.Update(crrentTime);
		}
		for (auto& bar : stage.bar)
		{
			bar.Update(crrentTime);
		}
		for (auto& ball : stage.ball)
		{
			ball.Update(crrentTime);
		}
		crrentTime++;
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