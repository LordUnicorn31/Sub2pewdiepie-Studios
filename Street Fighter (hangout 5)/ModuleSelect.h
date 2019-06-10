#ifndef __MODULESELECT_H__
#define __MODULESELECT__H__

#include "Module.h"
#include "Globals.h"

struct SDL_Texture;
struct Mix_Chunk;

class ModuleSelect : public Module
{
public:
	ModuleSelect();
	~ModuleSelect();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	Mix_Chunk* audio = nullptr;
	SDL_Texture* graphics = nullptr;
	SDL_Rect background;
};

#endif // __MODULESELECT__H__

