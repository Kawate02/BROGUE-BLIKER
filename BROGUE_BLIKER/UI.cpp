#include "UI.h"

namespace BROGUE_BLIKER
{
	UserInterface::UserInterface() : Object(0, 0, 0, 0, 64), viewModels(), texts(), moveable(false) {}
	UserInterface::UserInterface(Point2D pos, std::vector<ViewModel> viewModels, std::vector<Text> texts, int layer, bool isMove) :
		Object(pos.x, pos.y, 0, 0, layer + 64), viewModels(viewModels), texts(texts), moveable(isMove) {}
	void UserInterface::Draw()
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
	void UserInterface::Update(int crrentTime)
	{
		for (auto& model : viewModels)
		{
			ViewModelList::Update(&model);
		}
		for (auto& text : texts)
		{
			text.Draw();
		}
	}
	void UserInterface::Remove()
	{
		for (auto& model : viewModels)
		{
			ViewModelList::Remove(&model);
		}
		for (auto& text : texts)
		{
			text.Remove();
		}
	}
}
