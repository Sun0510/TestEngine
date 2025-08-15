#pragma once
#include "..\\TestEngine_SOURCE\\sunSceneManager.h"

namespace sun
{
	class PlayScene : public Scene
	{
	private:

	public:
		PlayScene();
		~PlayScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	};
}

