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
	const char *time_text[99]{"00","01","02","03","04","05","06","07","08","09","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31","32","33","34","35","36","37","38","39","40","41","42","43","44","45","46","47","48","49","50","51","52","53","54","55","56","57","58","59","60","61","62","63","64","65","66","67","68","69","70","71","72","73","74","75","76","77","78","79","80","81","82","83","84","85","86","87","88","89","90","91","92","93","94","95","96","97","98"};
	int second;
	uint current_time;
	SDL_Texture* uitext = nullptr;	//V
	SDL_Rect uibg; //V
	SDL_Rect uip1; //V
	SDL_Rect uip2; //V
	int prevHP1 = 100;	//V: es una variable placeholder que equivale a la vida antes del update
	int prevHP2 = 100;	//V: recordad iniciarlas en 100 cuando esté hecho (están en 0 para ver que funcionan)
};

#endif // __MODULEUI_H__
