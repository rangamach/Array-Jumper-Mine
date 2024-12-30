#include "../../header/Level/LevelService.h"
#include "../../header/Level/LevelModel.h"
#include "../../header/Level/LevelController.h"

using namespace Level;

void LevelService::Destroy()
{
	delete(level_controller);
}

LevelService::LevelService()
{
	level_controller = new LevelController();
}

LevelService::~LevelService()
{
	Destroy();
}

void LevelService::Initialize()
{
	level_controller->Initialize();
}

void LevelService::Update()
{
	level_controller->Update();
}

void LevelService::Render()
{
	level_controller->Render();
}

BoxDimensions LevelService::GetBoxDimensions()
{
	return level_controller->GetBoxDimensions();
}

BlockType LevelService::GetCurrentBoxValue(int current_position)
{
	return level_controller->GetCurrentBoxValue(current_position);
}
