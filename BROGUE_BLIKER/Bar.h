#pragma once
#include "ObjectModel.h"
#include "Vector.h"

namespace BROGUE_BLIKER
{
#define BAR_WIDTH 40
#define BAR_HEIGHT 5
	class Bar : public Object
	{
	private:
		BarModel model;
		bool down;
	public:
		Bar(int _x, int _y, Color _color, bool down);
		void Draw() override;
		void Update() override;
		void Remove() override;
		void Rotate(bool right);
		Vector GetReflectVector(Vector, Object*);
	};
}