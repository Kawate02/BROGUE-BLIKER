#include "Bitmap.h"

namespace BROGUE_BLIKER
{
	void Bitmap::Init(int _width, int _height)
	{
		width = _width;
		height = _height;
		bitmap.resize(width * height);
	}
	/// <summary>
	/// bitmap‚Écolorƒf[ƒ^‚ğ“o˜^
	/// </summary>
	/// <param name="_color">“o˜^‚·‚éF</param>
	/// <param name="index">“o˜^‚·‚éêŠ</param>
	void Bitmap::SetDot(Color _color, int index, int _layer)
	{
		if (index < 0 || index >= bitmap.size()) return;
		switch (bitmap[index].state)
		{
		case Dotdata::Null: //ŠY“–‰ÓŠ‚ª‹ó”’‚Ìê‡
			bitmap[index].color = _color;
			bitmap[index].state = Dotdata::Fill;
			bitmap[index].layer = _layer;
			break;
		case Dotdata::Fill: //ŠY“–‰ÓŠ‚ÉŠù‚ÉF‚ª“o˜^‚³‚ê‚Ä‚¢‚éê‡
			if (bitmap[index].layer > _layer) return;
			bitmap[index].color = AlphaBlend(_color, bitmap[index].color);
			bitmap[index].layer = _layer;
			break;
		default:
			break;
		}
	}

	/// <summary>
	/// bitmap‚ğ‰Šú‰»
	/// </summary>
	void Bitmap::ClearBitmap()
	{
		for (int i = 0; i < bitmap.size(); i++)
		{
			bitmap[i].state = Dotdata::Null;
		}
	}
	int Bitmap::Width()
	{
		return width;
	}
	int Bitmap::Height()
	{
		return height;
	}
	int Bitmap::Size()
	{
		return width * height;
	}
	std::vector<Dotdata> Bitmap::GetBitmap()
	{
		return bitmap;
	}
	/// <summary>
	/// “Á’è‚Ìbit‚Ì‚İ’Šo
	/// </summary>
	/// <param name="index"></param>
	/// <returns></returns>
	Dotdata Bitmap::GetDotdata(int index)
	{
		return bitmap[index];
	}
}

