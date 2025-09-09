#pragma once
#include "ObjectModel.h"
#include "Vector.h"
#include "Block.h"
#include "Bar.h"
#include "Effects.h"

namespace BROGUE_BLIKER
{
#define BALL_RADIUS 5
#define BALL_MOVE_SPEED 10
	class Ball : public Object
	{
	private:
		BallModel model;
		int size = BALL_RADIUS;
		float move_speed;
		Vector velocity = Vector(0, -1);
		std::vector<EffectForBall*> effects;
	public:
		Ball();
		Ball(int _x, int _y, Color _color);
		void Draw() override;
		void Update(int crrentTime) override;
		void Remove() override;
		void SetVelocity(float, float);
		Vector GetVelocity();
		void SetSpeed(float);
		float GetSpeed();
		void BoundOnBlock(Block*, std::vector<Point2D>);
		void BoundOnBar(Bar*, std::vector<Point2D>);
		void AddEffect(EffectForBall* _effect);

		float base_speed = BALL_MOVE_SPEED;
		bool deleteFlag = false;
	};
}