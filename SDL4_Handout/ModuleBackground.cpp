#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleBackground.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleBackground::ModuleBackground()
{
	// ground
	ground.x = 8;
	ground.y = 391;
	ground.w = 896;
	ground.h = 72;

	// Background / sky
	background.x = 72;
	background.y = 208;
	background.w = 768;
	background.h = 176;

	//girl animation
	girl.PushBack({ 624, 16, 55, 31 });
	girl.PushBack({ 624, 80, 55, 31 });
	girl.PushBack({ 624, 144, 55, 31 });
	girl.PushBack({ 624, 80, 55, 31 });
	girl.PushBack({ 624, 16, 55, 31 });
	girl.speed = 0.05f;
	// flag animation
	flag.PushBack({848, 208, 40, 40});
	flag.PushBack({848, 256, 40, 40});
	flag.PushBack({848, 304, 40, 40});
	flag.speed = 0.08f;

	// Ship
	ship.x = 8;
	ship.y = 24;
	ship.w = 520;
	ship.h = 180;
	/*ship.PushBack({ 8, 12, 520, 180 });
	flag.PushBack({ 8, 24, 520, 180 });
	flag.speed = 0.05f;*/
	//ship.y = 0;
	//ship.y = 12;
	//ship.y = 24;
}

ModuleBackground::~ModuleBackground()
{}

// Load assets
bool ModuleBackground::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("ken_stage.png");
	return ret;
}

// Update: draw background
update_status ModuleBackground::Update()
{
	// Draw everything --------------------------------------
	App->render->Blit(graphics, 0, 0, &background, 0.75f); // sea and sky
	App->render->Blit(graphics, 560, 8, &(flag.GetCurrentFrame()), 0.75f); // flag animation
	App->render->Blit(graphics, 0, 0, &ship , 0.75f);//ship
	//ship movement
	shipmovement += 0.125f;
	if (shipmovement == 1)
		ship.y = shipYpos2;
	if (shipmovement == 2)
		ship.y = shipYpos3;
	if (shipmovement == 4)
		ship.y = shipYpos4;
	if (shipmovement == 5)
		ship.y = shipYpos5;
	if (shipmovement == 8) {
		ship.y = shipYpos1;
		shipmovement = 0;
	}
	App->render->Blit(graphics, 192, 79, &(girl.GetCurrentFrame()), 0.75f);
	// TODO 2: Draw the ship from the sprite sheet with some parallax effect
	// TODO 3: Animate the girl on the ship (see the sprite sheet)
	
	App->render->Blit(graphics, 0, 170, &ground);

	return UPDATE_CONTINUE;
}