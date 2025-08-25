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
		Gdiplus::Image* mImage; //png 파일
		HBITMAP mBitmap; //bmp 파일
		HDC mHdc; //bmp 파일에 대한 DC
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


