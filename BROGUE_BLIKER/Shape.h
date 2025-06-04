#pragma once
#include "Point2D.h"
#include "Macro.h"

#include <vector>


namespace BROGUE_BLIKER
{
	class Shape
	{
	private:
		std::vector<Point2D> pixels;

	public:
		Shape();
		Shape(std::vector<Point2D> pixels);
		std::vector<Point2D> GetShape();

		/*Shape operator+(const Shape& other)
		{
			std::vector<Point2D> result;
			std::merge(pixels.begin(), pixels.end(), other.pixels.begin(), other.pixels.end(), std::back_inserter(result));
			return Shape(result);
		}*/
	};

	class Line : public Shape
	{
	private:
		std::vector<Point2D> LineGenerator(Point2D begin, Point2D end, int lineWidth);
	public:
		Line(Point2D begin, Point2D end, int lineWidth);
	};

	class Squea : public Shape
	{
	private:
		std::vector<Point2D> SqueaGenerator(Point2D begin, Point2D end);
	public:
		Squea(Point2D end);
	};

	class Circle : public Shape
	{
	private:
		std::vector<Point2D> CircleGenerator(int radius, bool fill);
	public:
		Circle(int radius, bool fill);
	};
}