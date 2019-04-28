#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "Globals.h"
#include "Application.h"
#include "ModuleSceneRyu.h"
#include "ModuleWelcomeScreen.h"
#include "ModuleCongratsScreen.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "Module.h"
#include "Application.h"
#include "ModuleFadeToBlack.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
// Reference at https://youtu.be/6OlenbCC4WI?t=382

ModuleCongratsScreen::ModuleCongratsScreen()
{
	// Background
	background = { 0, 0, 384, 224 };
	//winer image
	winer = { 127,2588,131,113 };
	//loser image
	loser = { 276,2588,130,113 };
}

ModuleCongratsScreen::~ModuleCongratsScreen()
{}

// Load assets
bool ModuleCongratsScreen::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("congratsplayer1.png");
	graphics2 = App->textures->Load("congratsplayer2.png");
	congratsmusic = App->audio->Load("13 End Battle.ogg");
	
	App->audio->Play(congratsmusic, 0);
	return ret;
}

// Load assets
bool ModuleCongratsScreen::CleanUp()
{
	// TODO 5: Remove all memory leaks
	LOG("Unloading congrats stage");
	App->textures->Unload(graphics);
	App->audio->Unload(congratsmusic);
	return true;
}

// Update: draw background
update_status ModuleCongratsScreen::Update()
{
	if (App->player->life > App->player2->life)
		App->render->Blit(graphics, 0, 0, &background, 0.75f);
	else
		App->render->Blit(graphics2, 0, 0, &background, 0.75f);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN) {
		App->fade->FadeToBlack(App->congratsscreen, App->welcomescreen,1);
		
	}
	return UPDATE_CONTINUE;
}