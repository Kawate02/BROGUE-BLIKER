#include "UI.h"

namespace BROGUE_BLIKER
{
	UIElement::UIElement() : Object(0, 0, 0, 0, 64), viewModels(), texts(), moveable(false) {}
	UIElement::UIElement(Point2D pos, std::vector<ViewModel> viewModels, std::vector<Text> texts, int layer, bool isMove) :
		Object(pos.x, pos.y, 0, 0, layer + 64), moveable(isMove) 
	{
		for (auto i=0; i< viewModels.size(); i++)
		{
			viewModels[i].layer += layer + 64;
			viewModels[i].position.x += pos.x;
			viewModels[i].position.y += pos.y;
		}
		this->viewModels = viewModels;
		for (auto i = 0; i < texts.size(); i++)
		{
			texts[i].layer += layer + 64;
			texts[i].pos.x += pos.x;
			texts[i].pos.y += pos.y;
		}
		this->texts = texts;
	}
	void UIElement::Draw()
	{
		for (auto& model : viewModels)
		{
			ViewModelList::Add(&model);
		}
		for (auto& text : texts)
		{
			text.Draw();
		}
	}
	void UIElement::Update(int crrentTime)
	{
		for (auto& model : viewModels)
		{
			ViewModelList::Update(&model);
		}
		for (auto& text : texts)
		{
			text.Update(crrentTime);
		}
	}
	void UIElement::Remove()
	{
		for (auto& model : viewModels)
		{
			ViewModelList::Remove(&model);
		}
		for (auto& text : texts)
		{
			text.Remove();
		}
		deleteMyself = true;
	}
	std::shared_ptr<UIElement> UIElement::Clone()
	{
		return std::make_shared<UIElement>(position, viewModels, texts, layer, moveable);
	}
}
