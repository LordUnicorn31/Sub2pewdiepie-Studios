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
// Reference at https://youtu.be/6OlenbCC4WI?t=382

ModuleCongratsScreen::ModuleCongratsScreen()
{
	// Background / sky
	background = { 120, 128, 671, 300 };
}

ModuleCongratsScreen::~ModuleCongratsScreen()
{}

// Load assets
bool ModuleCongratsScreen::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("honda_stage4.png");
	return ret;
}

// Load assets
bool ModuleCongratsScreen::CleanUp()
{
	// TODO 5: Remove all memory leaks
	LOG("Unloading honda stage");
	App->textures->Unload(graphics);
	return true;
}

// Update: draw background
update_status ModuleCongratsScreen::Update()
{
	App->render->Blit(graphics, -150, -45, &background, 0.75f); // back of the room
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN) {
		App->fade->FadeToBlack(App->congratsscreen, App->welcomescreen,1);
	}
	return UPDATE_CONTINUE;
}