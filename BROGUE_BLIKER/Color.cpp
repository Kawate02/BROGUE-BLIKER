#include "Color.h"

namespace BROGUE_BLIKER
{
	Color::Color()
	{
		r = 255;
		g = 255;
		b = 255;
		a = 1.0f;
	}
	Color::Color(int _r, int _g, int _b, float _a)
	{
		this->r = _r;
		this->g = _g;
		this->b = _b;
		this->a = _a;
		if (r > 255) r = 255;
		if (g > 255) g = 255;
		if (b > 255) b = 255;
		if (r < 0) r = 0;
		if (g < 0) g = 0;
		if (b < 0) b = 0;
		if (a > 1.0) a = 1.0;
		if (a < 0) a = 0;
	}
	Color AlphaBlend(Color front, Color back)
	{
		float fr = front.r, fg = front.g, fb = front.b, br = back.r, bg = back.g, bb = back.b;
		int rr, rg, rb;
		rr = br + (fr * front.a) - (br * front.a);
		rg = bg + (fg * front.a) - (bg * front.a);
		rb = bb + (fb * front.a) - (bb * front.a);

		return Color(rr, rg, rb);
	}
}