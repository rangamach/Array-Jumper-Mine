#include "../../header/Player/Player_Controller.h"
#include "../../header/Player/PlayerModel.h"
#include "../../header/Player/PlayerView.h"

using namespace Player;

void Player::Player_Controller::Destroy()
{
	delete(player_model);
	delete(player_view);
}

Player::Player_Controller::Player_Controller()
{
	player_model = new PlayerModel();
	player_view = new PlayerView(this);
}

Player::Player_Controller::~Player_Controller()
{
	Destroy();
}

void Player::Player_Controller::Initialize()
{
	player_view->Initialize();
}

void Player::Player_Controller::Update()
{
	player_view->Update();
}

void Player::Player_Controller::Render()
{
	player_view->Render();
}

PlayerState Player::Player_Controller::GetPlayerState()
{
	return player_model->GetPlayerState();
}

void Player::Player_Controller::SetPlayerState(PlayerState state)
{
	player_model->SetPlayerState(state);
}
