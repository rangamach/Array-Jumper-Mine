#include "../../header/Player/PlayerView.h"
#include "../../header/Player/Player_Controller.h"
#include "../../header/Global/Config.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Player/PlayerModel.h"
#include "../../header/Level/LevelModel.h"

using namespace Player;
using namespace Global;

void PlayerView::InitializePlayerImage()
{
	player_image->initialize(Config::character_texture_path, player_width, player_height, Vector2f(0.f, 0.f));
}

void PlayerView::DrawPlayer()
{
	player_image->render();
}

void PlayerView::LoadPlayer()
{
	CalculatePlayerDimensions();
	InitializePlayerImage();
}

void PlayerView::CalculatePlayerDimensions()
{
	current_box_dimensions = ServiceLocator::getInstance()->GetLevelService()->GetBoxDimensions();
	player_height = current_box_dimensions.box_height;
	player_width = current_box_dimensions.box_width;
}

void PlayerView::UpdatePlayerPosition()
{
	player_image->setPosition(CalculatePlayerPosition());
}

Vector2f PlayerView::CalculatePlayerPosition()
{
	float x = current_box_dimensions.box_spacing + static_cast<float>(player_controller->GetCurrentPosition()) * (current_box_dimensions.box_width + current_box_dimensions.box_spacing);
	float y = static_cast<float>(game_window->getSize().y) - current_box_dimensions.box_height - current_box_dimensions.bottom_offset - player_height;
	return Vector2f(x, y);
}

PlayerView::PlayerView(Player_Controller* controller)
{
	player_controller = controller;
	player_image = new ImageView();
}

PlayerView::~PlayerView()
{
}

void PlayerView::Initialize()
{
	game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
	LoadPlayer();
}

void PlayerView::Update()
{
	UpdatePlayerPosition();
}

void PlayerView::Render()
{
	switch (player_controller->GetPlayerState())
	{
	case PlayerState::Alive:
		DrawPlayer();
		break;
	}
}
