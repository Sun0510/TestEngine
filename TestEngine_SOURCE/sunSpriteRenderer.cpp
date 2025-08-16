#include "sunSpriteRenderer.h"
#include "sunGameObject.h"
#include "sunTransform.h"

namespace sun
{
	SpriteRenderer::SpriteRenderer()
		: mImage(nullptr)
		, mWidth(0)
		, mHeight(0)
	{
	}

	SpriteRenderer::~SpriteRenderer()
	{
	}

	void SpriteRenderer::Initialize()
	{
	}

	void SpriteRenderer::Update()
	{
	}

	void SpriteRenderer::LateUpdate()
	{
	}

	void SpriteRenderer::Render(HDC hdc)
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		Gdiplus::Graphics graphics(hdc);
		graphics.DrawImage(mImage, Gdiplus::Rect(pos.x, pos.y, mWidth, mHeight)); //사각형 모양으로 이미지 그리기
	}

	void SpriteRenderer::ImageLoad(const std::wstring& path)
	{
		mImage = Gdiplus::Image::FromFile(path.c_str()); //해당 경로로부터 이미지를 불러와 mImage에 저장
		mWidth = mImage->GetWidth();
		mHeight = mImage->GetHeight();
	}
}

