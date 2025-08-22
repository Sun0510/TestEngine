#pragma once
#include "CommonInclude.h"
#include "sunEntity.h"
#include "sunGameObject.h"

namespace sun
{
	class Layer : public Entity
	{
	private:
		eLayerType mType;
		std::vector<GameObject*> mGameObjects;
	public:
		Layer();
		~Layer();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		//���� Scene�� ������Ʈ �߰�
		void AddGameObject(GameObject* gameObject);
	};
}


