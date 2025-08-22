#pragma once
#include "..\\TestEngine_SOURCE\\sunSceneManager.h"

namespace sun
{
	class TitleScene : public Scene
	{
	private:

	public:
		TitleScene();
		~TitleScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	};

}

