#include "../../header/Gameplay/GameplayController.h"
#include "../../header/Global/ServiceLocator.h"

using namespace Gameplay;
using namespace Global;

void GameplayController::ProcessObstacle()
{
	ServiceLocator::getInstance()->GetPlayerService()->TakeDamage();
	ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::DEATH);
}

bool GameplayController::IsObstacle(BlockType value)
{
	return value == BlockType::Obstacle_One || value == BlockType::Obstacle_Two;
}

void GameplayController::Initialize()
{

}

void GameplayController::Update()
{

}

void GameplayController::Render()
{

}

void GameplayController::OnPositionChange(int position)
{
	BlockType pos = ServiceLocator::getInstance()->GetLevelService()->GetCurrentBoxValue(position);
	if (IsObstacle(pos))
	{
		ProcessObstacle();
	}
}