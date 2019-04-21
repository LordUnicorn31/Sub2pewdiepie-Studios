#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"

struct SDL_Texture;

class ModulePlayer : public Module
{
public:
	ModulePlayer();
	~ModulePlayer();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	Animation* current_animation = nullptr;
	Animation idle;
	Animation backward;
	Animation forward;
	Animation short_punch;
	Animation hadouken;
	Animation jump_floor;
	Animation jump_air;
	Animation jump_fall;
	Animation kick;
	Animation large_kick;
	bool a;
	bool b;
	bool aaa;
	bool bbb;
	bool ccc;
	bool ddd;
	bool eee;
	bool fff;
	bool ggg;
	Uint32 start_time;
	Uint32 current_time;
	Uint32 final_time;
	Uint32 start_jump;
	iPoint position;
};

#endif