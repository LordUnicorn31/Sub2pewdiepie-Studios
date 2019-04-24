#define _CRTDBG_MAP_ALLOC
#include "Globals.h"
#include "Application.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleSceneKen.h"
#include "ModulePlayer.h"
#include "ModuleFadeToBlack.h"
#include "ModuleCongratsScreen.h"
#include "ModuleAudio.h"

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

	//castle
	castle.x = 744;
	castle.y = 215;
	castle.w = 138;
	castle.h = 73;
}

ModuleSceneKen::~ModuleSceneKen()
{}

// Load assets
bool ModuleSceneKen::Start()
{
	LOG("Loading ken scene");

	graphics = App->textures->Load("scene_ryu.png");
	music = App->audio->Load("05 Ryu.ogg");
	App->audio->Play(music, -1);
	App->player->Enable();
	App->player2->Enable();
	return true;
}

// UnLoad assets
bool ModuleSceneKen::CleanUp()
{
	LOG("Unloading ken scene");
	App->textures->Unload(graphics);
	App->player->Disable();
	App->player2->Disable();
	App->audio->Unload(music);
	return true;
}

// Update: draw background
update_status ModuleSceneKen::Update()
{
	// Draw everything --------------------------------------
	App->render->Blit(graphics, 0, 0, &sky, 0.75f);
	App->render->Blit(graphics, 290, 39, &castle,0.1f);
	App->render->Blit(graphics, 0, 0, &background, 0.75f);
	App->render->Blit(graphics, 0, 176, &ground);


	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1) {
		App->fade->FadeToBlack(App->scene_ken, App->congratsscreen,1);
		if (App->player->position.x > 300)
			App->fade->FadeToBlack(App->scene_ken, App->congratsscreen,1);
	}
	return UPDATE_CONTINUE;
}