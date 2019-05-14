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

ModuleController::ModuleController()
{

}

ModuleController::~ModuleController()
{}

bool ModuleController::Init() {
	return true;
}
// UnLoad assets
bool ModuleController::CleanUp()
{
	return true;
}

// Update: draw background
update_status ModuleController::Update()
{

	return UPDATE_CONTINUE;
}
