////////////////////////
//
//  Created on Sun Mar 12 2023
//
//  entity.inl
//
////////////////////////

#include "engine/scene/entity.hpp"

namespace Fly::Engine
{
    template<is_base_of<Component> T>
    T *Entity::addComponent()
    {
        T *component = new T();

        m_components.push_back(dynamic_cast<Component *>(component));
        return component;
    }

    template<is_base_of<Component> T>
    T *Entity::getComponent()
    {
        for (auto it = m_components.begin(); it != m_components.end(); ++it)
            if (dynamic_cast<T *>(*it))
                return dynamic_cast<T *>(*it);
        return nullptr;
    }

    template<is_base_of<Component> T>
    const T *Entity::getComponent() const
    {
        for (auto it = m_components.begin(); it != m_components.end(); ++it)
            if (dynamic_cast<const T *>(*it))
                return dynamic_cast<const T *>(*it);
        return nullptr;
    }

    template<is_removable_component<Component> T>
    void Entity::removeComponent(size_t index)
    {
        for (auto it = m_components.begin(); it != m_components.end(); ++it) {
            if (dynamic_cast<T *>(*it)) {
                if (index == 0) {
                    delete *it;
                    m_components.erase(it);
                    return;
                }
                --index;
            }
        }
    }

    inline const uuid_t &Entity::getID() const
    {
        return m_id;
    }

    inline const std::vector<Component *> &Entity::getComponents() const
    {
        return m_components;
    }

    inline std::vector<Component *> &Entity::getComponents()
    {
        return m_components;
    }
}
