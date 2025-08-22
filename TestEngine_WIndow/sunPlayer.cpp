#include "sunPlayer.h"
#include "sunInput.h"
#include "sunTime.h"
#include "sunTransform.h"

namespace sun
{
	void Player::Initialize()
	{
		GameObject::Initialize();
	}

	void Player::Update()
	{
		GameObject::Update();

		const float speed = 100.0f;
		float x, y;

		/*
		//Player1
		if (Input::GetKey(eKeyCode::Left))
		{
			tr->SetPos(x - speed * Time::DeltaTime(), y);
		}

		if (Input::GetKey(eKeyCode::Right))
		{
			tr->SetPos(x + speed * Time::DeltaTime(), y);
		}

		if (Input::GetKey(eKeyCode::Up))
		{
			tr->SetPos(x, y - speed * Time::DeltaTime()); // 윈도우 좌표계상 가장 왼쪽위가 (0,0)이기 때문에 마이너스
		}

		if (Input::GetKey(eKeyCode::Down))
		{
			tr->SetPos(x, y + speed * Time::DeltaTime());
		}
		*/
	}

	void Player::LateUpdate()
	{
		GameObject::LateUpdate();

		if (Input::GetKey(eKeyCode::Right))
		{
			Transform* tr = GetComponent<Transform>();
			Vector2 pos = tr->GetPosition();
			pos.x += 100.0f * Time::DeltaTime();
			tr->SetPos(pos);
		}
	}

	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}

