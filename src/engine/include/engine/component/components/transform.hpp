////////////////////////
//
//  Created on Sun Mar 12 2023
//
//  transform.hpp
//
////////////////////////

#pragma once

#include "engine/engine.hpp"
#include "engine/component/component.hpp"
#include "engine/component/modifiers.hpp"
#include "engine/component/required.hpp"

namespace Fly::Engine
{
    class Transform : public Component
    {
        public:
            Transform();
            ~Transform();

            inline const glm::vec3 &getPosition() const;
            inline const glm::vec3 &getRotation() const;
            inline const glm::vec3 &getScale() const;
            inline glm::vec3 &getPosition();
            inline glm::vec3 &getRotation();
            inline glm::vec3 &getScale();
            inline void setPosition(const glm::vec3 &position);
            inline void setRotation(const glm::vec3 &rotation);
            inline void setScale(const glm::vec3 &scale);

        private:
            glm::vec3 m_position;
            glm::vec3 m_rotation;
            glm::vec3 m_scale;
    };
}

#include "engine/component/components/inl/transform.inl"
