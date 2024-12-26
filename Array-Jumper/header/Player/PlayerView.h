#pragma once
#include "../UI/UIElement/ImageView.h"

using namespace UI;
using namespace UIElement;
using namespace sf;

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

