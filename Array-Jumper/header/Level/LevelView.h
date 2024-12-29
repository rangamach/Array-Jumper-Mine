#pragma once

#include <SFML/Graphics.hpp>
#include "../UI/UIElement/ImageView.h"
#include "LevelModel.h"

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
		ImageView* box_image;
		ImageView* target_overlay;
		ImageView* one_overlay;
		ImageView* two_overlay;
		ImageView* three_overlay;
		ImageView* obstacle_one_overlay;
		ImageView* obstacle_two_overlay;
		BoxDimensions box_dimensions;
		const float background_alpha = 110.f;

		void CreateImages();
		void InitializeImages();
		void UpdateImages();
		void DrawLevel();
		void DrawBox(Vector2f position);
		void DrawBoxValue(Vector2f position, BlockType box_value);
		void DeleteImages();
		void CalculateBoxDimensions();
		void CalculateBoxWidthHeight();
		void CalculateBoxSpacing();
		Vector2f CalculateBoxPosition(int index);

	public:
		LevelView(LevelController* controller);
		~LevelView();

		void Initialize();
		void Update();
		void Render();

		ImageView* GetBoxOverlayImage(BlockType block_type);
	};
}

