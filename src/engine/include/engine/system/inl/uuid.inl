////////////////////////
//
//  Created on Sun Mar 12 2023
//
//  uuid.inl
//
////////////////////////

#include "engine/system/uuid.hpp"

namespace Fly::Engine
{
    inline uuid_t UUID::generate()
    {
        return m_dist(m_rng);
    }
}
