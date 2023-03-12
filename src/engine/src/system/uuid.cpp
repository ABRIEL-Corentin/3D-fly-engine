////////////////////////
//
//  Created on Sun Mar 12 2023
//
//  uuid.cpp
//
////////////////////////

#include "engine/system/uuid.hpp"

namespace Fly::Engine
{
    std::random_device UUID::m_device = std::random_device();
    std::mt19937_64 UUID::m_rng = std::mt19937_64(UUID::m_device());
    std::uniform_int_distribution<std::mt19937_64::result_type> UUID::m_dist = std::uniform_int_distribution<std::mt19937_64::result_type>(0, 18446744073709551615UL);
}
