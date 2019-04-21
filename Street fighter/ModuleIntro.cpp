#include "ModuleIntro.h"
#include "ModuleSceneKen.h"
#include "ModulePlayer.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"

ModuleIntro::ModuleIntro() {}
ModuleIntro::~ModuleIntro() {}

bool ModuleIntro::Start() {
	App->scene_ken->Disable();
	App->player->Disable();
	LOG("Loading Intro texture and audio");
	graphics = App->textures->Load("intro.png");
	return true;
}

bool ModuleIntro::CleanUp() {
	App->textures->Unload(graphics);
	return true;
}

update_status ModuleIntro::Update() {
	if (App->input->keyboard[SDL_SCANCODE_SPACE]) {
		App->fade->FadeToBlack(App->intro, App->scene_ken, 1);
	}
	App->render->Blit(graphics, 0, 0, NULL);
	return UPDATE_CONTINUE;
}