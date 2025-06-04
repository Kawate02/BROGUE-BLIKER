#pragma once
#include <string>

namespace BROGUE_BLIKER
{
	struct Point2D
	{
		struct
		{
			int x;
			int y;
		};

		Point2D()
		{
			x = 0;
			y = 0;
		}
		Point2D(int _x, int _y) : x(_x), y(_y) {}
		int getAddress()
		{
			return x * y;
		}
		Point2D operator+(const Point2D& other)
		{
			return Point2D(x + other.x, y + other.y);
		}
		Point2D& operator+=(const Point2D& other)
		{
			x += other.x;
			y += other.y;
			return *this;
		}
		Point2D operator-(const Point2D& other)
		{
			return Point2D(x - other.x, y - other.y);
		}
		bool operator==(const Point2D& other)
		{
			return x == other.x && y == other.y;
		}
		std::string toString()
		{
			return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
		}
	};
}