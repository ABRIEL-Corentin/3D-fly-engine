////////////////////////
//
//  Created on Fri Mar 10 2023
//
//  main.cpp
//
////////////////////////

#define IMGUI_DEFINE_PLACEMENT_NEW
#define IMGUI_DEFINE_MATH_OPERATORS
#include "src/imgui/include/imgui/imgui.h"
#include "src/imgui/include/imgui/imgui_internal.h"
#include "src/imgui/include/imgui/imgui_impl_glfw.h"
#include "src/imgui/include/imgui/imgui_impl_opengl3.h"
#include "src/imgui/include/imgui/imgui_stdlib.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main()
{
    if (!glfwInit()) {
        std::cerr << "Error to init glfw" << std::endl;
        return EXIT_FAILURE;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *m_window = glfwCreateWindow(800, 600, "WINDOW", nullptr, nullptr);

    if (!m_window) {
        std::cerr << "Error to create window" << std::endl;
        glfwTerminate();
        return EXIT_FAILURE;
    }
    glfwMakeContextCurrent(m_window);

    if (glewInit() != GLEW_OK) {
        std::cerr << "Error to init glew" << std::endl;
        glfwDestroyWindow(m_window);
        glfwTerminate();
        return EXIT_FAILURE;
    }

    glViewport(0, 0, 800, 600);

    IMGUI_CHECKVERSION();

    if (ImGui::CreateContext() == NULL) {
        std::cerr << "Error: Init ImGui" << std::endl;
        return 0;
    }

    if (!ImGui_ImplGlfw_InitForOpenGL(m_window, true)) {
        std::cerr << "Error: Init ImGui for GLFW" << std::endl;
        return 0;
    }

    if (!ImGui_ImplOpenGL3_Init("#version 330")) {
        std::cerr << "Error: Init ImGui for OpenGL" << std::endl;
        return 0;
    }

    ImGui::StyleColorsDark();
    ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_DockingEnable;

    glClearColor(0, 0.3f, 0.5f, 1.00f);
    while (!glfwWindowShouldClose(m_window)) {

        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::Begin("test window");
        ImGui::End();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }

    glfwDestroyWindow(m_window);
    glfwTerminate();

    return 0;
}
