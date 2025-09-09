#include "Input.h"

#include <iostream>

namespace BROGUE_BLIKER
{
	int Input::mouse_pos[2];
	BYTE Input::key[256];
	Input::Input() {}

	void Input::Update(HWND hwnd)
	{
		GetCursorPoint(hwnd);
		InputKey();
	}

	void Input::InputKey()
	{
		static BYTE buf[256];

		if (!GetKeyboardState(buf)) return;

		for (int i = 0; i < 256; i++)
		{
			if (buf[i] & 0x80)
			{
				if (key[i] == 0) key[i] = 1;
				else if (key[i] == 1) key[i] = 2;
			}
			else key[i] = 0;
		}
	}

	void Input::GetCursorPoint(HWND hwnd)
	{
		static POINT cursor_pos;

		GetCursorPos(&cursor_pos);
		ScreenToClient(hwnd, &cursor_pos);

		mouse_pos[0] = cursor_pos.x;
		mouse_pos[1] = cursor_pos.y;
	}

	bool Input::KeyPress(int keycode)
	{
		return !(key[keycode] & 0);
	}

	bool Input::KeyDown(int keycode)
	{
		return key[keycode] & 1;
	}
}