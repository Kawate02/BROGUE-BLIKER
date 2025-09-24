#include "InGame.h"
#include "Input.h"

namespace BROGUE_BLIKER
{
	void InGameDisplay::Init()
	{
		crrentState = READY;
		oldState = READY;
		crrentStage = GenerateStage(crrentId);
		stageExitFlag = false;
	}
	void InGameDisplay::Update()
	{
		std::cout << frame.GetSize() << std::endl;
		switch (crrentState)
		{
		case DOING:
			if (oldState == PAUSE)
			{
				frame.Remove();
			}

			if (crrentStage->gameClearFlag)
			{
				crrentState = RESULT;
			}
			if (crrentStage->gameOverFlag)
			{
				crrentState = GAMEOVER;
			}
			if (Input::KeyDown(ESCAPE))
			{
				crrentState = PAUSE;
			}
			crrentStage->Update();
			oldState = DOING;
			break;
		case READY:
			if (Input::KeyDown(MOUSE_LEFT))
			{
				crrentState = DOING;
			}
			oldState = READY;
			break;
		case PAUSE:
			if (oldState == DOING)
			{
				frame.AddElement<Button>(Point2D(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 3 * 2 + 50),
					Point2D(200, 40),
					std::vector<ViewModel>{ViewModel(0, 0, Square(Point2D(200, 40)), 0, Color(200, 200, 200))},
					std::vector<Text>{Text(Point2D(0, 0), L"CONTINUE", 0, L"游ゴシック", Color(black), 16)},
					[this]() { this->crrentState = DOING; frame.Clear(); }, 1, false);
				frame.AddElement<Button>(Point2D(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 3 * 2 + 100),
					Point2D(200, 40),
					std::vector<ViewModel>{ViewModel(0, 0, Square(Point2D(200, 40)), 0, Color(200, 200, 200))},
					std::vector<Text>{Text(Point2D(0, 0), L"EXIT", 0, L"游ゴシック", Color(black), 16)},
					[this]() { this->nextState = TITLE; frame.Clear(); }, 1, false);
				frame.Draw();
			}
			if (Input::KeyDown(ESCAPE))
			{
				crrentState = DOING;
				frame.Clear();
			}
			oldState = PAUSE;
			break;
		case GAMEOVER:
			if (oldState == DOING)
			{
				frame.AddElement<UIElement>(Point2D(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2),
					std::vector<ViewModel>{ },
					std::vector<Text>{ Text(Point2D(0, 0), L"GAME OVER", 0, L"游ゴシック", Color(white), 32) }, 0, false);
				frame.AddElement<Button>(Point2D(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 3 * 2 + 50),
					Point2D(200, 40),
					std::vector<ViewModel>{ViewModel(0, 0, Square(Point2D(200, 40)), 0, Color(200, 200, 200))},
					std::vector<Text>{Text(Point2D(0, 0), L"RETRY", 0, L"游ゴシック", Color(black), 16)},
					[this]() { Remove(); Init(); }, 1, false);
				frame.AddElement<Button>(Point2D(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 3 * 2 + 100),
					Point2D(200, 40),
					std::vector<ViewModel>{ViewModel(0, 0, Square(Point2D(200, 40)), 0, Color(200, 200, 200))},
					std::vector<Text>{Text(Point2D(0, 0), L"EXIT", 0, L"游ゴシック", Color(black), 16)},
					[this]() { this->nextState = TITLE; frame.Remove(); }, 1, false);
				frame.Draw();
			}
			oldState = GAMEOVER;
			break;
		case RESULT:
			if (oldState == DOING)
			{
				frame.AddElement<UIElement>(Point2D(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2),
					std::vector<ViewModel>{ },
					std::vector<Text>{ Text(Point2D(0, 0), L"CLEAR", 0, L"游ゴシック", Color(white), 32) }, 0, false);
				frame.AddElement<Button>(Point2D(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 3 * 2 + 50),
					Point2D(200, 40),
					std::vector<ViewModel>{ViewModel(0, 0, Square(Point2D(200, 40)), 0, Color(200, 200, 200))},
					std::vector<Text>{Text(Point2D(0, 0), L"RETRY", 0, L"游ゴシック", Color(black), 16)},
					[this]() { Remove(); Init(); }, 1, false);
				frame.AddElement<Button>(Point2D(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 3 * 2 + 100),
					Point2D(200, 40),
					std::vector<ViewModel>{ViewModel(0, 0, Square(Point2D(200, 40)), 0, Color(200, 200, 200))},
					std::vector<Text>{Text(Point2D(0, 0), L"EXIT", 0, L"游ゴシック", Color(black), 16)},
					[this]() { this->nextState = TITLE; crrentStage = GenerateStage(crrentId); frame.Remove(); }, 1, false);
				frame.Draw();
			}
			oldState = RESULT;
			break;
		default:
			break;
		}
		frame.Update(0);
	}
	void InGameDisplay::Remove()
	{
		crrentStage->DestroyStage();
		frame.Clear();
	}
	void InGameDisplay::SetStage(Stage::StageId stage)
	{
		crrentId = stage;
	}
	GameState InGameDisplay::GetState()
	{
		return crrentState;
	}
}