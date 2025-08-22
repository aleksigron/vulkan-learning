#include "VulkanUtil.h"

#include <string.h>
#include <stdint.h>

#include <vector>

#include <vulkan/vulkan.h>

namespace vulkan::util
{

bool checkValidationLayerSupport(const char* const* validationLayers, size_t validationLayerCount)
{
	uint32_t availableLayerCount;
	vkEnumerateInstanceLayerProperties(&availableLayerCount, nullptr);

	std::vector<VkLayerProperties> availableLayers(availableLayerCount);
	vkEnumerateInstanceLayerProperties(&availableLayerCount, availableLayers.data());

	for (size_t i = 0; i != validationLayerCount; ++i)
	{
		const char* layerName = validationLayers[i];
		bool layerFound = false;

		for (const auto& layerProperties : availableLayers)
		{
			if (strcmp(layerName, layerProperties.layerName) == 0)
			{
				layerFound = true;
				break;
			}
		}

		if (!layerFound)
		{
			return false;
		}
	}

	return true;
}

}
