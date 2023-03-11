////////////////////////
//
//  Created on Sat Mar 11 2023
//
//  editor_application.hpp
//
////////////////////////

#pragma once

#include "editor/editor.hpp"
#include "editor/application/windows.hpp"

namespace Fly::Editor
{
    class EditorApplication
    {
        public:
            static int init();
            static void terminate();
            static void run();

        private:
            static GLFWwindow *m_window;
            static Windows m_windows;
    };
}
