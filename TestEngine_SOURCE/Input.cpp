#include "Input.h"

namespace sun
{
	std::vector<Input::Key> Input::mKeys = {};

	int ASCII[(UINT)eKeyCode::End] = 
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',  VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN,
	};

	void Input::Initialize()
	{
		mKeys.resize((UINT)eKeyCode::End);

		for (size_t i = 0; i < (UINT) eKeyCode::End; i++)
		{
			Key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.keyCode = (eKeyCode) i;

			mKeys.push_back(key);
		}
	}
	void Input::Update()
	{
		for (size_t i = 0; i < mKeys.size(); i++)
		{
			//Ű�� ����
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				if (mKeys[i].bPressed == true) // �������� Ű�� �������־���
					mKeys[i].state = eKeyState::Pressed;
				else // �������� Ű�� �� �������־���
					mKeys[i].state = eKeyState::Down;
				mKeys[i].bPressed = true;
				
			}
			else //Ű�� �� ����
			{
				if (mKeys[i].bPressed == true) // �������� Ű�� �������־���
					mKeys[i].state = eKeyState::Up;
				else // �������� Ű�� �� �������־���
					mKeys[i].state = eKeyState::None;
				mKeys[i].bPressed = false;
			}

		}
	}
}

