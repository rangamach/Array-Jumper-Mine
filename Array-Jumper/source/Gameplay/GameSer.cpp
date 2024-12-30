#include "../../header/Gameplay/GameSer.h"
#include "../../header/Gameplay/GameplayController.h"

using namespace Gameplay;

void GameSer::Initialize()
{
	gameplay_controller->Initialize();
}

void GameSer::Update()
{
	gameplay_controller->Update();
}

void GameSer::Render()
{
	gameplay_controller->Render();
}

void GameSer::OnPositionChange(int position)
{
	gameplay_controller->OnPositionChange(position);
}

void GameSer::OnDeath()
{
	gameplay_controller->OnDeath();
}