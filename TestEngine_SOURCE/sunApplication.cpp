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
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false); //�������� ũ�� ����

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 100, 100, mWidth, mHeight, 0); //�����찡 �� ��ġ ����
		ShowWindow(mHwnd, true);		
	}

	void Application::createBuffer(UINT width, UINT height)
	{
		//������ �ػ󵵿� �´� ����� ����
		mBackBuffer = CreateCompatibleBitmap(mHdc, width, height); //��Ʈ�� �ϳ� �� �����, �޸𸮸� �� ���� ������ ������ �ϱ� ����
		//����۸� ����ų DC ����
		mBackHdc = CreateCompatibleDC(mHdc);
		//���θ��� ���ۿ� DC ����
		HBITMAP oldBitMap = (HBITMAP)SelectObject(mBackHdc, mBackBuffer);
		//���� ���� �����
		DeleteObject(oldBitMap);
	}

	void Application::clearRenderTarget()
	{
		//�޹�濡 ����ϴ� ��� �簢��
		HBRUSH brush = CreateSolidBrush(RGB(255, 255, 255));
		SelectObject(mBackHdc, brush);
		Rectangle(mBackHdc, -1, -1, 1601, 901);
		DeleteObject(brush);
	}

	void Application::copyRenderTarget(HDC source, HDC dest)
	{
		//BackBuffer�� �ִ� ���� ���� Buffer�� ����, DC�� �� �� ��, hdcSrc�� �ִ� ���� �� DC�� �׸��ٴ� �ǹ�, SRCCOPY�� ����
		BitBlt(dest, 0, 0, mWidth, mHeight, source, 0, 0, SRCCOPY);
	}
}