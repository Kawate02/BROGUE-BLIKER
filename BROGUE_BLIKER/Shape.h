#pragma once
#include "Point2D.h"
#include "Macro.h"
#include "Bitmap.h"

#include <vector>


namespace BROGUE_BLIKER
{
	/// <summary>
	/// 形状を定義する基底クラス
	/// </summary>
	class Shape : public Bitmap
	{
	public:
		Shape();
		Shape(Bitmap pixels);

		/*Shape operator+(const Shape& other)
		{
			std::vector<Point2D> result;
			std::merge(pixels.begin(), pixels.end(), other.pixels.begin(), other.pixels.end(), std::back_inserter(result));
			return Shape(result);
		}*/
	};

	/// <summary>
	/// 直線
	/// </summary>
	class Line : public Shape
	{
	private:
		Bitmap LineGenerator(Point2D begin, Point2D end, int lineWidth);
	public:
		Line(Point2D begin, Point2D end, int lineWidth);
	};

	/// <summary>
	/// 直方体
	/// </summary>
	class Square : public Shape
	{
	private:
		Bitmap SqueaGenerator(Point2D begin, Point2D end);
	public:
		Square(Point2D end);
	};

	/// <summary>
	/// 円形
	/// </summary>
	class Circle : public Shape
	{
	private:
		Bitmap CircleGenerator(int radius, bool fill);
	public:
		Circle(int radius, bool fill);
	};
}