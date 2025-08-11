#pragma once
#include "CommonInclude.h"
#include "sunGameObject.h"

namespace sun {
	class Application
	{
	private:
		HWND mHwnd;
		HDC mHdc;
		float mSpeed;

		GameObject mPlayer;
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd);
		void Run();

		void Update();
		void LateUpdate();
		void Render();

	};
}


