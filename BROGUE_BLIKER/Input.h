#pragma once
#include <windows.h>

namespace BROGUE_BLIKER
{
#define ESCAPE 0x1B
#define SPACE 0x20
#define MOUSE_LEFT 0x01
#define MOUSE_RIGHT 0x02
#define MOUSE_MIDDLE 0x04

	class Input
	{
	public:
		Input();
		static int mouse_pos[2];
		void Update(HWND hWnd);
		static bool KeyPress(int);
		static bool KeyDown(int);
	private:
		static BYTE key[256];
		void InputKey();
		void GetCursorPoint(HWND hwnd);
	};
}