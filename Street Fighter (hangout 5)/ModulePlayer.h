#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"

struct SDL_Texture;
struct Mix_Chunk;

class ModulePlayer : public Module
{
public:
	ModulePlayer();
	~ModulePlayer();

	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(Collider*, Collider*);

public:
	float vely = 0.0f;
	float gravity = -0.08f;
	Animation* current_animation = &idle;
	//Animation* current_animation_player2 = &idle;
	SDL_Texture* graphics = nullptr;
	bool lookingright;
	int hadoukenable = 0;
	bool forwarding = false;
	bool backwarding = false;
	bool jumpingidle = false;
	bool jumpingright = false;
	bool jumpingleft = false;
	bool punching = false;
	bool kicking = false;
	bool hadouking = false;
	bool hadouking2 = false;//le fet pk no vull borrar el que as fet am el numero 1
	//colliders
	Collider* playercollider = nullptr;
	Collider* player1punch = nullptr;
	//Collider* player2collider = nullptr;

	//hadouken
	Animation playerhadouken;
	//movement
	Animation idle;
	Animation forward;
	Animation backward;
	Animation turning;
	Animation jump;
	Animation jump_frontflip;
	//punches
	Animation lowpunch;
	Animation midhigh_punch;
		Animation low_close_punch;
		Animation high_close_punch;
			Animation low_jump_punch;
			Animation high_jump_punch;
			iPoint punchpos;
			
	//kicks
	Animation lowmid_kick;
	Animation high_kick;
		Animation low_close_kick;
		Animation high_close_kick;
			//Animation jump_kick;
	//
	//Animations player2
	//

		/*
	Animation idle2;
	//movement
	Animation forward2;
	Animation backward2;
	Animation turning2;
	Animation jump2;
	Animation jump_frontflip2;
	//punches
	Animation lowpunch2;
	Animation midhigh_punch2;
		Animation low_close_punch2;
		Animation high_close_punch2;
			Animation low_jump_punch2;
			Animation high_jump_punch2;
			
	//kicks
	Animation lowmid_kick2;
	Animation high_kick2;
		Animation low_close_kick2;
		Animation high_close_kick2;*/
			//Animation jump_kick2;
	//
	fPoint position;

	//Mix_Chunk* 
	/*void playerRotation(ModulePlayer *foe) {
		if (foe == nullptr)
			return;
		if (this->position.x < foe->position.x && lookingright == false) { //TURN LEFT TO RIGHT
			current_animation = &turning;
			if (current_animation->Finished() == true)
				lookingright = true;
		}
		else if (this->position.x > foe->position.x && lookingright == true) { //TURN RIGHT TO LEFT
			current_animation = &turning;
			if (current_animation->Finished() == true)
				lookingright = false;
		}
	}*/
	//Audios
	Mix_Chunk* lowattack = nullptr;			//punch or kick that you miss (you don't hit anything)
	Mix_Chunk* midattack = nullptr;			//punch or kick that you miss (you don't hit anything)	// needed
	Mix_Chunk* highattackpunch = nullptr;	//high punch that you miss (you don't hit anything)
	Mix_Chunk* highattackkick = nullptr;	//high kick that you miss (you don't hit anything)

	Mix_Chunk* lowpunchhit = nullptr;		//triggers when low punch collides with enemy
	Mix_Chunk* midpunchhit = nullptr;		//triggers when mid punch collides with enemy			//needed
	Mix_Chunk* highpunchhit = nullptr;		//triggers when high punch collides with enemy

	Mix_Chunk* lowkickhit = nullptr;		//triggers when low kick collides with enemy
	Mix_Chunk* midkickhit = nullptr;		//triggers when mid kick collides with enemy			//needed
	Mix_Chunk* highkickhit = nullptr;		//triggers when high kick collides with enemy

	Mix_Chunk* hadoukenaudio = nullptr;			//triggers when player throws hadouken					//needed
	Mix_Chunk* hadoukenhit = nullptr;		//triggers when hadouken collider hits the enemy (so i think it should go to Particles.h maybe, idk)
	Mix_Chunk* jumpgrounded = nullptr;
};

#endif