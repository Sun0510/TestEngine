#pragma once
#include "sunScene.h"

namespace sun
{
	class SceneManager
	{
	private:
		//static std::vector<Scene*> mScene;
		static std::map<std::wstring, Scene*> mScene;
		static Scene* mActiveScene;

	public:
		//�� ����
		template <typename T>
		static Scene* CreateScene(const std::wstring& name)
		{
			T* scene = new T();
			scene->Initialize();
			scene->SetName(name);

			mScene.insert(std::make_pair(name, scene));

			return scene;
		}

		//�� �ҷ�����
		static Scene* LoadScene(const std::wstring& name)
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

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);

	};
}

