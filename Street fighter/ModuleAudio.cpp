#include "ModuleAudio.h"
#include "Application.h"
#include "Globals.h"
#include "ModuleInput.h"
#include "SDL/include/SDL.h"
#include "SDL_mixer/include/SDL_mixer.h"
#pragma comment (lib,"SDL_Mixer/libx86/SDL2_Mixer.lib")
bool ModuleAudio::Init() {
	bool ret = true;
	int flags = MIX_INIT_OGG;
	int initted = Mix_Init(flags);
	if (flags&&initted != flags) {
		ret = false;
		LOG("Error initialazing audio module: %s", Mix_GetError());
	}
	else {
		LOG("Audio module initialized");
		if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024) != 0) {
			LOG("Error opening audio: %s", Mix_GetError());
			ret = false;
		}
		else
			LOG("Audio opened");
	}
	return ret;
}
ModuleAudio::ModuleAudio() {
	for (uint i = 0; i < MAX_AUDIOS; ++i) {
		audios[i] = nullptr;
	}
}
bool ModuleAudio::CleanUp() {
	for (uint i = 0; i < MAX_AUDIOS; ++i) {
		if (audios[i] != nullptr) {
			Mix_FreeChunk(audios[i]);
		}
	}
	Mix_CloseAudio();
	Mix_Quit();
	return true;
}

Mix_Chunk* const ModuleAudio::Load(const char* path) {
	for (uint i = 0; i < MAX_AUDIOS; ++i) {
		if (audios[i] == nullptr) {
			audios[i] = Mix_LoadWAV(path);
			if (audios[i] == NULL) {
				LOG("Error loading the audio:%s", Mix_GetError());
				return nullptr;
			}
			else
				return audios[i];
		}
	}
	return nullptr;
}
//times=-1 for infinit play
void ModuleAudio::Play(Mix_Chunk* audio,int times) {
	Mix_PlayChannel(-1, audio, times);
}
bool ModuleAudio::Unload(Mix_Chunk*audio) {
	bool ret = false;
	if (audio != nullptr)
	{
		LOG("Unloading Audio");
		for (int i = 0; i < MAX_AUDIOS; ++i)
		{
			if (audios[i] == audio)
			{
				if (App->input->keyboard[SDL_SCANCODE_ESCAPE] != 1) {
					Mix_FreeChunk(audio);
				}
				audios[i] = nullptr;
				ret = true;
				break;
			}
		}
	}
	return ret;
}