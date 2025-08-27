#include "UIFrame.h"

namespace BROGUE_BLIKER
{
	void UIFrame::TurnEnableJustFaceButton()
	{

	}
	UIFrame::UIFrame() : elements() {}

	UIFrame::UIFrame(std::vector<UserInterface> elements)
	{
		for (auto& element : elements)
		{
			auto ptr = MakeSharedFromInstance(element);
			this->elements.emplace_back(ptr);
		}
	}

	void UIFrame::Draw()
	{
		for (auto& element : elements)
		{
			element->Draw();
		}
	}
	void UIFrame::Update(int crrentTime)
	{
		for (auto& element : elements)
		{
			element->Update(crrentTime);
		}
		for (auto it = elements.begin(); it != elements.end();)
		{
			if (it->get()->deleteMyself)
			{
				it = elements.erase(it);
			}
			else
			{
				++it;
			}
		}
	}
	void UIFrame::Remove()
	{
		for (auto& element : elements)
		{
			element->Remove();
		}
	}

	void UIFrame::Move(Point2D pos)
	{
		for (auto& element : elements)
		{
			if (element->moveable) element->Move(pos);
		}
	}
}