#pragma once
#include "sunEntity.h"

namespace sun
{
	class Resource : public Entity
	{
	private:
		const enums::eResourceType mType;
		std::wstring mPath;
	public:
		Resource(enums::eResourceType type);
		virtual ~Resource();

		virtual HRESULT Load(const std::wstring& path) = 0; //HRESULT: 0보다 클 경우 참 반환
		const std::wstring& GetPath() { return mPath; }
		void SetPath(const std::wstring& path) { mPath = path; }

	};
}


