#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "Globals.h"
#include "Application.h"
#include "ModuleSceneKen.h"
#include "ModuleWelcomeScreen.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "Module.h"
#include "Application.h"
#include "ModuleFadeToBlack.h"
#include "ModuleInput.h"
// Reference at https://youtu.be/6OlenbCC4WI?t=382

ModuleWelcomeScreen::ModuleWelcomeScreen()
{
	background = { 120, 128, 671, 300 };
}

ModuleWelcomeScreen::~ModuleWelcomeScreen()
{}

// Load assets
bool ModuleWelcomeScreen::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("honda_stage3.png");
	return ret;
}

// Load assets
bool ModuleWelcomeScreen::CleanUp()
{
	// TODO 5: Remove all memory leaks
	LOG("Unloading honda stage");
	App->textures->Unload(graphics);
	return true;
}

// Update: draw background
update_status ModuleWelcomeScreen::Update()
{
	App->render->Blit(graphics, -150, -45, &background, 0.75f); // back of the room
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1)
	{
		App->fade->FadeToBlack(App->welcomescreen, App->scene_ken,1);
	}
	return UPDATE_CONTINUE;
}