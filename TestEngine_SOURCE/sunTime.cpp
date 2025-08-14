#include "sunTime.h"

namespace sun {
	LARGE_INTEGER Time::CpuFrequency = {};
	LARGE_INTEGER Time::PrevFrequency = {};
	LARGE_INTEGER Time::CurrentFrequency = {};
	float Time::DeltaTimeValue = 0.0f;

	void Time::Initialize()
	{
		QueryPerformanceFrequency(&CpuFrequency);

		// 프로그램이 시작했을 때 진동수
		QueryPerformanceCounter(&PrevFrequency);
	}

	void Time::Update()
	{
		//현재 진동수
		QueryPerformanceCounter(&CurrentFrequency);

		float differenceFrequency = static_cast<float>(CurrentFrequency.QuadPart - PrevFrequency.QuadPart);

		DeltaTimeValue = differenceFrequency / static_cast<float>(CpuFrequency.QuadPart);

		PrevFrequency.QuadPart = CurrentFrequency.QuadPart;
	}

	void Time::Render(HDC hdc)
	{
		static float time = 0.0f; //실행된 시간
		float fps; //FPS 현재 초당 프레임

		time += DeltaTimeValue; 
		fps = 1.0f / DeltaTimeValue;

		wchar_t str1[50] = L"";
		wchar_t str2[50] = L"";

		swprintf_s(str1, 50, L"Time : %f", time);
		swprintf_s(str2, 50, L"FPS : %f", fps);

		int len = wcsnlen_s(str1, 50);

		TextOut(hdc, 0, 0, str1, len);
		TextOut(hdc, 0, 20, str2, len);
	}
}

