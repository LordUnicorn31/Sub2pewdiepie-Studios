#ifndef __MODULECONTROLLER_H__
#define __MODULECONTROLLER_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;
struct Mix_Chunk;


class ModuleController : public Module
{
public:
	ModuleController();
	~ModuleController();
	bool Init();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
};

#endif // __MODULECONTROLLER_H__
