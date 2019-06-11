#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleWindow.h"
#include "ModuleInput.h"
#include "SDL/include/SDL.h"
#include "ModulePlayer.h"

ModuleRender::ModuleRender() : Module()
{
	camera.x = camera.y = 0;
	camera.w = SCREEN_WIDTH;
	camera.h = SCREEN_HEIGHT;
}

// Destructor
ModuleRender::~ModuleRender()
{}

// Called before render is available
bool ModuleRender::Init()
{
	LOG("Creating Renderer context");
	bool ret = true;
	Uint32 flags = 0;

	if(REN_VSYNC == true)
	{
		flags |= SDL_RENDERER_PRESENTVSYNC;
	}

	renderer = SDL_CreateRenderer(App->window->window, -1, flags);

	SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH * SCREEN_SIZE, SCREEN_HEIGHT * SCREEN_SIZE);
	
	if(renderer == NULL)
	{
		LOG("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}

	return ret;
}

// Called every draw update
update_status ModuleRender::PreUpdate()
{
	SDL_RenderClear(renderer);

	return update_status::UPDATE_CONTINUE;
}

update_status ModuleRender::Update()	
{
	int speed = 3;

	/*if(App->input->keyboard[SDL_SCANCODE_6] == KEY_STATE::KEY_REPEAT)
		camera.y += speed;

	if(App->input->keyboard[SDL_SCANCODE_Y] == KEY_STATE::KEY_REPEAT)
		camera.y -= speed;

	if(App->input->keyboard[SDL_SCANCODE_T] == KEY_STATE::KEY_REPEAT)
		camera.x += speed;

	if(App->input->keyboard[SDL_SCANCODE_U] == KEY_STATE::KEY_REPEAT)
		camera.x -= speed;*/
	//camera.x = (App->player2->position.x - App->player->position.x) / 2;
	//camera.x = -App->player->position.x;
	//camera.x = (App->input->mPosX - SCREEN_WIDTH);
	return update_status::UPDATE_CONTINUE;
}

update_status ModuleRender::PostUpdate()
{
	SDL_RenderPresent(renderer);
	return update_status::UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleRender::CleanUp()
{
	LOG("Destroying renderer");

	//Destroy window
	if(renderer != NULL)
	{
		SDL_DestroyRenderer(renderer);
	}

	return true;
}


// Blit to screen
bool ModuleRender::Blit(SDL_Texture* texture, int x, int y, SDL_Rect* section, float speed, bool isFlipped, bool use_camera)
{
	bool ret = true;
	SDL_Rect rect;
	rect.x = (int)(camera.x * speed) + x * SCREEN_SIZE;
	rect.y = (int)(camera.y * speed) + y * SCREEN_SIZE;

	if (use_camera)
	{
		if (isFlipped) {
			rect.x = (int)(-camera.x * speed) + x * SCREEN_SIZE /*+ section->w*/;
			rect.y = (int)(-camera.y * speed) + y * SCREEN_SIZE /*+ section->h*/;
		}
		else {
			rect.x = (int)(-camera.x * speed) + x * SCREEN_SIZE;
			rect.y = (int)(-camera.y * speed) + y * SCREEN_SIZE;
		}
	}
	else
	{
		if (isFlipped) {
			rect.x = x * SCREEN_SIZE;
			rect.y = y * SCREEN_SIZE;
		} 
		else {
			rect.x = x * SCREEN_SIZE;
			rect.y = y * SCREEN_SIZE;
		}
	}

	if(section != NULL)
	{
		rect.w = section->w;
		rect.h = section->h;
	}
	else
	{
		SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
	}
	if (!isFlipped) {
		rect.w *= SCREEN_SIZE;
		rect.h *= SCREEN_SIZE;
	}
	else {
		rect.w *= -SCREEN_SIZE;
		rect.h *= SCREEN_SIZE;
	}

	/*SDL_RendererFlip flip = SDL_FLIP_NONE;
	if (isFlipped == true)
		flip = SDL_FLIP_HORIZONTAL;*/

	if(SDL_RenderCopyEx(renderer, texture, section, &rect, NULL, NULL, SDL_FLIP_NONE) != 0)
	{
		LOG("Cannot blit to screen. SDL_RenderCopy error: %s", SDL_GetError());
		ret = false;
	}

	return ret;
}

bool ModuleRender::DrawQuad(const SDL_Rect& rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a, bool use_camera, bool isFlipped)
{
	bool ret = true;

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(renderer, r, g, b, a);

	SDL_Rect rec(rect);
	if (use_camera)
	{
		rec.x = (int)(camera.x + rect.x * SCREEN_SIZE);
		rec.y = (int)(camera.y + rect.y * SCREEN_SIZE);
		rec.w *= SCREEN_SIZE;
		rec.h *= SCREEN_SIZE;
	}

	if (SDL_RenderFillRect(renderer, &rec) != 0)
	{
		LOG("Cannot draw quad to screen. SDL_RenderFillRect error: %s", SDL_GetError());
		ret = false;
	}

	return ret;
}
void ModuleRender::StartCameraShake(int duration, float magnitude)
{
	//TODO 1: Store the data and start the shake
	shaking = true;
	shake_duration = duration;
	shake_timer = 0.0f;
	shake_magnitude = magnitude;
}
void ModuleRender::UpdateCameraShake()
{
	//TODO 2: Update the shake timer, stop shaking if we reach the full duration
	//		  Generate a random value and set the camera offset
	if (shake_timer < shake_duration) {
		camera_offset.x = (rand() % 4 - 2) * shake_magnitude / 2;
		camera_offset.y = (rand() % 4 - 2) * shake_magnitude / 2;
		shake_timer++;
	}
	else {
		shaking = false;
		shake_duration = 0.0f;
		shake_timer = 0.0f;
		shake_magnitude = 0.0f;
		camera_offset.x = 0;
		camera_offset.y = 0;
	}
	return;
}

