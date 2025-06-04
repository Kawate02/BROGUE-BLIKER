#pragma once
#include "DxLib.h"

namespace BROGUE_BLIKER
{
#define ESCAPE 0x01
#define SPACE 0x39
#define MOUSE_LEFT 0x01

	class Input
	{
	public:
		Input();
		static int mouse_pos[2];
		void Update();
		static bool KeyPress(int);
		static bool KeyDown(int);
		static bool MousePress(int);
		static bool MouseDown(int);
	private:
		static int key[256];
		static int mouse;
		void InputKey();
	};
}