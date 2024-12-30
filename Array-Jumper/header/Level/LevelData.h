#pragma once

#include "BlockType.h"

namespace Level
{
	struct LevelData
	{
		static const int number_of_boxes = 10;
        BlockType blocks_array[number_of_boxes] =
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
	};
}

