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

ModuleSelect::ModuleSelect()
{
	background = { 120, 128, 671, 300 };
	background = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

	//Selector animation
	select.PushBack({ 0, 1, 21, 33 });
	select.PushBack({ 24, 0, 23, 34 });
}

ModuleSelect::~ModuleSelect()
{}

// Load assets
bool ModuleSelect::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("media_files/backgroundselectscreen.png");
	selector = App->textures->Load("media_files/selectorP1.png");
	App->render->Blit(selector, 384, 224, &(select.GetCurrentFrame()), 0.75f);

	selectmusic = App->audio->Load("media_files/03 Player Select.ogg");
	App->audio->Play(selectmusic, 1);
	return ret;
}

// Load assets
bool ModuleSelect::CleanUp()
{
	// TODO 5: Remove all memory leaks
	LOG("Unloading honda stage");
	App->textures->Unload(graphics);
	App->audio->Unload(selectmusic);
	
	return true;
}

// Update: draw background
update_status ModuleSelect::Update()
{
	App->render->Blit(graphics, 0,  0, &background, 0.75f);
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN || App->input->game_pad[App->player->startButton][0]) {
		App->fade->FadeToBlack(App->select, App->vs_screen, 1);
	}

	return UPDATE_CONTINUE;
}