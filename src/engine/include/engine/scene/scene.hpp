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

            Entity *createEntity(const std::string &label);
            inline const std::vector<Entity *> &getEntities() const;

        private:
            std::vector<Entity *> m_entities;
    };
}

#include "engine/scene/inl/scene.inl"
