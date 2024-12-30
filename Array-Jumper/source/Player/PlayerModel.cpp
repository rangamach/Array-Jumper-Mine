#include "../../header/Player/PlayerModel.h"

using namespace Player;

PlayerState PlayerModel::GetPlayerState()
{
	return player_state;
}

void PlayerModel::SetPlayerState(PlayerState state)
{
	player_state = state;
}

int PlayerModel::GetCurrentPosition()
{
	return current_position;
}

void PlayerModel::SetCurrentPosition(int position)
{
	current_position = position;
}

void PlayerModel::ResetPlayer()
{
	current_position = 0;
	current_lives = max_lives;
	player_state = PlayerState::Alive;
}

int PlayerModel::GetCurrentLives()
{
	return current_lives;
}

void PlayerModel::DecrementLife()
{
	current_lives -= 1;
}
