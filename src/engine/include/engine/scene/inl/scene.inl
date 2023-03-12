////////////////////////
//
//  Created on Sun Mar 12 2023
//
//  scene.inl
//
////////////////////////

#include "engine/scene/scene.hpp"

namespace Fly::Engine
{
    inline const std::vector<Entity *> &Scene::getEntities() const
    {
        return m_entities;
    }

    inline void Scene::selectEntity(Entity *entity)
    {
        m_entity_selected = entity;
    }

    inline const Entity *Scene::getEntitySelected() const
    {
        return m_entity_selected;
    }

    inline Entity *Scene::getEntitySelected()
    {
        return m_entity_selected;
    }
}
