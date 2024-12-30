#pragma once

namespace Player
{
	enum class PlayerState
	{
		Alive = 0,
		Dead = 1
	};
	class PlayerModel
	{
	private:
		int current_position;
		const int max_lives = 3;
		int current_lives;

		PlayerState player_state;

	public:
		PlayerState GetPlayerState();
		void SetPlayerState(PlayerState state);

		int GetCurrentPosition();
		void SetCurrentPosition(int position);
		void ResetPlayer();
		int GetCurrentLives();
		void DecrementLife();
	};
}

