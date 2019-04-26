//#define _CRTDBG_MAP_ALLOC
//#include <stdlib.h>
//#include <crtdbg.h>
//#include "Globals.h"
//#include "Application.h"
//#include "ModuleSceneRyu.h"
//#include "ModuleWelcomeScreen.h"
//#include "ModuleTextures.h"
//#include "ModuleRender.h"
//#include "ModulePlayer.h"
//#include "Module.h"
//#include "Application.h"
//#include "ModuleFadeToBlack.h"
//#include "ModuleInput.h"
//#include "ModuleAudio.h"
//#include "ModuleWinloseScreen.h"
//// Reference at https://youtu.be/6OlenbCC4WI?t=382
//
//ModuleWinloseScreen::ModuleWinloseScreen()
//{
//	background = { 795, 0, 1050, 220 };
//}
//
//ModuleWinloseScreen::~ModuleWinloseScreen()
//{}
//
//// Load assets
//bool ModuleWinloseScreen::Start()
//{
//	LOG("Loading background assets");
//	bool ret = true;
//	graphics = App->textures->Load("UI1.png");
//	mainmenumusic = App->audio->Load("02 The World Warrior.ogg");
//	mainmenutoscenesound = App->audio->Load("IntroToScene.wav");
//	App->audio->Play(mainmenumusic, -1);
//	return ret;
//}
//
//// Load assets
//bool ModuleWinloseScreen::CleanUp()
//{
//	// TODO 5: Remove all memory leaks
//	LOG("Unloading UI1");
//	App->textures->Unload(graphics);
//	App->audio->Unload(mainmenumusic);
//	App->audio->Unload(mainmenutoscenesound);
//	return true;
//}
//
//// Update: draw background
//update_status ModuleWinloseScreen::Update()
//{
//	App->render->Blit(graphics, -150, -45, &background, 0.75f); // back of the room
//	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
//	{
//		App->audio->Play(mainmenutoscenesound, 0);
//		App->fade->FadeToBlack(App->winlosescreen, App->scene_Ryu, 1);
//	}
//	return UPDATE_CONTINUE;
//}