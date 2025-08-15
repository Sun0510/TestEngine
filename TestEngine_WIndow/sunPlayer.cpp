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

		Transform* tr = this->GetComponent<Transform>();
		x = tr->GetX();
		y = tr->GetY();
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
			tr->SetPos(x, y - speed * Time::DeltaTime()); // ������ ��ǥ��� ���� �������� (0,0)�̱� ������ ���̳ʽ�
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
	}

	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}

