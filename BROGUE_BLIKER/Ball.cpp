#include "Ball.h"

namespace BROGUE_BLIKER
{
	Ball::Ball() : move_speed(BALL_MOVE_SPEED), model(0, 0, Color(white)), Object(0, 0, BALL_SIZE * 2, BALL_SIZE * 2) {}
	Ball::Ball(int _x, int _y, Color _color) : move_speed(BALL_MOVE_SPEED), model(_x, _y, _color), Object(_x, _y, BALL_SIZE * 2, BALL_SIZE * 2) {}
	void Ball::Draw()
	{
		model.Draw();
	}
	void Ball::Update()
	{
		Move();
		SetCollision(position.x - BALL_SIZE, position.y - BALL_SIZE, BALL_SIZE * 2, BALL_SIZE * 2);
		model.Move(position);
		model.Update();
	}
	void Ball::Remove()
	{
		model.Remove();
	}
	void Ball::Move()
	{
		position = Point2D(position.x + velocity.x * move_speed, position.y + velocity.y * move_speed);
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
	void Ball::BoundOnBlock(Block *obj, std::vector<Point2D> hitPosList)
	{
		velocity = obj->GetReflectVector(velocity, hitPosList);
		Move();
		SetCollision(position.x - BALL_SIZE, position.y - BALL_SIZE, BALL_SIZE * 2, BALL_SIZE * 2);
	}
	void Ball::BoundOnBar(Bar *obj, std::vector<Point2D> hitPosList)
	{
		move_speed += 0.1;
		velocity = obj->GetReflectVector(velocity, this);
		Move();
		SetCollision(position.x - BALL_SIZE, position.y - BALL_SIZE, BALL_SIZE * 2, BALL_SIZE * 2);
	}
}