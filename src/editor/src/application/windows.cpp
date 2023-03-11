////////////////////////
//
//  Created on Sat Mar 11 2023
//
//  windows.cpp
//
////////////////////////

#include "editor/application/windows.hpp"
#include "editor/application/editor_application.hpp"

namespace Fly::Editor
{
    Windows::Windows()
        : m_tool_bar_height(50),
          m_menu_bar_height(0)
    { }

    Windows::~Windows()
    { }

    void Windows::initDocking()
    {
        ImGuiViewport *viewport = ImGui::GetMainViewport();
        ImGuiWindowFlags window_flags = 0;

        window_flags |= ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
        window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse;
        window_flags |= ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
        window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;

        ImGui::SetNextWindowPos(viewport->Pos + ImVec2(0, m_tool_bar_height));
        ImGui::SetNextWindowSize(viewport->Size - ImVec2(0, m_tool_bar_height));
        ImGui::SetNextWindowViewport(viewport->ID);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0);
        ImGui::Begin("DockSpace", NULL, window_flags);
        ImGuiID dock_main = ImGui::GetID("DockSpace");

        m_menu_bar_height = ImGui::GetCurrentWindow()->MenuBarHeight();

        ImGui::DockSpace(dock_main);
        ImGui::End();
        ImGui::PopStyleVar(3);
    }

    void Windows::drawMainMenuBar()
    {
        ImGui::BeginMainMenuBar();
        if (ImGui::BeginMenu("File")) {
            if (ImGui::MenuItem("Quit", "Alt+F4"))
                EditorApplication::quit();
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }

    void Windows::drawToolBar()
    {
        ImGuiViewport *viewport = ImGui::GetMainViewport();
        ImGuiWindowFlags window_flags = 0;

        window_flags |= ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoTitleBar;
        window_flags |= ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
        window_flags |= ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoSavedSettings;

        ImGui::SetNextWindowPos(viewport->Pos + ImVec2(0, m_menu_bar_height));
        ImGui::SetNextWindowSize(ImVec2(viewport->Size.x, m_tool_bar_height));
        ImGui::SetNextWindowViewport(viewport->ID);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0);
        ImGui::Begin("TOOLBAR", NULL, window_flags);
        ImGui::PopStyleVar();
        ImGui::PopStyleVar();

        ImGui::End();
    }

    void Windows::drawSceneWindow()
    {
        ImGui::Begin("Scene", nullptr, ImGuiWindowFlags_NoCollapse);
        ImGui::End();
    }

    void Windows::drawConsoleWindow()
    {
        ImGui::Begin("Console", nullptr, ImGuiWindowFlags_NoCollapse);
        ImGui::End();
    }

    void Windows::drawHierarchyWindow()
    {
        ImGui::Begin("Hierarchy", nullptr, ImGuiWindowFlags_NoCollapse);
        ImGui::End();
    }

    void Windows::drawInspectorWindow()
    {
        ImGui::Begin("Inspector", nullptr, ImGuiWindowFlags_NoCollapse);
        ImGui::End();
    }

    void Windows::drawExplorerWindow()
    {
        ImGui::Begin("Explorer", nullptr, ImGuiWindowFlags_NoCollapse);
        ImGui::End();
    }
}
