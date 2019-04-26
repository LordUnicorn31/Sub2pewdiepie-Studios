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
	SDL_Rect ground;
	SDL_Rect roof;
	SDL_Rect foreground;
	SDL_Rect background;
	Animation water;
	Mix_Chunk* congratsmusic = nullptr;
	//Mix_Chunk *audio=nullptr;
	
};

#endif // __MODULECONGRATSSCREEN_H__