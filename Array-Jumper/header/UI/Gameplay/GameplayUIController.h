#pragma once
#include "../UIElement/TextView.h"

using namespace UI::UIElement;

namespace GameplayUI
{
	class GameplayUIController
	{
	private:
		TextView* life_count_text;

		float font_size = 55.f;
		const float top_offset = 100.f;
		const float left_offset = 100.f;
		const float right_offset = 250.f;

		void CreateTexts();
		void InitializeTexts();
		void InitializeLifeCountText();
		void UpdateLifeCountText();
		void Destroy();

	public:
		GameplayUIController();
		~GameplayUIController();

		void Initialize();
		void Update();
		void Render();
	};
}
