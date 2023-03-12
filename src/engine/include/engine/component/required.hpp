////////////////////////
//
//  Created on Sun Mar 12 2023
//
//  required.hpp
//
////////////////////////

#pragma once

#include "engine/engine.hpp"
#include "engine/scene/entity.hpp"
#include "engine/component/modifiers.hpp"

namespace Fly::Engine
{
    template<is_base_of<Component> ... COMPONENTS>
    class Required : public RequiredBase
    {
        public:
            bool check(const Entity *entity) override;
    };
}

#include "engine/component/inl/required.inl"
