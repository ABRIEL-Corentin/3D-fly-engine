////////////////////////
//
//  Created on Sat Mar 11 2023
//
//  editor_application.cpp
//
////////////////////////

#include "editor/application/editor_application.hpp"
#include "editor/application/theme.hpp"
#include "engine/engine.hpp"
#include "engine/component/components/identity.hpp"

namespace Fly::Editor
{
    GLFWwindow *EditorApplication::m_window = nullptr;
    Windows EditorApplication::m_windows = Windows();
    Engine::Scene EditorApplication::m_scene = Engine::Scene();

    int EditorApplication::init()
    {
        if (!glfwInit()) {
            std::cerr << "Error to init glfw" << std::endl;
            return EXIT_FAILURE;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        m_window = glfwCreateWindow(1920, 1080, "EDITOR", nullptr, nullptr);

        if (!m_window) {
            std::cerr << "Error to create editor window" << std::endl;
            glfwTerminate();
            return EXIT_FAILURE;
        }
        glfwMakeContextCurrent(m_window);
        glfwSwapInterval(0);

        if (glewInit() != GLEW_OK) {
            std::cerr << "Error to ini glew" << std::endl;
            glfwDestroyWindow(m_window);
            glfwTerminate();
            return EXIT_FAILURE;
        }

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

        UpdateTheme();

        m_scene.createEntity("Entity 1");
        m_scene.createEntity("Entity 2");
        m_scene.createEntity("Entity 3");
        m_scene.createEntity("Entity 4");

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
        std::cout << std::fixed;
        std::cout << std::setprecision(3);

        while (!glfwWindowShouldClose(m_window)) {
            if (!framerateLimiter(60))
                continue;

            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            m_windows.initDocking();
            m_windows.drawMainMenuBar();
            m_windows.drawToolBar();
            m_windows.drawSceneWindow();
            m_windows.drawConsoleWindow();
            m_windows.drawHierarchyWindow(m_scene);
            m_windows.drawInspectorWindow(m_scene.getEntitySelected());
            m_windows.drawExplorerWindow();

            ImGui::Render();
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

            glfwSwapBuffers(m_window);
            glfwPollEvents();
        }
        std::cout << std::endl;
    }

    bool EditorApplication::framerateLimiter(double framerate)
    {
        static double last_time = 0;
        double current_time = glfwGetTime();

        if (current_time - last_time < 1.0 / framerate)
            return false;
        std::cout << "\rFPS: " << 1 / (current_time - last_time) << std::flush;
        last_time = current_time;
        return true;
    }
}
