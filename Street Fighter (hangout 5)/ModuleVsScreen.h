#ifndef __MODULEVSSCREEN_H__
#define __MODULEVSSCREEN__H__

#include "Module.h"
#include "Globals.h"

struct SDL_Texture;
struct Mix_Chunk;

class ModuleVsScreen : public Module
{
public:
	ModuleVsScreen();
	~ModuleVsScreen();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	Mix_Chunk* music = nullptr;
	SDL_Texture* graphics = nullptr;
	SDL_Rect background;
	uint seconds;
};

#endif // __MODULEVSSCREEN__H__
