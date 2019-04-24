#ifndef __MODULESCENEKEN_H__
#define __MODULESCENEKEN_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleSceneKen : public Module
{
public:
	ModuleSceneKen();
	~ModuleSceneKen();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	SDL_Rect ground;
	SDL_Rect sky;
	SDL_Rect background;
	SDL_Rect castle;
	//falta la musica de fons

	float foreground_pos;
	bool forward;
};

#endif // __MODULESCENEKEN_H__