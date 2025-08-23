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

			//���� �ּҰ��� ������
			std::map<std::wstring, Scene*>::iterator iter = mScene.find(name);

			//���� ������ end �� (���� ������ ���� �κ�)�� ������
			if (iter == mScene.end())
			{
				return nullptr;
			}

			//first�� Ű��, second�� �����Ͱ�
			mActiveScene = iter->second;
			mActiveScene->OnEnter();

			return iter->second;
		}
}

