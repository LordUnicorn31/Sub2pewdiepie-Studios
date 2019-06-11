#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "Globals.h"
#include "Application.h"
#include "ModuleSceneZangief.h"
#include "ModuleWelcomeScreen.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "Module.h"
#include "Application.h"
#include "ModuleFadeToBlack.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModuleVsScreen.h"
#include "ModuleSelect.h"
#include "ModuleCollision.h"
// Reference at https://youtu.be/6OlenbCC4WI?t=382

ModuleWelcomeScreen::ModuleWelcomeScreen()
{
	//background = { 120, 128, 671, 300 };
	background = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
}

ModuleWelcomeScreen::~ModuleWelcomeScreen()
{}

// Load assets
bool ModuleWelcomeScreen::Start()
{
	App->collision->CleanUp();
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("media_files/intro.png");
	mainmenumusic = App->audio->Load("media_files/02 The World Warrior.ogg");
	mainmenutoscenesound = App->audio->Load("media_files/IntroToScene.wav");
	App->audio->Play(mainmenumusic, -1);
	return ret;
}

// Load assets
bool ModuleWelcomeScreen::CleanUp()
{
	// TODO 5: Remove all memory leaks
	LOG("Unloading honda stage");
	App->textures->Unload(graphics);
	App->audio->Unload(mainmenumusic);
	App->audio->Unload(mainmenutoscenesound);
	return true;
}

// Update: draw background
update_status ModuleWelcomeScreen::Update()
{
	App->render->Blit(graphics, /*-150*/ 0, /*-45*/ 0, &background, 0.75f); // back of the room
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN || App->input->game_pad[App->player->startButton][0])
	{
		App->audio->Play(mainmenutoscenesound, 0);
		App->vs_screen->seconds = 0;
		App->fade->FadeToBlack(App->welcomescreen, App->select,1);
	}
	return UPDATE_CONTINUE;
}