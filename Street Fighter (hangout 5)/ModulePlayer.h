#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "ModuleInput.h"

struct SDL_Texture;
struct Mix_Chunk;
enum playernames {
	RYU, ZANGIEF
};
enum playermoves {
	LP, MP, HP, LK, MK, HK,
	LPC, MPC, HPC, LKC, MKC, HKC
	
};
enum players {
	PLAYER1, PLAYER2
};

class ModulePlayer : public Module
{
public:
	ModulePlayer(
		int playername,
		int leftButton,
		int rightButton,
		int upButton,
		int downButton,
		int lp,
		int mp,
		int hp,
		int lk,
		int mk,
		int hk,
		int godModeOn,
		int godModeOff,
		int playernum,
		int startButton
	);
	~ModulePlayer();

	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(Collider*, Collider*);

public:
	int score = 0;
	int matcheswon = 0;
	int name;
	int playernum;
	int life = 0;
	float vely = 0.0f;
	float gravity = -0.08f;
	Animation* current_animation = &idle;
	//Animation* current_animation_player2 = &idle;
	SDL_Texture* graphics = nullptr;
	SDL_Texture *bigfactory = nullptr;
	SDL_Rect verja;
	SDL_Rect palanca;
	//SDL_Texture* graphicszangief = nullptr;
	bool lookingright;
	bool godmode = false;
	int hadoukenable = 0;
	bool forwarding = false;
	bool backwarding = false;
	bool jumpingidle = false;
	bool jumpingright = false;
	bool jumpingleft = false;
	bool lping = false;
	bool mping = false;
	bool hping = false;
	bool lking = false;
	bool mking = false;
	bool hking = false;
	bool lpcring = false;
	bool mpcring = false;
	bool hpcring = false;
	bool lkcring = false;
	bool mkcring = false;
	bool hkcring = false;
	bool crouching = false;
	bool punching = false;
	bool kicking = false;
	int blocking = 0;
	bool freezing = false;
	bool knockdown = false;
	bool justwon = false;
	//ryu
	bool hadouking = false;
	bool hadouking2 = false;//le fet pk no vull borrar el que as fet am el numero 1
	//zangief
	
	int playerhittedcounter = 0;
	//colliders
	Collider* playercollider = nullptr;
	Collider* pdamagecollider = nullptr;
	//Collider* player1kcik = nullptr;
	//Collider* player2collider = nullptr;

	//hadouken
	Animation playerhadouken;
	//movement
	Animation idle;
	Animation forward;
	Animation backward;
	Animation crouch;
	Animation hittedcrouch;
	Animation hittednormal;
	Animation hittedknockdown;
	Animation turning;
	Animation jump;
	Animation jump_frontflip;
	Animation block;

	Animation KO;
	Animation victory;
	//punches
	Animation low_punch;
	Animation mid_punch;
	Animation high_punch;
		Animation low_close_punch;
		Animation mid_close_punch;
		Animation high_close_punch;
			Animation low_jump_punch;
			Animation mid_jump_punch;
			Animation high_jump_punch;
				Animation low_crouch_punch;
				Animation mid_crouch_punch;		//
				Animation high_crouch_punch;	//share animation
					Animation jumping_punch;
					Animation jumping_forward_highpunch;

	iPoint punchpos;
			
	//kicks
	Animation low_kick;
	Animation mid_kick;
	Animation high_kick;
		Animation low_close_kick;
		Animation mid_close_kick;
		Animation high_close_kick;
			Animation low_crouch_kick;		//
			Animation mid_crouch_kick;		//
			Animation high_crouch_kick;		//share animation
				Animation jumping_kick;

	//specials
	Animation spinninglariat;
	Animation siberiansplash;
	Animation jumpheadbutt;
	Animation kneedrop;
	Animation bitegrab;
	Animation facegrab;
	Animation chestgrab;
	Animation suplex;
	Animation piledriver;
	Animation deadlydrive;

	fPoint position;

	/*void playerRotation(ModulePlayer *foe) {
		if (foe == nullptr)
			return;
		if (this->position.x < foe->position.x && lookingright == false) { //TURN LEFT TO RIGHT
			current_animation = &turning;
			if (current_animation->Finished() == true)
				lookingright = true;
		}
		else if (this->position.x > foe->position.x && lookingright == true) { //TURN RIGHT TO LEFT
			current_animation = &turning;
			if (current_animation->Finished() == true)
				lookingright = false;
		}
	}*/
	//Audios
	Mix_Chunk* lowattack = nullptr;			//punch or kick that you miss (you don't hit anything)
	Mix_Chunk* midattack = nullptr;			//punch or kick that you miss (you don't hit anything)	// needed
	Mix_Chunk* highattack = nullptr;	//high punch that you miss (you don't hit anything)

	Mix_Chunk* lowpunchhit = nullptr;		//triggers when low punch collides with enemy
	Mix_Chunk* midpunchhit = nullptr;		//triggers when mid punch collides with enemy			//needed
	Mix_Chunk* highpunchhit = nullptr;		//triggers when high punch collides with enemy

	Mix_Chunk* lowkickhit = nullptr;		//triggers when low kick collides with enemy
	Mix_Chunk* midkickhit = nullptr;		//triggers when mid kick collides with enemy			//needed
	Mix_Chunk* highkickhit = nullptr;		//triggers when high kick collides with enemy

	Mix_Chunk* hadoukenaudio = nullptr;		//triggers when player throws hadouken					//needed
	Mix_Chunk* hadoukenhit = nullptr;		//triggers when hadouken collider hits the enemy (so i think it should go to Particles.h maybe, idk)
	Mix_Chunk* jumpgrounded = nullptr;
	//player Buttons
	int leftButton;
	int rightButton;
	int upButton;
	int downButton;
	int lp;
	int mp;
	int hp;
	int lk;
	int mk;
	int hk;
	int startButton;
	int specialButton;
	int godModeOnButton;
	int godModeOffButton;

	int collidertype;
	//function declarations
	//void renderPlayerOnScreen(ModulePlayer* player);
};

#endif