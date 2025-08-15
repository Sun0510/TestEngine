#pragma once
#include "sunComponent.h"

namespace sun
{
	class Transform : public Component
	{
	private:
		int mX;
		int mY;
	public:
		Transform();
		~Transform();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetPos(int x, int y) { mX = x; mY = y; }
		int GetX() { return mX; }
		int GetY() { return mY; }
	};
}


