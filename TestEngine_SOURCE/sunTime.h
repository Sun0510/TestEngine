#pragma once
#include "CommonInclude.h"

namespace sun {
	class Time
	{
	private:
		static LARGE_INTEGER CpuFrequency; //Cpu 고유 진동수
		static LARGE_INTEGER PrevFrequency; //이전 진동수
		static LARGE_INTEGER CurrentFrequency; //현재 진동수
		static float DeltaTimeValue; //시간
	public:
		static void Initialize();
		static void Update();
		static void Render(HDC hdc);

		static float DeltaTime() { return DeltaTimeValue; }
	};
}


