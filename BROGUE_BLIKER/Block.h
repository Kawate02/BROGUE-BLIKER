#pragma once
#include "ObjectModel.h"
#include "Vector.h"
#include "Effects.h"

namespace BROGUE_BLIKER
{
#define BLOCK_WIDTH 20
#define BLOCK_HEIGHT 20
	class Block : public Object
	{
	private:
		BlockModel model;
		bool IsHitToBlockSide(std::vector<Point2D>);
		std::vector<EffectForBlock*> effects;
	public:
		Block();
		Block(int _x, int _y, Color _color);
		void Draw() override;
		void Update(int crrentTime) override;
		void Remove() override;
		Vector GetReflectVector(Vector, std::vector<Point2D>);
		void Break();
	};
}