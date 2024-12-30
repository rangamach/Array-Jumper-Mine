#include "../../header/Player/PlayerService.h"
#include "../../header/Player/Player_Controller.h"

using namespace Player;

void PlayerService::Destroy()
{
	delete(player_controller);
}

PlayerService::PlayerService()
{
	player_controller = new Player_Controller();
}

PlayerService::~PlayerService()
{
	Destroy();
}

void PlayerService::Initialize()
{
	player_controller->Initialize();
}

void PlayerService::Update()
{
	player_controller->Update();
}

void PlayerService::Render()
{
	player_controller->Render();
}
