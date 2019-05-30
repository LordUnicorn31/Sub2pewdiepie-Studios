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
#include "ModuleController.h"
#include "ModuleUi.h"
//#include "ModuleWinloseScreen.h"

Application::Application()
{
	modules[0] = window = new ModuleWindow();
	modules[1] = render = new ModuleRender();
	modules[2] = input = new ModuleInput();
	modules[3] = controller = new ModuleController();
	modules[4] = special_moves = new ModuleSpecialMoves();
	modules[5] = textures = new ModuleTextures();
	modules[6] = scene_Ryu = new ModuleSceneRyu();
	modules[7] = scene_Zangief = new ModuleSceneZangief();
	modules[8] = player = new ModulePlayer
	(playernames::ZANGIEF,
		SDL_SCANCODE_A, 
		SDL_SCANCODE_D, 
		SDL_SCANCODE_W, 
		SDL_SCANCODE_S, 
		SDL_SCANCODE_1, 
		SDL_SCANCODE_2, 
		SDL_SCANCODE_3, 
		SDL_SCANCODE_4, 
		SDL_SCANCODE_5, 
		SDL_SCANCODE_6, 
		SDL_SCANCODE_F1,
		SDL_SCANCODE_F2);
	modules[9] = fade = new ModuleFadeToBlack();
	modules[10] = welcomescreen = new ModuleWelcomeScreen();
	modules[11] = congratsscreen = new ModuleCongratsScreen();
	modules[12] = particles = new ModuleParticles();
	modules[13] = audio = new ModuleAudio();
	modules[14] = collision = new ModuleCollision();
	modules[15] = player2 = new ModulePlayer
	(playernames::ZANGIEF,
		SDL_SCANCODE_LEFT,
		SDL_SCANCODE_RIGHT,
		SDL_SCANCODE_UP,
		SDL_SCANCODE_DOWN,
		SDL_SCANCODE_J,
		SDL_SCANCODE_K,
		SDL_SCANCODE_L,
		SDL_SCANCODE_F3,
		SDL_SCANCODE_F4,
		NULL,
		NULL,
		NULL);
	modules[16] = fonts = new ModuleFonts();
	modules[17] = ui = new ModuleUi();
	//modules[13] = winlosescreen = new ModuleWinloseScreen();
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