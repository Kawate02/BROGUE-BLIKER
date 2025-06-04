#include "TestStage.h"

#include "Debug.h"

namespace BROGUE_BLIKER
{
	TestStage::TestStage() : Stage("TEST", -1,
		ViewModel(0, 0, Squea(Point2D(WINDOW_WIDTH, WINDOW_HEIGHT)), 0, Color(70, 70, 70)),
		std::vector<Block>(25),
		{ Bar(WINDOW_WIDTH / 2, 50, Color(white), true), Bar(WINDOW_WIDTH / 2, WINDOW_HEIGHT - 50, Color(white), true), Bar(50, WINDOW_HEIGHT / 2, Color(white), false), Bar(WINDOW_WIDTH - 50, WINDOW_HEIGHT / 2, Color(white), false) },
		std::vector<Ball>{ Ball(WINDOW_WIDTH / 2, WINDOW_HEIGHT - 55, Color(white)) })
	{
		auto basePos = Point2D(WINDOW_WIDTH / 2 - BLOCK_WIDTH * 2, WINDOW_HEIGHT / 2 - BLOCK_HEIGHT * 2);
		for (auto i = 0; i < stage.block.size(); i++)
		{
			stage.block[i] = Block(basePos.x + BLOCK_WIDTH * (i % 5), basePos.y + BLOCK_HEIGHT * (int)(i / 5), Color(gray));
		}
	}
	void TestStage::GenerateStage()
	{
		Stage::GenerateStage();
	}
	void TestStage::Update()
	{
		if (Input::MousePress(MOUSE_LEFT))
		{
			stage.ball[0].SetVelocity(0, -1);
		}
		Stage::Update();
		for (auto i = 0; i < stage.ball.size(); i++)
		{
			std::vector<Point2D> hitPosList;
			for (auto j = 0; j < stage.bar.size(); j++)
			{
				hitPosList = CollisionCheck(stage.ball[i].GetCollision(), stage.bar[j].GetCollision());
				if (hitPosList.size() != 0 )
				{
					stage.ball[i].BoundOnBar(&stage.bar[j], hitPosList);
					if (i == 0)
					{
						stage.ball.push_back(Ball(hitPosList[i].x, hitPosList[i].y, Color(black, 0.1f)));
						stage.ball[stage.ball.size() - 1].SetVelocity(-stage.ball[i].GetVelocity().x, stage.ball[i].GetVelocity().y);
						stage.ball[stage.ball.size() - 1].Draw();
					}
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
	void TestStage::DestroyStage()
	{
		Stage::DestroyStage();
	}
}