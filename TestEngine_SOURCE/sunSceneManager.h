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
		//씬 생성
		template <typename T>
		static Scene* CreateScene(const std::wstring& name)
		{
			T* scene = new T();
			scene->Initialize();
			scene->SetName(name);

			mScene.insert(std::make_pair(name, scene));

			return scene;
		}

		//씬 불러오기
		static Scene* LoadScene(const std::wstring& name)
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

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);

	};
}

