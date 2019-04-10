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
	forward.PushBack({9, 136, 53, 83});
	forward.PushBack({78, 131, 60, 88});
	forward.PushBack({162, 128, 64, 92});
	forward.PushBack({259, 128, 63, 90});
	forward.PushBack({352, 128, 54, 91});
	forward.PushBack({432, 131, 50, 89});
	forward.speed = 0.2f;

	backward.PushBack({542, 131, 60, 86});
	backward.PushBack({628, 129, 58, 89});
	backward.PushBack({713, 128, 56, 89});
	backward.PushBack({797, 127, 57, 89});
	backward.PushBack({883, 128, 57, 90});
	backward.PushBack({974, 129, 56, 88});
	backward.speed = 0.2f;

	turning.PushBack({480, 9, 53, 94});
	turning.PushBack({553, 7, 57, 96});
	turning.PushBack({ 629, 11, 55, 93});
	turning.speed = 0.1f;
	turning.loop = false;

	jump.PushBack({17,  847, 71-17,   931-847});
	jump.PushBack({100, 823, 155-100, 926-823});
	jump.PushBack({176, 805, 225-176, 893-805});
	jump.PushBack({251, 798, 304-251, 874-798});
	jump.PushBack({327, 813, 374-327, 882-813});
	jump.PushBack({397, 810, 444-397, 898-810});
	jump.PushBack({464, 819, 518-464, 927-819});
	jump.speed = 0.2f;

	jump_frontflip.PushBack({594, 823, 648-594,  925-823});
	jump_frontflip.PushBack({669, 813, 729-669,  890-813});
	jump_frontflip.PushBack({744, 811, 847-744,  852-811});
	jump_frontflip.PushBack({864, 791, 916-864,  872-791});
	jump_frontflip.PushBack({927, 808, 1048-927, 851-808});
	jump_frontflip.PushBack({1064,806, 1134-1064,892-806});
	jump_frontflip.PushBack({1149,802, 1203-1149,910-802});
	jump_frontflip.speed = 0.2f;

	lowpunch.PushBack({19, 272, 63, 90});
	lowpunch.PushBack({108, 272, 91, 90});
	lowpunch.speed = 0.2f;

	midhigh_punch.PushBack({253, 269, 312-253, 362-269}); //millor fer servir aquesta nomenclatura de posar pixels {x, y, xfinal-xinicial, yfinal-yinicial}
	midhigh_punch.PushBack({333, 268, 406-333, 362-268});
	midhigh_punch.PushBack({432, 268, 539-432, 361-268});
	midhigh_punch.PushBack({333, 268, 406-333, 362-268});
	midhigh_punch.PushBack({253, 269, 312-253, 362-269});
	midhigh_punch.speed = 0.2f;

	low_close_punch.PushBack({18,  519, 77-18,   612-519});
	low_close_punch.PushBack({101, 515, 166-101, 612-515});
	low_close_punch.speed = 0.2f;

	high_close_punch.PushBack({759, 519, 824-759, 611-519});
	high_close_punch.PushBack({848, 518, 936-848, 611-518});
	high_close_punch.PushBack({950, 500, 1031-950,612-500});
	high_close_punch.PushBack({848, 518, 936-848, 611-518});
	high_close_punch.PushBack({759, 519, 824-759, 611-519});
	high_close_punch.speed = 0.2f;

	lowmid_kick.PushBack({606, 269, 665-606, 362-269});
	lowmid_kick.PushBack({689, 267, 754-689, 358-267});
	lowmid_kick.PushBack({777, 265, 890-777, 358-265});
	lowmid_kick.PushBack({689, 267, 754-689, 358-267});
	lowmid_kick.PushBack({606, 269, 665-606, 362-269});
	lowmid_kick.speed = 0.2f;

	high_kick.PushBack({16,  398, 76-16,   487-398});
	high_kick.PushBack({99,  394, 192-99,  487-394});
	high_kick.PushBack({211, 394, 330-211, 487-394});
	high_kick.PushBack({351, 411, 451-351, 487-411});
	high_kick.PushBack({482, 407, 545-482, 487-407});
	high_kick.speed = 0.2f;

	low_close_kick.PushBack({ 12, 657, 71-12,  750-657});
	low_close_kick.PushBack({ 95, 657, 142-95, 750-657});
	low_close_kick.PushBack({ 167,658, 246-167,750-658});
	low_close_kick.PushBack({ 95, 657, 142-95, 750-657});
	low_close_kick.PushBack({ 12, 657, 71-12,  750-657});
	low_close_kick.speed = 0.2f;

	high_close_kick.PushBack({637, 657, 696-637, 750-657});
	high_close_kick.PushBack({720, 657, 773-720, 750-657});
	high_close_kick.PushBack({797, 629, 845-797, 750-629});
	high_close_kick.PushBack({875, 640, 967-875, 750-640});
	high_close_kick.PushBack({989, 657, 1036-989,750-657});
	high_close_kick.speed = 0.15f;

	low_jump_punch.PushBack({29, 987, 80-29,  1055-987});
	low_jump_punch.PushBack({97, 985, 177-97, 1055-985});
	low_jump_punch.speed = 0.2f;

	high_jump_punch.PushBack({235, 987, 286-235, 1055-987});
	high_jump_punch.PushBack({307, 979, 375-307, 1055-979});
	high_jump_punch.PushBack({395, 992, 482-395, 1055-992});
	high_jump_punch.PushBack({307, 979, 375-307, 1055-979});
	high_jump_punch.PushBack({235, 987, 286-235, 1055-987});
	high_jump_punch.speed = 0.2f;

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
	current_animation = &high_jump_punch;
	playerRotation(nullptr);
	int speed = 1;

	if (App->input->keyboard[SDL_SCANCODE_D] == 1)
	{
		current_animation = &forward;
		position.x += speed;
	}
	if (App->input->keyboard[SDL_SCANCODE_A] == 1)
	{
		current_animation = &backward;
		position.x -= speed;
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