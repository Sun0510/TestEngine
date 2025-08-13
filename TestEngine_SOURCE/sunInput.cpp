#include "sunInput.h"

using namespace std;

namespace sun
{
	std::vector<Input::Key> Input::Keys = {};

	int ASCII[(UINT)eKeyCode::End] = 
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',  VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN,
	};

	void Input::Initialize()
	{
		CreateKeys();
	}
	void Input::Update()
	{
		UpdateKeys();
	}

	void Input::CreateKeys()
	{
		//Keys.resize((UINT)eKeyCode::End);

		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
		{
			Key key = {};
			key.bPressed = true;
			key.state = eKeyState::Down;
			key.keyCode = (eKeyCode)i;

			Keys.push_back(key);
		}
	}

	void Input::UpdateKeys()
	{	
		for (size_t i = 0; i < Keys.size(); i++)
		{
			UpdateKey(Keys[i]);
		}
	}

	void Input::UpdateKey(Key& key)
	{
		//키가 눌림
		if (IsKeyDown(key.keyCode))
		{
			UpdateKeyDown(key);

		}
		else //키가 안 눌림
		{
			UpdateKeyUp(key);
		}
	}

	bool Input::IsKeyDown(eKeyCode code)
	{
		return GetAsyncKeyState(ASCII[(UINT) code]) & 0x8000;
	}

	void Input::UpdateKeyDown(Key& key)
	{
		if (key.bPressed == true) // 이전에도 키가 눌려져있었음
			key.state = eKeyState::Pressed;
		else // 이전에는 키가 안 눌려져있었음
			key.state = eKeyState::Down;

		key.bPressed = true;
	}

	void Input::UpdateKeyUp(Key& key)
	{
		if (key.bPressed == true) // 이전에는 키가 눌려져있었음
			key.state = eKeyState::Down;
		else // 이전에도 키가 안 눌려져있었음
			key.state = eKeyState::Down;

		key.bPressed = true;
	}
	
}

