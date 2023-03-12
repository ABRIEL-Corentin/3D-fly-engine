////////////////////////
//
//  Created on Sun Mar 12 2023
//
//  transform.inl
//
////////////////////////

#include "engine/component/components/transform.hpp"

namespace Fly::Engine
{
    inline const glm::vec3 &Transform::getPosition() const
    {
        return m_position;
    }

    inline const glm::vec3 &Transform::getRotation() const
    {
        return m_rotation;
    }

    inline const glm::vec3 &Transform::getScale() const
    {
        return m_scale;
    }

    inline glm::vec3 &Transform::getPosition()
    {
        return m_position;
    }

    inline glm::vec3 &Transform::getRotation()
    {
        return m_rotation;
    }

    inline glm::vec3 &Transform::getScale()
    {
        return m_scale;
    }

    inline void Transform::setPosition(const glm::vec3 &position)
    {
        m_position = position;
    }

    inline void Transform::setRotation(const glm::vec3 &rotation)
    {
        m_rotation = rotation;
    }

    inline void Transform::setScale(const glm::vec3 &scale)
    {
        m_scale = scale;
    }
}
