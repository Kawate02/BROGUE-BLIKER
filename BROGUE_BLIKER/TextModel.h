#pragma once
#include "Point2D.h"
#include "Bitmap.h"
namespace BROGUE_BLIKER
{
	class TextModel
	{
	private:
		Bitmap bitmap;
		Point2D position;
	public:
	};

	static class TextModelList
	{
	private:
		static std::vector<Bitmap> list;
	public:
		static void Add(Bitmap* bitmap);
		static void Update(Bitmap* bitmap);
		static void Remove(Bitmap* bitmap);
		static void Clear();
		static const std::vector<Bitmap*>& GetList();
	};
}