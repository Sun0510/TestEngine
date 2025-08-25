#pragma once
#include "..\\TestEngine_SOURCE\\sunResources.h"
#include "..\\TestEngine_SOURCE\\sunTexture.h"

namespace sun
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"BG", L"..\\Resources\\CloudOcean.png");
	}
}