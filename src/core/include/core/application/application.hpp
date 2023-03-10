////////////////////////
//
//  Created on Fri Mar 10 2023
//
//  application.hpp
//
////////////////////////

#pragma once

#include "core/core.hpp"

namespace Fly::Core
{
    class Application
    {
        public:
            Application();
            ~Application();

            int init();
            void terminate();
            void run();
    };
}
