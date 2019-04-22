#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "SDL/include/SDL.h"
#pragma comment( lib, "SDL/libx86/SDL2.lib" )
#pragma comment( lib, "SDL/libx86/SDL2main.lib" )

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModulePlayer::ModulePlayer()
{
	graphics = NULL;
	current_animation = NULL;

	position.x = 100;
	position.y = 130;

	// idle animation (just the ship)
	idle.PushBack({ 7, 14, 60, 90 });
	idle.PushBack({ 95, 15, 60, 89 });
	idle.PushBack({ 184, 14, 60, 90 });
	idle.PushBack({ 276, 11, 60, 93 });
	idle.PushBack({ 366, 12, 60, 92 });
	idle.speed = 0.2f;

	//backwards animation
	backward.PushBack({ 532,128,74,90 });
	backward.PushBack({ 612,128,74,90 });
	backward.PushBack({ 695,128,74,90 });
	backward.PushBack({ 870,128,74,90 });
	backward.PushBack({ 955,128,74,90 });
	backward.speed = 0.1f;

	//foward aplication
	forward.PushBack({ 78, 131, 60, 88 });
	forward.PushBack({ 162, 128, 64, 92 });
	forward.PushBack({ 259, 128, 63, 90 });
	forward.PushBack({ 352, 128, 54, 91 });
	forward.PushBack({ 432, 131, 50, 89 });
	forward.speed = 0.1f;

	//jump
	jump_floor.PushBack({16,846,51,86});
	jump_floor.PushBack({104,822,53,105});
	jump_air.PushBack({176,804,49,90});
	jump_air.PushBack({ 250,797,55,78 });
	jump_air.PushBack({326,812,49,88});
	jump_fall.PushBack({396,812,50,88});
	jump_fall.PushBack({463,819,57,109});
	jump_floor.speed = 0.1f;
	jump_air.speed = 0.1f;
	jump_fall.speed = 0.1f;

	//short punch
	short_punch.PushBack({ 14,270,85,93 });
	short_punch.PushBack({ 107,270,110,93 });
	short_punch.speed = 0.1f;

	//kick
	kick.PushBack({605,268,62,95});
	kick.PushBack({687,266,68,93});
	kick.PushBack({775,266,117,93});
	kick.speed = 0.1f;

	//large kick
	large_kick.PushBack({15,397,62,91});
	large_kick.PushBack({98,393,96,95});
	large_kick.PushBack({210,393,122,95});
	large_kick.PushBack({350,410,104,78});
	large_kick.PushBack({480,406,67,83});
	large_kick.speed = 0.1f;

	//hadouken
	hadouken.PushBack({36,1544,72,92});
	hadouken.PushBack({137,1550,82,84});
	hadouken.PushBack({243,1552,92,83});
	hadouken.PushBack({356,1557,108,79});
	hadouken.speed = 0.1f;

	a = true;
	b = true;
	aaa = false;
	bbb = false;
	ccc = false;
	ddd = false;
	eee = false;
	fff = false;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	start_time = SDL_GetTicks();
	LOG("Loading player");
	graphics = App->textures->Load("ryu.png");

	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);

	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	int speed = 1;
	current_time = (SDL_GetTicks()) - start_time;
	//if statement to negate the foward and backward movement while doing other animations
	if (a) {
		if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
		{
			if (current_animation != &backward) {
				backward.Reset();
				current_animation = &backward;
			}
			position.x -= speed;
		}
		else if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
		{
			if (current_animation != &forward) {
				forward.Reset();
				current_animation = &forward;
			}
			position.x += speed;
		}
		else {
			current_animation = &idle;
		}
	}
	if (b) {
		if (App->input->keyboard[SDL_SCANCODE_B] == KEY_STATE::KEY_DOWN) {
			aaa = true;
			a = false;
			b = false;
			final_time = current_time + 750;
			hadouken.Reset();
		}
		else if (App->input->keyboard[SDL_SCANCODE_J] == KEY_STATE::KEY_DOWN) {
			bbb = true;
			a = false;
			b = false;
			final_time = current_time + 380;
			short_punch.Reset();
		}
		else if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_DOWN) {
			ccc = true;
			a = false;
			b = false;
			final_time = current_time + 371;
			start_jump = current_time;
			jump_floor.Reset();
			jump_fall.Reset();
			jump_air.Reset();
		}
		else if (App->input->keyboard[SDL_SCANCODE_N] == KEY_STATE::KEY_DOWN) {
			fff = true;
			a = false;
			b = false;
			final_time = current_time + 561;
			kick.Reset();
		}
		else if (App->input->keyboard[SDL_SCANCODE_M] == KEY_STATE::KEY_DOWN) {
			ggg = true;
			a = false;
			b = false;
			final_time = current_time + 930;
			large_kick.Reset();
		}
		else {
			if (current_animation != &backward&&current_animation != &forward) {
				current_animation = &idle;
			}
		}
	}

	//hadouken
	if (aaa) {
		if (current_time < final_time) {
			if (current_animation != &hadouken) {
				current_animation = &hadouken;
			}
		}
		else {
			App->particles->AddParticle(App->particles->hadouken, position.x + 24, position.y + 15, 0);
			current_animation = &idle;
			aaa = false;
			a = true;
			b = true;
		}
	}

	//short punch
	if (bbb) {
		if (current_time < final_time) {
			if (current_animation != &short_punch) {
				current_animation = &short_punch;
			}
		}
		else {
			current_animation = &idle;
			bbb = false;
			a = true;
			b = true;
		}
	}
	//jump
	if (ccc) {
		if (current_time < final_time) {
			if (current_animation != &jump_floor) {
				current_animation = &jump_floor;
			}
		}
		else {
			current_animation = &jump_air;
			ccc = false;
			ddd = true;
			final_time = current_time + 557;
		}
	}
	if (ddd) {
		if (current_time < final_time) {
			if (current_animation != &jump_air) {
				current_animation = &jump_air;
			}
			position.y -= 2*speed;
		}
		else {
			final_time = current_time + 372;
			current_animation = &jump_fall;
			ddd = false;
			eee = true;
		}

	}
	if (eee) {
		if (current_time < final_time) {
			if (current_animation != &jump_floor) {
				current_animation = &jump_floor;
			}
			position.y += 2*speed;
		}
		else {
			eee = false;
			a = true;
			b = true;
			current_animation = &idle;
			position.y = 130;
		}
	}
	//end jump

	//kick
	if (fff) {
		if (current_time < final_time) {
			if (current_animation != &kick) {
				current_animation = &kick;
			}
		}
		else {
			current_animation = &idle;
			fff = false;
			a = true;
			b = true;
		}
	}
	//large kick
	if (ggg) {
		if (current_time < final_time) {
			if (current_animation != &large_kick) {
				current_animation = &large_kick;
			}
		}
		else {
			current_animation = &idle;
			ggg = false;
			a = true;
			b = true;
		}
	}
	// Draw everything --------------------------------------

	App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));

	return UPDATE_CONTINUE;
}