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
#include "engine/engine.hpp"
#include "engine/scene/scene.hpp"

namespace Fly::Editor
{
    class EditorApplication
    {
        public:
            static int init();
            static void terminate();
            static void run();

            static inline void quit();

        private:
            static GLFWwindow *m_window;
            static Windows m_windows;
            static Engine::Scene m_scene;

            static bool framerateLimiter(double framerate);
    };
}

#include "editor/application/inl/editor_application.inl"
