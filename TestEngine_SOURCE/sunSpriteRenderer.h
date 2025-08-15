#pragma once
#include "sunComponent.h"

namespace sun
{
	class SpriteRenderer : public Component
	{
	private:

	public:
		SpriteRenderer();
		~SpriteRenderer();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	};
}


