////////////////////////
//
//  Created on Sun Mar 12 2023
//
//  transform.cpp
//
////////////////////////

#include "engine/component/components/transform.hpp"

namespace Fly::Engine
{
    Transform::Transform()
        : m_position(glm::vec3(0, 0, 0)),
          m_rotation(glm::vec3(0, 0, 0)),
          m_scale(glm::vec3(1, 1, 1))
    { }

    Transform::~Transform()
    { }
}
