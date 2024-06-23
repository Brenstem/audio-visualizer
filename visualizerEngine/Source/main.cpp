//#define GLFW_INCLUDE_VULKAN
//#include <GLFW/glfw3.h>
#include "Graphics.h"
#include <iostream>

int main() {
    //glfwInit();

    //glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    //GLFWwindow* window = glfwCreateWindow(800, 600, "Vulkan window", nullptr, nullptr);

    //uint32_t extensionCount = 0;
    //vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

    //std::cout << extensionCount << " extensions supported\n";

    //glm::mat4 matrix;
    //glm::vec4 vec;
    //auto test = matrix * vec;

    Graphics GraphicsObj(640, 800);
    VulkanImpl Vulkan;

    std::cout << Vulkan.GetExtensionCount() << " extensions supported\n";
    //std::cout << test.x << "\n";
    while (!glfwWindowShouldClose(GraphicsObj.GetWindow())) 
    {
        glfwPollEvents();
    }

    return 0;
}