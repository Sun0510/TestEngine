#pragma once
#include "..\\TestEngine_SOURCE\\sunSceneManager.h"
#include "sunPlayScene.h"
#include "sunTitleScene.h"

namespace sun
{
	void LoadScenes()
	{
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		//SceneManager::CreateScene<PlayScene>(L"EndScene");

		SceneManager::LoadScene(L"TitleScene");
	}
}
