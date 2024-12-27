#include "../../header/Level/LevelController.h"
#include "../../header/Level/LevelModel.h"
#include "../../header/Level/LevelView.h"

using namespace Level;

Level::LevelController::LevelController()
{
	level_view = new LevelView(this);
	level_model = new LevelModel();
}

Level::LevelController::~LevelController()
{
}

void Level::LevelController::Initialize()
{
	level_view->Initialize();
}

void Level::LevelController::Update()
{
	level_view->Update();
}

void Level::LevelController::Render()
{
	level_view->Render();
}
