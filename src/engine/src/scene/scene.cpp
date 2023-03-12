////////////////////////
//
//  Created on Sat Mar 11 2023
//
//  scene.cpp
//
////////////////////////

#include "engine/scene/scene.hpp"

namespace Fly::Engine
{
    Scene::Scene()
        : m_entities(std::vector<Entity>())
    { }

    Scene::~Scene()
    { }

    Entity &Scene::createEntity()
    {
        m_entities.push_back(EntityManager::createEntity());
        return m_entities.back();
    }
}
