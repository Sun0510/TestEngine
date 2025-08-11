#include "sunApplication.h"
#include "Input.h"

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

		mPlayer.SetPosition1(0, 0);
		mPlayer.SetPosition2(0, 0);

		Input::Initialize();
	}
	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	
	void Application::Update()
	{
		Input::Update();

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