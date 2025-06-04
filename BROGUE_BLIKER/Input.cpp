#include "Input.h"

namespace BROGUE_BLIKER
{
	int Input::mouse_pos[2];
	int Input::key[256];
	int Input::mouse;

	int oldmouse = 0;
	Input::Input() {}

	void Input::Update()
	{
		GetMousePoint(&mouse_pos[0], &mouse_pos[1]);
		InputKey();
	}

	void Input::InputKey()
	{
		static char buf[256];
		GetHitKeyStateAll(buf);
		for (int i = 0; i < 256; i++)
		{
			if (buf[i])
			{
				if (key[i] == 0) key[i] = 1;
				else if (key[i] == 1) key[i] = 2;
			}
			else key[i] = 0;
		}

		mouse = GetMouseInput();
	}

	bool Input::KeyPress(int keycode)
	{
		return !(key[keycode] & 0);
	}

	bool Input::KeyDown(int keycode)
	{
		return key[keycode] & 1 ? true : false;
	}
	bool Input::MousePress(int keycode)
	{
		return mouse & keycode;
	}
	bool Input::MouseDown(int keycode)
	{
		bool result = mouse & keycode && !(oldmouse & mouse);
		oldmouse = mouse;
		return result;
	}
}