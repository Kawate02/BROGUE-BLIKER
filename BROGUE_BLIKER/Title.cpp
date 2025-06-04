#include "Title.h"
#include "Shape.h"
#include "ViewModel.h"

#include "const.h"
#include "Input.h"
#include "Block.h"

namespace BROGUE_BLIKER
{
	ViewModel background(0, 0, Squea(Point2D(WINDOW_WIDTH, WINDOW_HEIGHT)), 1, Color(100, 100, 100));

	void TitleDisplay::Init()
	{
		ViewModelList::Add(&background);
	}
	void TitleDisplay::Update()
	{
	}
	void TitleDisplay::Remove()
	{
		ViewModelList::Remove(&background);
	}
}