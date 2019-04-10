#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 12

class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleRender;
class ModuleSceneKen;
class ModuleSceneHonda;
class ModuleWelcomeScreen; //
class ModuleCongratsScreen; //
class ModulePlayer;
class ModuleFadeToBlack;
class Module;
class ModuleParticles;
class ModuleAudio;

class Application
{
public:
	
	Module* modules[NUM_MODULES];
	ModuleWindow* window;
	ModuleRender* render;
	ModuleInput* input;
	ModuleTextures* textures;
	ModuleSceneKen* scene_ken;
	ModuleSceneHonda* scene_honda;
	ModulePlayer* player;
	ModuleFadeToBlack* fade;
	ModuleWelcomeScreen* welcomescreen;
	ModuleCongratsScreen* congratsscreen;
	ModuleParticles* particles;
	ModuleAudio* audio;

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