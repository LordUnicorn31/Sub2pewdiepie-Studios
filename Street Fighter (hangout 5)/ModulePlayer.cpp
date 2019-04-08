#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneHonda.h"
#include "ModuleSceneKen.h"
#include "ModuleParticles.h"
// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModulePlayer::ModulePlayer()
{
	position.x = 100;
	position.y = 220;

	// idle animation (arcade sprite sheet)
	idle.PushBack({7, 14, 60, 90});
	idle.PushBack({95, 15, 60, 89});
	idle.PushBack({184, 14, 60, 90});
	idle.PushBack({276, 11, 60, 93});
	idle.PushBack({366, 12, 60, 92});
	idle.speed = 0.2f;

	// walk forward animation (arcade sprite sheet)
	//forward.frames.PushBack({9, 136, 53, 83});
	forward.PushBack({78, 131, 60, 88});
	forward.PushBack({162, 128, 64, 92});
	forward.PushBack({259, 128, 63, 90});
	forward.PushBack({352, 128, 54, 91});
	forward.PushBack({432, 131, 50, 89});
	forward.speed = 0.1f;

	turning.PushBack({480, 9, 53, 94});
	turning.PushBack({553, 7, 57, 96});
	turning.PushBack({ 629, 11, 55, 93});
	turning.speed = 0.1f;
	turning.loop = false;

	/*
	turningright.PushBack({ 480, 9, 53, 94 });
	turningright.PushBack({ 553, 7, 57, 96 });
	turningright.PushBack({ 629, 11, 55, 93 });
	turningright.speed = 0.1f;
	*/
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("ryu.png"); // arcade version
	lookingright = false;
	return ret;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	//turning.Reset();
	current_animation = &idle;
	playerRotation(nullptr);
	int speed = 1;

	if(App->input->keyboard[SDL_SCANCODE_D] == 1)
	{
		current_animation = &forward;
		position.x += speed;
	}

	if (App->player->position.x < App->input->mPosX && lookingright == false) { //TURN LEFT TO RIGHT
		
		current_animation = &turning;
		if (current_animation->Finished() == true) 
		{
			//turning.speed = 0.1f;
			lookingright = true;
			turning.Reset();
		}
			

	}
	else if (App->player->position.x > App->input->mPosX && lookingright == true) { //TURN RIGHT TO LEFT
		
		current_animation = &turning;
		if (current_animation->Finished() == true) 
		{
			//turning.speed = 0.1f;
			lookingright = false;
			turning.Reset();
		}
			
	}

	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();
	if (App->player->lookingright == false)
		App->render->Blit(graphics, position.x, position.y - r.h, &r, 1.0f, true);
	else
		App->render->Blit(graphics, position.x, position.y - r.h, &r, 1.0f, false);

	
	return UPDATE_CONTINUE;
}