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
	Animation forward;
	Animation backward;
	Animation turning;
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