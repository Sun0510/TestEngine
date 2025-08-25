#pragma once
#include "sunResource.h"

namespace sun::graphics
{
	class Texture : public Resource
	{
	public:
		enum class eTextureType
		{
			Bmp,
			Png,
			None
		};
	private:
		eTextureType mType;
		Gdiplus::Image* mImage; //png ����
		HBITMAP mBitmap; //bmp ����
		HDC mHdc; //bmp ���Ͽ� ���� DC
		UINT mWidth;
		UINT mHeight;
	public:
		

		Texture();
		~Texture();

		virtual HRESULT Load(const std::wstring& path) override;

		UINT GetWidth() { return mWidth; }
		UINT GetHeight() { return mHeight; }
		HDC GetHdc() { return mHdc; }
		eTextureType GetTextureType() { return mType; }
		Gdiplus::Image* GetImage() { return mImage; }
		
	};
}


