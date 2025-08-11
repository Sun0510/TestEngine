#include "sunGameObject.h"

namespace sun {
	GameObject::GameObject()
	{

	}

	GameObject::~GameObject()
	{
	}

	void GameObject::Update()
	{
		//Player1
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			mX1 -= 0.01f;
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			mX1 += 0.01f;
		}

		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			mY1 -= 0.01f;// 윈도우 좌표계상 가장 왼쪽위가 (0,0)이기 때문에 마이너스
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			mY1 += 0.01f;
		}

		//Player2
		if (GetAsyncKeyState('A') & 0x8000)
		{
			mX2 -= 0.01f;
		}

		if (GetAsyncKeyState('D') & 0x8000)
		{
			mX2 += 0.01f;
		}

		if (GetAsyncKeyState('W') & 0x8000)
		{
			mY2 -= 0.01f;// 윈도우 좌표계상 가장 왼쪽위가 (0,0)이기 때문에 마이너스
		}

		if (GetAsyncKeyState('S') & 0x8000)
		{
			mY2 += 0.01f;
		}

	}
	void GameObject::LateUpdate()
	{

	}
	void GameObject::Render(HDC hdc)
	{

		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));
		SelectObject(hdc, brush);

		Rectangle(hdc, 100 + mX2, 100 + mY2, 200 + mX2, 200 + mY2);
		DeleteObject(brush);

		brush = CreateSolidBrush(RGB(255, 0, 0));
		SelectObject(hdc, brush);
		Ellipse(hdc, 300 + mX1, 300 + mY1, 400 + mX1, 400 + mY1);
		DeleteObject(brush);

	}
}

