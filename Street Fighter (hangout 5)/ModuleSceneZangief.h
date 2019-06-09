#ifndef __MODULESCENEZANGIEF_H__
#define __MODULESCENEZANGIEF_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;
struct Mix_Chunk;


class ModuleSceneZangief : public Module
{
public:
	ModuleSceneZangief();
	~ModuleSceneZangief();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	Mix_Chunk* music = nullptr;
	SDL_Texture* uitext = nullptr;	//V
	uint zangief_init_time;
	SDL_Rect background;
	SDL_Rect ground;
	SDL_Rect background2;
	SDL_Rect valla;
	SDL_Rect extinctor;
	SDL_Rect palanca;
	Animation dudes;
	Animation dudes2;
};

#endif // __MODULESCENEZANGIEF_H__
