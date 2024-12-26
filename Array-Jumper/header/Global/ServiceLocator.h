#pragma once
#include "../../header/Graphics/GraphicService.h"
#include "../../header/Event/EventService.h"
#include "../../header/UI/UIService.h"
#include "../../header/Sound/SoundService.h"
#include "../Player/PlayerService.h"

using namespace Event;
using namespace Sound;
using namespace Player;

namespace Global
{
    class ServiceLocator
    {
    private:
        Graphics::GraphicService* graphic_service;
        EventService* event_service;
        SoundService* sound_service;
        UI::UIService* ui_service;
        PlayerService* player_service;

        ~ServiceLocator();

        void createServices();
        void clearAllServices();

    public:
        ServiceLocator();
        static ServiceLocator* getInstance();

        void initialize();
        void update();
        void render();

        Graphics::GraphicService* getGraphicService();
        EventService* getEventService();
        SoundService* getSoundService();
        UI::UIService* getUIService();
        PlayerService* GetPlayerService();
    };
}