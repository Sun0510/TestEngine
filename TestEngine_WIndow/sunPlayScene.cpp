#include "sunPlayScene.h"
#include "sunGameObject.h"

namespace sun
{
	PlayScene::PlayScene()
	{
	}

	PlayScene::~PlayScene()
	{
	}

	void PlayScene::Initialize()
	{
		GameObject* obj = new GameObject();
		srand((UINT)&obj); //위치 랜덤 위함

		obj->SetPosition(rand() % 1600, rand() % 900);

		AddGameObject(obj);
	}

	void PlayScene::Update()
	{
		Scene::Update();
	}

	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}

