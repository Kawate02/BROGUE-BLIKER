#include "Block.h"

#include "Input.h"

namespace BROGUE_BLIKER
{
	Block::Block() : model(0, 0, BLOCK_WIDTH, BLOCK_HEIGHT, Color(white)), Object(0, 0, BLOCK_WIDTH, BLOCK_HEIGHT)
	{
	}
	Block::Block(int _x, int _y, Color _color) : model(_x, _y, BLOCK_WIDTH, BLOCK_HEIGHT, _color), Object(_x, _y, BLOCK_WIDTH, BLOCK_HEIGHT)
	{
		
	}
	void Block::Draw()
	{
		model.Draw();
	}
	void Block::Update()
	{
		SetCollision(position.x - BLOCK_WIDTH / 2, position.y - BLOCK_HEIGHT / 2, BLOCK_WIDTH, BLOCK_HEIGHT);
	}
	void Block::Remove()
	{
		model.Remove();
	}
	bool Block::IsHitToBlockSide(std::vector<Point2D> hitPoint)
	{
		std::vector<Point2D> side;
		std::vector<Point2D> upanddown;
		for (auto i = 0; i < hitPoint.size(); i++)
		{
			if (hitPoint[i].x == position.x - BLOCK_WIDTH / 2 || hitPoint[i].x == position.x + BLOCK_WIDTH / 2)
			{
				side.push_back(hitPoint[i]);
			}
			else if (hitPoint[i].y == position.y - BLOCK_HEIGHT / 2 || hitPoint[i].y == position.y + BLOCK_HEIGHT / 2)
			{
				upanddown.push_back(hitPoint[i]);
			}
		}
		if (side.size() >= upanddown.size()) return true;
		return false;
	}
	Vector Block::GetReflectVector(Vector vec, std::vector<Point2D> hitPoint)
	{
		if (IsHitToBlockSide(hitPoint)) return Vector(vec.x * -1, vec.y);
		else return Vector(vec.x, vec.y * -1);
	}
	void Block::Break()
	{
		Remove();
	}
}
