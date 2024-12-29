#include "../../header/Level/LevelView.h"
#include "../../header/Level/LevelController.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Global/Config.h"

using namespace Level;
using namespace Global;
using namespace UI::UIElement;

void Level::LevelView::CreateImages()
{
	background_image = new ImageView();
	box_image = new ImageView();
	target_overlay = new ImageView();
	one_overlay = new ImageView();
	two_overlay = new ImageView();
	three_overlay = new ImageView();
	obstacle_one_overlay = new ImageView();
	obstacle_two_overlay = new ImageView();
}

void Level::LevelView::InitializeImages()
{
	background_image->initialize(Config::array_jumper_bg_texture_path, game_window->getSize().x, game_window->getSize().y, Vector2f(0, 0));
	background_image->setImageAlpha(background_alpha);

	box_image->initialize(Config::box_texture_path, box_dimensions.box_width, box_dimensions.box_height, Vector2f(0.f, 0.f));

	target_overlay->initialize(Config::target_texture_path, box_dimensions.box_width, box_dimensions.box_height, Vector2f(0.f, 0.f));
	one_overlay->initialize(Config::letter_one_texture_path, box_dimensions.box_width, box_dimensions.box_height, Vector2f(0.f, 0.f));
	two_overlay->initialize(Config::letter_two_texture_path, box_dimensions.box_width, box_dimensions.box_height, Vector2f(0.f, 0.f));
	three_overlay->initialize(Config::letter_three_texture_path, box_dimensions.box_width, box_dimensions.box_height, Vector2f(0.f, 0.f));
	obstacle_one_overlay->initialize(Config::obstacle_01_texture_path, box_dimensions.box_width, box_dimensions.box_height, Vector2f(0.f, 0.f));
	obstacle_two_overlay->initialize(Config::obstacle_02_texture_path, box_dimensions.box_width, box_dimensions.box_height, Vector2f(0.f, 0.f));
}

void Level::LevelView::UpdateImages()
{
	background_image->update();

	box_image->update();

	target_overlay->update();
	one_overlay->update();
	two_overlay->update();
	three_overlay->update();
	obstacle_one_overlay->update();
	obstacle_two_overlay->update();
}

void Level::LevelView::DrawLevel()
{
	background_image->render();

	for (int i = 0; i < LevelData::number_of_boxes; ++i)
	{
		Vector2f pos = CalculateBoxPosition(i);
		BlockType block_type_to_draw = level_controller->GetCurrentBoxValue(i);
		DrawBox(pos);
		DrawBoxValue(pos, block_type_to_draw);
	}
}

void Level::LevelView::DrawBox(Vector2f position)
{
	box_image->setPosition(position);
	box_image->render();
}

void Level::LevelView::DrawBoxValue(Vector2f position, BlockType box_value)
{
	ImageView* image = GetBoxOverlayImage(box_value);
	image->setPosition(position);
	image->render();
}

void Level::LevelView::DeleteImages()
{
	delete(background_image);

	delete(box_image);

	delete(target_overlay);
	delete(one_overlay);
	delete(two_overlay);
	delete(three_overlay);
	delete(obstacle_one_overlay);
	delete(obstacle_two_overlay);

}

void Level::LevelView::CalculateBoxDimensions()
{
	if (!game_window) return;
	CalculateBoxWidthHeight();
	CalculateBoxSpacing();
}

void LevelView::CalculateBoxWidthHeight()
{
	float screen_width = static_cast<float>(game_window->getSize().x);
	int number_of_boxes = LevelData::number_of_boxes;
	int number_of_gaps = number_of_boxes + 1;
	float total_space_of_gaps = box_dimensions.box_spacing_percentage * static_cast<float>(number_of_gaps);
	float total_space_available = number_of_boxes + number_of_gaps;
	box_dimensions.box_width = screen_width / total_space_available;
	box_dimensions.box_height = box_dimensions.box_width;
}

void LevelView::CalculateBoxSpacing()
{
	box_dimensions.box_spacing = box_dimensions.box_width * box_dimensions.box_spacing_percentage;
}

Vector2f LevelView::CalculateBoxPosition(int index)
{
	Vector2f pos;
	pos.x = box_dimensions.box_spacing + static_cast<float>(index) * (box_dimensions.box_width + box_dimensions.box_spacing);
	pos.y = game_window->getSize().y - box_dimensions.bottom_offset;
	return pos;
}

LevelView::LevelView(LevelController* controller)
{
	game_window = nullptr;
	level_controller = controller;
	CreateImages();
}

LevelView::~LevelView()
{
	DeleteImages();
}

void LevelView::Initialize()
{
	game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
	CalculateBoxDimensions();
	InitializeImages();
}

void LevelView::Update()
{
	UpdateImages();
}

void LevelView::Render()
{
	DrawLevel();
}

ImageView* Level::LevelView::GetBoxOverlayImage(BlockType block_type)
{
	switch (block_type)
	{
	case BlockType::Target:
		return target_overlay;
	case BlockType::One:
		return one_overlay;
	case BlockType::Two:
		return two_overlay;
	case BlockType::Three:
		return three_overlay;
	case BlockType::Obstacle_One:
		return obstacle_one_overlay;
	case BlockType::Obstacle_Two:
		return obstacle_two_overlay;
	}
	return nullptr;
}
