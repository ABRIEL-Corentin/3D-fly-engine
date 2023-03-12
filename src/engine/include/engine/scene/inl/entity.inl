////////////////////////
//
//  Created on Sun Mar 12 2023
//
//  entity.inl
//
////////////////////////

#include "engine/scene/entity.hpp"

namespace Fly::Engine
{
    inline Entity EntityManager::createEntity()
    {
        return UUID::generate();
    }
}
