#pragma once
#include "../UI/UIElement/ImageView.h"
#include "../Level/LevelModel.h"

using namespace UI;
using namespace UIElement;
using namespace sf;
using namespace Level;

namespace Player
{
	class Player_Controller;
	class PlayerView
	{
	private:
		ImageView* player_image;
		RenderWindow* game_window;
		Player_Controller* player_controller;

		float player_height;
		float player_width;
		BoxDimensions current_box_dimensions;

		void InitializePlayerImage();
		void DrawPlayer();
		void LoadPlayer();
		void CalculatePlayerDimensions();
		void UpdatePlayerPosition();
		Vector2f CalculatePlayerPosition();

	public:
		PlayerView(Player_Controller* controller);
		~PlayerView();

		void Initialize();
		void Update();
		void Render();
	};
}

