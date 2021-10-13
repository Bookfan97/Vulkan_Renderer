#pragma once
#include "LvePipeline.h"
#include "Window.h"
#include "lve_device.h"
#include <string>

namespace lve {
	class FirstApp {
	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;

		void run();

	private:
		LveWindow lveWindow{ WIDTH, HEIGHT, "Hello Vulkan!" };
		LveDevice lveDevice{ lveWindow };
		LvePipeline lvePipeline{ lveDevice, "s haders/simple_shader.vert.spv", "shaders/simple_shader.frag.spv", LvePipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT) };
	};
}