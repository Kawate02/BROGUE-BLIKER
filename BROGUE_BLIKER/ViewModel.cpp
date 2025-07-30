#include "ViewModel.h"

namespace BROGUE_BLIKER
{
	ViewModel::ViewModel() : position(), bitmap(), id(-1), direction(0), layer(0), color() {}

	ViewModel::ViewModel(int _x, int _y, Bitmap bitmap, int _layer, Color _color) : default_position(Point2D(_x, _y)), position(Point2D(_x, _y)), bitmap(bitmap), id(-1), direction(0), layer(_layer), color(_color) {}

	std::vector<ViewModel*> ViewModelList::list;
	/// <summary>
	/// Modelを描画リストに登録
	/// </summary>
	/// <param name="vm">描画するModelポインタ</param>
	void ViewModelList::Add(ViewModel* vm)
	{
		list.push_back(vm);
		vm->id = list.size() - 1;
	}
	/// <summary>
	/// 登録済みModelの状態を更新
	/// </summary>
	/// <param name="vm">対象Modelのポインタ</param>
	void ViewModelList::Update(ViewModel* vm)
	{
		list[vm->id] = vm;
	}
	/// <summary>
	/// Modelを描画リストから削除
	/// </summary>
	/// <param name="vm">対象Modelのポインタ</param>
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
	const std::vector<ViewModel*>& ViewModelList::GetList()
	{
		return list;
	}
}