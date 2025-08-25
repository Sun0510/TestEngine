#include "sunTexture.h"
#include "sunApplication.h"

extern sun::Application application; //main.cpp�� �ִ� ���� ���� ������

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
		std::wstring ext = path.substr(path.find_last_of(L".") + 1); //.�� ���� ������ ���� ������
		//bmp�� ���
		if (ext == L"bmp")
		{
			mType = eTextureType::Bmp;
			mBitmap = (HBITMAP) LoadImageW(nullptr, path.c_str(), IMAGE_BITMAP, 
				0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

			if (mBitmap == nullptr)
				return S_FALSE;

			BITMAP info = {};
			GetObject(mBitmap, sizeof(BITMAP), &info); //Bitmap�� ������ info�� ����

			mWidth = info.bmWidth;
			mHeight = info.bmHeight;

			HDC mainDC = application.GetHdc();
			mHdc = CreateCompatibleDC(mainDC);

			HBITMAP oldBitmap = (HBITMAP) SelectObject(mHdc, mBitmap); //���� �⺻�� ��Ʈ�� ����
			DeleteObject(oldBitmap);
		}
		else if (ext == L"png") //png�� ���
		{
			mType = eTextureType::Png;
			mImage = Gdiplus::Image::FromFile(path.c_str()); //�ش� ��ηκ��� �̹����� �ҷ��� mImage�� ����
			mWidth = mImage->GetWidth();
			mHeight = mImage->GetHeight();

			if (mImage == nullptr)
				return S_FALSE;
		}

		return S_OK;
	}
}