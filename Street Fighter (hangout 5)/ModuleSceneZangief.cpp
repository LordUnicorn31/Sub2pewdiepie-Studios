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
	// background
	background.x = 0;
	background.y = 269;
	background.w = 643;
	background.h = 389;//389

	ground.x = 356;
	ground.y = 195;
	ground.w = 1065-356;
	ground.h = 242-195;//389

	background2.x = 654;
	background2.y = 269;
	background2.w = 1181-654;
	background2.h = 653-269;//389

	valla.x = 0;
	valla.y = 170;
	valla.w = 347;
	valla.h = 265-170;

	dudes.PushBack({ 0,0,106,54 });
	dudes.PushBack({ 0,57,106,54 });
	dudes.PushBack({ 0,114,106,54 });
	dudes.speed = 0.08f;

	dudes2.PushBack({ 121,0,128,87 });
	dudes2.PushBack({ 264,0,128,87 });
	dudes2.PushBack({ 408,0,128,87 });
	dudes2.speed = 0.08f;

	extinctor.x = 552;
	extinctor.y = 54;
	extinctor.w = 566-552;
	extinctor.h = 87-54;
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
	App->render->Blit(graphics, -40, -206, &background2, 0.75);
	App->render->Blit(graphics, -140, 176, &ground, 0.75);
	App->render->Blit(graphics, -140, -206, &background, 0.75);
	App->render->Blit(graphics, -76, 9.5, &(dudes.GetCurrentFrame()), 0.75);
	App->render->Blit(graphics, -90, 78, &(dudes2.GetCurrentFrame()), 0.75);
	App->render->Blit(graphics, 229, 146, &extinctor, 0.75);
	App->render->Blit(graphics, -171, 130, &valla, 0.75);


	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN) {
		App->fade->FadeToBlack(App->scene_Zangief, App->congratsscreen, 1);
	}
	return UPDATE_CONTINUE;
}
