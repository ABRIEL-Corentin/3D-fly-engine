////////////////////////
//
//  Created on Fri Mar 10 2023
//
//  application.cpp
//
////////////////////////

#include "core/application/application.hpp"
#include "editor/application/editor_application.hpp"

namespace Fly::Core
{
    Application::Application()
    { }

    Application::~Application()
    { }

    int Application::init()
    {
        return Editor::EditorApplication::init();
    }

    void Application::terminate()
    {
        Editor::EditorApplication::terminate();
    }

    void Application::run()
    {
        Editor::EditorApplication::run();
    }
}
