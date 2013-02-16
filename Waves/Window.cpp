#include "stdafx.h"
#include "Window.h"

namespace
{
	LRESULT WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{

	}
}


Window::Window(HINSTANCE hInstance, std::wstring title)
{
	WNDCLASSEX wndClass;
	::ZeroMemory(&wndClass, sizeof(wndClass));

	wndClass.cbSize = sizeof(WNDCLASS);
	wndClass.style			= CS_HREDRAW | CS_VREDRAW;
	wndClass.lpfnWndProc	= WndProc;
	wndClass.cbClsExtra		= 0;
	wndClass.cbWndExtra		= 0;
	wndClass.hInstance		= hInstance;
	wndClass.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WAVES));
	wndClass.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wndClass.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wndClass.lpszMenuName	= MAKEINTRESOURCE(IDC_WAVES);
	wndClass.lpszClassName	= title.c_str();
	wndClass.hIconSm		= LoadIcon(wndClass.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	m_windowHandle = CreateWindow(title.c_str(), title.c_str(),  WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);
}


Window::~Window(void)
{
}

void Window::Show()
{
	ShowWindow(m_windowHandle, SW_SHOWDEFAULT);
	UpdateWindow(m_windowHandle);
}

void Window::Hide()
{
	ShowWindow(m_windowHandle, SW_HIDE);
}
