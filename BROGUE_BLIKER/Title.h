#pragma once
#include "Display.h"
#include "Shape.h"
#include "ViewModel.h"

#include "Text.h"

#include "const.h"
#include "Input.h"
#include "Block.h"

#include "UIFrame.h"

namespace BROGUE_BLIKER
{
	class TitleDisplay : public Display
	{
	private:
		ViewModel background = ViewModel(0, 0, Square(Point2D(WINDOW_WIDTH, WINDOW_HEIGHT)), 0, Color(100, 100, 100));
		Text title = Text(Point2D(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2), L"BROGUE BLIKER", 0, L"游ゴシック", Color(white), 32);
		Button button = Button(Point2D(0, 0), Point2D(WINDOW_WIDTH, WINDOW_HEIGHT), { ViewModel(0, 0, Square(Point2D(WINDOW_WIDTH, WINDOW_HEIGHT)), 0, Color(100, 100, 100)) }, {}, [this]() { this->nextState = SELECT_STAGE; });
	public:
		void Init() override;
		void Update() override;
		void Remove() override;
		bool endFlag = false;
	};
}