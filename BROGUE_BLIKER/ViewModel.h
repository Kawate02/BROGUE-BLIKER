#pragma once
#include "Shape.h"
#include "Color.h"
#include "TextDictionary.h"

#include <vector>
#include <memory>

///////////////////////////////////////////////////////////////////////////
// Debugging utilities
#include <iostream>
#include <unordered_map>
#include <string>
inline void LogVectorSizeWithCount(const char* funcName, size_t size) {
	static std::unordered_map<std::string, int> callCount;
	int count = ++callCount[funcName];
	std::cout << "[Call #" << count << "] " << funcName << " - list.size() = " << size << std::endl;
}

#define LOG_VECTOR_SIZE() LogVectorSizeWithCount(__FUNCTION__, ViewModelList::GetList().size())

///////////////////////////////////////////////////////////////////////////

namespace BROGUE_BLIKER
{

	struct ViewModel
	{
	public:
		ViewModel();
		ViewModel(int, int, Bitmap, int, Color);
		int layer;
		int id;
		Point2D default_position;
		Point2D position;
		Bitmap bitmap;
		Color color;
		int direction;
	};

	static class ViewModelList
	{
	private:
		static std::vector<ViewModel*> list;
	public:
		static void Add(ViewModel* vm);
		static void Update(ViewModel* vm);
		static void Remove(ViewModel* vm);
		static void Clear();
		static const std::vector<ViewModel*>& GetList();
	};
}