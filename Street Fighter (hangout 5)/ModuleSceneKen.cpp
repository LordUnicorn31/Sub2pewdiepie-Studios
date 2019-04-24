#define _CRTDBG_MAP_ALLOC
#include "Globals.h"
#include "Application.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleSceneKen.h"
#include "ModuleSceneHonda.h"
#include "ModulePlayer.h"
#include "ModuleFadeToBlack.h"
// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleSceneKen::ModuleSceneKen()
{
	// ground
	ground.x = 0;
	ground.y = 400;
	ground.w = 622;
	ground.h = 48;

	// Background / sky
	sky.x = 0;
	sky.y = 0;
	sky.w = 622;
	sky.h = 113;

	//background
	background.x = 0;
	background.y = 184;
	background.w = 622;
	background.h = 193;


	// for moving the foreground
	foreground_pos = 0;
	forward = true;
}

ModuleSceneKen::~ModuleSceneKen()
{}

// Load assets
bool ModuleSceneKen::Start()
{
	LOG("Loading ken scene");

	graphics = App->textures->Load("scene_ryu.png");

	// TODO 1: Enable (and properly disable) the player module
	if (ModuleSceneKen::IsEnabled() == true) {
		App->scene_ken->Enable();
		App->player->Enable();
		App->player2->Enable();
	}
	else {
		App->player->Disable();
		App->player2->Disable();
	}
	return true;
}

// UnLoad assets
bool ModuleSceneKen::CleanUp()
{
	LOG("Unloading ken scene");

	return true;
}

// Update: draw background
update_status ModuleSceneKen::Update()
{
	// Calculate boat Y position -----------------------------
	if (foreground_pos < -6.0f)
		forward = false;
	else if (foreground_pos > 0.0f)
		forward = true;

	if (forward)
		foreground_pos -= 0.02f;
	else
		foreground_pos += 0.02f;

	// Draw everything --------------------------------------
	App->render->Blit(graphics, 0, 0, &sky, 0.75f);
	App->render->Blit(graphics, 0, 0, &background, 0.75f); // sea and sky
	App->render->Blit(graphics, 0, 170, &ground);

	// TODO 2: make so pressing SPACE the HONDA stage is loaded
	/*if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1)
	{
		if (App->scene_ken->IsEnabled() == true)
			App->fade->FadeToBlack(App->scene_ken, App->scene_honda);

	}*/
	if (App->player->position.x > 300)
		App->fade->FadeToBlack(App->scene_ken, App->scene_honda);
	return UPDATE_CONTINUE;
}