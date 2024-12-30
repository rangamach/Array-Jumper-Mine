#pragma once

#include "../Event/EventService.h"

using namespace Event;
namespace Player
{
	class PlayerView;
	class PlayerModel;
	enum class PlayerState;
	enum class MovementDirection;
	class Player_Controller
	{
	private:
		PlayerModel* player_model;
		PlayerView* player_view;
		EventService* event_service;

		bool IsValidStep(int step_number);
		void ReadInput();
		void Destroy();

	public:
		Player_Controller();
		~Player_Controller();
		
		void Initialize();
		void Update();
		void Render();

		PlayerState GetPlayerState();
		void SetPlayerState(PlayerState state);
		int GetCurrentPosition();
		void move(MovementDirection movement_direction);
	};
}

