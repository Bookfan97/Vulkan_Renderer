#pragma once

#include "lve_device.h"
#include "lve_game_object.h"
#include "LvePipeline.h"
#include "lve_swap_chain.h"
#include "Window.h"

// std
#include <memory>
#include <vector>

#include "lve_renderer.h"

namespace lve {
	class FirstApp {
	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;

		FirstApp();
		~FirstApp();

		FirstApp(const FirstApp&) = delete;
		FirstApp& operator=(const FirstApp&) = delete;

		void run();

	private:
		void loadGameObjects();

		LveWindow lveWindow{ WIDTH, HEIGHT, "Vulkan Tutorial" };
		LveDevice lveDevice{ lveWindow };
		LveRenderer lveRenderer{ lveWindow, lveDevice };
		std::vector<LveGameObject> gameObjects;
	};
}  // namespace lve