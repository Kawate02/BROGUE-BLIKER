#include "Collision.h"

namespace BROGUE_BLIKER
{
	/// <summary>
	/// 重なっている座標一覧を返す
	/// </summary>
	/// <param name="obj">オブジェクト1</param>
	/// <param name="other">オブジェクト2</param>
	/// <returns>1と2の重複座標</returns>
	std::vector<Point2D> CollisionCheck(Collision obj, Collision other)
	{
		std::vector<Point2D> list;
		for (auto i = 0; i <= obj.w; i++)
		{
			for (auto j = 0; j <= obj.h; j++)
			{
				if (obj.x + i <= other.x + other.w && obj.x + i >= other.x &&
				obj.y + j <= other.y + other.h && obj.y + j >= other.y) // 重複している座標である
				{
					list.push_back(Point2D(obj.x + i, obj.y + j));
				}
			}
		}
		return list;
	}
}