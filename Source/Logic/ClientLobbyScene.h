#ifndef CLIENT_LOBBY_SCENE_H_
#define CLIENT_LOBBY_SCENE_H_

#include <vector>
#include <cstdio>
#include <SFML/Graphics.hpp>
#include "../Engine/Scene.h"
#include "../AppWindow.h"
#include "../Engine/TextureManager.h"
#include "../Multimedia/graphics/Renderer.h"
#include "../Multimedia/gui/Button.h"
#include "../Multimedia/graphics/object/BGO.h"
#include "../Multimedia/graphics/object/SGO.h"

#include "../Network/Client.h"
#include "Entities/ClientMux.h"
#include "PlayerLobbyChoices.h"

#define BTN_WIDTH 150
#define BTN_HEIGHT 75
#define COUNTDOWN 4

#define CLASS_BTN_WIDTH 46
#define CLASS_BTN_HEIGHT 47

/*
*   This is the Lobby scene.
*/
class ClientLobbyScene : public Scene
{
    public:
        ClientLobbyScene();
        virtual void update(sf::Time);
        virtual void processEvents(sf::Event&);
        virtual void draw();
        virtual void onLoad();
        ~ClientLobbyScene();

        static void onLeaveClick();
        static void onVesselOneClick();
        static void onVesselTwoClick();
        static void onDeityOneClick();
        static void onDeityTwoClick();

        static int getDeityChoice();
        static int getVesselChoice();

        void updateMainView(sf::View& v);
        static int vesselChoice;
        static int deityChoice;
        
        void startTimer(int remainingTime);
        void stopTimer(int remainingTime);
        void updatePlayerCount(int numPlayers);

        PlayerLobbyChoices *getSelections();
    private:

        sf::View viewMain;
        Renderer renderer;

        SGO *background;
        id_resource backgroundImg;

        id_resource circle;
        GUI::TextBox * countdownBox;
        GUI::TextBox * playerBox;

        SGO *vesselOneCircleSGO;
        SGO *vesselTwoCircleSGO;
        SGO *deityOneCircleSGO;
        SGO *deityTwoCircleSGO;

        SGO *vesselOneSGO;
        SGO *vesselTwoSGO;

        GUI::Button * vesselOneBtn;
        GUI::Button * vesselTwoBtn;

        GUI::Button * aspectOneBtn;
        GUI::Button * aspectTwoBtn;

        GUI::Button * leaveBtn;

        id_resource vesselOneArt;
        id_resource vesselTwoArt;

        id_resource vesselOneImg;
        id_resource vesselTwoImg;

        id_resource aspectOneImg;
        id_resource aspectTwoImg;

        id_resource leaveImg;

        const int SCN_WIDTH = 1366;
        const int SCN_HEIGHT = 768;

        const int CIRCLE_WH = 200;
        const int VESSEL_ART_WH = 400;

        static sf::Clock clck;
        static bool timego;
        static float currentTime;
        int playerCount;

        GameScene * gameScene;
        ClientMux * clientMux;
        PlayerLobbyChoices playerSelections;
};

#endif