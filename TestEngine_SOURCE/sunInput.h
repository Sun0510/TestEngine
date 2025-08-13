#pragma once
#include "CommonInclude.h"
namespace sun {
	enum class eKeyState
	{
		Down,
		Pressed,
		Up,
		None
	};

	enum class eKeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M, Left, Right, Up, Down,
		End
	};

	class Input
	{
	private:
		struct Key
		{
			eKeyCode keyCode;
			eKeyState state;
			bool bPressed;
		};

		static std::vector<Key> Keys;
		eKeyState mState;

	public:
		static void Initialize();
		static void Update();

		static void CreateKeys();
		static void UpdateKeys();
		static void UpdateKey(Key& key);
		static bool IsKeyDown(eKeyCode code);
		static void UpdateKeyDown(Key& key);
		static void UpdateKeyUp(Key& key);		

		static bool GetKeyDown(eKeyCode code) { return Keys[(UINT)code].state == eKeyState::Down; }
		static bool GetKeyUp(eKeyCode code) { return Keys[(UINT)code].state == eKeyState::Up; }
		static bool GetKey(eKeyCode code) { return Keys[(UINT)code].state == eKeyState::Pressed; }

	
	};

}


