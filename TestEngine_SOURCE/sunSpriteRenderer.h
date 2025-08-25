#pragma once
#include "sunComponent.h"
#include "sunTexture.h"

namespace sun
{
	using namespace math;

	class SpriteRenderer : public Component
	{
	private:
		graphics::Texture* mTexture;
		Vector2 mSize;
	public:
		SpriteRenderer();
		~SpriteRenderer();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetTexture(graphics::Texture* texture) { mTexture = texture; }
		void SetSize(Vector2 size) { mSize = size; }
	};
}


