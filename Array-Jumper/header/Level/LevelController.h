#pragma once

namespace Level
{
	class LevelModel;
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
	};
}

