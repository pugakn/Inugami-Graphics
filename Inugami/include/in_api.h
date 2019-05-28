#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <functional>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>

#include <optional>
namespace Inugami {
  struct QueueFamilyIndices {
    std::optional<uint32_t> graphicsFamily;
    std::optional<uint32_t> presentFamily;

    bool isComplete() {
      return graphicsFamily.has_value() && presentFamily.has_value();
    }
  };

  class GraphicsAPI {
  public:
    const int WIDTH = 800;
    const int HEIGHT = 600;    const std::vector<const char*> validationLayers = { 
      "VK_LAYER_KHRONOS_validation" 
    };
    const std::vector<const char*> deviceExtensions = {
    VK_KHR_SWAPCHAIN_EXTENSION_NAME
  };
#ifdef NDEBUG
    const bool enableValidationLayers = false;
#else
    const bool enableValidationLayers = true;
#endif
    void Run();
  private:
    static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
      VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
      VkDebugUtilsMessageTypeFlagsEXT messageType,
      const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
      void* pUserData);

    void InitWindow();
    std::vector<const char*> GetRequiredExtensions();
    bool checkValidationLayerSupport();
    void CreateInstance();
    void setupDebugMessenger();
    void initVulkan();
    void pickPhysicalDevice();    int rateDeviceSuitability(VkPhysicalDevice device);    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
    void createLogicalDevice();
    void createSurface();
    void mainLoop();
    void cleanup();

    VkInstance instance;    GLFWwindow* window;
    VkDebugUtilsMessengerEXT debugMessenger;    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;    VkDevice device; //Logical device
    VkQueue graphicsQueue;
    VkQueue presentQueue;
    VkSurfaceKHR surface;

  };
}
