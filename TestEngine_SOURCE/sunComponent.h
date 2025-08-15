#pragma once
#include "sunEntity.h"

namespace sun
{
	class GameObject;
	class Component : public Entity
	{
	private:
		GameObject* mOwner;
	public:
		Component();
		~Component();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void SetOwner(GameObject* owner) { mOwner = owner; }
		GameObject* GetOwner() { return mOwner; }
	};
}


