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
            T *getComponent();

            template<is_base_of<Component> T>
            const T *getComponent() const;

            template<is_removable_component<Component> T>
            void removeComponent(size_t index = 0);

            inline const uuid_t &getID() const;

        private:
            uuid_t m_id;
            std::vector<Component *> m_components;
    };
}

#include "engine/scene/inl/entity.inl"
