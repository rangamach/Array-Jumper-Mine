#pragma once

#include "LevelData.h"
#include "BlockType.h"

namespace Level
{
	class LevelConfiguration
	{
	private:
		BlockType level_1[LevelData::number_of_boxes] =
		{
			BlockType::One, 
			BlockType::Two,
			BlockType::Obstacle_One,
			BlockType::Two,
			BlockType::Three,
			BlockType::One,
			BlockType::Obstacle_Two,
			BlockType::Two,
			BlockType::One,
			BlockType::Target
		};

		BlockType level_2[LevelData::number_of_boxes] =
		{
			BlockType::One,
			BlockType::Two,
			BlockType::Obstacle_One,
			BlockType::One,
			BlockType::Two,
			BlockType::Obstacle_One,
			BlockType::Three,
			BlockType::Obstacle_One,
			BlockType::One,
			BlockType::Target
		};

		BlockType level_3[LevelData::number_of_boxes] =
		{
			BlockType::One,
			BlockType::Three,
			BlockType::Obstacle_One,
			BlockType::Obstacle_Two,
			BlockType::One,
			BlockType::Two,
			BlockType::Obstacle_One,
			BlockType::Two,
			BlockType::One,
			BlockType::Target
		};
	public:
		static const int number_of_levels = 3;
		LevelData levels[number_of_levels];
		
		LevelConfiguration()
		{
			for (int i = 0; i < LevelData::number_of_boxes; i++)
			{
				levels[0].blocks_array[i] = level_1[i];
			}
			for (int i = 0; i < LevelData::number_of_boxes; i++)
			{
				levels[1].blocks_array[i] = level_2[i];
			}
			for (int i = 0; i < LevelData::number_of_boxes; i++)
			{
				levels[2].blocks_array[i] = level_3[i];
			}
		}
	};
}
