#pragma once
#include "sunEntity.h"
#include "sunLayer.h"
#include "sunGameObject.h"

namespace sun
{
	class Scene : public Entity
	{
	private:
		std::vector<Layer*> mLayers;
	public:
		Scene();
		~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		//Scene으로 진입할 때
		virtual void OnEnter(); 
		//Scene에서 나갈 때
		virtual void OnExit();

		void AddGameObject(GameObject* gameObj, eLayerType type);
	
	};
}


