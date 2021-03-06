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
	Mix_Chunk* mainmenumusic = nullptr;
	Mix_Chunk* mainmenutoscenesound = nullptr;
	SDL_Texture* graphics = nullptr;
	SDL_Texture* logo = nullptr;
	Animation loggo;
	//Mix_Chunk *audio=nullptr;
	SDL_Rect background;
};

#endif // __MODULEWELCOMESCENE_H__