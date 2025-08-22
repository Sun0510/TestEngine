#include "sunScene.h"

namespace sun
{
    Scene::Scene()
        :mLayers{}
    {
        mLayers.resize((UINT)eLayerType::Max);
        for (size_t i = 0; i < (UINT)eLayerType::Max; i++)
        {
            mLayers[i] = new Layer();
        }
    }
    Scene::~Scene()
    {
    }
    void Scene::Initialize()
    {
        for (Layer* layer : mLayers)
        {
            if (layer == nullptr)
                continue;
            layer->Initialize();
        }
    }

    void Scene::Update()
    {
        //범위 기반 for문
        for (Layer* layer : mLayers)
        {
            if (layer == nullptr)
                continue;
            layer->Update();
        }

    }
    void Scene::LateUpdate()
    {
        for (Layer* layer : mLayers)
        {
            if (layer == nullptr)
                continue;
            layer->LateUpdate();
        }
    }
    void Scene::Render(HDC hdc)
    {
        for (Layer* layer : mLayers)
        {
            if (layer == nullptr)
                continue;
            layer->Render(hdc);
        }
    }

    void Scene::OnEnter()
    {

    }

    void Scene::OnExit()
    {

    }

    void Scene::AddGameObject(GameObject* gameObj, eLayerType type)
    {
        mLayers[(UINT)type]->AddGameObject(gameObj);
    }
}