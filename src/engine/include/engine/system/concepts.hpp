////////////////////////
//
//  Created on Sun Mar 12 2023
//
//  concepts.hpp
//
////////////////////////

#pragma once

#include "engine/engine.hpp"
#include "engine/component/modifiers.hpp"

namespace Fly::Engine
{
    template<class CLASS, class BASE>
    concept is_base_of =
        std::is_base_of_v<BASE, CLASS> &&
        !std::is_same_v<BASE, CLASS>;

    template<class CLASS, class BASE>
    concept is_removable_component =
        is_base_of<CLASS, BASE> &&
        !std::is_base_of_v<Fixed, CLASS>;
}
