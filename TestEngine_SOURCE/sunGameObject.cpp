#include "sunGameObject.h"
#include "sunInput.h"
#include "sunTime.h"
#include "sunTransform.h"

namespace sun {
	GameObject::GameObject()
		: mX(0),
		mY(0)
	{
		initializeAddTransform();
	}

	GameObject::~GameObject()
	{
	}

	void GameObject::initializeAddTransform()
	{
		AddComponent<Transform>();
	}

	void GameObject::Initialize()
	{
		for (Component* comp : mComponents)
		{
			comp->Initialize();
		}
	}

	void GameObject::Update()
	{
		for (Component* comp : mComponents)
		{
			comp->Update();
		}

	}
	void GameObject::LateUpdate()
	{
		for (Component* comp : mComponents)
		{
			comp->LateUpdate();
		}
	}
	void GameObject::Render(HDC hdc)
	{
		for (Component* comp : mComponents)
		{
			comp->Render(hdc);
		}


	}
}

