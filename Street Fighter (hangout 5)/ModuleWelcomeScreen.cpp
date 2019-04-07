#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "Globals.h"
#include "Application.h"
#include "ModuleSceneHonda.h"
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
	// ground
	//ground = { 8, 376, 848, 64 };

	// roof
	//roof = { 91, 7, 765, 49 };

	// foreground
	//foreground = { 164, 66, 336, 51 };

	// Background / sky
	background = { 120, 128, 671, 300 };

	// flag animation
	/*water.PushBack({ 8, 447, 283, 9 });
	water.PushBack({ 296, 447, 283, 12 });
	water.PushBack({ 588, 447, 283, 18 });
	water.speed = 0.02f;*/
}

ModuleWelcomeScreen::~ModuleWelcomeScreen()
{}

// Load assets
bool ModuleWelcomeScreen::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("honda_stage3.png");

	// TODO 1: Enable (and properly disable) the player module
	App->welcomescreen->Enable();
	return ret;
}

// Load assets
bool ModuleWelcomeScreen::CleanUp()
{
	// TODO 5: Remove all memory leaks
	LOG("Unloading honda stage");
	_CrtDumpMemoryLeaks();
	return true;
}

// Update: draw background
update_status ModuleWelcomeScreen::Update()
{
	// Draw everything --------------------------------------	
	//App->render->Blit(graphics, 0, 160, &ground);
	App->render->Blit(graphics, -150, -45, &background, 0.75f); // back of the room

	//App->render->Blit(graphics, 280, 125, &foreground);
	//App->render->Blit(graphics, 305, 136, &(water.GetCurrentFrame())); // water animation
	//App->render->Blit(graphics, 0, -16, &roof, 0.75f);

	// TODO 2: make so pressing SPACE the KEN stage is loaded
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1)
	{
		App->fade->FadeToBlack(App->welcomescreen, App->scene_ken);
	}
	return UPDATE_CONTINUE;
}