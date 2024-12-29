#pragma once

namespace Player
{
	class PlayerView;
	class PlayerModel;
	enum class PlayerState;
	class Player_Controller
	{
	private:
		PlayerModel* player_model;
		PlayerView* player_view;

		void Destroy();

	public:
		Player_Controller();
		~Player_Controller();
		
		void Initialize();
		void Update();
		void Render();

		PlayerState GetPlayerState();
		void SetPlayerState(PlayerState state);
		int GetCurrentPosition();
	};
}

