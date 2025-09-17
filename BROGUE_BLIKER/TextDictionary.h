#pragma once
#include <unordered_map>
#include "Bitmap.h"

namespace BROGUE_BLIKER
{
	struct TextStruct
	{
		wchar_t key;
		int fontSize;
		const wchar_t* font;

		inline bool operator ==(const TextStruct& other) const
		{
			return key == other.key && fontSize == other.fontSize && font == other.font;
		}
	};
	

	static class TextDictionary
	{
	private:
		static std::unordered_map<TextStruct, Bitmap> dictionary;
	public:
		TextDictionary();
		static void Add(TextStruct key, Bitmap bitmap);
		static Bitmap Get(TextStruct key);
		static bool Contains(TextStruct key);
	};
}

using namespace BROGUE_BLIKER;
namespace std
{
	template<>
	struct hash<TextStruct>
	{
		size_t operator()(const TextStruct& k) const
		{
			return hash<wchar_t>()(k.key) ^ (hash<int>()(k.fontSize) << 1);
		}
	};
}