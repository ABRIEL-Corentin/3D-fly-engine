////////////////////////
//
//  Created on Sun Mar 12 2023
//
//  identity.hpp
//
////////////////////////

#pragma once

#include "engine/engine.hpp"
#include "engine/component/component.hpp"
#include "engine/component/modifiers.hpp"

namespace Fly::Engine
{
    class Identity : public Component, public Singular, public Fixed
    {
        public:
            Identity();
            ~Identity();

            inline const std::string &getLabel() const;
            inline std::string &getLabel();
            inline void setLabel(const std::string &label);

        private:
            std::string m_label;
    };
}

#include "engine/component/components/inl/identity.inl"
