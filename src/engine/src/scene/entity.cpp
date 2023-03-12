////////////////////////
//
//  Created on Sun Mar 12 2023
//
//  entity.cpp
//
////////////////////////

#include "engine/scene/entity.hpp"

namespace Fly::Engine
{
    Entity::Entity()
        : m_id(UUID::generate()),
          m_components(std::vector<Component *>())
    { }

    Entity::~Entity()
    {
        for (auto it = m_components.begin(); it != m_components.end(); ++it)
            delete *it;
    }
}
