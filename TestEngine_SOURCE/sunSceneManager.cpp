#include "sunSceneManager.h"

namespace sun
{
	std::map<std::wstring, Scene*> SceneManager::mScene = {};
	Scene* SceneManager::mActiveScene = nullptr;

	void SceneManager::Initialize()
	{
	}

	void SceneManager::Update()
	{
		mActiveScene->Update();
	}

	void SceneManager::LateUpdate()
	{
		mActiveScene->LateUpdate();
	}

	void SceneManager::Render(HDC hdc)
	{
		mActiveScene->Render(hdc);
	}

	Scene* SceneManager::LoadScene(const std::wstring& name)
		{
			if (mActiveScene)
				mActiveScene->OnExit();

			//씬의 주소값을 가져옴
			std::map<std::wstring, Scene*>::iterator iter = mScene.find(name);

			//값이 없으면 end 값 (가장 마지막 남는 부분)을 가져옴
			if (iter == mScene.end())
			{
				return nullptr;
			}

			//first는 키값, second는 데이터값
			mActiveScene = iter->second;
			mActiveScene->OnEnter();

			return iter->second;
		}
}

