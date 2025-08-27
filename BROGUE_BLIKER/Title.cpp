#include "Title.h"

namespace BROGUE_BLIKER
{
	void TitleDisplay::Init()
	{
		frame.AddElement<Button>(Point2D(0, 0), 
			Point2D(WINDOW_WIDTH, WINDOW_HEIGHT), 
			std::vector<ViewModel>{ ViewModel(0, 0, Square(Point2D(WINDOW_WIDTH, WINDOW_HEIGHT)), 0, Color(100, 100, 100)) },
			std::vector<Text>{},
			[this]() { this->nextState = SELECT_STAGE; });
		frame.Draw();
	}
	void TitleDisplay::Update()
	{
		LOG_VECTOR_SIZE();
		frame.Update(0);
		if (Input::KeyDown(ESCAPE))
		{
			endFlag = true;
		}
		if (Input::KeyDown(SPACE))
		{
			nextState = SELECT_STAGE;
		}
	}
	void TitleDisplay::Remove()
	{
		frame.Remove();
	}
}