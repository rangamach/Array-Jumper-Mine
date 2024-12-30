#pragma once

namespace Player
{
	class Player_Controller;
	class PlayerService
	{
	private:
		Player_Controller* player_controller;

		void Destroy();
	public:
		PlayerService();
		~PlayerService();

		void Initialize();
		void Update();
		void Render();
	};
}

