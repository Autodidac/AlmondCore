#pragma once

//#include "aleConfig.h"
#include "Engine.h"  // Assuming this remains a necessary include

#define USE_HEADLESS
#ifndef USE_HEADLESS

#ifdef _WIN32
#include <windows.h>      // Include windows.h for necessary WinAPI functions
#include "resource.h"

// Global Variables for Windows
inline HINSTANCE hInst = nullptr;  // Handle to the application instance
inline HWND hWnd = nullptr;        // Handle to the main window

// Global Default Window Size
constexpr int WINDOW_WIDTH = 800;
constexpr int WINDOW_HEIGHT = 600;

// Namespace to encapsulate key state tracking
namespace KeyStates {
    inline bool rightArrowKeyPressed = false;
    inline bool downArrowKeyPressed = false;
    inline bool leftArrowKeyPressed = false;
    inline bool upArrowKeyPressed = false;
    inline bool escapeKeyPressed = false;
}

// Forward Declarations (Add these)
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

// Function to print the last Win32 error
inline void PrintLastWin32Error(const wchar_t* lpszFunction) {
    DWORD errorCode = GetLastError();
    if (errorCode == 0) {
        return;
    }

    wchar_t* errorMsg;
    FormatMessageW(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
        nullptr, errorCode, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPWSTR)&errorMsg, 0, nullptr
    );
    wprintf(L"%s failed with error %d: %s", lpszFunction, errorCode, errorMsg);
    LocalFree(errorMsg);
}

// Utility function to register window class
inline ATOM MyRegisterClass(HINSTANCE hInstance, LPCWSTR windowClass, LPCWSTR title) {
    WNDCLASSEXW wcex = { sizeof(WNDCLASSEXW), CS_HREDRAW | CS_VREDRAW, WndProc,
                         0, 0, hInstance, LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION)),
                         LoadCursor(nullptr, IDC_ARROW), (HBRUSH)(COLOR_WINDOW + 1),
                         nullptr, windowClass, LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION)) };

    return RegisterClassExW(&wcex);
}

// Window initialization function
inline HWND InitWindowInstance(HINSTANCE hInstance, int nCmdShow, LPCWSTR windowClass, LPCWSTR title) {
    hInst = hInstance;
    hWnd = CreateWindowExW(0, windowClass, title, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
        WINDOW_WIDTH, WINDOW_HEIGHT, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd) {
        PrintLastWin32Error(L"CreateWindowExW");
        return nullptr;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);
    return hWnd;
}

// Message handler for window procedure
inline LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
    case WM_COMMAND: {
        int wmId = LOWORD(wParam);
        switch (wmId) {
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    } break;

    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        EndPaint(hWnd, &ps);
    } break;

    case WM_LBUTTONUP:
        InvalidateRect(hWnd, nullptr, TRUE);
        std::cout << "Button clicked!" << std::endl;
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for the about box
inline INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
    if (message == WM_INITDIALOG) {
        return (INT_PTR)TRUE;
    }
    if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) {
        EndDialog(hDlg, LOWORD(wParam));
        return (INT_PTR)TRUE;
    }
    return (INT_PTR)FALSE;
}

// WinMain definition for Windows Desktop
int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow) {
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    LPCWSTR szTitle = L"Almond Engine";
    LPCWSTR szWindowClass = L"AlmondCoreWindowClass";

    MyRegisterClass(hInstance, szWindowClass, szTitle);

    if (!InitWindowInstance(hInstance, nCmdShow, szWindowClass, szTitle)) {
        return FALSE;
    }

    //AlmondEngine engine;
    MSG msg = {};
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_ALMONDCORELIB));

    // engine.RunWin32Desktop(msg, hAccelTable);

    return (int)msg.wParam;
}

#else  // Other platforms (e.g., Linux, macOS)
// Cross-platform code goes here, potentially SDL or Vulkan-specific logic
#endif  // _WIN32

#else  // Headless mode
// Headless mode logic if required
int main(int argc, char** argv) {
   // Engine engine(6);
  //  engine.run();
    return 0;
}
#endif  // USE_HEADLESS
