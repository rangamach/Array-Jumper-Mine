#include "../../header/Level/LevelModel.h"

using namespace Level;

Level::LevelModel::LevelModel()
{
}

Level::LevelModel::~LevelModel()
{
}

BlockType Level::LevelModel::GetCurrentBoxValue(int current_position)
{
	return level_data.blocks_array[current_position];
}
