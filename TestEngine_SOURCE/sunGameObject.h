#pragma once
#include "CommonInclude.h"

namespace sun 
{
	class GameObject
	{
	private:
		float mX;
		float mY;
	public:
		GameObject();
		~GameObject();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void SetPosition(float x, float y)
		{
			mX = x;
			mY = y;
		}
		float GetPositionX() { return mX; }
		float GetPositionY() { return mY; }

	};
}
