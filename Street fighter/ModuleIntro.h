#ifndef __MODULEINTRO_H__
#define __MODULEITRO_H__

#include "Globals.h"
#include "Application.h"
#include "Module.h"

struct SDL_Texture;
struct Mix_Chunk;

class ModuleIntro :public Module {
public:
	ModuleIntro();
	~ModuleIntro();
	bool Start();
	update_status Update();
	bool CleanUp();
	SDL_Texture*graphics = nullptr;
};
#endif // __MODULEINTRO_H__