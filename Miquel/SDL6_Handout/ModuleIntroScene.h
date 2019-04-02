#ifndef __MODULEINTROSCENE_H__
#define __MODULEINTROSCENE_H__

#include "Module.h"
#include "SDL_mixer/include/SDL_mixer.h"
#include "SDL/include/SDL.h"

struct SDL_Texture;

class ModuleIntroScene : public Module
{
public:
	ModuleIntroScene();
	~ModuleIntroScene();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	_Mix_Music* intromusic = nullptr;
	SDL_Texture* background = nullptr;
	SDL_Texture* stars = nullptr;
};

#endif // __MODULEINTROSCENE_H__