#include "Text.h"

namespace BROGUE_BLIKER
{
	Text::Text(Point2D pos, const wchar_t* str, int layer, const wchar_t* fontName, Color color, int fontSize)
	{
		this->pos = pos;
		this->layer = layer;
		this->color = color;
		for (size_t i = 0; i < wcslen(str); i++)
		{
			TextStruct ts = TextStruct();
			ts.key = str[i];
			ts.font = fontName;
			ts.fontSize = fontSize;
			text.push_back(ts);
		}
	}
	void Text::SetText(const std::string str)
	{
		
	}
	void Text::SetFontSize(int size, int index)
	{
		
	}
	ViewModel Text::CreateText()
	{
		if (text.empty()) return ViewModel();
		Bitmap textResult;
		int allWidth = 0;
		int allHeight = 0;
		for (auto i = 0; i < text.size(); i++)
		{
			wchar_t textTmp[2] = { text[i].key, L'\0' };
			Bitmap textBuffer;
			if (!TextDictionary::Contains(text[i]))
			{
				HDC hdc = CreateCompatibleDC(NULL);

				HFONT hFont = CreateFontW(
					text[i].fontSize, 0, 0, 0,
					FW_NORMAL, FALSE, FALSE, FALSE,
					DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
					DEFAULT_PITCH | FF_DONTCARE, text[i].font);

				SelectObject(hdc, hFont);

				SIZE size;
				GetTextExtentPoint32W(hdc, textTmp, 1, &size);

				int width = static_cast<int>(size.cx) * 1.3;
				int height = static_cast<int>(size.cy) * 1.3;
				textBuffer.Init(width, height);

				BITMAPINFO bmi = {};
				bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
				bmi.bmiHeader.biWidth = width;
				bmi.bmiHeader.biHeight = -height;
				bmi.bmiHeader.biPlanes = 1;
				bmi.bmiHeader.biBitCount = 32;
				bmi.bmiHeader.biCompression = BI_RGB;

				void* bits = nullptr;
				HBITMAP bmp = CreateDIBSection(hdc, &bmi, DIB_RGB_COLORS, &bits, nullptr, 0);
				SelectObject(hdc, bmp);

				HBRUSH bg = CreateSolidBrush(RGB(0, 0, 0));
				RECT rc = { 0, 0, width, height };
				FillRect(hdc, &rc, bg);
				DeleteObject(bg);
				SetBkMode(hdc, TRANSPARENT);
				SetTextColor(hdc, RGB(255, 255, 255));

				TextOutW(hdc, 0, 0, textTmp, 1);

				uint32_t* raw = (uint32_t*)bits;

				for (int y = 0; y < height; ++y) 
				{
					for (int x = 0; x < width; ++x) 
					{
						uint32_t pixel = raw[y * width + x];
						unsigned char r = (pixel & 0x000000FF);
						unsigned char g = (pixel & 0x0000FF00) >> 8;
						unsigned char b = (pixel & 0x00FF0000) >> 16;
						textBuffer.SetDot(Color(r, g, b), y * width + x, 0);
					}
				}
				TextDictionary::Add(text[i], textBuffer);

				DeleteDC(hdc);
			}
			else
			{
				textBuffer = TextDictionary::Get(text[i]);
			}

			allWidth += textBuffer.Width();
			allHeight < textBuffer.Height() ? allHeight = textBuffer.Height() : allHeight = allHeight;
		}
		textResult.Init(allWidth + TEXT_BETWEEN_PIXEL * (text.size() - 1), allHeight);
		int offsetX = 0;
		for (auto i = 0; i < text.size(); i++)
		{
			Bitmap textBuffer = TextDictionary::Get(text[i]);

			for (auto j = 0; j < textBuffer.Height(); j++)
			{
				for (auto k = 0; k < textBuffer.Width(); k++)
				{
					Color color = textBuffer.GetDotdata(j * textBuffer.Width() + k).color;
					if (color.GetColor() != Color(0, 0, 0).GetColor())
					{
						textResult.SetDot(color, j * textResult.Width() + (k + offsetX), 0);
					}
				}
			}
			offsetX += textBuffer.Width() + TEXT_BETWEEN_PIXEL;
		}
		return ViewModel(pos.x, pos.y, textResult, layer, color);
	}
	void Text::Draw()
	{
		if (text.empty()) return;
		vm = CreateText();
		ViewModelList::Add(&vm);
	}
	void Text::Update(int crrentTime)
	{
		ViewModelList::Update(&vm);
	}
	void Text::Remove()
	{
		if (vm.id == -1) return;
		ViewModelList::Remove(&vm);
	}
}
