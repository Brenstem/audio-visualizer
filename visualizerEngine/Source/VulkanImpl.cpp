#include "VulkanImpl.h"
#include "VulkanDebugLayers.h"
#include <stdexcept>
#include <iostream>

VulkanImpl::VulkanImpl()
{
    vkEnumerateInstanceExtensionProperties(nullptr, &m_ExtensionCount, nullptr);
    CreateInstance();
    VulkanDebugLayers::CreateDebugLayers(m_Instance);
}

VulkanImpl::~VulkanImpl()
{
}

void VulkanImpl::FrameBufferResizeCallback(GLFWwindow* Window, int Width, int Height)
{
    auto app = reinterpret_cast<VulkanImpl*>(glfwGetWindowUserPointer(Window));
    app->bFrameBufferResized = true;
}


void VulkanImpl::CreateInstance()
{
    if (bEnableValidationLayers && !VulkanDebugLayers::CheckValidationLayerSupport()) 
    {
		throw std::runtime_error("Validation layers requested, but none were available");
    }
    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "AudioVisualizer";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "RenderEngine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;


    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions;

    auto extensions = GetRequiredExtensions();
    createInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
    createInfo.ppEnabledExtensionNames = extensions.data();

    VkDebugUtilsMessengerCreateInfoEXT debugCreateInfo = VulkanDebugLayers::GetCreateInfo();// = m_DebugLayers->GetDebugMessengerUtils();
    const auto ValidationLayers = VulkanDebugLayers::GetValidationLayers();
    if (bEnableValidationLayers)
    {
        createInfo.enabledLayerCount = static_cast<uint32_t>(ValidationLayers.size());
        createInfo.ppEnabledLayerNames = ValidationLayers.data();
        createInfo.pNext = (VkDebugUtilsMessengerCreateInfoEXT*)&debugCreateInfo;
    }
    else 
    {
        createInfo.enabledLayerCount = 0;
        createInfo.pNext = nullptr;
    }

   // uint32_t ExtensionCount = 0;
   // vkEnumerateInstanceExtensionProperties(nullptr, &ExtensionCount, nullptr);
   // std::vector<VkExtensionProperties> ExtensionProperties(ExtensionCount);
   // vkEnumerateInstanceExtensionProperties(nullptr, &ExtensionCount, ExtensionProperties.data());

    VkResult Result = vkCreateInstance(&createInfo, nullptr, &m_Instance);

    if (Result != VK_SUCCESS)
    {
        throw std::runtime_error("failed to create instance!");
    }
}

std::vector<const char*> VulkanImpl::GetRequiredExtensions()
{
    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions;
    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    std::vector<const char*> Extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);

    if (bEnableValidationLayers) 
    {
        Extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
    }

    return Extensions;
}

