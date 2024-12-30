#include "../../header/UI/Gameplay/GameplayUIController.h"
#include "../../header/UI/UIElement/TextView.h"
#include "../../header/Global/ServiceLocator.h"

#include <sstream>
#include <iomanip>
#include <iostream>

using namespace GameplayUI;
using namespace UI::UIElement;
using namespace Global;
using namespace sf;

GameplayUIController::GameplayUIController()
{
	CreateTexts();
}

GameplayUIController::~GameplayUIController()
{
	Destroy();
}

void GameplayUIController::Initialize()
{
	InitializeTexts();
}

void GameplayUIController::Update()
{
	UpdateLifeCountText();
}

void GameplayUIController::Render()
{
	life_count_text->render();
}

void GameplayUIController::CreateTexts()
{
	life_count_text = new TextView();
}

void GameplayUIController::InitializeTexts()
{
	InitializeLifeCountText();
}

void GameplayUIController::InitializeLifeCountText()
{
	float window_width = ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->getSize().x;
	float x = (static_cast<float>(window_width) - right_offset);
	float y = top_offset;

	life_count_text->initialize("0", Vector2f(x, y), FontType::BUBBLE_BOBBLE, font_size, Color::White);
}

void GameplayUIController::UpdateLifeCountText()
{
	int life_count = ServiceLocator::getInstance()->GetPlayerService()->GetCurrentLives();
	std::string life_count_string = "Life: " + std::to_string(life_count);
	life_count_text->setText(life_count_string);
	life_count_text->update();
}

void GameplayUIController::Destroy()
{
	delete(life_count_text);
}