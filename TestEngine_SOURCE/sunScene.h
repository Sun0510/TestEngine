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
	private:
		void createLayers();
	public:
		Scene();
		~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		//Scene���� ������ ��
		virtual void OnEnter(); 
		//Scene���� ���� ��
		virtual void OnExit();

		void AddGameObject(GameObject* gameObj, const enums::eLayerType type);
		Layer* GetLayer(const enums::eLayerType type) { return mLayers[(UINT)type]; }
	
	};
}


