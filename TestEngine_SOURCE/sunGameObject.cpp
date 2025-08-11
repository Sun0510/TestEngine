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
			mY -= 0.01f;// ������ ��ǥ��� ���� �������� (0,0)�̱� ������ ���̳ʽ�
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			mY += 0.01f;
		}
		
	}
	void GameObject::LateUpdate()
	{

	}
	void GameObject::Render(HDC hdc)
	{

		HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
		SelectObject(hdc, brush);

		Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);
		DeleteObject(brush);

		HPEN pen = CreatePen(PS_SOLID, 3, RGB(128, 128, 128));
		SelectObject(hdc, pen);

		DeleteObject(pen);

		brush = (HBRUSH)GetStockObject(GRAY_BRUSH);
		SelectObject(hdc, brush);
	}
}

