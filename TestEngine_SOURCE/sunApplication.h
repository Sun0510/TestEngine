#pragma once
#include "CommonInclude.h"

namespace sun {
	class Application
	{
	private:
		HWND mHwnd;
		HDC mHdc;
		float mSpeed;
		float mX;
		float mY;
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


