////////////////////////
//
//  Created on Fri Mar 10 2023
//
//  main.cpp
//
////////////////////////

#include <iostream>

int main(int argc, char **argv)
{
    for (int i = 0; i < argc; ++i)
        std::cout << argv[i] << std::endl;
    return 0;
}
