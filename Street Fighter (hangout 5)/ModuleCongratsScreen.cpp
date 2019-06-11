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
#include "ModuleUi.h"
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
	graphics = App->textures->Load("media_files/p1_win.png");
	graphics2 = App->textures->Load("media_files/p2_win.png");
	congratsmusic = App->audio->Load("media_files/13 End Battle.ogg");
	
	App->audio->Play(congratsmusic, 0);
	return ret;
}

// Load assets
bool ModuleCongratsScreen::CleanUp()
{
	// TODO 5: Remove all memory leaks
	LOG("Unloading congrats stage");
	App->textures->Unload(graphics);
	App->textures->Unload(graphics2);
	App->audio->Unload(congratsmusic);
	App->player->matcheswon = 0;
	App->player2->matcheswon = 0;
	App->ui->round_index = -1;
	App->ui->current_round = 0;
	return true;
}

// Update: draw background
update_status ModuleCongratsScreen::Update()
{
	/*if (App->player->life > App->player2->life)
		App->render->Blit(graphics, 0, 0, &background, 0.75f);
	else
		App->render->Blit(graphics2, 0, 0, &background, 0.75f);*/
	if (App->player->matcheswon > App->player2->matcheswon) {
		App->render->Blit(graphics, 0, 0, &background);
	}
	else if (App->player->matcheswon < App->player2->matcheswon) {
		App->render->Blit(graphics2, 0, 0, &background);
	}

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN) {
		App->fade->FadeToBlack(App->congratsscreen, App->welcomescreen,1);
		
	}
	return UPDATE_CONTINUE;
}