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

		HDC mBackHdc;
		HBITMAP mBackBuffer;

		UINT mWidth;
		UINT mHeight;

		std::vector<GameObject*> mGameObjects;
	private:
		void createBuffer(UINT width, UINT height);
		void adjustWindowRect(HWND hwnd, UINT width, UINT height);
		void clearRenderTarget();
		void copyRenderTarget(HDC source, HDC dest);
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd, UINT width, UINT height);
		void Run();

		void Update();
		void LateUpdate();
		void Render();

	};
}


