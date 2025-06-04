#pragma once
#include <string>

namespace BROGUE_BLIKER
{
	struct Vector
	{
		float x, y;
		Vector() : x(0), y(0) {}
		Vector(float x, float y) : x(x), y(y) {}
		Vector operator+(const Vector& other)
		{
			return Vector(x + other.x, y + other.y);
		}
		Vector& operator+=(const Vector& other)
		{
			x += other.x;
			y += other.y;
			return *this;
		}
		Vector operator-(const Vector& other)
		{
			return Vector(x - other.x, y - other.y);
		}
		bool operator==(const Vector& other)
		{
			return x == other.x && y == other.y;
		}
		std::string toString()
		{
			return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
		}
	};
}