#include "BROGUE_BLIKER.h"

using namespace BROGUE_BLIKER;

HWND hwnd;
HDC hdc;

#include <iostream>
#include <fcntl.h>
#include <io.h>
//デバッグ用コンソール
void OpenConsole()
{
    AllocConsole();
    FILE* fp;
    freopen_s(&fp, "CONOUT$", "w", stdout);
    freopen_s(&fp, "CONIN$", "r", stdin);
    std::ios::sync_with_stdio();
}


LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) 
{
    switch (msg) 
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow) 
{
    OpenConsole();
    std::cout << "[Logger] Initialized" << std::endl;
    const char CLASS_NAME[] = "MyGameWindow";

    WNDCLASS wc = {};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    RegisterClass(&wc);

    std::function<long long(void)> currentTimeMicro = []() 
        {
            std::chrono::system_clock::duration d = std::chrono::system_clock::now().time_since_epoch();
            return std::chrono::duration_cast<std::chrono::microseconds>(d).count();
        };

    int fps = 60;
    long long end = currentTimeMicro();
    long long next = end + (1000 * 1000 / fps);

    RECT rect = { 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT };
    AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);

    int windowWidth = rect.right - rect.left;
    int windowHeight = rect.bottom - rect.top;

    hwnd = CreateWindowEx
    (
        0, CLASS_NAME, "BROGUE_BLIKER",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, windowWidth, windowHeight,
        nullptr, nullptr, hInstance, nullptr
    );
    if (!hwnd) return 0;

    ShowWindow(hwnd, nCmdShow);

    Init(hwnd); //ゲーム初期化

    MSG msg = {};
    while (true) {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) 
        {
            if (msg.message == WM_QUIT) break;
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        Update(hwnd); //ゲームループ

        end = currentTimeMicro();
        if (end < next) 
        {
            std::this_thread::sleep_for(std::chrono::microseconds(next - end));

            next += (1000 * 1000 / fps);
        }
        else 
        {
            next = end + (1000 * 1000 / fps);
        }
    }
	Exit(hwnd); //ゲーム終了

    return 0;
}