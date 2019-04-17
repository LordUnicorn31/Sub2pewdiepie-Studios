#ifndef __ModuleInput_H__
#define __ModuleInput_H__

#include "Module.h"
#include "Globals.h"
#include "SDL\include\SDL_scancode.h"

#define MAX_KEYS 300

typedef unsigned char Uint8;
//typedef unsigned char Uint32;
enum KEY_STATE {
	KEY_IDLE = 0, 
	KEY_DOWN, 
	KEY_REPEAT,
	KEY_UP
};

class ModuleInput : public Module
{
public:
	
	ModuleInput();
	~ModuleInput();

	bool Init();
	update_status PreUpdate();
	bool CleanUp();

public:
	KEY_STATE keyboardstates[MAX_KEYS];
	const Uint8 *keyboard = nullptr;
	//Uint32 mouse;
	int mPosX;
	int mPosY;
};

#endif // __ModuleInput_H__