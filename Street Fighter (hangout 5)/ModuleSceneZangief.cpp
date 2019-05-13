#define _CRTDBG_MAP_ALLOC
#include "Globals.h"
#include "Application.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleSceneZangief.h"
#include "ModuleSceneRyu.h"
#include "ModulePlayer.h"
#include "ModuleFadeToBlack.h"
#include "ModuleCongratsScreen.h"
#include "ModuleAudio.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA


ModuleSceneZangief::ModuleSceneZangief()
{
	// ground
	ground.x = 0;
	ground.y = 400;
	ground.w = 622;
	ground.h = 48;
}

ModuleSceneZangief::~ModuleSceneZangief()
{}

// Load assets
bool ModuleSceneZangief::Start()
{
	LOG("Loading Zangief scene");


	uitext = App->textures->Load("media_files/HPBAR.png"); //V
	graphics = App->textures->Load("media_files/bg_zangief_sprite.png");
	App->player->Enable();
	App->player2->Enable();
	return true;
}

// UnLoad assets
bool ModuleSceneZangief::CleanUp()
{
	LOG("Unloading Ryu scene");
	App->textures->Unload(graphics);
	App->textures->Unload(uitext); //V
	App->player->Disable();
	App->player2->Disable();
	return true;
}

// Update: draw background
update_status ModuleSceneZangief::Update()
{

	//HP update mechanic
	if (prevHP1 > App->player->life)
	{
		prevHP1--;
	}
	else if (prevHP1 < App->player->life)
	{
		prevHP1++;
	}
	uip1.w = (prevHP1 * 0.88); // V
	if (prevHP2 > App->player2->life)
	{
		prevHP2--;
	}
	else if (prevHP2 < App->player2->life)
	{
		prevHP2++;
	}
	uip2.w = (prevHP2 * 0.88); // V
	// Draw everything --------------------------------------
	//App->render->Blit(graphics, 0, 0, &sky, 0.75);


	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN) {
		App->player2->life = 0;
		/*App->fade->FadeToBlack(App->scene_Ryu, App->congratsscreen,1);
		if (App->player->position.x > 300)
			App->fade->FadeToBlack(App->scene_Ryu, App->congratsscreen,1);*/
	}
	if (App->input->keyboard[SDL_SCANCODE_RETURN] == KEY_STATE::KEY_DOWN) {
		App->player->life = 0;
	}
	return UPDATE_CONTINUE;
}
