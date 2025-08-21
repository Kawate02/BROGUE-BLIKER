#include "Ball.h"

namespace BROGUE_BLIKER
{
	Ball::Ball() : move_speed(BALL_MOVE_SPEED), model(0, 0, Color(white)), Object(0, 0, BALL_RADIUS * 2, BALL_RADIUS * 2, 0) {}
	Ball::Ball(int _x, int _y, Color _color) : move_speed(BALL_MOVE_SPEED), model(_x, _y, _color), Object(_x, _y, BALL_RADIUS * 2, BALL_RADIUS * 2, 0) {}
	void Ball::Draw()
	{
		model.Draw();
	}
	void Ball::Update(int crrentTime)
	{
		if (Input::KeyDown(MOUSE_LEFT) && velocity.x == 0 && velocity.y == 0)
		{
			SetVelocity(0, -1);
		}
		Move(Point2D(velocity.x * move_speed, velocity.y * move_speed));
		SetCollision(position.x - BALL_RADIUS, position.y - BALL_RADIUS, BALL_RADIUS * 2, BALL_RADIUS * 2);
		if (position.x < 0 || position.y < 0 || position.x > WINDOW_WIDTH || position.y > WINDOW_HEIGHT)
		{
			deleteFlag = true;
		}
		for (auto& effect : effects)
		{
			effect->OnUpdate(crrentTime, this);
		}
		model.Move(position);
		model.Update();
	}

	void Ball::Remove()
	{
		model.Remove();
	}

	void Ball::SetVelocity(float _x, float _y)
	{
		velocity.x = _x;
		velocity.y = _y;
	}

	Vector Ball::GetVelocity()
	{
		return velocity;
	}

	void Ball::SetSpeed(float speed)
	{
		move_speed = speed;
	}

	float Ball::GetSpeed()
	{
		return move_speed;
	}

	void Ball::BoundOnBlock(Block *obj, std::vector<Point2D> hitPosList)
	{
		velocity = obj->GetReflectVector(velocity, hitPosList);
		Move(Point2D(position.x + velocity.x * move_speed, position.y + velocity.y * move_speed));
		SetCollision(position.x - BALL_RADIUS, position.y - BALL_RADIUS, BALL_RADIUS * 2, BALL_RADIUS * 2);
	}

	void Ball::BoundOnBar(Bar *obj, std::vector<Point2D> hitPosList)
	{
		move_speed += 0.1;
		velocity = obj->GetReflectVector(velocity, this);
		Move(Point2D(position.x + velocity.x * move_speed, position.y + velocity.y * move_speed));
		SetCollision(position.x - BALL_RADIUS, position.y - BALL_RADIUS, BALL_RADIUS * 2, BALL_RADIUS * 2);
	}
	void Ball::AddEffect(EffectForBall* _effect)
	{
		effects.push_back(_effect);
		_effect->OnAddEffect(this);
	}
}