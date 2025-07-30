#include "TextDictionary.h"

namespace BROGUE_BLIKER
{
	std::unordered_map<TextStruct, Bitmap> TextDictionary::dictionary;
	TextDictionary::TextDictionary()
	{
	}
	void TextDictionary::Add(TextStruct key, Bitmap bitmap)
	{
		dictionary[key] = bitmap;
	}
	Bitmap TextDictionary::Get(TextStruct key)
	{
		return dictionary[key];
	}
	bool TextDictionary::Contains(TextStruct key)
	{
		if (dictionary.count(key))
		{
			return true;
		}
		return false;
	}
}
