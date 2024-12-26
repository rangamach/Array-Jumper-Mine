#pragma once

namespace Player
{
	enum class PlayerState
	{
		Alive,
		Dead
	};
	class PlayerModel
	{
	private:
		int current_position;
		PlayerState player_state;
	public:
		PlayerState GetPlayerState();
		void SetPlayerState(PlayerState state);

		int GetCurrentPosition();
		void SetCurrentPosition(int position);
	};
}

