#pragma once
#include "sunLayer.h"
#include "sunGameObject.h"
#include "sunSceneManager.h"
#include "sunScene.h"

namespace sun::object
{
	//Transform�� �����ϰ� ����ϱ� ����
	template <typename T>
	static T* Instantiate(enums::eLayerType type)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		return gameObject;
	}

	//Transform�� �����ϰ� ����ϱ� ����
	template <typename T>
	static T* Instantiate(enums::eLayerType type, math::Vector2 position)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		Transform* tr = gameObject->GetComponent<Transform>();
		tr->SetPosition(position);

		return gameObject;
	}
}