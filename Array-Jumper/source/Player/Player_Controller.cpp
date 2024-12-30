#include "../../header/Player/Player_Controller.h"
#include "../../header/Player/PlayerModel.h"
#include "../../header/Player/PlayerView.h"
#include "../../header/Player/MovementDirection.h"
#include <iostream>
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Event/EventService.h"

using namespace Player;
using namespace Global;
using namespace Event;

bool Player::Player_Controller::IsValidStep(int step_number)
{
	return step_number < LevelData::number_of_boxes && step_number >= 0;
}

void Player_Controller::ReadInput()
{
	if (!event_service->heldSpaceKey() && event_service->pressedDKey() || event_service->pressedRightArrowKey())
	{
		Move(MovementDirection::Forward);
	}
	if (!event_service->heldSpaceKey() && event_service->pressedAKey() || event_service->pressedLeftArrowKey())
	{
		Move(MovementDirection::Backward);
	}
	if (event_service->heldSpaceKey() && event_service->pressedAKey() || event_service->pressedLeftArrowKey())
	{
		Jump(MovementDirection::Backward);
	}
	if (event_service->heldSpaceKey() && event_service->pressedDKey() || event_service->pressedRightArrowKey())
	{
		Jump(MovementDirection::Forward);
	}
}

void Player_Controller::Destroy()
{
	delete(player_model);
	delete(player_view);
}

Player_Controller::Player_Controller()
{
	player_model = new PlayerModel();
	player_view = new PlayerView(this);
}

Player_Controller::~Player_Controller()
{
	Destroy();
}

void Player_Controller::Initialize()
{
	player_view->Initialize();
	event_service = ServiceLocator::getInstance()->getEventService();
	ResetPlayer();
}

void Player_Controller::Update()
{
	player_view->Update();
	ReadInput();	
}

void Player_Controller::Render()
{
	player_view->Render();
}

PlayerState Player_Controller::GetPlayerState()
{
	return player_model->GetPlayerState();
}

void Player_Controller::SetPlayerState(PlayerState state)
{
	player_model->SetPlayerState(state);
}

int Player_Controller::GetCurrentPosition()
{
	return player_model->GetCurrentPosition();
}

int Player_Controller::GetCurrentLives()
{
	return player_model->GetCurrentLives();
}

void Player::Player_Controller::Move(MovementDirection movement_direction)
{
	int steps;
	int target_position;
	switch (movement_direction)
	{
	case MovementDirection::Forward:
		steps = 1;
		break;
	case MovementDirection::Backward:
		steps = -1;
		break;
	default:
		steps = 0;
		break;
	}
	target_position = player_model->GetCurrentPosition() + steps;
	if (IsValidStep(target_position))
	{
		player_model->SetCurrentPosition(target_position);
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::MOVE);
	}
	ServiceLocator::getInstance()->GetGameSer()->OnPositionChange(target_position);
}

void Player_Controller::Jump(MovementDirection movement_direction)
{
	int current_position = player_model->GetCurrentPosition();
	BlockType box_value = ServiceLocator::getInstance()->GetLevelService()->GetCurrentBoxValue(current_position);
	int steps;
	int target_position;
	switch (movement_direction)
	{
	case MovementDirection::Forward:
		steps = static_cast<int>(box_value);
		break;
	case MovementDirection::Backward:
		steps = -static_cast<int>(box_value);
		break;
	default:
		steps = 0;
		break;
	}
	target_position = player_model->GetCurrentPosition() + steps;
	if (IsValidStep(target_position))
	{
		player_model->SetCurrentPosition(target_position);
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::MOVE);
	}
	ServiceLocator::getInstance()->GetGameSer()->OnPositionChange(target_position);
}

void Player_Controller::TakeDamage()
{
	player_model->DecrementLife();
	if (player_model->GetCurrentLives() <= 0)
		OnDeath();
	else
		player_model->SetCurrentPosition(0);

}

void Player_Controller::ResetPlayer()
{
	player_model->ResetPlayer();
}

void Player_Controller::OnDeath()
{
	ServiceLocator::getInstance()->GetGameSer()->OnDeath();
	ResetPlayer();
}

