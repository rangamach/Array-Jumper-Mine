#pragma once

#include "BlockType.h"
#include "LevelModel.h"

namespace Level
{
	class LevelView;
	class LevelController
	{
	private:
		LevelModel* level_model;
		LevelView* level_view;

	public:
		LevelController();
		~LevelController();

		void Initialize();
		void Update();
		void Render();

		BlockType GetCurrentBoxValue(int current_position);
		BoxDimensions GetBoxDimensions();
	};
}

