#include "../../header/Gameplay/GameplayController.h"
#include "../../header/Global/ServiceLocator.h"
#include "..//../header/Main/GameService.h"

using namespace Gameplay;
using namespace Global;
using namespace Main;

void GameplayController::ProcessObstacle()
{
	ServiceLocator::getInstance()->GetPlayerService()->TakeDamage();
	ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::DEATH);
}

void GameplayController::ProcessTargetBlock()
{
	ServiceLocator::getInstance()->GetPlayerService()->LevelComplete();
	ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::LEVEL_COMPLETE);

	if (IsLastLevel())
	{
		GameWon();
		return;
	}
	LoadNextLevel();
}

bool GameplayController::IsObstacle(BlockType value)
{
	return value == BlockType::Obstacle_One || value == BlockType::Obstacle_Two;
}

bool GameplayController::IsTargetBlock(BlockType value)
{
	return value == BlockType::Target;
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
	if (IsTargetBlock(pos))
	{
		ProcessTargetBlock();
	}
}

void GameplayController::GameOver()
{
	GameService::setGameState(GameState::CREDITS);
	ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::DEATH);
}

void GameplayController::OnDeath()
{
	GameOver();
}

void GameplayController::GameWon()
{
	GameService::setGameState(GameState::CREDITS);
	ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::LEVEL_COMPLETE);
}

void GameplayController::LoadNextLevel()
{
	ServiceLocator::getInstance()->GetLevelService()->LoadNextLevel();
}

bool GameplayController::IsLastLevel()
{
	return ServiceLocator::getInstance()->GetLevelService()->IsLastLevel();
}