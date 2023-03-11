////////////////////////
//
//  Created on Sat Mar 11 2023
//
//  editor_application.inl
//
////////////////////////

#include "editor/application/editor_application.hpp"

namespace Fly::Editor
{
    inline void EditorApplication::quit()
    {
        glfwSetWindowShouldClose(m_window, true);
    }
}
