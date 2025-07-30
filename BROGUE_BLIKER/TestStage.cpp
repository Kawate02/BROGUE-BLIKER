#include "TestStage.h"

namespace BROGUE_BLIKER
{
	TestStage::TestStage() : Stage("TEST", -1,
		ViewModel(0, 0, Square(
			Point2D(WINDOW_WIDTH, WINDOW_HEIGHT)), 0, Color(70, 70, 70)),
		std::vector<Block>(25),{ 
			Bar(WINDOW_WIDTH / 2, 50, Color(white), true), Bar(WINDOW_WIDTH / 2, WINDOW_HEIGHT - 50, Color(white), true), 
			Bar(50, WINDOW_HEIGHT / 2, Color(white), false), Bar(WINDOW_WIDTH - 50, WINDOW_HEIGHT / 2, Color(white), false) },
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
		stage.bar[1].AddEffect(&hyperBound);
		title.Draw();
	}
	void TestStage::Update()
	{
		LOG_VECTOR_SIZE();
		Stage::Update();
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
			stage.ball.push_back(Ball(WINDOW_WIDTH / 2, WINDOW_HEIGHT - 55, Color(white)));
			stage.ball[0].Draw();
		}
		BallBound();
	}
	void TestStage::DestroyStage()
	{
		Stage::DestroyStage();
		title.Remove();
	}
}