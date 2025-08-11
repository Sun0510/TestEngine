#pragma once
#include "CommonInclude.h"

namespace sun 
{
	class GameObject
	{
	private:
		float mX1;
		float mY1;

		float mX2;
		float mY2;
	public:
		GameObject();
		~GameObject();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void SetPosition1(float x, float y)
		{
			mX1 = x;
			mY1 = y;
		}

		void SetPosition2(float x, float y)
		{
			mX2 = x;
			mY2 = y;
		}
		float GetPositionX1() { return mX1; }
		float GetPositionY1() { return mY1; }
		float GetPositionX2() { return mX2; }
		float GetPositionY2() { return mY2; }

	};
}
