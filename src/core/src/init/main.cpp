////////////////////////
//
//  Created on Fri Mar 10 2023
//
//  main.cpp
//
////////////////////////

#include "core/core.hpp"
#include "core/application/application.hpp"

int main(int argc, char **)
{
    Fly::Core::Application application = Fly::Core::Application();
    int status = 0;

    if (argc != 1)
        return EXIT_FAILURE;
    status = application.init();
    if (status)
        return status;
    application.run();
    application.terminate();
    return EXIT_SUCCESS;
}
