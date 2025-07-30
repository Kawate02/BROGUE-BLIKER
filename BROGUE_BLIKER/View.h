#pragma once
#include <windows.h>
#include "ViewModel.h"
#include "Bitmap.h"
#include "const.h"

namespace BROGUE_BLIKER
{
	class View
	{
	public:
		View();
		void Init(HWND hwnd, int _width, int _height);
		void Update(HWND hwnd);
		void Exit(HWND hwnd);
	private:
		Bitmap bitmap;
		HDC mainHDC = NULL;
		HDC backHDC = NULL;
		HBITMAP backBitmap = NULL;
		int width = WINDOW_WIDTH;
		int height = WINDOW_HEIGHT;
		int frameCount = 0;
		Point2D displayOffset = Point2D(0, 0);
		std::vector<ViewModel*> list;
		void Present(HWND _hwnd);
		void DrawModel(int _x, int _y, Bitmap bitmap, Color _color, int _layer);
	};
}