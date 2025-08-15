#pragma once
#include "..\\TestEngine_SOURCE\\sunSceneManager.h"
#include "sunPlayScene.h"

namespace sun
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		//SceneManager::CreateScene<PlayScene>(L"EndScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}
