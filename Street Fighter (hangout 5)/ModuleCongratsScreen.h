#ifndef __MODULECONGRATSSCREEN_H__
#define __MODULECONGRATSSCREEN_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;
struct Mix_Chunck;
class ModuleCongratsScreen : public Module
{
public:
	ModuleCongratsScreen();
	~ModuleCongratsScreen();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	SDL_Texture* graphics2 = nullptr;
	SDL_Rect background;
	SDL_Rect winer;
	SDL_Rect loser;
	Mix_Chunk* congratsmusic = nullptr;
	
};

#endif // __MODULECONGRATSSCREEN_H__