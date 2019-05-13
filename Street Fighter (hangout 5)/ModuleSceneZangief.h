#ifndef __MODULESCENEZANGIEF_H__
#define __MODULESCENEZANGIEF_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;
struct Mix_Chunk;


class ModuleSceneZangief : public Module
{
public:
	ModuleSceneZangief();
	~ModuleSceneZangief();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	Mix_Chunk* music = nullptr;
	SDL_Texture* uitext = nullptr;	//V
	SDL_Rect uibg; //V
	SDL_Rect uip1; //V
	SDL_Rect uip2; //V
	int prevHP1 = 100;	//V: es una variable placeholder que equivale a la vida antes del update
	int prevHP2 = 100;	//V: recordad iniciarlas en 100 cuando est� hecho (est�n en 0 para ver que funcionan)
	SDL_Rect ground;
};

#endif // __MODULESCENEZANGIEF_H__