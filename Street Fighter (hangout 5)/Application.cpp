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
	modules[8] = player = new ModulePlayer(playernames::RYU);
	modules[9] = fade = new ModuleFadeToBlack();
	modules[10] = welcomescreen = new ModuleWelcomeScreen();
	modules[11] = congratsscreen = new ModuleCongratsScreen();
	modules[12] = particles = new ModuleParticles();
	modules[13] = audio = new ModuleAudio();
	modules[14] = collision = new ModuleCollision();
	modules[15] = player2 = new ModulePlayer(/*playernames::ZANGIEF*/playernames::ZANGIEF);
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