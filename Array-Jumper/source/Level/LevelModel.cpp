#include "../../header/Level/LevelModel.h"

using namespace Level;

Level::LevelModel::LevelModel()
{
}

Level::LevelModel::~LevelModel()
{
}

BlockType LevelModel::GetCurrentBoxValue(int current_position)
{
	return level_configuration.levels[current_level].blocks_array[current_position];
}

void LevelModel::LoadNextLevel()
{
	current_level++;
}

int LevelModel::GetCurrentLevel()
{
	return current_level;
}

bool LevelModel::IsLastLevel()
{
	return current_level == LevelConfiguration::number_of_levels - 1;
}

void LevelModel::ResetGame()
{
	current_level = 0;
}

