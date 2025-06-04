#include "Bar.h"
#include "Debug.h"
namespace BROGUE_BLIKER
{
	Bar::Bar(int _x, int _y, Color _color, bool down) :down(down), model(_x, _y, BAR_WIDTH, BAR_HEIGHT, _color, down), Object(_x, _y, BAR_WIDTH, BAR_HEIGHT)
	{
		SetCollision(position.x - model.getSize().x / 2, position.y - model.getSize().y / 2, model.getSize().x, model.getSize().y);
	}
	void Bar::Update()
	{
		if (down)
		{
			if (Input::mouse_pos[0] > WINDOW_WIDTH - 30) position.x = WINDOW_WIDTH - 30;
			else if (Input::mouse_pos[0] < 30) position.x = 30;
			else position.x = Input::mouse_pos[0];
		}
		else if (!down)
		{
			if (Input::mouse_pos[1] > WINDOW_HEIGHT - 30) position.y = WINDOW_HEIGHT - 30;
			else if (Input::mouse_pos[1] < 30) position.y = 30;
			else position.y = Input::mouse_pos[1];
		}
		SetCollision(position.x - model.getSize().x / 2, position.y - model.getSize().y / 2, model.getSize().x, model.getSize().y);
		model.Move(position);
		model.Update();
	}
	void Bar::Draw()
	{
		model.Draw();
	}
	void Bar::Remove()
	{
		model.Remove();
	}
	void Bar::Rotate(bool right)
	{

	}
	Vector Bar::GetReflectVector(Vector vec, Object *obj)
	{
		std::vector<Point2D> face;
		int pos = 0;
		float angle = 0;
		if (down)
		{
			angle = (obj->GetPosition().x - position.x) / ((float)BAR_WIDTH / 2);
			return Vector(sin(angle), cos(angle) * vec.y /abs(vec.y) * -1);
		}
		else
		{
			angle = (obj->GetPosition().y - position.y) / ((float)BAR_WIDTH / 2);
			return Vector(cos(angle) * vec.x / abs(vec.x) * -1, sin(angle));
		}
	}
}