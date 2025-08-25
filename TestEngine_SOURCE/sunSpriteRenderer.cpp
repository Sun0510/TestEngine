#include "sunSpriteRenderer.h"
#include "sunGameObject.h"
#include "sunTransform.h"

namespace sun
{
	SpriteRenderer::SpriteRenderer()
		: Component()
		, mTexture(nullptr)
		, mSize(Vector2::One)
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
		//텍스처가 없을 때,, 
		if (mTexture == nullptr)
			assert(false); //텍스처 세팅 필요
		
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		//bmp 파일일 때
		if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Bmp)
		{
			//설명: https://blog.naver.com/power2845/50147965306
			TransparentBlt(hdc, pos.x, pos.y
				, mTexture->GetWidth() * mSize.x, mTexture->GetHeight() * mSize.y
				, mTexture->GetHdc(), 0, 0
				, mTexture->GetWidth(), mTexture->GetHeight()
				, RGB(255, 0, 255));
		}
		else if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Png) //png 파일일 때
		{
			Gdiplus::Graphics graphics(hdc);
			graphics.DrawImage(mTexture->GetImage()
				, Gdiplus::Rect(pos.x, pos.y, mTexture->GetWidth() * mSize.x, mTexture->GetHeight() * mSize.y));
		}

		//Transform* tr = GetOwner()->GetComponent<Transform>();
		//Vector2 pos = tr->GetPosition();

		//Gdiplus::Graphics graphics(hdc);
		//graphics.DrawImage(mImage, Gdiplus::Rect(pos.x, pos.y, mWidth, mHeight)); //사각형 모양으로 이미지 그리기
	}


}

