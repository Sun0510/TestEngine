#include "sunGameObject.h"
#include "sunInput.h"
#include "sunTime.h"

namespace sun {
	GameObject::GameObject()
		: mX(0),
		mY(0)
	{

	}

	GameObject::~GameObject()
	{
	}

	void GameObject::Update()
	{
		const float speed = 100.0f;
		//Player1
		if (Input::GetKey(eKeyCode::Left))
		{
			mX -= speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::Right))
		{
			mX += speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::Up))
		{
			mY -= speed * Time::DeltaTime();// 윈도우 좌표계상 가장 왼쪽위가 (0,0)이기 때문에 마이너스
		}

		if (Input::GetKey(eKeyCode::Down))
		{
			mY += speed * Time::DeltaTime();
		}

	}
	void GameObject::LateUpdate()
	{

	}
	void GameObject::Render(HDC hdc)
	{

		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));
		SelectObject(hdc, brush);

		Rectangle(hdc, mX, mY, 100 + mX, 100 + mY);
		DeleteObject(brush);

		DeleteObject(brush);

	}
}

