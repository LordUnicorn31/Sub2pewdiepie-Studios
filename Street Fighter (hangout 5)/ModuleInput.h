#ifndef __ModuleInput_H__
#define __ModuleInput_H__

#include "Module.h"
#include "Globals.h"
#include "SDL\include\SDL_scancode.h"

typedef unsigned char Uint8;
//typedef unsigned char Uint32;

class ModuleInput : public Module
{
public:
	
	ModuleInput();
	~ModuleInput();

	bool Init();
	update_status PreUpdate();
	bool CleanUp();

public:
	const Uint8 *keyboard = nullptr;
	//Uint32 mouse;
	int mPosX;
	int mPosY;
};

#endif // __ModuleInput_H__