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
        T *component = nullptr;

        if (std::is_base_of_v<Singular, T> && (component = getComponent<T>()))
            return component;

        component = new T();

        if (std::is_base_of_v<RequiredBase, T> && !dynamic_cast<RequiredBase *>(component)->check(this)) {
            delete component;
            return nullptr;
        }

        m_components.push_back(dynamic_cast<Component *>(component));
        return component;
    }

    template<is_base_of<Component> T>
    T *Entity::getComponent(size_t index)
    {
        for (auto it = m_components.begin(); it != m_components.end(); ++it) {
            if (dynamic_cast<T *>(*it)) {
                if (index == 0)
                    return dynamic_cast<T *>(*it);
                --index;
            }
        }
        return nullptr;
    }

    template<is_base_of<Component> T>
    const T *Entity::getComponent(size_t index) const
    {
        for (auto it = m_components.begin(); it != m_components.end(); ++it) {
            if (dynamic_cast<const T *>(*it)) {
                if (index == 0)
                    return dynamic_cast<const T *>(*it);
                --index;
            }
        }
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

    template<is_base_of<Component> T>
    bool Entity::hasComponent(size_t index) const
    {
        for (auto it = m_components.begin(); it != m_components.end(); ++it) {
            if (dynamic_cast<T *>(*it)) {
                if (index == 0)
                    return true;
                --index;
            }
        }
        return false;
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
