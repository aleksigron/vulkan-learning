#pragma once

#include <stdint.h>

#include <optional>

#include <vulkan/vulkan.h>

namespace vulkan::util
{

struct QueueFamilyIndices
{
	std::optional<uint32_t> graphicsFamily;
	std::optional<uint32_t> presentFamily;

	bool isComplete()
	{
		return graphicsFamily.has_value() && presentFamily.has_value();
	}

	static QueueFamilyIndices fromDeviceAndSurface(VkPhysicalDevice device, VkSurfaceKHR surface);
};

bool checkValidationLayerSupport(const char* const* validationLayers, size_t validationLayerCount);

VkSampleCountFlagBits getMaxUsableSampleCount(VkPhysicalDevice physicalDevice);

uint32_t findMemoryType(VkPhysicalDevice physicalDevice, uint32_t typeFilter, VkMemoryPropertyFlags properties);

bool checkDeviceExtensionSupport(VkPhysicalDevice device, const char* const* deviceExtensions, size_t deviceExtensionsCount);

VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities, uint32_t preferredWidth, uint32_t preferredHeight);

}
