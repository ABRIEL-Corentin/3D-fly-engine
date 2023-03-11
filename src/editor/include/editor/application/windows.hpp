////////////////////////
//
//  Created on Sat Mar 11 2023
//
//  windows.hpp
//
////////////////////////

#pragma once

#include "editor/editor.hpp"

namespace Fly::Editor
{
    class Windows
    {
        public:
            Windows();
            ~Windows();

        public:
            void initDocking();
            void drawMainMenuBar();
            void drawToolBar();
            void drawSceneWindow();
            void drawConsoleWindow();
            void drawHierarchyWindow();
            void drawInspectorWindow();
            void drawExplorerWindow();

        private:
            float m_tool_bar_height;
            float m_menu_bar_height;
    };
}
