#pragma once
#include "ObjectModel.h"
#include "Vector.h"
#include "Block.h"
#include "Bar.h"

namespace BROGUE_BLIKER
{
#define BALL_SIZE 5
#define BALL_MOVE_SPEED 5
	class Ball : public Object
	{
	private:
		BallModel model;
		int size = BALL_SIZE;
		float move_speed;
		Vector velocity;
	public:
		Ball();
		Ball(int _x, int _y, Color _color);
		void Draw() override;
		void Update() override;
		void Remove() override;
		void Move();
		void SetVelocity(float, float);
		Vector GetVelocity();
		void SetSpeed(float);
		void BoundOnBlock(Block*, std::vector<Point2D>);
		void BoundOnBar(Bar*, std::vector<Point2D>);
	};
}