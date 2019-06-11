#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 20

class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleRender;
class ModuleSceneRyu;
class ModuleSceneZangief;
class ModuleWelcomeScreen; //
class ModuleCongratsScreen; //
class ModulePlayer;
class ModuleFadeToBlack;
class Module;
class ModuleParticles;
class ModuleAudio;
class ModuleCollision;
class ModuleFonts;
class ModuleUi;
class ModuleSpecialMoves;
class ModuleVsScreen;
class ModuleSelect;
class ModuleSlowdown;


class Application
{
public:
	
	Module* modules[NUM_MODULES];
	ModuleWindow* window;
	ModuleRender* render;
	ModuleInput* input;
	ModuleTextures* textures;
	ModuleSceneRyu* scene_Ryu;
	ModuleSceneZangief* scene_Zangief;
	ModulePlayer* player;
	ModulePlayer* player2;
	ModuleFadeToBlack* fade;
	ModuleWelcomeScreen* welcomescreen;
	ModuleCongratsScreen* congratsscreen;
	ModuleParticles* particles;
	ModuleAudio* audio;
	ModuleCollision* collision;
	ModuleFonts* fonts;
	ModuleUi*ui;
	ModuleSpecialMoves*special_moves;
	ModuleVsScreen*vs_screen;
	ModuleSelect*select;
	ModuleSlowdown *slowdown;
	

public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

};

// Global var made extern for Application ---
extern Application* App;

#endif // __APPLICATION_H__