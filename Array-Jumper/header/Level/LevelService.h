#pragma once

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
	};
}

