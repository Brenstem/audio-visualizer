#pragma once
#include "VulkanImpl.h"

#include <string>

class Graphics
{
public:
	Graphics(const uint32_t Width, const uint32_t Height, const std::string& WindowName = "Default");
	~Graphics();

    inline GLFWwindow* GetWindow() const { return m_Window; }

private:
    //Creating multiples of class might create memory leak?
    GLFWwindow* m_Window = nullptr;

    uint32_t m_Width = 0;
    uint32_t m_Height = 0;
    const int MAX_FRAMES_IN_FLIGHT = 2;
    uint32_t m_CurrentFrame = 0;
};

