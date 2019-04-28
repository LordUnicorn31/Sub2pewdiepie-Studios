#define _CRTDBG_MAP_ALLOC
#include "Globals.h"
#include "Application.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleSceneRyu.h"
#include "ModulePlayer.h"
#include "ModuleFadeToBlack.h"
#include "ModuleCongratsScreen.h"
#include "ModuleAudio.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA


ModuleSceneRyu::ModuleSceneRyu()
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
	
	//ui bars		//V
	uibg.x = 0;		//V
	uibg.y = 0;		//V
	uibg.w = 194;	//V
	uibg.h = 14;	//V
	uip1.x = 1;		//V
	uip1.y = 15;	//V
	uip1.w = 88;	//V
	uip1.h = 8;		//V
	uip2.x = 1;		//V
	uip2.y = 15;	//V
	uip2.w = 88;	//V
	uip2.h = 8;		//V
}

ModuleSceneRyu::~ModuleSceneRyu()
{}

// Load assets
bool ModuleSceneRyu::Start()
{
	LOG("Loading Ryu scene");

	
	uitext = App->textures->Load("media_files/HPBAR.png"); //V
	graphics = App->textures->Load("media_files/scene_ryu.png");
	music = App->audio->Load("media_files/05 Ryu.ogg");
	App->audio->Play(music, -1);
	App->player->Enable();
	App->player2->Enable();
	return true;
}

// UnLoad assets
bool ModuleSceneRyu::CleanUp()
{
	LOG("Unloading Ryu scene");
	App->textures->Unload(graphics);
	App->textures->Unload(uitext); //V
	App->player->Disable();
	App->player2->Disable();
	App->audio->Unload(music);
	return true;
}

// Update: draw background
update_status ModuleSceneRyu::Update()
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
	App->render->Blit(graphics, 0, 0, &sky,0.75);
	App->render->Blit(graphics, 290, 39, &castle,0.92f);
	App->render->Blit(graphics, 0, 0, &background, 0.92f);
	App->render->Blit(graphics, 0, 176, &ground);
	App->render->Blit(uitext, 100, 0, &uibg); //V
	App->render->Blit(uitext, 101 + (88 - uip1.w), 3, &uip1); //V
	App->render->Blit(uitext, 205, 3, &uip2); //V

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
