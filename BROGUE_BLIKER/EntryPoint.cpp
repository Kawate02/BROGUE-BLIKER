#include "EntryPoint.h"
namespace BROGUE_BLIKER
{
	View view;
	Input input;
	GameManager game;

	void Init(HWND hwnd)
	{
		game.Init();
		view.Init(hwnd, WINDOW_WIDTH, WINDOW_HEIGHT);
	}
	void Update(HWND hwnd)
	{
		input.Update(hwnd);
		game.Update();
 		view.Update(hwnd);
	}
	void Exit(HWND hwnd)
	{
		view.Exit(hwnd);
	}
	bool gameEnd()
	{
		return game.GameEndFlag();
	}
}