#include "Graphics.h"

Graphics::Graphics(const uint32_t Width, const uint32_t Height, const std::string& WindowName)
    : m_Width(Width), m_Height(Height)
{
	glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    m_Window = glfwCreateWindow(m_Width, m_Height, WindowName.c_str(), nullptr, nullptr);
    glfwSetWindowUserPointer(m_Window, this);
    glfwSetFramebufferSizeCallback(m_Window, VulkanImpl::FrameBufferResizeCallback);
}

Graphics::~Graphics()
{
    glfwDestroyWindow(m_Window);
    glfwTerminate();
}


