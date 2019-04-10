#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"

struct SDL_Texture;

class ModulePlayer : public Module
{
public:
	ModulePlayer();
	~ModulePlayer();

	bool Start();
	update_status Update();

public:

	Animation* current_animation = &idle;
	SDL_Texture* graphics = nullptr;
	bool lookingright;

	Animation idle;
	//movement
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
			

	//kicks
	Animation lowmid_kick;
	Animation high_kick;
		Animation low_close_kick;
		Animation high_close_kick;
			//Animation jump_kick;
	//
	iPoint position;

	void playerRotation(ModulePlayer *foe) {
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
	}
};

#endif