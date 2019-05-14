#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneRyu.h"
#include "ModuleCongratsScreen.h"
#include "ModuleParticles.h"
#include "ModuleCollision.h"
#include "ModuleAudio.h"
// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA



ModulePlayer::ModulePlayer(int playername) //parameter that takes enum playernames (0 = ryu, 1 = zangief). In Application.cpp (or whenever you create a new moduleplayer) you have to specify the character (for instance playernames::RYU). Depending in the character the constructor will vary
{
	
	//1 = Ryu
	//2 = Zangief

	switch (playername)
	{
		
	case RYU: 
		{
		//animations //missing crouch animation
#pragma region ryuanimations


#pragma region idle
		// idle animation (arcade sprite sheet)
		idle.PushBack({ 7, 14, 60, 90 });
		idle.PushBack({ 95, 15, 60, 89 });
		idle.PushBack({ 184, 14, 60, 90 });
		idle.PushBack({ 276, 11, 60, 93 });
		idle.PushBack({ 366, 12, 60, 92 });
		idle.speed = 0.1f;
#pragma endregion				//used

#pragma region forward

		// walk forward animation (arcade sprite sheet)
		forward.PushBack({ 9, 136, 53, 83 });
		forward.PushBack({ 78, 131, 60, 88 });
		forward.PushBack({ 162, 128, 64, 92 });
		forward.PushBack({ 259, 128, 63, 90 });
		forward.PushBack({ 352, 128, 54, 91 });
		forward.PushBack({ 432, 131, 50, 89 });
		forward.speed = 0.1f;

#pragma endregion				//used

#pragma region backward

		backward.PushBack({ 542, 131, 60, 86 });
		backward.PushBack({ 628, 129, 58, 89 });
		backward.PushBack({ 713, 128, 56, 89 });
		backward.PushBack({ 797, 127, 57, 89 });
		backward.PushBack({ 883, 128, 57, 90 });
		backward.PushBack({ 974, 129, 56, 88 });
		backward.speed = 0.1f;

#pragma endregion			//used

#pragma region turning

		turning.PushBack({ 480, 9, 53, 94 });
		turning.PushBack({ 553, 7, 57, 96 });
		turning.PushBack({ 629, 11, 55, 93 });
		turning.speed = 0.1f;
		turning.loop = false;

#pragma endregion				//not used

#pragma region jumpneutral

		jump.PushBack({ 464, 819, 518 - 464, 927 - 819 });
		//jump.PushBack({17,  847, 71-17,   931-847});
		//jump.PushBack({100, 823, 155-100, 926-823});
		//jump.PushBack({176, 805, 225-176, 893-805});
		jump.PushBack({ 251, 798, 304 - 251, 874 - 798 });
		jump.PushBack({ 251, 798, 304 - 251, 874 - 798 });
		//jump.PushBack({327, 813, 374-327, 882-813});
		//jump.PushBack({397, 810, 444-397, 898-810});
		jump.PushBack({ 464, 819, 518 - 464, 927 - 819 });
		jump.speed = 0.05f;
		jump.loop = false;

#pragma endregion			//used

#pragma region jumpfrontflip
		jump_frontflip.PushBack({ 594, 823, 648 - 594,  925 - 823 });
		jump_frontflip.PushBack({ 669, 813, 729 - 669,  890 - 813 });
		jump_frontflip.PushBack({ 744, 811, 847 - 744,  852 - 811 });
		jump_frontflip.PushBack({ 864, 791, 916 - 864,  872 - 791 });
		jump_frontflip.PushBack({ 927, 808, 1048 - 927, 851 - 808 });
		jump_frontflip.PushBack({ 1064,806, 1134 - 1064,892 - 806 });
		jump_frontflip.PushBack({ 1149,802, 1203 - 1149,910 - 802 });
		jump_frontflip.speed = 0.1f;

#pragma endregion		//not used

#pragma region low punch

		low_punch.PushBack({ 19, 272, 63, 90 });
		low_punch.PushBack({ 108, 272, 91, 90 });
		low_punch.speed = 0.1f;

#pragma endregion			//used

#pragma region mid punch

		mid_punch.PushBack({ 253, 269, 312 - 253, 362 - 269 }); //millor fer servir aquesta nomenclatura de posar pixels {x, y, xfinal-xinicial, yfinal-yinicial}
		mid_punch.PushBack({ 333, 268, 406 - 333, 362 - 268 });
		mid_punch.PushBack({ 432, 268, 539 - 432, 361 - 268 });
		mid_punch.PushBack({ 333, 268, 406 - 333, 362 - 268 });
		mid_punch.PushBack({ 253, 269, 312 - 253, 362 - 269 });
		mid_punch.speed = 0.1f;

#pragma endregion		//not used

#pragma region high punch

		high_punch.PushBack({ 253, 269, 312 - 253, 362 - 269 }); //millor fer servir aquesta nomenclatura de posar pixels {x, y, xfinal-xinicial, yfinal-yinicial}
		high_punch.PushBack({ 333, 268, 406 - 333, 362 - 268 });
		high_punch.PushBack({ 432, 268, 539 - 432, 361 - 268 });
		high_punch.PushBack({ 333, 268, 406 - 333, 362 - 268 });
		high_punch.PushBack({ 253, 269, 312 - 253, 362 - 269 });
		high_punch.speed = 0.1f;

#pragma endregion

#pragma region low close punch

		low_close_punch.PushBack({ 18,  519, 77 - 18,   612 - 519 });
		low_close_punch.PushBack({ 101, 515, 166 - 101, 612 - 515 });
		low_close_punch.speed = 0.1f;

#pragma endregion		//not used

#pragma region high close punch

		high_close_punch.PushBack({ 759, 519, 824 - 759, 611 - 519 });
		high_close_punch.PushBack({ 848, 518, 936 - 848, 611 - 518 });
		high_close_punch.PushBack({ 950, 500, 1031 - 950,612 - 500 });
		high_close_punch.PushBack({ 848, 518, 936 - 848, 611 - 518 });
		high_close_punch.PushBack({ 759, 519, 824 - 759, 611 - 519 });
		high_close_punch.speed = 0.1f;

#pragma endregion	//not used

#pragma region low kick

		low_kick.PushBack({ 606, 269, 665 - 606, 362 - 269 });
		low_kick.PushBack({ 689, 267, 754 - 689, 358 - 267 });
		low_kick.PushBack({ 777, 265, 890 - 777, 358 - 265 });
		low_kick.PushBack({ 689, 267, 754 - 689, 358 - 267 });
		low_kick.PushBack({ 606, 269, 665 - 606, 362 - 269 });
		low_kick.speed = 0.1f;

#pragma endregion		//not used

#pragma region mid kick

		mid_kick.PushBack({ 606, 269, 665 - 606, 362 - 269 });
		mid_kick.PushBack({ 689, 267, 754 - 689, 358 - 267 });
		mid_kick.PushBack({ 777, 265, 890 - 777, 358 - 265 });
		mid_kick.PushBack({ 689, 267, 754 - 689, 358 - 267 });
		mid_kick.PushBack({ 606, 269, 665 - 606, 362 - 269 });
		mid_kick.speed = 0.1f;

#pragma endregion

#pragma region high kick

		high_kick.PushBack({ 16,  398, 76 - 16,   487 - 398 });
		high_kick.PushBack({ 99,  394, 192 - 99,  487 - 394 });
		high_kick.PushBack({ 211, 394, 330 - 211, 487 - 394 });
		high_kick.PushBack({ 351, 411, 451 - 351, 487 - 411 });
		high_kick.PushBack({ 482, 407, 545 - 482, 487 - 407 });
		high_kick.speed = 0.1f;

#pragma endregion			//not used

#pragma region low close kick

		low_close_kick.PushBack({ 12, 657, 71 - 12,  750 - 657 });
		low_close_kick.PushBack({ 95, 657, 142 - 95, 750 - 657 });
		low_close_kick.PushBack({ 167,658, 246 - 167,750 - 658 });
		low_close_kick.PushBack({ 95, 657, 142 - 95, 750 - 657 });
		low_close_kick.PushBack({ 12, 657, 71 - 12,  750 - 657 });
		low_close_kick.speed = 0.1f;

#pragma endregion		//used

#pragma region high close kick

		high_close_kick.PushBack({ 637, 657, 696 - 637, 750 - 657 });
		high_close_kick.PushBack({ 720, 657, 773 - 720, 750 - 657 });
		high_close_kick.PushBack({ 797, 629, 845 - 797, 750 - 629 });
		high_close_kick.PushBack({ 875, 640, 967 - 875, 750 - 640 });
		high_close_kick.PushBack({ 989, 657, 1036 - 989,750 - 657 });
		high_close_kick.speed = 0.1f;

#pragma endregion		//not used

#pragma region low jumping punch

		low_jump_punch.PushBack({ 29, 987, 80 - 29,  1055 - 987 });
		low_jump_punch.PushBack({ 97, 985, 177 - 97, 1055 - 985 });
		low_jump_punch.speed = 0.1f;

#pragma endregion	//not used

#pragma region high jumping punch

		high_jump_punch.PushBack({ 235, 987, 286 - 235, 1055 - 987 });
		high_jump_punch.PushBack({ 307, 979, 375 - 307, 1055 - 979 });
		high_jump_punch.PushBack({ 395, 992, 482 - 395, 1055 - 992 });
		high_jump_punch.PushBack({ 307, 979, 375 - 307, 1055 - 979 });
		high_jump_punch.PushBack({ 235, 987, 286 - 235, 1055 - 987 });
		high_jump_punch.speed = 0.1f;

#pragma endregion	//not used

#pragma region player hadouken

		playerhadouken.PushBack({ 36,1544,72,92 });
		playerhadouken.PushBack({ 137,1550,82,84 });
		playerhadouken.PushBack({ 243,1552,92,83 });
		playerhadouken.PushBack({ 356,1557,108,79 });
		playerhadouken.speed = 0.08f;

#pragma endregion		//used

#pragma region player hitted

		hitted.PushBack({ 207, 2091, 274 - 207, 2179 - 2091 });
		hitted.speed = 0.1f;

#pragma endregion		//used (incomplete, missing 4 frames)

#pragma endregion

		break;
		}
	case ZANGIEF: 
		{
		//animations
#pragma region zangiefanimations

		idle.PushBack({3, 24, 59-3, 117-24});
		idle.PushBack({70, 22, 129-70, 117-22});
		idle.PushBack({145, 21, 210-145, 117-21});
		idle.PushBack({ 70, 22, 129 - 70, 117 - 22 });
		idle.speed = 0.06f;

		forward.PushBack({226, 22, 285-226, 117-22});
		forward.PushBack({295, 20, 358-295, 117-20});
		forward.PushBack({366, 22, 432-366, 117-22});
		forward.PushBack({445, 20, 508-445, 117-20});
		forward.speed = 0.06f;

		backward.PushBack({ 445, 20, 508 - 445, 117 - 20 });
		backward.PushBack({ 366, 22, 432 - 366, 117 - 22 });
		backward.PushBack({ 295, 20, 358 - 295, 117 - 20 });
		backward.PushBack({ 226, 22, 285 - 226, 117 - 22 });
		backward.speed = 0.06f;

		//the crouch animation doesn't loop, but needs to be reseted when the animation state changes from crouch to another one
		crouch.PushBack({522, 41, 580-522, 117-41});
		crouch.PushBack({591, 48, 647-591, 117-48});
		crouch.loop = false;
		crouch.speed = 0.06f;

		//shadow rect: ({660, 108, 713-660, 117-108})
		jump.PushBack({722, 23, 784-722, 119-23});
		jump.PushBack({801, 30, 873-801, 103-30});
		jump.PushBack({891, 23, 953-891, 119-23});
		jump.speed = 0.04f;
		jump.loop = false;

		low_punch.PushBack({6, 149, 64-6, 243-149});
		low_punch.PushBack({72, 150, 149-72, 243-150});
		low_punch.PushBack({165, 149, 223-165, 243-149});
		low_punch.speed = 0.06f;

#pragma endregion

		break;
		}
		
	}



}

