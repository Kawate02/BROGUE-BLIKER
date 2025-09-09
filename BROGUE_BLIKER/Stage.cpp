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
		gameClearFlag = false;
		gameOverFlag = false;
		stageExitFlag = false;
	}

	void Stage::Update()
	{
		if (stage.ballStock < 0)
		{
			gameOverFlag = true;
		}
		
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
		for (auto i = 0; i < stage.ball.size(); i++)
		{
			if (stage.ball[i].deleteFlag)
			{
				stage.ball[i].Remove();
				stage.ball.erase(stage.ball.begin() + i);
			}
		}
		if (stage.ball.size() == 0)
		{
			stage.ballStock--;
			if (stage.ballStock < 0)
			{
				gameOverFlag = true;
			}
			stage.ball.push_back(Ball(WINDOW_WIDTH / 2, WINDOW_HEIGHT - 55, Color(white)));
			stage.ball[0].Draw();
		}
		BallBound();
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
	void Stage::LoadStage(StageStruct stage)
	{
		this->stage = stage;
	}
}