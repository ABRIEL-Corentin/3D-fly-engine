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
        : m_entities(std::vector<Entity *>())
    { }

    Scene::~Scene()
    {
        for (auto it = m_entities.begin(); it != m_entities.end(); ++it)
            delete *it;
    }

    Entity *Scene::createEntity(const std::string &label)
    {
        // Entity *entity = new Entity();

        // entity->addComponent<Identity>()->setLabel(label);
        // m_entities.push_back(std::make_unique<Entity>())->addComponent<Identity>()->setLabel(label);
        m_entities.push_back(new Entity());
        m_entities.back()->addComponent<Identity>()->setLabel(label);
        // m_entities.emplace(m_entities.begin());
        return m_entities.back();
        // return *entity;
    }
}
