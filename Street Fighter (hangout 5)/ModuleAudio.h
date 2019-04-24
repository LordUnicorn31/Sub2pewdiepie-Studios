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

	Mix_Chunk* lowattack = nullptr;			//punch or kick that you miss (you don't hit anything)
	Mix_Chunk* midattack = nullptr;			//punch or kick that you miss (you don't hit anything)
	Mix_Chunk* highattackpunch = nullptr;	//high punch that you miss (you don't hit anything)
	Mix_Chunk* highattackkick = nullptr;	//high kick that you miss (you don't hit anything)

	Mix_Chunk* lowpunchhit = nullptr;
	Mix_Chunk* midpunchhit = nullptr;
	Mix_Chunk* highpunchhit = nullptr;

	Mix_Chunk* lowkickhit = nullptr;
	Mix_Chunk* midkickhit = nullptr;
	Mix_Chunk* highkickhit = nullptr;

	Mix_Chunk* hadoukenhit = nullptr;
};
#endif // __ModuleAudio_H__
