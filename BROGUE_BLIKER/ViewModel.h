#pragma once
#include "Shape.h"
#include "Color.h"

#include <vector>
#include <memory>

namespace BROGUE_BLIKER
{
	struct ViewModel
	{
	public:
		ViewModel();
		ViewModel(int, int, Shape, int, Color);
		int layer;
		int id;
		Point2D default_position;
		Point2D position;
		Shape shape;
		Color color;
		int direction;
	};


	static class ViewModelList
	{
	private:
		static std::vector<ViewModel*> list;
	public:
		static void Add(ViewModel* vm);
		static void Update(ViewModel* vm);
		static void Remove(ViewModel* vm);
		static void Clear();
		static std::vector<ViewModel*> GetList();
	};
}