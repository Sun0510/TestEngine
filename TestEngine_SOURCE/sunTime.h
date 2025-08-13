#pragma once
#include "CommonInclude.h"

namespace sun {
	class Time
	{
	private:
		static LARGE_INTEGER CpuFrequency;
		static LARGE_INTEGER PrevFrequency;
		static LARGE_INTEGER CurrentFrequency;
		static float DeltaTimeValue; //½Ã°£
	public:
		static void Initialize();
		static void Update();
		static void Render(HDC hdc);

		static float DeltaTime() { return DeltaTimeValue; }
	};
}


