#define _CRTDBG_MAP_ALLOC
#include "Globals.h"
#include "Application.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleSceneRyu.h"
#include "ModulePlayer.h"
#include "ModuleFadeToBlack.h"
#include "ModuleCongratsScreen.h"
#include "ModuleAudio.h"
#include "ModuleSceneZangief.h"
#include "ModuleUi.h"


ModuleUi::ModuleUi()
{
	//ui bars		//V
	uibg.x = 0;		//V
	uibg.y = 0;		//V
	uibg.w = 194;	//V
	uibg.h = 14;	//V
	uip1.x = 1;		//V
	uip1.y = 15;	//V
	uip1.w = 88;	//V
	uip1.h = 8;		//V
	uip2.x = 1;		//V
	uip2.y = 15;	//V
	uip2.w = 88;	//V
	uip2.h = 8;		//V
}

ModuleUi::~ModuleUi()
{}

bool ModuleUi::Init() {
	return true;
}
// UnLoad assets
bool ModuleUi::CleanUp()
{
	return true;
}

// Update: draw background
update_status ModuleUi::Update()
{

	return UPDATE_CONTINUE;
}
