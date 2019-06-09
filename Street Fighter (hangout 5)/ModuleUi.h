#ifndef __MODULEUI_H__
#define __MODULEUI_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;
struct Mix_Chunk;


class ModuleUi : public Module
{
public:
	ModuleUi();
	~ModuleUi();
	bool Init();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	int orange_font=-1;
	int grey_font=-1;
	int blueorange_font = -1;
	int green_font = -1;
	int red_font = -1;
	int white_font = -1;
	char time_text[2];
	int time = 99;
	uint current_time;
	SDL_Texture* uitext = nullptr;	//V
	SDL_Rect uibg; //V
	SDL_Rect uip1; //V
	SDL_Rect uip2; //V
	int prevHP1 = 100;	//V: es una variable placeholder que equivale a la vida antes del update
	int prevHP2 = 100;	//V: recordad iniciarlas en 100 cuando esté hecho (están en 0 para ver que funcionan)
};

#endif // __MODULEUI_H__
