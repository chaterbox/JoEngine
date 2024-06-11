#include "Joepch.h"
#include "VulkanContext.h"
#include "VulkanUtils.h"
#ifdef JOE_PLATFORM_WINDOWS
#include <vulkan_win32.h>
#endif
#ifdef JOE_PLATFORM_LINUX
#include <vulkan/vulkan_xcb.h>
#endif

namespace Joe{
	void VulkanContext::Init(){						
		///////////////////////////////////////////
		////               instance            ////
		///////////////////////////////////////////

		uint32_t apiVer = 0;
		vkEnumerateInstanceVersion(&apiVer);

		VkApplicationInfo appInfo = {};
		appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		appInfo.applicationVersion = VK_MAKE_VERSION(0, 0, 1);
		appInfo.pApplicationName = "JOE";
		appInfo.engineVersion = VK_MAKE_VERSION(0, 0, 1);
		appInfo.pEngineName = "JOE";
		appInfo.apiVersion = VK_API_VERSION_1_2;
		
		#ifdef JOE_PLATFORM_WINDOWS
			instanceExtensions.push_back(VK_KHR_WIN32_SURFACE_EXTENSION_NAME);
		#endif

		#ifdef JOE_PLATFORM_LINUX
			instanceExtensions.push_back(VK_KHR_XCB_SURFACE_EXTENSION_NAME);
		#endif

		#ifdef JOE_DEBUG
			instanceExtensions.push_back(VK_EXT_VALIDATION_FEATURES_EXTENSION_NAME);
		#endif

		VkValidationFeatureEnableEXT bestpratice = VK_VALIDATION_FEATURE_ENABLE_BEST_PRACTICES_EXT;
		VkValidationFeaturesEXT enableValFeat = {};
		enableValFeat.sType = VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT;
		enableValFeat.enabledValidationFeatureCount = 1;
		enableValFeat.pEnabledValidationFeatures = &bestpratice;

		#ifdef JOE_DEBUG
			std::vector<const char*>instanceLayers;
			instanceLayers.push_back("VK_LAYER_KHRONOS_validation");
			#ifdef JOE_ENABLE_API_DUMP
				instanceLayers.push_back("VK_LAYER_LUNARG_api_dump");
			#endif
		#endif

		#ifdef JOE_DIST
				std::vector<const char*>instanceLayers = {};
		#endif

		#ifdef JOE_RELEASE
			std::vector<const char*>instanceLayers = {};
		#endif
		
		VkInstanceCreateInfo instanceInfo = {};
		instanceInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		#ifdef JOE_DEBUG
			instanceInfo.pNext = &enableValFeat;
		#endif 
		instanceInfo.pApplicationInfo = &appInfo;
		instanceInfo.enabledExtensionCount = static_cast<uint32_t>(instanceExtensions.size());
		instanceInfo.ppEnabledExtensionNames = instanceExtensions.data();
		instanceInfo.enabledLayerCount = static_cast<uint32_t>(instanceLayers.size());
		instanceInfo.ppEnabledLayerNames = instanceLayers.data();

		if(vkCreateInstance(&instanceInfo, nullptr, &instance) != VK_SUCCESS) {
			JOE_FATAL("VULKAN::INSTANCE::CREATE::FAILED");
		}

		uint32_t physicalDeviceCount = 0;
		vkEnumeratePhysicalDevices(instance, &physicalDeviceCount, nullptr);

		if (physicalDeviceCount == 0) {
			JOE_CORE_ERROR("VULKAN: no physical device found");
		}

		vkEnumeratePhysicalDevices(instance, &physicalDeviceCount, &m_PhysDevice);

				///////////////////////////////////////////
				////            device info            ////
				///////////////////////////////////////////

		vkGetPhysicalDeviceProperties(m_PhysDevice, &m_DeviceProp);

		JOE_CORE_INFO("VULKAN INFO:");
		JOE_CORE_INFO("VULKAN: DEVICE INFO:");
		JOE_CORE_INFO("	VULKAN: Device: {0}", m_DeviceProp.deviceName);

		int driverMajor, driverMinor, driverPatch, apiMajor, apiMinor, apiPatch;

		apiMajor = VK_VERSION_MAJOR(m_DeviceProp.apiVersion);
		apiMinor = VK_VERSION_MINOR(m_DeviceProp.apiVersion);
		apiPatch = VK_VERSION_PATCH(m_DeviceProp.apiVersion);

		JOE_CORE_INFO("	VULKAN: API Version: {0}.{1}.{2}", apiMajor, apiMinor, apiPatch);

		driverMajor = VK_VERSION_MAJOR(m_DeviceProp.driverVersion);
		driverMinor = VK_VERSION_MINOR(m_DeviceProp.driverVersion);
		driverPatch = VK_VERSION_PATCH(m_DeviceProp.driverVersion);

		JOE_CORE_INFO("	VULKAN: Driver Version: {0}.{1}.{2}", driverMajor, driverMinor, driverPatch);

		switch (m_DeviceProp.deviceType) {
		case VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU:
			JOE_CORE_INFO("	VULKAN: Device type: Integerated GPU ");
			break;
		case VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU:
			JOE_CORE_INFO("	VULKAN: Device type: Discrete_GPU");
			break;
		default:
			JOE_CORE_ERROR("	VULKAN: Unsupported physical device");
			break;
		}

		std::vector<const char*>DeviceExtensions = { VK_KHR_SWAPCHAIN_EXTENSION_NAME };

		VkPhysicalDeviceFeatures physDeviceFeats = { VK_FALSE };

		float queuePri = 1.0f;

		VkDeviceQueueCreateInfo queueInfo = {};
		queueInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
		queueInfo.queueCount = 1;
		queueInfo.queueFamilyIndex = 0;
		queueInfo.pQueuePriorities = &queuePri;
		queueInfo.flags = 0;

		VkDeviceCreateInfo DeviceCreateInfo = {};
		DeviceCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
		DeviceCreateInfo.enabledExtensionCount = static_cast<uint32_t>(DeviceExtensions.size());
		DeviceCreateInfo.ppEnabledExtensionNames = DeviceExtensions.data();
		DeviceCreateInfo.pEnabledFeatures = &physDeviceFeats;
		DeviceCreateInfo.pQueueCreateInfos = &queueInfo;
		DeviceCreateInfo.queueCreateInfoCount = 1;
		DeviceCreateInfo.flags = 0;

		uint32_t queueFamPropsCount = 0;
		vkGetPhysicalDeviceQueueFamilyProperties(m_PhysDevice, &queueFamPropsCount, nullptr);

		if (vkCreateDevice(m_PhysDevice, &DeviceCreateInfo, nullptr, &m_LogicalDevice) != VK_SUCCESS) {
			JOE_FATAL("VULKAN::LOGICAL::DEVICE::CREATE::FAILED");
		}
	}

	void VulkanContext::Swapbuffers(){
	}

	VulkanContext::VulkanContext(){
	}

	VulkanContext::~VulkanContext(){
		vkDestroyInstance(instance, nullptr);
	}
}
