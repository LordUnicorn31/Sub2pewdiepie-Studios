#ifndef __MODULEWELCOMESCENE_H__
#define __MODULEWELCOMESCENE_H__

#include "Module.h"
#include "Globals.h"

struct SDL_Texture;
struct Mix_Chunk;

class ModuleWelcomeScreen : public Module
{
public:
	ModuleWelcomeScreen();
	~ModuleWelcomeScreen();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	//Mix_Chunk *audio=nullptr;
	SDL_Rect background;
};

#endif // __MODULEWELCOMESCENE_H__