#include "LvePipeline.h"

#include <fstream>
#include <ios>
#include <iostream>

namespace lve
{
	LvePipeline::LvePipeline(const std::string& vertFilePath, const std::string& fragFilePath)
	{
		createGraphicsPipeline(vertFilePath, fragFilePath);
	}

	std::vector<char> lve::LvePipeline::readFile(const std::string& filePath)
	{
		std::ifstream file(filePath, std::ios::ate | std::ios::binary);
		if (!file.is_open())
		{
			throw std::runtime_error("FAILED TO OPEN FILE: "+ filePath);
		}
		size_t fileSize = static_cast<size_t>(file.tellg());
		std::vector<char> buffer(fileSize);
		file.seekg(0);
		file.read(buffer.data(), fileSize);
		file.close();
		return buffer;

	}

	void LvePipeline::createGraphicsPipeline(const std::string& vertFilePath, const std::string& fragFilePath)
	{
		auto vertCode = readFile(vertFilePath);
		auto fragCode = readFile(fragFilePath);

		std::cout << "VERTEX SHADER CODE SIZE: "<<vertCode.size()<<'\n';
		std::cout << "FRAG SHADER CODE SIZE: "<<fragCode.size()<<'\n';
	}
}
