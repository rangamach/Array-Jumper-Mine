#pragma once

#include "../Level/BlockType.h"

using namespace Level;

namespace Gameplay
{
	class GameplayController
	{
	private:
		void ProcessObstacle();
		void ProcessTargetBlock();
		bool IsObstacle(BlockType value);
		bool IsTargetBlock(BlockType value);

	public:
		void Initialize();
		void Update();
		void Render();

		void OnPositionChange(int position);
	};
}