#pragma once
#include "ViewModel.h"
#include "Input.h"
#include "Collision.h"

namespace BROGUE_BLIKER
{
	class Object
	{
	protected:
		Point2D position;
		Point2D size;
		Collision collision;
	public:
		Object() : position(0, 0) {}
		Object(int x, int y, int w, int h) : position(x, y), size(w, h), collision() {}
		virtual void Draw() {}
		virtual void Update() {}
		virtual void Remove() {}
		virtual void Move() {}
		Point2D GetPosition() { return position; }
		void SetCollision(int x, int y, int w, int h) { collision = Collision(x, y, w, h); }
		Collision GetCollision() { return collision; }
	};
}