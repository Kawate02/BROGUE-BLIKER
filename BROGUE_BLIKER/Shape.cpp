#include "Shape.h"

namespace BROGUE_BLIKER
{
	Shape::Shape() : Bitmap()
	{

	}
	Shape::Shape(Bitmap _pixels) : Bitmap(_pixels)
	{
	}

	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="begin">始点</param>
	/// <param name="end">終点</param>
	/// <param name="lineWidth">線の太さ</param>
	Line::Line(Point2D begin, Point2D end, int lineWidth) : Shape(LineGenerator(begin, end, lineWidth)) {}

	Bitmap Line::LineGenerator(Point2D begin, Point2D end, int lineWidth)
	{
		int x = end.x - begin.x;
		int y = end.y - begin.y;
		Bitmap list;
		list.Init(x, y);
		for (auto i = 0; i < x; i++)
		{
			if (x == 0) break;
			list.SetDot(Color(white), (int)i * list.Width() +(int)(y / x * i), 0);
		}
		for (auto i = 0; i < y; i++)
		{
			if (y == 0) break;
			list.SetDot(Color(white), (int)(x / y * i) * list.Width() + (int)i, 0);
		}
		return list;
	}

	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="end">縦横の長さ</param>
	Square::Square(Point2D end) : Shape(SqueaGenerator(Point2D(0, 0), end)) {}

	Bitmap Square::SqueaGenerator(Point2D begin, Point2D end)
	{
		int x = end.x - begin.x;
		int y = end.y - begin.y;
		Bitmap list;
		list.Init(x, y);
		for (auto i = 0; i < x; i++)
		{
			for (auto j = 0; j < y; j++)
			{
				list.SetDot(Color(white), j * list.Width() + i, 0);
			}
		}
		return list;
	}

	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="radius">半径</param>
	/// <param name="fill">中身を埋めるか</param>
	Circle::Circle(int radius, bool fill) : Shape(CircleGenerator(radius, fill)){}
	Bitmap Circle::CircleGenerator(int radius, bool fill)
	{
		Bitmap list;
		list.Init(radius * 2, radius * 2);
		for (auto i = fill ?  1 : radius; i <= radius; i++)
		{
			for (auto j = 0; j < 360; j++)
			{
				int x = (int)(i * cos(j));
				int y = (int)(i * sin(j));
				list.SetDot(Color(white), radius + x + (radius * 2) * (y + radius), 0);
			}
		}
		return list;
	}
}