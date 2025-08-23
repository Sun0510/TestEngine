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
		//¾À »ý¼º
		template <typename T>
		static Scene* CreateScene(const std::wstring& name)
		{
			T* scene = new T();
			mActiveScene = scene;
			scene->Initialize();
			scene->SetName(name);

			mScene.insert(std::make_pair(name, scene));

			return scene;
		}

		//¾À ºÒ·¯¿À±â
		static Scene* LoadScene(const std::wstring& name);	

		static Scene* GetActiveScene() { return mActiveScene; }

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);

	};
}

