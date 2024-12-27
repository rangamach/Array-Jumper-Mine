#include "../../header/Level/LevelView.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Global/Config.h"

using namespace Level;
using namespace Global;
using namespace UI::UIElement;

void Level::LevelView::CreateImages()
{
	background_image = new ImageView();
}

void Level::LevelView::InitializeImages()
{
	background_image->initialize(Config::array_jumper_bg_texture_path, game_window->getSize().x, game_window->getSize().y, Vector2f(0, 0));
	background_image->setImageAlpha(background_alpha);
}

void Level::LevelView::UpdateImages()
{
	background_image->update();
}

void Level::LevelView::DrawLevel()
{
	background_image->render();
}

void Level::LevelView::DeleteImages()
{
	delete(background_image);
}

LevelView::LevelView(LevelController* controller)
{
	game_window = nullptr;
	level_controller = controller;
	CreateImages();
}

LevelView::~LevelView()
{
	DeleteImages();
}

void LevelView::Initialize()
{
	game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
	InitializeImages();
}

void LevelView::Update()
{
	UpdateImages();
}

void LevelView::Render()
{
	DrawLevel();
}
