#pragma once

namespace sun::enums
{
	enum class eLayerType
	{
		None,
		BackGround,
		Player,
		Max = 16
	};

	enum class eResourceType
	{
		Texture, //이미지
		AudioClip, //오디오
		Prefab, //데이터저장
		End
	};
}