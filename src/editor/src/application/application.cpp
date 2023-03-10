////////////////////////
//
//  Created on Fri Mar 10 2023
//
//  application.cpp
//
////////////////////////

#include "core/application/application.hpp"

namespace Fly::Core
{
    Application::Application()
    { }

    Application::~Application()
    { }

    int Application::init()
    {
        std::cout << "init" << std::endl;
        return EXIT_SUCCESS;
    }

    void Application::terminate()
    {
        std::cout << "terminate" << std::endl;
    }

    void Application::run()
    {
        std::cout << "run" << std::endl;
    }
}
