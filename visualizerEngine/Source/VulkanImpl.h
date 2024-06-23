#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#define VK_USE_PLATFORM_WIN32_KHR
#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3native.h>

#include <vector>
class VulkanImpl
{
public:

    VulkanImpl();
    ~VulkanImpl();

    inline uint32_t GetExtensionCount() const { return m_ExtensionCount; }
    static void FrameBufferResizeCallback(GLFWwindow* Window, int Width, int Height);
private:
    void CreateInstance();
    std::vector<const char*> GetRequiredExtensions();

private:
    uint32_t m_ExtensionCount = 0;
    bool bFrameBufferResized = false;
    VkInstance m_Instance;
    bool bEnableValidationLayers = true;
};
