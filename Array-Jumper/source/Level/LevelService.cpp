#include "../../header/Level/LevelService.h"
#include "../../header/Level/LevelModel.h"
#include "../../header/Level/LevelController.h"

using namespace Level;

void Level::LevelService::Destroy()
{
	delete(level_controller);
}

Level::LevelService::LevelService()
{
	level_controller = new LevelController();
}

Level::LevelService::~LevelService()
{
	Destroy();
}

void Level::LevelService::Initialize()
{
	level_controller->Initialize();
}

void Level::LevelService::Update()
{
	level_controller->Update();
}

void Level::LevelService::Render()
{
	level_controller->Render();
}

BoxDimensions Level::LevelService::GetBoxDimensions()
{
	return level_controller->GetBoxDimensions();
}
