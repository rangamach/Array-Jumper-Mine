#include "../../header/Player/PlayerView.h"
#include "../../header/Global/Config.h"
#include "../../header/Global/ServiceLocator.h"

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
	player_width = 1000.f;
	player_height = 1000.f;
}

void PlayerView::UpdatePlayerPosition()
{
	player_image->setPosition(CalculatePlayerPosition());
}

Vector2f PlayerView::CalculatePlayerPosition()
{
	return Vector2f(0.f,0.f);
}

PlayerView::PlayerView()
{
	game_window = nullptr;
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
}
