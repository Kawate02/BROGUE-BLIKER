#pragma once
#include "Point2D.h"
#include <vector>
#include <string>
namespace BROGUE_BLIKER
{
	class Collision
	{
	public:
		int x, y, w, h;
		Collision(int _x, int _y, int _w, int _h) : x(_x), y(_y), w(_w), h(_h) {}
		Collision() : x(0), y(0), w(0), h(0) {}
		std::string ToString() { return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(w) + ", " + std::to_string(h) + ")"; }
	};
	std::vector<Point2D> CollisionCheck(Collision obj, Collision other);
}