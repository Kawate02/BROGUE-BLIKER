#include "EntryPoint.h"
using namespace BROGUE_BLIKER;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(true);
	SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, 0);
	SetWaitVSyncFlag(FALSE);
	if (DxLib_Init() == -1)
	{
		return -1;
	}
	View view;
	Input input;
	GameManager game;
	
	bool end = false;
	while (!end)
	{
		if (ProcessMessage()) end = true;
		input.Update();
		if (Input::KeyDown(ESCAPE)) end = true;
		game.Update();
		view.Update();
		WaitTimer(1);
	}
	
	DxLib_End();
	return 0;
}