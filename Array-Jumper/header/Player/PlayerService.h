#pragma once

namespace Player
{
	class Player_Controller;
	class PlayerService
	{
	private:
		Player_Controller* player_controller;

		void Destroy();
		void TakeDamage();
	public:
		PlayerService();
		~PlayerService();

		void Initialize();
		void Update();
		void Render();
	};
}

