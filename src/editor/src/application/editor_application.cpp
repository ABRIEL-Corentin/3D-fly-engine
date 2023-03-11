////////////////////////
//
//  Created on Sat Mar 11 2023
//
//  editor_application.cpp
//
////////////////////////

#include "editor/application/editor_application.hpp"
#include "engine/engine.hpp"

namespace Fly::Editor
{
    GLFWwindow *EditorApplication::m_window = nullptr;

    int EditorApplication::init()
    {
        if (!glfwInit()) {
            std::cerr << "Error to init glfw" << std::endl;
            return EXIT_FAILURE;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        m_window = glfwCreateWindow(800, 600, "EDITOR", nullptr, nullptr);

        if (!m_window) {
            std::cerr << "Error to create editor window" << std::endl;
            glfwTerminate();
            return EXIT_FAILURE;
        }
        glfwMakeContextCurrent(m_window);

        if (glewInit() != GLEW_OK) {
            std::cerr << "Error to ini glew" << std::endl;
            glfwDestroyWindow(m_window);
            glfwTerminate();
            return EXIT_FAILURE;
        }

        glViewport(0, 0, 800, 600);
        IMGUI_CHECKVERSION();

        if (ImGui::CreateContext() == nullptr) {
            std::cerr << "Error to init ImGui" << std::endl;
            glfwDestroyWindow(m_window);
            glfwTerminate();
            return EXIT_FAILURE;
        }

        if (!ImGui_ImplGlfw_InitForOpenGL(m_window, true)) {
            std::cerr << "Error to init ImGui for GLFW" << std::endl;
            glfwDestroyWindow(m_window);
            glfwTerminate();
            return EXIT_FAILURE;
        }

        if (!ImGui_ImplOpenGL3_Init("#version 330")) {
            std::cerr << "Error to init ImGui for OpenGL" << std::endl;
            glfwDestroyWindow(m_window);
            glfwTerminate();
            return EXIT_FAILURE;
        }

        ImGui::StyleColorsDark();
        ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_DockingEnable;

        return EXIT_SUCCESS;
    }

    void EditorApplication::terminate()
    {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::Shutdown();
        glfwDestroyWindow(m_window);
        glfwTerminate();
    }

    void EditorApplication::run()
    {
        glClearColor(0.2, 0.2, 0.2, 1);
        while (!glfwWindowShouldClose(m_window)) {
            glClear(GL_COLOR_BUFFER_BIT);

            glfwSwapBuffers(m_window);
            glfwPollEvents();
        }
    }
}
