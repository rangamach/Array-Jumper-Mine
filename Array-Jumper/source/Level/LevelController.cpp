#include "../../header/Level/LevelController.h"
#include "../../header/Level/LevelModel.h"
#include "../../header/Level/LevelView.h"
#include "../../header/Level/LevelData.h"
#include "../../header/Level/BlockType.h"

using namespace Level;

LevelController::LevelController()
{
	level_view = new LevelView(this);
	level_model = new LevelModel();
}

LevelController::~LevelController()
{
}

void LevelController::Initialize()
{
	level_view->Initialize();
}

void LevelController::Update()
{
	level_view->Update();
}

void LevelController::Render()
{
	level_view->Render();
}

BlockType LevelController::GetCurrentBoxValue(int current_position)
{
	return level_model->GetCurrentBoxValue(current_position);
}

BoxDimensions LevelController::GetBoxDimensions()
{
	return level_view->GetBoxDimensions();
}

bool LevelController::IsLastLevel()
{
	return level_model->IsLastLevel();
}

int LevelController::GetCurrentLevelNumber()
{
	return level_model->GetCurrentLevel();
}

void LevelController::LoadNextLevel()
{
	level_model->LoadNextLevel();
}

