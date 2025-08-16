#pragma once
#include "sunComponent.h"

namespace sun
{
	using namespace math;

	class Transform : public Component
	{
	private:
		Vector2 mPosition;
	public:
		Transform();
		~Transform();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetPos(Vector2 pos) { mPosition.x = pos.x; mPosition.y = pos.y; }
		Vector2 GetPosition() { return mPosition; }
	};
}


