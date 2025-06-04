#include "View.h"

#include "Debug.h"

namespace BROGUE_BLIKER
{
	Bitmap bitmap;

	View::View() : list()
	{
		SetDrawScreen(DX_SCREEN_BACK);
	}

	void View::Update()
	{
		ClearDrawScreen();
		bitmap.ClearBitmap();

		list = ViewModelList::GetList();

		for (auto i = 0; i < list.size(); i++)
		{
			DrawModel(list[i]->position.x, list[i]->position.y, list[i]->shape.GetShape(), list[i]->color);
		}
		
		for (int i = 0; i < WINDOW_WIDTH * WINDOW_HEIGHT; i++)
		{
			if (bitmap.GetDotdata(i).state == Dotdata::Null)
			{
				continue;
			}
			Color tmp_color = bitmap.GetDotdata(i).color;
			DrawPixel(i % WINDOW_WIDTH, i / WINDOW_WIDTH, GetColor(tmp_color.r, tmp_color.g, tmp_color.b));
		}
		Write();
		ScreenFlip();
	}

	void View::DrawModel(int _x, int _y, std::vector<Point2D> _shape, Color _color)
	{
		for (int i = 0; i < _shape.size(); i++)
		{
			if (_shape[i].x + _x < displayOffset.x || _shape[i].x + _x >= WINDOW_WIDTH + displayOffset.x || _shape[i].y + _y < displayOffset.y || _shape[i].y + _y >= WINDOW_HEIGHT + displayOffset.y)
			{
				continue;
			}
			bitmap.SetDot(_color, WINDOW_WIDTH * (_shape[i].y + _y - displayOffset.y) + (_shape[i].x + _x - displayOffset.x));
		}
	}
}