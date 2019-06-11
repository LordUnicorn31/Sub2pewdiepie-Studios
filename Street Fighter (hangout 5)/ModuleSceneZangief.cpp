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
#include "SDL/include/SDL.h"
#include "ModuleUi.h"

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

	palanca.x=1185;
	palanca.y=206;
	palanca.w = 1298-1185;
	palanca.h = 644-206;
}

ModuleSceneZangief::~ModuleSceneZangief()
{}

// Load assets
bool ModuleSceneZangief::Start()
{
	LOG("Loading Zangief scene");

	zangief_init_time = SDL_GetTicks();
	time_index = 98;
	App->ui->second = 0;
	App->ui->seconds_end_round = 0;
	if(App->ui->round_index<50)App->ui->round_index++;
	App->ui->current_round++;
	App->ui->fighting = true;
	App->ui->rounding = true;
	App->ui->out_time = true;


	graphics = App->textures->Load("media_files/bg_zangief_sprite.png");
	music = App->audio->Load("media_files/zangief.ogg");
	App->audio->Play(music, -1);
	App->player->Enable();
	App->player2->Enable();
	
	return true;
}

// UnLoad assets
bool ModuleSceneZangief::CleanUp()
{
	LOG("Unloading Ryu scene");
	App->textures->Unload(graphics);
	App->player->Disable();
	App->player2->Disable();
	App->audio->Unload(music);
	return true;
}

// Update: draw background
update_status ModuleSceneZangief::Update()
{

	// Draw everything --------------------------------------
	App->render->Blit(graphics, -40, -206, &background2, 0.70);
	App->render->Blit(graphics, -140, 176, &ground,0.8);
	App->render->Blit(graphics, -140, -206, &background, 0.80);
	App->render->Blit(graphics, -76, 9.5, &(dudes.GetCurrentFrame()), 0.80);
	App->render->Blit(graphics, -90, 78, &(dudes2.GetCurrentFrame()), 0.80);
	App->render->Blit(graphics, 229, 146, &extinctor, 0.80);
	App->render->Blit(graphics, 369, -220, &palanca, 0.8);
	//App->render->Blit(graphics, -171, 130, &valla, 1.3);


	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN) {
		App->ui->round_index = -1;
		App->ui->current_round = 0;
		App->fade->FadeToBlack(App->scene_Zangief, App->congratsscreen, 1);
	}
	return UPDATE_CONTINUE;
}
