#pragma once
#include "sunComponent.h"

namespace sun
{
	using namespace math;

	class SpriteRenderer : public Component
	{
	private:
		Gdiplus::Image* mImage;
		UINT mWidth;
		UINT mHeight;
	public:
		SpriteRenderer();
		~SpriteRenderer();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void ImageLoad(const std::wstring& path); //이미지 불러오기
	};
}


