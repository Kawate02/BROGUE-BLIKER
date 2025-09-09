#include "TestStage.h"

namespace BROGUE_BLIKER
{
	TestStage::TestStage() : stageStruct("TEST", -1,
		ViewModel(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, Square(Point2D(WINDOW_WIDTH, WINDOW_HEIGHT)), 0, Color(70, 70, 70)),
		std::vector<Block>(25),
		{ Bar(WINDOW_WIDTH / 2, 50, Color(white), true), Bar(WINDOW_WIDTH / 2, WINDOW_HEIGHT - 50, Color(white), true), 
			Bar(50, WINDOW_HEIGHT / 2, Color(white), false), Bar(WINDOW_WIDTH - 50, WINDOW_HEIGHT / 2, Color(white), false) },
		std::vector<Ball>{ Ball(WINDOW_WIDTH / 2, WINDOW_HEIGHT - 55, Color(white)) }, 3)
	{
		auto basePos = Point2D(WINDOW_WIDTH / 2 - BLOCK_WIDTH * 2, WINDOW_HEIGHT / 2 - BLOCK_HEIGHT * 2);
		for (auto i = 0; i < stageStruct.block.size(); i++)
		{
			stageStruct.block[i] = Block(basePos.x + BLOCK_WIDTH * (i % 5), basePos.y + BLOCK_HEIGHT * (int)(i / 5), Color(gray));
		}
	}
	void TestStage::GenerateStage()
	{
		stage = stageStruct;
		Stage::GenerateStage();
		//stage.bar[1].AddEffect(&hyperBound);
	}
	void TestStage::Update()
	{
		LOG_VECTOR_SIZE();
		Stage::Update();
	}
	void TestStage::DestroyStage()
	{
		Stage::DestroyStage();
	}
}