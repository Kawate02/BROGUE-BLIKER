#include "Title.h"

namespace BROGUE_BLIKER
{
	void TitleDisplay::Init()
	{
		frame.AddElement<UserInterface>(Point2D(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2),
			std::vector<ViewModel>{ ViewModel(0, 0, Square(Point2D(WINDOW_WIDTH, WINDOW_HEIGHT)), 0, Color(100, 100, 100)) },
			std::vector<Text>{ Text(Point2D(0, 0), L"ブロック崩し", 0, L"游ゴシック", Color(white), 32) }, 0, false);
		frame.AddElement<Button>(Point2D(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 3 * 2 + 50),
			Point2D(200, 40), 
			std::vector<ViewModel>{ViewModel(0, 0, Square(Point2D(200, 40)), 0, Color(200, 200, 200))},
			std::vector<Text>{Text(Point2D(0, 0), L"START", 0, L"游ゴシック", Color(black), 16)},
			[this]() { this->nextState = SELECT_STAGE; }, 1, false);
		frame.AddElement<Button>(Point2D(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 3 * 2 + 100),
			Point2D(200, 40),
			std::vector<ViewModel>{ViewModel(0, 0, Square(Point2D(200, 40)), 0, Color(200, 200, 200))},
			std::vector<Text>{Text(Point2D(0, 0), L"EXIT", 0, L"游ゴシック", Color(black), 16)},
			[this]() { this->endFlag = true; }, 1, false);
		frame.Draw();
	}
	void TitleDisplay::Update()
	{
		//LOG_VECTOR_SIZE();
		frame.Update(0);
		if (Input::KeyDown(ESCAPE))
		{
			endFlag = true;
		}
		if (Input::KeyDown(SPACE))
		{
			std::cout << "SPACE" << std::endl;
		}
	}
	void TitleDisplay::Remove()
	{
		frame.Clear();
	}
}