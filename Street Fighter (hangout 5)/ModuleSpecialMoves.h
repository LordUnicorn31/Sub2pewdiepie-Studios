#ifndef __MODULESPECIALMOVES_H__
#define __MODULESPECIALMOVES_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;
struct Mix_Chunk;


class ModuleSpecialMoves : public Module
{
public:
	ModuleSpecialMoves();
	~ModuleSpecialMoves();
	bool Init();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
};

#endif // __MODULESPECIALMOVES_H__

