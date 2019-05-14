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
#include "ModuleController.h"
#include "ModuleSpecialMoves.h"

ModuleSpecialMoves::ModuleSpecialMoves()
{

}

ModuleSpecialMoves::~ModuleSpecialMoves()
{}

bool ModuleSpecialMoves::Init() {
	return true;
}
// UnLoad assets
bool ModuleSpecialMoves::CleanUp()
{
	return true;
}

// Update: draw background
update_status ModuleSpecialMoves::Update()
{

	return UPDATE_CONTINUE;
}
