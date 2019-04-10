#ifndef __MODULEAUDIO_H__
#define __MODULEAUDIO_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleAudio : public Module
{
public:
	ModuleAudio();
	~ModuleAudio();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	/*SDL_Texture* graphics = nullptr;
	SDL_Rect ground;
	SDL_Rect roof;
	SDL_Rect foreground;
	SDL_Rect background;
	Animation water;*/
};

#endif // __MODULEAUDIO_H__