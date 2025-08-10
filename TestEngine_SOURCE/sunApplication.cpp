#include "sunApplication.h"

namespace sun
{
	Application::Application()
		: mHwnd(nullptr),
		mHdc(nullptr),
		mSpeed(0),
		mX(0),
		mY(0)
	{

	}

	Application::~Application()
	{

	}

	void Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);
	}
	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	
	void Application::Update()
	{
		mSpeed += 0.01f;

		if (GetAsyncKeyState(VK_LEFT) & 0x8000) 
		{
			mX -= 0.01f;
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			mX += 0.01f;
		}

		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			mY -= 0.01f; // ������ ��ǥ��� ���� �������� (0,0)�̱� ������ ���̳ʽ�
		}
		
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			mY += 0.01f;
		}


	}
	void Application::LateUpdate()
	{

	}
	void Application::Render()
	{
		HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
		SelectObject(mHdc, brush);

		Rectangle(mHdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);
		DeleteObject(brush);

		HPEN pen = CreatePen(PS_SOLID, 3, RGB(128, 128, 128));
		SelectObject(mHdc, pen);

		DeleteObject(pen);

		brush = (HBRUSH)GetStockObject(GRAY_BRUSH);
		SelectObject(mHdc, brush);


	}
}