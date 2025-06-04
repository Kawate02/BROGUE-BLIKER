#include "Bitmap.h"

namespace BROGUE_BLIKER
{
	void Bitmap::SetDot(Color _color, int index)
	{
		switch (bitmap[index].state)
		{
		case Dotdata::Null:
			bitmap[index].color = _color;
			bitmap[index].state = Dotdata::Fill;
			break;
		case Dotdata::Fill:
			bitmap[index].color = AlphaBlend(_color, bitmap[index].color);
			break;
		default:
			break;
		}
	}
	void Bitmap::ClearBitmap()
	{
		for (int i = 0; i < ArraySizeOf(bitmap); i++)
		{
			bitmap[i].state = Dotdata::Null;
		}
	}
	Dotdata Bitmap::GetDotdata(int index)
	{
		return bitmap[index];
	}
}

