////////////////////////
//
//  Created on Sat Mar 11 2023
//
//  scene.cpp
//
////////////////////////

#include "engine/scene/scene.hpp"
#include "engine/component/components/identity.hpp"

namespace Fly::Engine
{
    Scene::Scene()
        : m_entities(std::vector<Entity *>()),
          m_entity_selected(nullptr)
    { }

    Scene::~Scene()
    {
        for (auto it = m_entities.begin(); it != m_entities.end(); ++it)
            delete *it;
    }

    Entity *Scene::createEntity(const std::string &label)
    {
        m_entities.push_back(new Entity());
        m_entities.back()->addComponent<Identity>()->setLabel(label);
        return m_entities.back();
    }
}