void loadanimations() {

}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	graphicsryu = App->textures->Load("media_files/ryu.png"); // arcade version
	graphicszangief = App->textures->Load("media_files/Zangief_Sprites.png"); //snes version lmao Yeet 
	lowattack = App->audio->Load("media_files/Street Fighter Attack moves\\lowattack.wav");
	midattack = App->audio->Load("media_files/Street Fighter Attack moves\\midattack.wav");
	lowpunchhit = App->audio->Load("media_files/Street Fighter Attack moves\\lowpunchhit.wav");
	lowkickhit = App->audio->Load("media_files/Street Fighter Attack moves\\lowkickhit.wav");
	hadoukenaudio = App->audio->Load("media_files/Hadouken.wav");
	jumpgrounded = App->audio->Load("media_files/jumpgrounded.wav");
	App->player->position.x = 50;
	App->player->position.y = 200;
	App->player2->position.x = 250;
	App->player2->position.y = 200;
	App->player->playercollider = App->collision->AddCollider({ 0, 220, 40, 80}, COLLIDER_PLAYER1, App->player);
	App->player2->playercollider = App->collision->AddCollider({ 100, 220, 40, 80 }, COLLIDER_PLAYER2, App->player2);
	punchpos.x = 0;
	punchpos.y = 220;
	life = 100;
	App->player->pdamagecollider = App->collision->AddCollider({ punchpos.x, punchpos.y, 50, 80 }, COLLIDER_PLAYER1_DAMAGE, App->player);
	App->player2->pdamagecollider = App->collision->AddCollider({ punchpos.x, punchpos.y, 50, 80 }, COLLIDER_PLAYER2_DAMAGE, App->player2);
	lookingright = false;
	godmode = false;

	return ret;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	forwarding = false;
	backwarding = false;
	//App->player->jumpingidle = true;
	//turning.Reset();
	/*if (App->input->keyboard[SDL_SCANCODE_N] == KEY_STATE::KEY_DOWN)
		App->audio->Play(lowattack, 0);*/
	App->player->current_animation = &App->player->idle;
	App->player2->current_animation = &App->player2->idle;
	//current_animation = &high_jump_punch;
	//playerRotation(nullptr);
	float speed = 1.0f;
	if (App->input->keyboard[SDL_SCANCODE_F1] == KEY_STATE::KEY_DOWN) 
		App->player->godmode = true;
	
	if (App->input->keyboard[SDL_SCANCODE_F2] == KEY_STATE::KEY_DOWN)
		App->player->godmode = false;

	if (App->input->keyboard[SDL_SCANCODE_F3] == KEY_STATE::KEY_DOWN)
		App->player2->godmode = true;

	if (App->input->keyboard[SDL_SCANCODE_F4] == KEY_STATE::KEY_DOWN)
		App->player2->godmode = false;

	if (App->player->position.x < App->player2->position.x)
		App->player->lookingright = true;
	else
		App->player->lookingright = false;
	if (App->player2->position.x < App->player->position.x)
		App->player2->lookingright = true;
	else
		App->player2->lookingright = false;

	if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT && App->player->position.x < SCREEN_WIDTH - 60 && !(App->player->jumpingidle || App->player->jumpingright || App->player->jumpingleft || App->player->punching||App->player->kicking || App->player->hadouking2 || App->player->playerhittedcounter < 59))
	{
		if (App->player->position.x < App->player2->position.x) {// App->player->lookingright = true
			App->player->current_animation = &App->player->forward;
			App->player->backwarding = false;
			App->player->forwarding = true;
		}
		else {
			App->player->current_animation = &App->player->backward;
			App->player->backwarding = true;
			App->player->forwarding = false;
		}

		if (App->player->position.x < App->player2->position.x)
			App->player->position.x += speed;
		else
			App->player->position.x += speed / 1.5f;
	}
	if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT && App->player->position.x > 1 && !(App->player->jumpingidle || App->player->jumpingright || App->player->jumpingleft || App->player->punching||App->player->kicking || App->player->hadouking2 || App->player->playerhittedcounter < 59))
	{
		if (App->player->position.x < App->player2->position.x) { // App->player->lookingright = true
			App->player->current_animation = &App->player->backward;
			App->player->backwarding = true;
			App->player->forwarding = false;
		}
		else {
			App->player->current_animation = &App->player->forward;
			App->player->forwarding = true;
			App->player->backwarding = false;
		}
		if (App->player->position.x < App->player2->position.x)
			App->player->position.x -= speed / 1.5f;
		else
			App->player->position.x -= speed;
	}
	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT && App->player2->position.x < SCREEN_WIDTH - 60 && !(App->player2->jumpingidle || App->player2->jumpingright || App->player2->jumpingleft || App->player2->punching || App->player2->kicking || App->player2->hadouking2 || App->player2->playerhittedcounter < 59))
	{
		if (App->player2->position.x < App->player->position.x) {// App->player2->lookingright = true
			App->player2->current_animation = &App->player2->forward;
			App->player2->forwarding = true;
			App->player2->backwarding = false;
		}
		else {
			App->player2->current_animation = &App->player2->backward;
			App->player2->backwarding = true;
			App->player2->forwarding = false;
		}
		if (App->player2->position.x < App->player->position.x)
			App->player2->position.x += speed;
		else
			App->player2->position.x += speed / 1.5f;
	}
	if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT && App->player2->position.x > 1 && !(App->player2->jumpingidle || App->player2->jumpingright || App->player2->jumpingleft || App->player2->punching || App->player2->kicking || App->player2->hadouking2 || App->player2->playerhittedcounter < 59))
	{
		if (App->player2->position.x < App->player->position.x) {// App->player2->lookingright = true
			App->player2->current_animation = &App->player2->backward;
			App->player2->backwarding = true;
			App->player2->forwarding = false;
		}
		else {
			App->player2->current_animation = &App->player2->forward;
			App->player2->forwarding = true;
			App->player2->backwarding = false;
		}
		if (App->player2->position.x < App->player->position.x)
			App->player2->position.x -= speed / 1.5f;
		else
			App->player2->position.x -= speed;
	}
	/*if (App->player->hadoukenable < 101)
	App->player->hadoukenable += 1;
	if (App->input->keyboard[SDL_SCANCODE_1] == KEY_STATE::KEY_DOWN && !(App->player->jumpingidle || App->player->jumpingright || App->player->jumpingleft))
		if (App->player->hadoukenable > 100) {
			if (App->player->lookingright)
			App->particles->AddParticle(App->particles->hadouken, App->player->position.x, App->player->position.y - 90, 0); 
			else {
				App->particles->hadouken.speed.x = -4;
				App->particles->AddParticle(App->particles->hadouken, App->player->position.x, App->player->position.y - 90, 0, true);
				App->particles->hadouken.speed.x = 4;
			}
			App->player->hadoukenable = 0;
		}*/
	
	if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT && !(App->player->jumpingidle || App->player->jumpingright || App->player->jumpingleft || App->player->punching || App->player->kicking || App->player->playerhittedcounter < 59)) {
		//jump.Reset();
		App->player->jumpingidle = true;
		//LOG("uWu");
		App->player->vely = 4.5f;


	}
	if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT && !(App->player2->jumpingidle || App->player2->jumpingright || App->player2->jumpingleft || App->player2->punching || App->player2->kicking || App->player2->playerhittedcounter < 59)) {
		//jump.Reset();
		App->player2->jumpingidle = true;
		//LOG("uWu");
		App->player2->vely = 4.5f;


	}

	if (App->input->keyboard[SDL_SCANCODE_1] == KEY_STATE::KEY_DOWN && !(App->player->jumpingidle || App->player->jumpingright || App->player->jumpingleft||App->player->punching||App->player->kicking || App->player->hadouking2 || App->player->playerhittedcounter < 59/* || App->player->forwarding || App->player->backwarding*/)) {
		App->player->low_punch.Reset();
		App->player->punching = true;
		App->audio->Play(App->player->lowattack, 0);
		App->player->current_animation = &App->player->low_punch;
	}
	if (App->player->punching) {
		if (!App->player->low_punch.Finished()) {
			if (App->player->current_animation != &App->player->low_punch) {
				App->player->current_animation = &App->player->low_punch;
			}
		}
		else {
			App->player->current_animation = &App->player->idle;
			App->player->punching = false;
		}
	}
	if (App->input->keyboard[SDL_SCANCODE_J] == KEY_STATE::KEY_DOWN && !(App->player2->jumpingidle || App->player2->jumpingright || App->player2->jumpingleft || App->player2->punching || App->player2->kicking || App->player2->hadouking2 || App->player2->playerhittedcounter < 59/* || App->player->forwarding || App->player->backwarding*/)) {
		App->player2->low_punch.Reset();
		App->player2->punching = true;
		App->audio->Play(App->player2->lowattack, 0);
		App->player2->current_animation = &App->player2->low_punch;
	}
	if (App->player2->punching) {
		if (!App->player2->low_punch.Finished()) {
			if (App->player2->current_animation != &App->player2->low_punch) {
				App->player2->current_animation = &App->player2->low_punch;
			}
		}
		else {
			App->player2->current_animation = &App->player2->idle;
			App->player2->punching = false;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_2] == KEY_STATE::KEY_DOWN && !(App->player->jumpingidle || App->player->jumpingright || App->player->jumpingleft||App->player->punching||App->player->kicking || App->player->hadouking2 || App->player->playerhittedcounter < 59/* || App->player->forwarding || App->player->backwarding*/)) {
		App->player->low_close_kick.Reset();
		App->player->kicking = true;
		App->audio->Play(App->player->midattack, 0);
		App->player->current_animation = &App->player->low_close_kick;
	}
	if (App->player->kicking) {
		if (!App->player->low_close_kick.Finished()) {
			if (App->player->current_animation != &App->player->low_close_kick) {
				App->player->current_animation = &App->player->low_close_kick;
			}
		}
		else {
			App->player->current_animation = &App->player->idle;
			App->player->kicking = false;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_K] == KEY_STATE::KEY_DOWN && !(App->player2->jumpingidle || App->player2->jumpingright || App->player2->jumpingleft || App->player2->punching || App->player2->kicking||App->player2->hadouking2 || App->player2->playerhittedcounter < 59/* || App->player->forwarding || App->player->backwarding*/)) {
		App->player2->low_close_kick.Reset();
		App->player2->kicking = true;
		App->audio->Play(App->player2->midattack, 0);
		App->player2->current_animation = &App->player2->low_punch;
	}
	if (App->player2->kicking) {
		if (!App->player2->low_close_kick.Finished()) {
			if (App->player2->current_animation != &App->player2->low_close_kick) {
				App->player2->current_animation = &App->player2->low_close_kick;
			}
		}
		else {
			App->player2->current_animation = &App->player2->idle;
			App->player2->kicking = false;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_3] == KEY_STATE::KEY_DOWN && !(App->player->jumpingidle || App->player->jumpingright || App->player->jumpingleft || App->player->punching || App->player->kicking||App->player->hadouking2 || App->player->playerhittedcounter < 59/* || App->player->forwarding || App->player->backwarding*/)) {
		App->player->playerhadouken.Reset();
		App->player->hadouking2 = true;
		App->audio->Play(App->player->hadoukenaudio, 0);
		App->player->current_animation = &App->player->playerhadouken;
	}
	if (App->player->hadouking2) {
		if (!App->player->playerhadouken.Finished()) {
			if (App->player->current_animation != &App->player->playerhadouken) {
				App->player->current_animation = &App->player->playerhadouken;
			}
		}
		else {
			App->player->current_animation = &App->player->idle;
			if (App->player->position.x > App->player2->position.x) {
				App->particles->hadouken.speed.x = -4;
				App->particles->AddParticle(App->particles->hadouken, App->player->position.x, App->player->position.y - 80, COLLIDER_PLAYER1_HADOUKEN, 0, true);
			}
			if (App->player->position.x < App->player2->position.x) {
				App->particles->hadouken.speed.x = 4;
				App->particles->AddParticle(App->particles->hadouken, App->player->position.x+10, App->player->position.y - 80, COLLIDER_PLAYER1_HADOUKEN, 0, false);
			}
			App->player->hadouking2 = false;
		}
	}
	if (App->input->keyboard[SDL_SCANCODE_L] == KEY_STATE::KEY_DOWN && !(App->player2->jumpingidle || App->player2->jumpingright || App->player2->jumpingleft || App->player2->punching || App->player2->kicking || App->player2->hadouking2 || App->player2->playerhittedcounter < 59/* || App->player->forwarding || App->player->backwarding*/)) {
		App->player2->playerhadouken.Reset();
		App->player2->hadouking2 = true;
		App->audio->Play(App->player->hadoukenaudio, 0);
		App->player2->current_animation = &App->player2->playerhadouken;
	}
	if (App->player2->hadouking2) {
		if (!App->player2->playerhadouken.Finished()) {
			if (App->player2->current_animation != &App->player2->playerhadouken) {
				App->player2->current_animation = &App->player2->playerhadouken;
			}
		}
		else {
			App->player2->current_animation = &App->player2->idle;
			if (App->player2->position.x > App->player->position.x) {
				App->particles->hadouken.speed.x = -4;
				App->particles->AddParticle(App->particles->hadouken, App->player2->position.x, App->player2->position.y - 80, COLLIDER_PLAYER2_HADOUKEN, 0, true);
			}
			/*if (App->player2->position.x < App->player->position.x)*/ else {
				App->particles->hadouken.speed.x = 4;
				App->particles->AddParticle(App->particles->hadouken, App->player2->position.x+10, App->player2->position.y - 80, COLLIDER_PLAYER2_HADOUKEN, 0, false);
			}
			App->player2->hadouking2 = false;
		}
	}
	if (App->player->jumpingidle) {
		App->player->current_animation = &App->player->jump;
		App->player->position.y -= App->player->vely;
		App->player->vely += gravity;
		if (App->player->position.y >= 220) {
			App->player->jumpingidle = false;
			App->audio->Play(App->player->jumpgrounded, 0);
			App->player->position.y = 220;
			App->player->jump.Reset();
			App->player->current_animation = &App->player->idle;
		}
	}
	if (App->player2->jumpingidle) {
		App->player2->current_animation = &App->player2->jump;
		App->player2->position.y -= App->player2->vely;
		App->player2->vely += gravity;
		if (App->player2->position.y >= 220) {
			App->player2->jumpingidle = false;
			App->audio->Play(App->player2->jumpgrounded, 0);
			App->player2->position.y = 220;
			App->player2->jump.Reset();
			App->player2->current_animation = &App->player2->idle;
		}
	}

	//if playerposition.y <= groundY && (jumpingright/left/idle) then jumpingleft, idle, right to false
	//if jumping left position -= speed
	//if jumping right position += speed
	/*if (App->player->punching) {
		//App->collision->AddCollider({10, -80, 28, 10}, COLLIDER_PLAYER1_PUNCH, )
	}*/

	//if (App->player->lookingright)
	App->player->playercollider->rect.x = App->player->position.x + 10;
	//else
	//App->player->playercollider->rect.x = App->player->position.x + 10;
	App->player->playercollider->rect.y = App->player->position.y - 80;
	//if (App->player2->lookingright)
	App->player2->playercollider->rect.x = App->player2->position.x + 10;
	//else
	//App->player2->playercollider->rect.x = App->player2->position.x + 10;
	App->player2->playercollider->rect.y = App->player2->position.y - 80;

	if (App->player->punching) {

		App->player->pdamagecollider->rect.w = 30;
		App->player->pdamagecollider->rect.h = 15;
		if (App->player->lookingright)
			App->player->pdamagecollider->rect.x = App->player->position.x + 60;
		else
			App->player->pdamagecollider->rect.x = App->player->position.x - 31;
			App->player->pdamagecollider->rect.y = App->player->position.y - 76;
	}
	else if (App->player->kicking) {

		App->player->pdamagecollider->rect.w = 40;
		App->player->pdamagecollider->rect.h = 40;
		if (App->player->lookingright)
			App->player->pdamagecollider->rect.x = App->player->position.x + 40;
		else
			App->player->pdamagecollider->rect.x = App->player->position.x - 20;
		App->player->pdamagecollider->rect.y = App->player->position.y - 54;
	}
	else
	{
		App->player->pdamagecollider->rect.x = 0;
		App->player->pdamagecollider->rect.y = 500;
	}

	
	//
	if (App->player2->punching) {

		App->player2->pdamagecollider->rect.w = 30;
		App->player2->pdamagecollider->rect.h = 15;
		if (App->player2->lookingright)
			App->player2->pdamagecollider->rect.x = App->player2->position.x + 60;
		else
			App->player2->pdamagecollider->rect.x = App->player2->position.x - 31;
		App->player2->pdamagecollider->rect.y = App->player2->position.y - 76;
	}
	else if (App->player2->kicking) {

		App->player2->pdamagecollider->rect.w = 40;
		App->player2->pdamagecollider->rect.h = 40;
		if (App->player2->lookingright)
			App->player2->pdamagecollider->rect.x = App->player2->position.x + 40;
		else
			App->player2->pdamagecollider->rect.x = App->player2->position.x - 20;
		App->player2->pdamagecollider->rect.y = App->player2->position.y - 54;
	}
	else
	{
		App->player2->pdamagecollider->rect.x = 0;
		App->player2->pdamagecollider->rect.y = 500;
	}

	if (App->player->playerhittedcounter < 60) {
		App->player->playerhittedcounter++;
		App->player->current_animation = &App->player->hitted;
		if (App->player->lookingright)
			App->player->position.x -= 0.3f;
		else
			App->player->position.x += 0.3f;
	}
	if (App->player2->playerhittedcounter < 60) {
		App->player2->playerhittedcounter++;
		App->player2->current_animation = &App->player2->hitted;
		if (App->player2->lookingright)
			App->player2->position.x -= 0.3f;
		else
			App->player2->position.x += 0.3f;
	}
	
	//player2collider->rect.x = App->player2->position.x;
	//player2collider->rect.y = App->player2->position.y - 90;
	// Draw everything --------------------------------------
	SDL_Rect r1 = App->player->current_animation->GetCurrentFrame();
	SDL_Rect r2 = App->player2->current_animation->GetCurrentFrame();
	if (App->player->lookingright)
	App->render->Blit(graphicsryu, App->player->position.x, App->player->position.y - r1.h, &r1, 1.0f, !App->player->lookingright);
	else
	App->render->Blit(graphicsryu, App->player->position.x + 60, App->player->position.y - r1.h, &r1, 1.0f, !App->player->lookingright);
	if (App->player2->lookingright)
	App->render->Blit(graphicszangief, App->player2->position.x, App->player2->position.y - r2.h, &r2, 1.0f, !App->player2->lookingright);
	else
	App->render->Blit(graphicszangief, App->player2->position.x + 60, App->player2->position.y - r2.h, &r2, 1.0f, !App->player2->lookingright);

	if (App->player->life <= 0) {
		//App->particles->CleanUp();
		App->fade->FadeToBlack(App->scene_Ryu, App->congratsscreen);
	}
	if (App->player2->life <= 0) {
		//App->particles->CleanUp();
		App->fade->FadeToBlack(App->scene_Ryu, App->congratsscreen);
	}
	//fonts
	//font_welcome = App->fonts->Load("")
	return UPDATE_CONTINUE;
}

