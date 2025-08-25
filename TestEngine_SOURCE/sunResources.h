#pragma once
#include "sunResource.h"

namespace sun
{
	class Resources
	{
	private:
		static std::map<std::wstring, Resource*> mResources;
	public:


		template <typename T>
		static T* Find(const std::wstring& key)
		{
			//std::map<std::wstring, Resource*> iterator
			auto iter = mResources.find(key);

			if (iter == mResources.end())
				return nullptr;

			return dynamic_cast<T*> (iter->second);
		}

		template <typename T>
		static T* Load(const std::wstring& key, const std::wstring& path)
		{
			T* resource = Resources::Find<T>(key);
			if (resource != nullptr)
				return resource;

			//없으면 새로 할당
			resource = new T();
			//또 실패하면 메시지박스로 오류 출력
			if (FAILED(resource->Load(path)))
			{
				//MessageBox(nullptr, key + L"Image Laod Failed!", L"Error", MB_OK);
				assert(false);
				return nullptr;
			}

			resource->SetName(key);
			resource->SetPath(path);
			mResources.insert(std::make_pair(key, resource));
			return resource;
		}
	};
}


