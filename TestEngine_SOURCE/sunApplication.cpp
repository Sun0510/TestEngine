#include "sunApplication.h"

namespace sun
{
	Application::Application()
		: mHwnd(nullptr),
		mHdc(nullptr),
		mSpeed(0)
	{

	}

	Application::~Application()
	{

	}

	void Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		mPlayer.SetPosition(0, 0);
	}
	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	
	void Application::Update()
	{
		mSpeed += 0.01f;

		mPlayer.Update();
	}
	void Application::LateUpdate()
	{

	}
	void Application::Render()
	{
		mPlayer.Render(mHdc);

	}
}