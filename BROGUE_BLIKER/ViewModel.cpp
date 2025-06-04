#include "ViewModel.h"

namespace BROGUE_BLIKER
{
	ViewModel::ViewModel() : position(), shape(), id(-1), direction(0), layer(0), color() {}

	ViewModel::ViewModel(int _x, int _y, Shape _shape, int _layer, Color _color) : default_position(Point2D(_x, _y)), position(Point2D(_x, _y)), shape(_shape), id(-1), direction(0), layer(_layer), color(_color) {}

	std::vector<ViewModel*> ViewModelList::list;
	void ViewModelList::Add(ViewModel* vm)
	{
		list.push_back(vm);
		vm->id = list.size() - 1;
	}
	void ViewModelList::Update(ViewModel* vm)
	{
		list[vm->id] = vm;
	}
	void ViewModelList::Remove(ViewModel* vm)
	{
		for (auto i = vm->id + 1 ; i < list.size(); i++)
		{
			list[i]->id--;
		}
		list.erase(list.begin() + vm->id);
	}

	void ViewModelList::Clear()
	{
		list.clear();
	}
	std::vector<ViewModel*> ViewModelList::GetList()
	{
		return list;
	}
}