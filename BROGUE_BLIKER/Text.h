#pragma once
#include <string>
#include <vector>
#include <windows.h>

#include "Macro.h"
#include "Point2D.h"
#include "ViewModel.h"
#include "TextDictionary.h"

namespace BROGUE_BLIKER
{
#define TEXT_BETWEEN_PIXEL 0

	class Text
	{
	private:
		std::vector<TextStruct> text;
		ViewModel vm;
		Color color = Color(white);
	public:
		Point2D pos;
		int layer;
		Text(Point2D pos, const wchar_t* str, int _layer, const wchar_t* fontName, Color color = Color(white), int fontSize = 16);

		void SetText(const std::string str);
		void SetFontSize(int size, int index = 0);
		ViewModel CreateText();
		void Draw();
		void Update(int crrentTime);
		void Remove();
	};
}