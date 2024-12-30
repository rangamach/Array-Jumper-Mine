#pragma once

#include "LevelModel.h"

namespace Level
{
	class LevelController;
	class LevelService
	{
	private:
		LevelController* level_controller;

		void Destroy();

	public:
		LevelService();
		~LevelService();

		void Initialize();
		void Update();
		void Render();

		BoxDimensions GetBoxDimensions();
		BlockType GetCurrentBoxValue(int current_position);
	};
}

