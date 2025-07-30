#pragma once
#include <vector>

#include "Color.h"
#include "const.h"
#include "Macro.h"

namespace BROGUE_BLIKER
{
	struct Dotdata
	{
	public:
		Dotdata() : state(State::Null), color(), layer(0) {}
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
		std::vector<Dotdata> bitmap;
		int width;
		int height;
	public:
		void Init(int _width, int _height);
		void SetDot(Color _color, int index, int _layer);
		void ClearBitmap();
		int Width();
		int Height();
		int Size();
		std::vector<Dotdata> GetBitmap();
		Dotdata GetDotdata(int index);
	};
}