#include <iostream>
#include <stdexcept>
#include "../../external/glad/glad.h"
#include <GLFW/glfw3.h>

// Concrete class representing the basic triangle rendering concept
class BasicTriangleRendering
{
public:
    void run()
    {
        // Initialize GLFW
        if (!glfwInit())
        {
            throw std::runtime_error("Failed to initialize GLFW");
        }

        // Create a GLFW window
        GLFWwindow *window = glfwCreateWindow(800, 600, "Basic Triangle Rendering", NULL, nullptr);
        if (!window)
        {
            glfwTerminate();
            throw std::runtime_error("Failed to create GLFW window");
        }

        // Make the window's context current
        glfwMakeContextCurrent(window);

        // Load OpenGL function pointers with Glad
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            glfwTerminate();
            throw std::runtime_error("Failed to initialize GLAD");
        }

        // Debug point: Enable debug messages if DEBUG flag is defined
#ifdef DEBUG
        std::cout << "Debug: OpenGL initialized successfully." << std::endl;
#endif

        // Rendering loop
        while (!glfwWindowShouldClose(window))
        {
            // Clear the framebuffer
            glClear(GL_COLOR_BUFFER_BIT);

            // Render a basic triangle
            renderTriangle();

            // Swap the front and back buffers
            glfwSwapBuffers(window);

            // Poll for and process events
            glfwPollEvents();
        }

        // Terminate GLFW
        glfwTerminate();
    }

private:
    // Method to render a basic triangle
    void renderTriangle()
    {
        // Debug point: Enable debug messages if DEBUG flag is defined
#ifdef DEBUG
        std::cout << "Debug: Rendering triangle..." << std::endl;
#endif

        // Define the vertices of the triangle
        float vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f, 0.5f, 0.0f};

        // Create a vertex buffer object (VBO)
        unsigned int VBO;
        glGenBuffers(1, &VBO);

        // Bind the VBO
        glBindBuffer(GL_ARRAY_BUFFER, VBO);

        // Copy vertex data to the VBO
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        // Specify the layout of the vertex data
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
        glEnableVertexAttribArray(0);

        // Render the triangle
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // Unbind the VBO
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        // Debug point: Enable debug messages if DEBUG flag is defined
#ifdef DEBUG
        std::cout << "Debug: Triangle rendered successfully." << std::endl;
#endif
    }
};

int main()
{
    try
    {
        // Create an instance of the BasicTriangleRendering class
        BasicTriangleRendering basicTriangleRendering;

        // Run the graphics concept
        basicTriangleRendering.run();

        return 0;
    }
    catch (const std::exception &e)
    {
        // Handle any exceptions that occur during execution
        std::cerr << "An exception occurred: " << e.what() << std::endl;
        return 1;
    }
}
