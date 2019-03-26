#ifndef __ModuleBackground_H__
#define __ModuleBackground_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleBackground : public Module
{
public:
	ModuleBackground();
	~ModuleBackground();

	bool Start();
	update_status Update();

public:
	
	SDL_Texture* graphics = nullptr;
	SDL_Rect ground;
	SDL_Rect background;
	SDL_Rect ship;
	int shipYpos1 = 22;
	int shipYpos2 = 24;
	int shipYpos3 = 26;
	int shipYpos4 = 24;
	int shipYpos5 = 22;
	Animation girl;
	Animation flag;
	float shipmovement = 0;
};

#endif