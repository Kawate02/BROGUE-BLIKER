#include "View.h"


namespace BROGUE_BLIKER
{
	View::View() : list() {}
	void* pPixels = nullptr;

	void View::Init(HWND hwnd, int _width, int _height)
	{
		width = _width;
		height = _height;
		bitmap.Init(_width, _height);

		BITMAPINFO bmi = {};
		bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		bmi.bmiHeader.biWidth = width;
		bmi.bmiHeader.biHeight = -height;
		bmi.bmiHeader.biPlanes = 1;
		bmi.bmiHeader.biBitCount = 32;
		bmi.bmiHeader.biCompression = BI_RGB;

		HDC tempHDC = GetDC(hwnd);
		backHDC = CreateCompatibleDC(tempHDC);
		backBitmap = CreateDIBSection(tempHDC, &bmi, DIB_RGB_COLORS, &pPixels, NULL, 0);
		SelectObject(backHDC, backBitmap);
		ReleaseDC(hwnd, tempHDC);
	}

	/// <summary>
	/// âÊñ Ç…ì]ëó
	/// </summary>
	void View::Present(HWND hwnd)
	{
		HDC hdc = GetDC(hwnd);
		BitBlt(hdc, 0, 0, width, height, backHDC, 0, 0, SRCCOPY);
		ReleaseDC(hwnd, hdc);
	}

	void View::Update(HWND hwnd)
	{
		if (!pPixels) return;

		DWORD* pixels = (DWORD*)pPixels;

		bitmap.ClearBitmap();

		list = ViewModelList::GetList();

		for (auto i = 0; i < list.size(); i++)
		{
			DrawModel(list[i]->position.x, list[i]->position.y, list[i]->bitmap, list[i]->color, list[i]->layer);
		}
		
		for (int i = 0; i < width * height; i++)
		{
			Dotdata tmp = bitmap.GetDotdata(i);
			if (tmp.state == Dotdata::Null)
			{
				continue;
			}
			DWORD color = tmp.color.GetColor();
			pixels[i] = color;
		}
		Present(hwnd);
	}

	/// <summary>
	/// ÉäÉ\Å[ÉXâï˙
	/// </summary>
	void View::Exit(HWND hwnd)
	{
		DeleteObject(backBitmap);
		DeleteDC(backHDC);
	}

	/// <summary>
	/// pixelåQÇbitmapÇ…ìoò^
	/// </summary>
	/// <param name="_x, _y">viewmodelÇÃç¿ïW</param>
	/// <param name="_shape">ëäëŒç¿ïWÇÃpixelÉfÅ[É^åQ</param>
	/// <param name="_color">bitmapìoò^éûÇÃêF</param>
	void View::DrawModel(int _x, int _y, Bitmap _bitmap, Color _color, int _layer)
	{
		for (int i = 0; i < _bitmap.Size() ; i++)
		{
			if (_bitmap.GetDotdata(i).state == Dotdata::Null || i % _bitmap.Width() + _x < displayOffset.x || i % _bitmap.Width() + _x >= width + displayOffset.x || i / _bitmap.Width() + _y < displayOffset.y || i / _bitmap.Width() + _y >= height + displayOffset.y)
			{
				continue;
			}
			bitmap.SetDot(_color, width * (i / _bitmap.Width() + _y - displayOffset.y) + (i % _bitmap.Width() + _x - displayOffset.x), _layer);
		}
	}
}