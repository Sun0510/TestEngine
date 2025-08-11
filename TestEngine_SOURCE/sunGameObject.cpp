#include "sunGameObject.h"
#include "Input.h"

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
		if (Input::GetKey(eKeyCode::Left))
		{
			mX1 -= 0.01f;
		}

		if (Input::GetKey(eKeyCode::Right))
		{
			mX1 += 0.01f;
		}

		if (Input::GetKey(eKeyCode::Up))
		{
			mY1 -= 0.01f;// ������ ��ǥ��� ���� �������� (0,0)�̱� ������ ���̳ʽ�
		}

		if (Input::GetKey(eKeyCode::Down))
		{
			mY1 += 0.01f;
		}

		//Player2
		if (Input::GetKey(eKeyCode::A))
		{
			mX2 -= 0.01f;
		}

		if (Input::GetKey(eKeyCode::D))
		{
			mX2 += 0.01f;
		}

		if (Input::GetKey(eKeyCode::W))
		{
			mY2 -= 0.01f;// ������ ��ǥ��� ���� �������� (0,0)�̱� ������ ���̳ʽ�
		}

		if (Input::GetKey(eKeyCode::S))
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

