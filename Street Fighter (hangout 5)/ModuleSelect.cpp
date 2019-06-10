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
	//background = { 120, 128, 671, 300 };
	background = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
}

ModuleSelect::~ModuleSelect()
{}

// Load assets
bool ModuleSelect::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	//graphics = App->textures->Load("media_files/vs_screen.png");
	//audio = App->audio->Load("media_files/04 Start Battle.ogg");
	//App->audio->Play(music, 0);
	return ret;
}

// Load assets
bool ModuleSelect::CleanUp()
{
	// TODO 5: Remove all memory leaks
	LOG("Unloading honda stage");
	//App->textures->Unload(graphics);
	return true;
}

// Update: draw background
update_status ModuleSelect::Update()
{
	//App->render->Blit(graphics, /*-150*/ 0, /*-45*/ 0, &background, 0.75f);
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN) {
		App->fade->FadeToBlack(App->select, App->vs_screen, 1);
	}

	return UPDATE_CONTINUE;
}