#include "UIBase.h"

void BROGUE_BLIKER::UI::Draw()
{
	for (auto& element : elements)
	{
		element->Draw();
	}
}

void BROGUE_BLIKER::UI::Update(int crrentTime)
{
	for (auto& element : elements)
	{
		element->Update(crrentTime);
	}
}

void BROGUE_BLIKER::UI::Remove()
{
	for (auto& element : elements)
	{
		element->Remove();
	}

}
