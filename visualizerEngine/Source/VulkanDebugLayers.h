#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#define VK_USE_PLATFORM_WIN32_KHR
#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3native.h>
#include <vector>



//Static class for now
class VulkanDebugLayers
{
public:
	VulkanDebugLayers(){}
	~VulkanDebugLayers(){}

    //Debug
private:
    inline static VkDebugUtilsMessengerEXT m_DebugMessenger;
    inline static const std::vector<const char*> m_ValidationLayers =
    {
        "VK_LAYER_KHRONOS_validation"
    };
public:

    inline static const std::vector<const char*> GetValidationLayers() { return m_ValidationLayers; }
    static bool CheckValidationLayerSupport();
    static VkDebugUtilsMessengerCreateInfoEXT GetCreateInfo();
    static void CreateDebugLayers(const VkInstance& Instance);
private:
    static VKAPI_ATTR VkBool32 VKAPI_CALL DebugCallback(
    	VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, 
    	VkDebugUtilsMessageTypeFlagsEXT messageType,
    	const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, 
    	void* pUserData);
private:


};
