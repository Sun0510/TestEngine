#pragma once
#include "sunGameObject.h"

namespace sun
{
	class Player : public GameObject
	{
	private:

	public:

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	};
}


