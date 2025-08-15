#pragma once
#include "sunEntity.h"
#include "sunGameObject.h"

namespace sun
{
	class Scene : public Entity
	{
	private:
		std::vector<GameObject*> mGameObjects;
	public:
		Scene();
		~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);
		
		//���� Scene�� ������Ʈ �߰�
		void AddGameObject(GameObject* gameObject);
	
	};
}


