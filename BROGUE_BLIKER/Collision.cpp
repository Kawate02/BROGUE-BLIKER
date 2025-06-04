#include "Collision.h"

namespace BROGUE_BLIKER
{
	std::vector<Point2D> CollisionCheck(Collision obj, Collision other)
	{
		std::vector<Point2D> list;
		for (auto i = 0; i <= obj.w; i++)
		{
			for (auto j = 0; j <= obj.h; j++)
			{
				if (obj.x + i <= other.x + other.w && obj.x + i >= other.x &&
				obj.y + j <= other.y + other.h && obj.y + j >= other.y)
				{
					list.push_back(Point2D(obj.x + i, obj.y + j));
				}
			}
		}
		return list;
	}
}