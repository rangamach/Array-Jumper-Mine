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
	player_state = PlayerState::Alive;
}
