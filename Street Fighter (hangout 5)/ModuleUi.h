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
	const char *round_text[99]{ "ROUND 1","ROUND 2","ROUND 3","ROUND 4","ROUND 5","ROUND 6","ROUND 7","ROUND 8","ROUND 9","ROUND 10","ROUND 11","ROUND 12","ROUND 13","ROUND 14","ROUND 15","ROUND 16","ROUND 17","ROUND 18","ROUND 19","ROUND 20","ROUND 21","ROUND 22","ROUND 23","ROUND 24","ROUND 25","ROUND 26","ROUND 27","ROUND 28","ROUND 29","ROUND 30","ROUND 31","ROUND 32","ROUND 33","ROUND 34","ROUND 35","ROUND 36","ROUND 37","ROUND 38","ROUND 39","ROUND 40","ROUND 41","ROUND 42","ROUND 43","ROUND 44","ROUND 45","ROUND 46","ROUND 47","ROUND 48","ROUND 49","ROUND 50" };
	uint current_round;
	float second;
	float seconds_end_round;
	float seconds_winner;
	bool next_round;
	bool out_time;
	bool stop_time;
	int time_end_round;
	int round_index;
	uint current_time;
	SDL_Texture* uitext = nullptr;	//V
	Mix_Chunk* fight= nullptr;
	Mix_Chunk*round = nullptr;
	Mix_Chunk*one = nullptr;
	Mix_Chunk*two= nullptr;
	Mix_Chunk*three= nullptr;
	Mix_Chunk*four = nullptr;
	Mix_Chunk*five = nullptr;
	Mix_Chunk*six = nullptr;
	Mix_Chunk*seven = nullptr;
	bool fighting;
	bool rounding;
	SDL_Rect uibg; //V
	SDL_Rect uip1; //V
	SDL_Rect uip2; //V
	SDL_Rect win_hand;
	int prevHP1 = 100;	//V: es una variable placeholder que equivale a la vida antes del update
	int prevHP2 = 100;	//V: recordad iniciarlas en 100 cuando esté hecho (están en 0 para ver que funcionan)
};

#endif // __MODULEUI_H__
