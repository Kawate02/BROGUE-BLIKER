#pragma once

namespace BROGUE_BLIKER
{
#define white 255,255,255
#define black 0,0,0
#define red 255,0,0
#define green 0,255,0
#define blue 0,0,255
#define gray 128,128,128

	struct Color
	{
	public:
		Color();
		Color(int, int, int, float _a = 1);
		int r;
		int g;
		int b;
		float a;

		Color operator+(const Color& other)
		{
			return Color(r + other.r, g + other.g, b + other.b, a);
		}
		Color operator-(const Color& other)
		{
			return Color(r - other.r, g - other.g, b - other.b, a);
		}
		Color operator*(const float& num)
		{
			return Color(r * num, g * num, b * num, a);
		}
	};
	Color AlphaBlend(Color front, Color back);
}