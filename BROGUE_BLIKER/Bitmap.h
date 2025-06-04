#pragma once
#include "Color.h"
#include "const.h"
#include "Macro.h"

namespace BROGUE_BLIKER
{
	struct Dotdata
	{
	public:
		enum State
		{
			Null = -1,
			Fill = 0
		};
		State state;
		Color color;
		int layer;
	};
	class Bitmap
	{
	private:
		Dotdata bitmap[WINDOW_WIDTH * WINDOW_HEIGHT];
	public:
		void SetDot(Color _color, int index);
		void ClearBitmap();
		Dotdata GetDotdata(int index);
	};
}