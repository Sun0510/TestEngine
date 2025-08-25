#include "sunTexture.h"
#include "sunApplication.h"

extern sun::Application application; //main.cpp에 있는 전역 변수 가져옴

namespace sun::graphics
{
	Texture::Texture()
		: Resource(enums::eResourceType::Texture)
	{
	}

	Texture::~Texture()
	{
	}

	HRESULT Texture::Load(const std::wstring& path)
	{
		std::wstring ext = path.substr(path.find_last_of(L".") + 1); //.을 만날 때까지 문장 가져옴
		//bmp일 경우
		if (ext == L"bmp")
		{
			mType = eTextureType::Bmp;
			mBitmap = (HBITMAP) LoadImageW(nullptr, path.c_str(), IMAGE_BITMAP, 
				0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

			if (mBitmap == nullptr)
				return S_FALSE;

			BITMAP info = {};
			GetObject(mBitmap, sizeof(BITMAP), &info); //Bitmap의 정보를 info에 넣음

			mWidth = info.bmWidth;
			mHeight = info.bmHeight;

			HDC mainDC = application.GetHdc();
			mHdc = CreateCompatibleDC(mainDC);

			HBITMAP oldBitmap = (HBITMAP) SelectObject(mHdc, mBitmap); //이전 기본값 비트맵 없앰
			DeleteObject(oldBitmap);
		}
		else if (ext == L"png") //png일 경우
		{
			mType = eTextureType::Png;
			mImage = Gdiplus::Image::FromFile(path.c_str()); //해당 경로로부터 이미지를 불러와 mImage에 저장
			mWidth = mImage->GetWidth();
			mHeight = mImage->GetHeight();

			if (mImage == nullptr)
				return S_FALSE;
		}

		return S_OK;
	}
}