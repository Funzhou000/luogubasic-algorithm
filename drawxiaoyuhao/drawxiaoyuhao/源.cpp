#include <windows.h>

// 窗口过程函数
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    static int startX, startY, endX, endY;
    static bool drawing = false;

    switch (uMsg) {
    case WM_LBUTTONDOWN: // 鼠标左键按下
        startX = LOWORD(lParam);
        startY = HIWORD(lParam);
        drawing = true;
        break;

    case WM_MOUSEMOVE: // 鼠标移动
        if (drawing) {
            endX = LOWORD(lParam);
            endY = HIWORD(lParam);
            InvalidateRect(hwnd, NULL, TRUE); // 请求重绘
        }
        break;

    case WM_LBUTTONUP: // 鼠标左键松开
        drawing = false;
        break;

    case WM_PAINT: // 绘制
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        if (!drawing && startX != endX && startY != endY) {
            MoveToEx(hdc, startX, startY, NULL);
            LineTo(hdc, (startX + endX) / 2, endY);
            LineTo(hdc, startX, endY);
        }
        EndPaint(hwnd, &ps);
        break;
    }

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    const char CLASS_NAME[] = "Sample Window Class";

    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(0, CLASS_NAME, "Draw Less Than Sign", WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, NULL, NULL, hInstance, NULL);

    if (hwnd == NULL) {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
