////////////////////////
//
//  Created on Sun Mar 12 2023
//
//  modifiers.hpp
//
////////////////////////

#pragma once

#include "engine/engine.hpp"
#include "engine/system/concepts.hpp"

namespace Fly::Engine
{
    class Entity;
    class Component;

    class Fixed
    { };

    class Singular
    { };

    class RequiredBase
    {
        public:
            virtual bool check(const Entity *) { return false; }
    };
}
