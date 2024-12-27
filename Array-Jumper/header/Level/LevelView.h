#pragma once

#include <SFML/Graphics.hpp>
#include "../UI/UIElement/ImageView.h"

using namespace sf;
using namespace UI;
using namespace UIElement;

namespace Level
{
	class LevelController;
	class LevelView
	{
	private:
		RenderWindow* game_window;
		LevelController* level_controller;
		ImageView* background_image;
		const float background_alpha = 110.f;

		void CreateImages();
		void InitializeImages();
		void UpdateImages();
		void DrawLevel();
		void DeleteImages();

	public:
		LevelView(LevelController* controller);
		~LevelView();

		void Initialize();
		void Update();
		void Render();
	};
}

