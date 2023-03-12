////////////////////////
//
//  Created on Sun Mar 12 2023
//
//  uuid.hpp
//
////////////////////////

#pragma once

#include "engine/engine.hpp"

namespace Fly::Engine
{
    typedef size_t uuid_t;

    class UUID
    {
        public:
            static inline uuid_t generate();

        private:
            static std::random_device m_device;
            static std::mt19937_64 m_rng;
            static std::uniform_int_distribution<std::mt19937_64::result_type> m_dist;
    };
}

#include "engine/system/inl/uuid.inl"
