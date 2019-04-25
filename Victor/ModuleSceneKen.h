#ifndef __MODULESCENEKEN_H__
#define __MODULESCENEKEN_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;
struct Mix_Chunk;

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
	Mix_Chunk* music = nullptr;
	SDL_Rect ground;
	SDL_Rect sky;
	SDL_Rect background;
	SDL_Rect castle;
	SDL_Texture* uitext = nullptr;	//V
	SDL_Rect uibg; //V
	SDL_Rect uip1; //V
	SDL_Rect uip2; //V
};

#endif // __MODULESCENEKEN_H__