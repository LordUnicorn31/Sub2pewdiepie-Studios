#ifndef __ModuleAudio_H__
#define __ModuleAudio_H__

#include "Module.h"
#include "Globals.h"


#define MAX_AUDIOS 50

struct Mix_Chunk;

class ModuleAudio :public Module {
public:
	ModuleAudio();
	~ModuleAudio() {};

	bool Init();
	bool CleanUp();
	Mix_Chunk* const Load(const char* path);
	void Play(Mix_Chunk* audio, int times);
	bool Unload(Mix_Chunk * audio);

public:
	Mix_Chunk* audios[MAX_AUDIOS];

};
#endif // __ModuleAudio_H__
