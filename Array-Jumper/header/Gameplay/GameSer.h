#pragma once

namespace Gameplay
{
	class GameplayController;
	class GameSer
	{
	private:
		GameplayController* gameplay_controller;
	public:
		void Initialize();
		void Update();
		void Render();

		void OnPositionChange(int position);
		void OnDeath();
	};
}