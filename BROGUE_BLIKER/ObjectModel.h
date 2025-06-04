#pragma once
#include "Object.h"

namespace BROGUE_BLIKER
{
	class Model
	{
	protected:
		std::vector<ViewModel> models;
	public:
		virtual void Draw()
		{
			for (auto& model : models)
			{
				ViewModelList::Add(&model);
			}
		}
		virtual void Remove()
		{
			for (auto& model : models)
			{
				ViewModelList::Remove(&model);
			}
		}
		virtual void Update()
		{
			for (auto& model : models)
			{
				ViewModelList::Update(&model);
			}
		}
		virtual void Move(Point2D _position)
		{
			for (auto& model : models)
			{
				model.position = model.default_position + Point2D(_position.x, _position.y);
			}
		}
	};
	class BlockModel : public Model
	{
	private:
		Point2D size;
	public:
		BlockModel(int _x, int _y, int _w, int _h, Color _color) : size(Point2D(_w, _h))
		{
			models.push_back(ViewModel(0 - size.x / 2, 0 - size.y / 2, Squea(size), 1, Color(gray)));
			models.push_back(ViewModel(0 - size.x / 2 + 1, 0 - size.y / 2 + 1, Squea(Point2D(size)), 1, Color(gray)));
			models.push_back(ViewModel(0 - size.x / 2 + 1, 0 - size.y / 2 + 1, Squea(Point2D(size.x - 2, size.y - 2)), 0, Color(white)));
			for (auto& model : models)
			{
				model.position = model.default_position + Point2D(_x, _y);
			}
			models[2].color = _color;
			models[0].color = _color + Color(128, 128, 128, _color.a);
			models[1].color = _color - Color(128, 128, 128, _color.a);
		}
	};

	class BallModel : public Model
	{
	public:
		BallModel(int _x, int _y, Color _color) 
		{
			models.push_back(ViewModel(0, 0, Circle(5, true), 0, Color(white)));
			models[0].position = models[0].position + Point2D(_x, _y);
			models[0].color = _color;
		}
	};
	class BarModel : public Model
	{
	private:
		Point2D size;
		bool down;
	public:
		BarModel(int _x, int _y, int _w, int _h, Color _color, bool down) : size(Point2D(_w, _h)), down(down)
		{
			if (!down)
			{
				std::swap(size.x, size.y);
			}
			models.push_back(ViewModel(0 - size.x / 2, 0 - size.y / 2, Squea(size), 0, Color(white)));
			models[0].position = models[0].position + Point2D(_x, _y);
			models[0].color = _color;
		}
		Point2D getSize()
		{
			return size;
		}
	};
}