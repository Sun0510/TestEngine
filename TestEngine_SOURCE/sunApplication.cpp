#include "sunApplication.h"
#include "sunInput.h"
#include "sunTime.h"

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
		Time::Initialize();
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
		Time::Update();

		mPlayer.Update();
	}
	void Application::LateUpdate()
	{

	}
	void Application::Render()
	{
		Time::Render(mHdc);
		mPlayer.Render(mHdc);

	}
}