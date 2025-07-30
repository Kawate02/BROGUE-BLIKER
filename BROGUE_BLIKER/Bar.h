#pragma once
#include "ObjectModel.h"
#include "Vector.h"
#include "Effects.h"

namespace BROGUE_BLIKER
{
#define BAR_WIDTH 40
#define BAR_HEIGHT 5
	class Bar : public Object
	{
	private:
		BarModel model;
		bool down;
		std::vector<EffectForBar*> effects;
	public:
		Bar(int _x, int _y, Color _color, bool down);
		void Draw() override;
		void Update(int crrentTime) override;
		void Remove() override;
		void Rotate(bool right);
		void HitOnBall(Ball* ball);
		void AddEffect(EffectForBar* _effect);
		Vector GetReflectVector(Vector, Object*);
	};
}