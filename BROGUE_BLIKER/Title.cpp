#include "Title.h"

namespace BROGUE_BLIKER
{

	void TitleDisplay::Init()
	{
		ViewModelList::Add(&background);
		title.Draw();
	}
	void TitleDisplay::Update()
	{
		LOG_VECTOR_SIZE();
		if (Input::KeyDown(ESCAPE))
		{
			endFlag = true;
		}
	}
	void TitleDisplay::Remove()
	{
		ViewModelList::Remove(&background);
		title.Remove();
	}
}