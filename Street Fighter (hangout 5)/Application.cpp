#include "Application.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleSceneRyu.h"
#include "ModuleSceneZangief.h"
#include "ModuleWelcomeScreen.h"
#include "ModuleCongratsScreen.h"
#include "ModulePlayer.h"
#include "ModuleFadeToBlack.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModuleCollision.h"
#include "ModuleFonts.h"
#include "ModuleSpecialMoves.h"
#include "ModuleUi.h"
#include "ModuleVsScreen.h"
//#include "ModuleWinloseScreen.h"

Application::Application()
{
	modules[0] = window = new ModuleWindow();
	modules[1] = render = new ModuleRender();
	modules[2] = input = new ModuleInput();
	modules[3] = special_moves = new ModuleSpecialMoves();
	modules[4] = textures = new ModuleTextures();
	modules[5] = scene_Ryu = new ModuleSceneRyu();
	modules[6] = scene_Zangief = new ModuleSceneZangief();
	modules[7] = player = new ModulePlayer
	(playernames::ZANGIEF,
		SDL_CONTROLLER_BUTTON_DPAD_LEFT, 
		SDL_CONTROLLER_BUTTON_DPAD_RIGHT, 
		SDL_CONTROLLER_BUTTON_DPAD_UP, 
		SDL_CONTROLLER_BUTTON_DPAD_DOWN, 
		SDL_CONTROLLER_BUTTON_X, 
		SDL_CONTROLLER_BUTTON_Y, 
		SDL_CONTROLLER_BUTTON_LEFTSHOULDER, 
		SDL_CONTROLLER_BUTTON_A, 
		SDL_CONTROLLER_BUTTON_B, 
		SDL_CONTROLLER_BUTTON_RIGHTSHOULDER, 
		SDL_SCANCODE_F1,
		SDL_SCANCODE_F2,
		players::PLAYER1
	);
	modules[8] = fade = new ModuleFadeToBlack();
	modules[9] = welcomescreen = new ModuleWelcomeScreen();
	modules[10] = congratsscreen = new ModuleCongratsScreen();
	modules[11] = particles = new ModuleParticles();
	modules[12] = audio = new ModuleAudio();
	modules[13] = collision = new ModuleCollision();
	modules[14] = player2 = new ModulePlayer
	(playernames::ZANGIEF,
		SDL_CONTROLLER_BUTTON_DPAD_LEFT,
		SDL_CONTROLLER_BUTTON_DPAD_RIGHT,
		SDL_CONTROLLER_BUTTON_DPAD_UP,
		SDL_CONTROLLER_BUTTON_DPAD_DOWN,
		SDL_CONTROLLER_BUTTON_X,
		SDL_CONTROLLER_BUTTON_Y,
		SDL_CONTROLLER_BUTTON_LEFTSHOULDER,
		SDL_CONTROLLER_BUTTON_A,
		SDL_CONTROLLER_BUTTON_B,
		SDL_CONTROLLER_BUTTON_RIGHTSHOULDER,
		SDL_SCANCODE_F3,
		SDL_SCANCODE_F4,
		players::PLAYER2
	);
	modules[15] = fonts = new ModuleFonts();
	modules[16] = ui = new ModuleUi();
	modules[17] = vs_screen = new ModuleVsScreen();
}	

Application::~Application()
{
	for(int i = NUM_MODULES - 1; i >= 0; --i)
		delete modules[i];
}

bool Application::Init()
{
	bool ret = true;

	player->Disable();
	player2->Disable();
	scene_Ryu->Disable();
	scene_Zangief->Disable();
	congratsscreen->Disable();
	vs_screen->Disable();
	for(int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->Init();

	for(int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Start() : true;

	return ret;
}

update_status Application::Update()
{
	update_status ret = UPDATE_CONTINUE;

	for(int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PreUpdate() : UPDATE_CONTINUE;

	for(int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Update() : UPDATE_CONTINUE;

	for(int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PostUpdate() : UPDATE_CONTINUE;

	return ret;
}

bool Application::CleanUp()
{
	bool ret = true;

	for(int i = NUM_MODULES - 1; i >= 0 && ret == true; --i)
		ret = modules[i]->CleanUp();

	return ret;
}