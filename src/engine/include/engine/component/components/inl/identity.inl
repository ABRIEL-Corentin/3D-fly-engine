////////////////////////
//
//  Created on Sun Mar 12 2023
//
//  identity.inl
//
////////////////////////

#include "engine/component/components/identity.hpp"

namespace Fly::Engine
{
    inline const std::string &Identity::getLabel() const
    {
        return m_label;
    }

    inline std::string &Identity::getLabel()
    {
        return m_label;
    }

    inline void Identity::setLabel(const std::string &label)
    {
        m_label = label;
    }
}
