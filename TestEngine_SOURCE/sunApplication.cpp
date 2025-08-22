#include "sunApplication.h"
#include "sunInput.h"
#include "sunTime.h"
#include "sunSceneManager.h"

namespace sun
{
	Application::Application()
		: mHwnd(nullptr),
		mHdc(nullptr),
		mSpeed(0),
		mWidth(0),
		mHeight(0),
		mBackHdc(NULL),
		mBackBuffer(NULL)
	{

	}

	Application::~Application()
	{

	}

	void Application::Initialize(HWND hwnd, UINT width, UINT height)
	{
		adjustWindowRect(hwnd, width, height);
		createBuffer(width, height);
		
		Input::Initialize();
		Time::Initialize();
		SceneManager::Initialize();
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

		SceneManager::Update();
	}
	void Application::LateUpdate()
	{
		SceneManager::LateUpdate();
	}
	void Application::Render()
	{
		clearRenderTarget();

		//Time::Render(mBackHdc);
		SceneManager::Render(mBackHdc);

		copyRenderTarget(mBackHdc, mHdc);
	}
	void  Application::adjustWindowRect(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		RECT rect = { 0, 0, width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false); //윈도우의 크기 설정

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 100, 100, mWidth, mHeight, 0); //윈도우가 뜰 위치 설정
		ShowWindow(mHwnd, true);		
	}

	void Application::createBuffer(UINT width, UINT height)
	{
		//윈도우 해상도에 맞는 백버퍼 생성
		mBackBuffer = CreateCompatibleBitmap(mHdc, width, height); //비트맵 하나 더 만들기, 메모리를 더 쓰고 연산을 빠르게 하기 위함
		//백버퍼를 가리킬 DC 생성
		mBackHdc = CreateCompatibleDC(mHdc);
		//새로만든 버퍼와 DC 연결
		HBITMAP oldBitMap = (HBITMAP)SelectObject(mBackHdc, mBackBuffer);
		//이전 버퍼 지우기
		DeleteObject(oldBitMap);
	}

	void Application::clearRenderTarget()
	{
		//뒷배경에 사용하는 흰색 사각형
		HBRUSH brush = CreateSolidBrush(RGB(255, 255, 255));
		SelectObject(mBackHdc, brush);
		Rectangle(mBackHdc, -1, -1, 1601, 901);
		DeleteObject(brush);
	}

	void Application::copyRenderTarget(HDC source, HDC dest)
	{
		//BackBuffer에 있는 것을 원본 Buffer에 복사, DC가 두 개 들어감, hdcSrc에 있는 것을 앞 DC에 그린다는 의미, SRCCOPY는 복사
		BitBlt(dest, 0, 0, mWidth, mHeight, source, 0, 0, SRCCOPY);
	}
}