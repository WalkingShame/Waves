#pragma once


class Window
{
public:
	Window(HINSTANCE hInstande, std::wstring title);
	~Window();

	void Show();
	void Hide();

private:
	HWND m_windowHandle;
};

