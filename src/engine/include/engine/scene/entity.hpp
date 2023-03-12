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
#include "engine/component/component.hpp"
#include "engine/system/concepts.hpp"

namespace Fly::Engine
{
    class Entity
    {
        public:
            Entity();
            ~Entity();

            template<is_base_of<Component> T>
            T *addComponent();

            template<is_base_of<Component> T>
            T *getComponent(size_t index = 0);

            template<is_base_of<Component> T>
            const T *getComponent(size_t index = 0) const;

            template<is_removable_component<Component> T>
            void removeComponent(size_t index = 0);

            template<is_base_of<Component> T>
            bool hasComponent(size_t index = 0);

            inline const uuid_t &getID() const;
            inline const std::vector<Component *> &getComponents() const;
            inline std::vector<Component *> &getComponents();

        private:
            uuid_t m_id;
            std::vector<Component *> m_components;
    };
}

#include "engine/scene/inl/entity.inl"
