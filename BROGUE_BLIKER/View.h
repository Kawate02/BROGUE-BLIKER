#pragma once
#include "DxLib.h"
#include "ViewModel.h"
#include "Bitmap.h"
#include "const.h"

namespace BROGUE_BLIKER
{
	class View
	{
	public:
		View();
		void Update();
	private:
		int frameCount = 0;
		Point2D displayOffset = Point2D(0, 0);
		std::vector<ViewModel*> list;
		void DrawModel(int _x, int _y, std::vector<Point2D> _shape, Color _color);
	};
}