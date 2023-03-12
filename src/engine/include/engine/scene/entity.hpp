////////////////////////
//
//  Created on Sat Mar 11 2023
//
//  entity.hpp
//
////////////////////////

#pragma once

#include "engine/engine.hpp"
#include "engine/system/uuid.hpp"

namespace Fly::Engine
{
    class Scene;

    typedef size_t Entity;

    class EntityManager
    {
        public:

            friend class Scene;

        private:
            static inline Entity createEntity();
    };
}

#include "engine/scene/inl/entity.inl"
