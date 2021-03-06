#ifndef __MODULEPARTICLES_H__
#define __MODULEPARTICLES_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "ModuleCollision.h"

#define MAX_ACTIVE_PARTICLES 250

struct SDL_Texture;
struct Mix_Chunk;
struct Collider;
enum COLLIDER_TYPE;
struct Particle
{
	Collider* collider = nullptr;
	Animation anim;
	//uint fx = 0;
	Mix_Chunk* sfx = nullptr;
	iPoint position;
	iPoint speed;
	Uint32 born = 0;
	Uint32 life = 0;
	bool flipped = false;
	bool fx_played = false;

	Particle();
	Particle(const Particle& p);
	~Particle();
	bool Update();
	
};

class ModuleParticles : public Module
{
public:
	ModuleParticles();
	~ModuleParticles();

	bool Start();
	update_status Update();
	bool CleanUp();

	void AddParticle(const Particle& particle, int x, int y, COLLIDER_TYPE collider_type, Uint32 delay = 0, bool flipped_ = false);
	Particle hadouken;
	Mix_Chunk* hadoukenhit = nullptr;

private:
	
	SDL_Texture* graphics = nullptr;
	Particle* active[MAX_ACTIVE_PARTICLES];

public:
	void OnCollision(Collider*, Collider*);
};


#endif // __MODULEPARTICLES_H__