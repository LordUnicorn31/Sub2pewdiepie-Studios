#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleSceneSpace.h"
#include "ModuleIntroScene.h"
//#include "SDL_mixer/include/SDL_mixer.h"
#include "SDL/include/SDL.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleIntroScene::ModuleIntroScene()
{}

ModuleIntroScene::~ModuleIntroScene()
{}

// Load assets
bool ModuleIntroScene::Start()
{
	LOG("Loading space scene");
	/*Mix_Init(MIX_INIT_OGG);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
	intromusic = Mix_LoadMUS("rtype/intro.ogg");
	Mix_PlayMusic(intromusic, -1);*/
	background = App->textures->Load("rtype/intro.png");

	App->player->Enable();

	return true;
}

// UnLoad assets
bool ModuleIntroScene::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(background);
	App->player->Disable();
	/*Mix_CloseAudio();
	Mix_Quit();*/
	return true;
}

// Update: draw background
update_status ModuleIntroScene::Update()
{
	// Move camera forward -----------------------------
	/*int scroll_speed = 1;

	App->player->position.x += 1;
	App->render->camera.x -= 3;*/


	// Draw everything --------------------------------------
	App->render->Blit(background, 0, 0, NULL);

	return UPDATE_CONTINUE;
}