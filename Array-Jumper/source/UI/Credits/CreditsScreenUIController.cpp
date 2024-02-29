#include "../../header/Credits/CreditsScreenUIController.h"
#include "../../header/Main/GameService.h"

namespace UI
{
    namespace Credits
    {
        using namespace Main;
        CreditsScreenUIController::CreditsScreenUIController()
        {
            game_window = nullptr;
            sound_service = nullptr;
        }

        CreditsScreenUIController::~CreditsScreenUIController()
        {
        }

        void CreditsScreenUIController::initialize(Graphics::GraphicService* graphic_handler_instance, Sound::SoundService* sound_handler_instance)
        {
            graphic_service = graphic_handler_instance;
            sound_service = sound_handler_instance;
            game_window = graphic_service->getGameWindow();

            initializeBackgroundImage();
            initializeButtons();
        }

        void CreditsScreenUIController::initializeBackgroundImage()
        {
            if (background_texture.loadFromFile("assets/textures/array_jumper_bg.png"))
            {
                background_sprite.setTexture(background_texture);
                setBackgroundAlpha();
                scaleBackgroundImage();
            }
        }

        void CreditsScreenUIController::setBackgroundAlpha()
        {
            sf::Color color = background_sprite.getColor();
            color.a = background_alpha;
            background_sprite.setColor(color);
        }


        void CreditsScreenUIController::scaleBackgroundImage()
        {
            background_sprite.setScale(
                static_cast<float>(game_window->getSize().x) / background_sprite.getTexture()->getSize().x,
                static_cast<float>(game_window->getSize().y) / background_sprite.getTexture()->getSize().y
            );
        }

        void CreditsScreenUIController::initializeButtons()
        {
            if (loadButtonTexturesFromFile())
            {
                setButtonSprites();
                scaleAllButttons();
                positionButtons();
            }
        }

        bool CreditsScreenUIController::loadButtonTexturesFromFile()
        {
            return quit_button_texture.loadFromFile("assets/textures/quit_button.png") &&
                menu_button_texture.loadFromFile("assets/textures/menu_button.png");
        }

        void CreditsScreenUIController::setButtonSprites()
        {
            quit_button_sprite.setTexture(quit_button_texture);
            menu_button_sprite.setTexture(menu_button_texture);
        }

        void CreditsScreenUIController::scaleAllButttons()
        {
            scaleButton(&quit_button_sprite);
            scaleButton(&menu_button_sprite);
        }

        void CreditsScreenUIController::scaleButton(sf::Sprite* button_to_scale)
        {
            button_to_scale->setScale(
                button_width / button_to_scale->getTexture()->getSize().x,
                button_height / button_to_scale->getTexture()->getSize().y
            );
        }

        void CreditsScreenUIController::positionButtons()
        {
            float x_position = (static_cast<float>(game_window->getSize().x) / 2) - button_width / 2;

            menu_button_sprite.setPosition({ x_position, 600.f });
            quit_button_sprite.setPosition({ x_position, 800.f });
        }

        void CreditsScreenUIController::update()
        {
            if (pressedMouseButton())
            {
                handleButtonInteractions();
                mouse_button_pressed = true;
            }
            else
            {
                mouse_button_pressed = false;
            }
        }

        void CreditsScreenUIController::render()
        {
            game_window->draw(background_sprite);
            game_window->draw(menu_button_sprite);
            game_window->draw(quit_button_sprite);
            drawGameTitle();
        }

        bool CreditsScreenUIController::pressedMouseButton() { return sf::Mouse::isButtonPressed(sf::Mouse::Left); }

        void CreditsScreenUIController::handleButtonInteractions()
        {
            sf::Vector2f mouse_position = sf::Vector2f(sf::Mouse::getPosition(*game_window));

            if (clickedButton(&quit_button_sprite, mouse_position))
            {
                onClickQuitButton();
            }

            if (clickedButton(&menu_button_sprite, mouse_position))
            {
                onClickMenuButton();
            }
        }

        bool CreditsScreenUIController::clickedButton(sf::Sprite* button_sprite, sf::Vector2f mouse_position)
        {
            return button_sprite->getGlobalBounds().contains(mouse_position);
        }

        void CreditsScreenUIController::onClickQuitButton()
        {
            game_window->close();
        }

        void CreditsScreenUIController::onClickMenuButton()
        {
            sound_service->playSound(SoundType::BUTTON_CLICK);
            GameService::setGameState(GameState::MAIN_MENU);
        }

        void CreditsScreenUIController::drawGameTitle()
        {
            graphic_service->drawText(game_window_title, top_offset, font_size);
        }
    }
}
