#include "../../header/Player/Player_Controller.h"
#include "../../header/Player/PlayerModel.h"
#include "../../header/Player/PlayerView.h"

using namespace Player;

void Player_Controller::Destroy()
{
	delete(player_model);
	delete(player_view);
}

Player_Controller::Player_Controller()
{
	player_model = new PlayerModel();
	player_view = new PlayerView(this);
}

Player_Controller::~Player_Controller()
{
	Destroy();
}

void Player_Controller::Initialize()
{
	player_view->Initialize();
}

void Player_Controller::Update()
{
	player_view->Update();
}

void Player_Controller::Render()
{
	player_view->Render();
}

PlayerState Player_Controller::GetPlayerState()
{
	return player_model->GetPlayerState();
}

void Player::Player_Controller::SetPlayerState(PlayerState state)
{
	player_model->SetPlayerState(state);
}
