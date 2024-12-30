#pragma once

#include "BlockType.h"

namespace Level
{
	struct LevelData
	{
		static const int number_of_boxes = 10;
        BlockType blocks_array[number_of_boxes];
	};
}

