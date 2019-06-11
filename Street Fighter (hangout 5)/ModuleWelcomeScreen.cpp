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
#include "Animation.h"
// Reference at https://youtu.be/6OlenbCC4WI?t=382

ModuleWelcomeScreen::ModuleWelcomeScreen()
{
	//background = { 120, 128, 671, 300 };
	background = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

	loggo.loop = false;
	loggo.PushBack({ 0,0,135,61 });
	loggo.PushBack({ 128,0,258-128,61 });
	loggo.PushBack({ 257,0,335 - 257,131 });
	loggo.PushBack({ 341,0,460 - 341,132 });
	loggo.PushBack({ 0,142,144,223 - 142 });
	loggo.PushBack({ 152,143,293 - 152,272 - 143 });
	loggo.PushBack({300,136,383-300,285-136});
	loggo.PushBack({ 393,150,512 - 393,271 - 150 });
	loggo.PushBack({ 0,307,290,420 - 307 });
	loggo.speed = 0.08f;
}

ModuleWelcomeScreen::~ModuleWelcomeScreen()
{}

// Load assets
bool ModuleWelcomeScreen::Start()
{
	App->collision->CleanUp();
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("media_files/welcome_background.png");
	logo = App->textures->Load("media_files/logo.png");
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
	App->textures->Unload(logo);
	return true;
}

// Update: draw background
update_status ModuleWelcomeScreen::Update()
{
	App->render->Blit(graphics, /*-150*/ 0, /*-45*/ 0, &background, 0.75f); // back of the room
	App->render->Blit(logo, 45, 50, &loggo.GetCurrentFrame(), 0.80);
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN || App->input->game_pad[App->player->startButton][0])
	{
		App->audio->Play(mainmenutoscenesound, 0);
		App->vs_screen->seconds = 0;
		App->fade->FadeToBlack(App->welcomescreen, App->select,1);
	}
	return UPDATE_CONTINUE;
}