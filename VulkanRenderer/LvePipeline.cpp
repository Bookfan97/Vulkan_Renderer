#include "LvePipeline.h"

#include <fstream>
#include <ios>
#include <iostream>

namespace lve
{
	LvePipeline::LvePipeline(LveDevice& device, const std::string& vertFilePath, const std::string& fragFilePath, const PipelineConfigInfo& configInfo):
	lveDevice(device)
	{
		createGraphicsPipeline(vertFilePath, fragFilePath, configInfo);
	}

	LvePipeline::~LvePipeline()
	{
	}

	PipelineConfigInfo LvePipeline::defaultPipelineConfigInfo(uint32_t width, uint32_t height)
	{
		PipelineConfigInfo configInfo{};
		return configInfo;
	}

	std::vector<char> lve::LvePipeline::readFile(const std::string& filePath)
	{
		std::ifstream file(filePath, std::ios::ate | std::ios::binary);
		if (!file.is_open())
		{
			throw std::runtime_error("FAILED TO OPEN FILE: " + filePath);
		}
		size_t fileSize = static_cast<size_t>(file.tellg());
		std::vector<char> buffer(fileSize);
		file.seekg(0);
		file.read(buffer.data(), fileSize);
		file.close();
		return buffer;
	}

	void LvePipeline::createGraphicsPipeline(const std::string& vertFilePath, const std::string& fragFilePath,
		const PipelineConfigInfo& config_info)
	{
		auto vertCode = readFile(vertFilePath);
		auto fragCode = readFile(fragFilePath);

		std::cout << "VERTEX SHADER CODE SIZE: " << vertCode.size() << '\n';
		std::cout << "FRAG SHADER CODE SIZE: " << fragCode.size() << '\n';
	}

	void LvePipeline::createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule)
	{
		VkShaderModuleCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
		createInfo.codeSize = code.size();
		createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());
		if (vkCreateShaderModule(lveDevice.device(), &createInfo, nullptr, shaderModule) != VK_SUCCESS)
		{
			std::runtime_error("FAILED TO CREATE SAHDER MODULE");
		}
	}
}