void ModulePlayer::OnCollision(Collider*c1, Collider*c2) {

	if (c1 == App->player->playercollider &&!App->fade->IsFading() && c2->type == COLLIDER_PLAYER2) {
		//player 1 empuja player 2
		if(App->player->position.x<App->player2->position.x)
			App->player2->position.x += 2;
		else
			App->player2->position.x -= 2;
	}
	//player 2 empuja player 1
	if (c1 == App->player2->playercollider && !App->fade->IsFading() && c2->type == COLLIDER_PLAYER1) {
		if (App->player2->position.x < App->player->position.x)
			App->player->position.x += 2;
		else
			App->player->position.x -= 2;
	}
	if (c1 == App->player->playercollider && c2->type == COLLIDER_PLAYER2_HADOUKEN && (App->player->playerhittedcounter > 59) && !App->player->godmode) {
		App->player->life -= 15;
		App->player->playerhittedcounter = 0;
	}

	if (c1 == App->player2->playercollider && c2->type == COLLIDER_PLAYER1_HADOUKEN && (App->player2->playerhittedcounter > 59) && !App->player2->godmode) {
		App->player2->life -= 15;
		App->player2->playerhittedcounter = 0;
	}

	if (c1 == App->player->playercollider && c2->type == COLLIDER_PLAYER2_DAMAGE && (App->player->playerhittedcounter > 59) && !App->player->godmode) {
		App->player->life -= 10;
		App->player->playerhittedcounter = 0;
	}

	if (c1 == App->player2->playercollider && c2->type == COLLIDER_PLAYER1_DAMAGE && (App->player2->playerhittedcounter > 59) && !App->player2->godmode) {
		App->player2->life -= 10;
		App->player2->playerhittedcounter = 0;
	}

	/*if (App->scene_ken->IsEnabled() == true)
	App->fade->FadeToBlack(App->scene_ken, App->scene_honda);
	if (App->scene_honda->IsEnabled() == true)
	App->fade->FadeToBlack(App->scene_honda, App->congratsscreen);*/
}

bool ModulePlayer::CleanUp() {
	App->textures->Unload(graphicsryu);
	App->audio->Unload(lowattack);
	App->audio->Unload(lowattack);
	App->audio->Unload(lowpunchhit);
	App->audio->Unload(lowkickhit);
	App->audio->Unload(jumpgrounded);
	if (App->player->playercollider!=nullptr) {
		App->player->playercollider->to_delete = true;
	}
	if (App->player2->playercollider!=nullptr) {
		App->player2->playercollider->to_delete = true;
	}
	return true;
}