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
}
