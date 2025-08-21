#pragma once
#include "ViewModel.h"
#include "Input.h"
#include "Collision.h"

namespace BROGUE_BLIKER
{
	enum ObjectType
	{
		BALL = 0,
		BAR,
		BLOCK,
		UI
	};
	class Object
	{
	protected:
		Point2D position;
		Point2D size;
		Collision collision;
		int layer;
	public:
		Object() : position(0, 0), layer(0) {}
		Object(int x, int y, int w, int h, int _layer) : position(x, y), layer(_layer),  size(w, h), collision() {}
		virtual void Draw() {}
		virtual void Update(int crrentTime) {}
		virtual void Remove() {}
		virtual void Move(Point2D pos) { position += pos; }
		Point2D GetPosition() { return position; }
		void SetCollision(int x, int y, int w, int h) { collision = Collision(x, y, w, h); }
		Collision GetCollision() { return collision; }
	};
}