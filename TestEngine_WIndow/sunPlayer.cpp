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
			tr->SetPosition(x - speed * Time::DeltaTime(), y);
		}

		if (Input::GetKey(eKeyCode::Right))
		{
			tr->SetPosition(x + speed * Time::DeltaTime(), y);
		}

		if (Input::GetKey(eKeyCode::Up))
		{
			tr->SetPosition(x, y - speed * Time::DeltaTime()); // ������ ��ǥ��� ���� �������� (0,0)�̱� ������ ���̳ʽ�
		}

		if (Input::GetKey(eKeyCode::Down))
		{
			tr->SetPosition(x, y + speed * Time::DeltaTime());
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
			tr->SetPosition(pos);
		}
	}

	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}

