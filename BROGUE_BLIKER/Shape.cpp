#include "Shape.h"

namespace BROGUE_BLIKER
{
	Shape::Shape() : pixels()
	{

	}
	Shape::Shape(std::vector<Point2D> _pixels) : pixels(_pixels)
	{

	}
	std::vector<Point2D> Shape::GetShape()
	{
		return pixels;
	}

	Line::Line(Point2D begin, Point2D end, int lineWidth) : Shape(LineGenerator(begin, end, lineWidth)) {}

	std::vector<Point2D> Line::LineGenerator(Point2D begin, Point2D end, int lineWidth)
	{
		float x = end.x - begin.x;
		float y = end.y - begin.y;
		std::vector<Point2D> list;
		for (auto i = 0; i < x; i++)
		{
			if (x == 0) break;
			list.push_back(Point2D((int)i, (int)(y / x * i)));
		}
		for (auto i = 0; i < y; i++)
		{
			if (y == 0) break;
			list.push_back(Point2D((int)(x / y * i), (int)i));
		}
		return list;
	}

	Squea::Squea(Point2D end) : Shape(SqueaGenerator(Point2D(0, 0), end)) {}

	std::vector<Point2D> Squea::SqueaGenerator(Point2D begin, Point2D end)
	{
		int x = end.x - begin.x;
		int y = end.y - begin.y;
		std::vector<Point2D> list;
		for (auto i = 0; i < x; i++)
		{
			for (auto j = 0; j < y; j++)
			{
				list.push_back(Point2D(i, j));
			}
		}
		return list;
	}

	Circle::Circle(int radius, bool fill) : Shape(CircleGenerator(radius, fill)){}
	std::vector<Point2D> Circle::CircleGenerator(int radius, bool fill)
	{
		std::vector<Point2D> list;
		for (auto i = fill ?  1 : radius; i <= radius; i++)
		{
			for (auto j = 0; j < 360; j++)
			{
				list.push_back(Point2D((int)(i * sin(j)), (int)(i * cos(j))));
			}
		}
		return list;
	}
}