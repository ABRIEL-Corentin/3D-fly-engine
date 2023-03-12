////////////////////////
//
//  Created on Sun Mar 12 2023
//
//  required.inl
//
////////////////////////

#include "engine/component/required.hpp"

namespace Fly::Engine
{
    template<is_base_of<Component> ... COMPONENTS>
    bool Required<COMPONENTS...>::check(const Entity *entity)
    {
        bool state = true;

        ((state = entity->hasComponent<COMPONENTS>() ? state : false), ...);
        return state;
    }
}
