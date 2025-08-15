#pragma once
#include "CommonInclude.h"

namespace sun
{
	class Entity
	{
	private:
		std::wstring mName;
	public:
		Entity();
		virtual ~Entity();

		void SetName(const std::wstring& name) { mName = name; }
		std::wstring& GetName() { return mName; }
	};
}


