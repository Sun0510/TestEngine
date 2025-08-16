#include "sunPlayScene.h"
#include "sunTransform.h"
#include "sunSpriteRenderer.h"
#include "sunPlayer.h"

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
		Player* p1 = new Player();

		Transform* tr = p1->AddComponent<Transform>();
		tr->SetPos(Vector2(0, 0));
		tr->SetName(L"TR");

		SpriteRenderer* sr = p1->AddComponent<SpriteRenderer>();
		sr->SetName(L"SR");
		sr->ImageLoad(L"..\\Resources\\CloudOcean.png");

		AddGameObject(p1);
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

