////////////////////////
//
//  Created on Sat Mar 11 2023
//
//  scene.hpp
//
////////////////////////

#pragma once

#include "engine/engine.hpp"
#include "engine/scene/entity.hpp"

namespace Fly::Engine
{
    class Scene
    {
        public:
            Scene();
            ~Scene();

            inline const std::vector<Entity> &getEntities() const;

            Entity &createEntity();

        private:
            std::vector<Entity> m_entities;
    };
}

#include "engine/scene/inl/scene.inl"
