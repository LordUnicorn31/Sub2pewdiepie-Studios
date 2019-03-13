#include <iostream>

#include "SDL/include/SDL.h"
#include "SDL_Image/include/SDL_image.h"
#include "SDL_Mixer/include/SDL_mixer.h"

#pragma comment(lib, "SDL/lib/x86/SDL2.lib")
#pragma comment(lib, "SDL/lib/x86/SDL2main.lib")
#pragma comment(lib, "SDL_Image/lib/x86/SDL2_image.lib")
#pragma comment(lib, "SDL_Mixer/lib/x86/SDL2_mixer.lib")

enum Key_State
{
	KEY_IDLE,
	KEY_DOWN,
	KEY_REPEAT,
	KEY_UP
};

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;
SDL_Surface* surface = nullptr;
SDL_Surface* loadedImage = nullptr;

//Textures
SDL_Texture* bg_texture = nullptr;
SDL_Texture* ship_texture = nullptr;
SDL_Texture* bullet_texture = nullptr;

Mix_Music* Music = nullptr;
Mix_Chunk* bullet_sound = nullptr;
//Input
Key_State keys[300];

//Rects
SDL_Rect bg_rect = { 0, 0, 1920, 1080 };
SDL_Rect ship_rect = { 10, 10, 160, 160 };
SDL_Rect bullet_rect = { -50, -50, 36, 16 };
bool shot = false;

bool InitSDL()
{
	//Initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("Wrong initialization");
		return false;
	}
	else
	{
		window = SDL_CreateWindow("SDLTest", 0, 0, 1920, 1080, SDL_WINDOW_SHOWN);
		if (window == nullptr)
		{
			printf("Window not created");
			return false;
		}
		else
		{
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			//Initialize SDL_Image
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) & imgFlags))
			{
				printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
				return false;
			}
			else
			{
				surface = SDL_GetWindowSurface(window);
			}
			if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
			{
				printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
				return false;
			}
		}
	}

	return true;
}

void CleanupSDL()
{
	SDL_Quit();
	IMG_Quit();
}

void InitVariables()
{
	ship_texture = IMG_LoadTexture(renderer, "Textures/spaceShip.png");
	bullet_texture = IMG_LoadTexture(renderer, "Textures/bullet.png");
	bg_texture = IMG_LoadTexture(renderer, "Textures/background.png");
	Music = Mix_LoadMUS("Music/music.wav");
	bullet_sound = Mix_LoadWAV("Music/bullet_sound.wav");
	
}

bool ProcessInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case(SDL_QUIT):
		{
			return false;
		}
		}
	}

	const Uint8* state = SDL_GetKeyboardState(nullptr);
	for (int i = 0; i < 300; ++i)
	{
		if (state[i])
		{
			keys[i] = (keys[i] == KEY_IDLE ? KEY_DOWN : KEY_REPEAT);
		}
		else
		{
			keys[i] = (keys[i] == KEY_REPEAT ? KEY_UP : KEY_IDLE);
		}
	}

	return true;
}

void Draw()
{
	SDL_RenderClear(renderer);

	SDL_RenderCopy(renderer, bg_texture, nullptr, &bg_rect);
	SDL_RenderCopy(renderer, ship_texture, nullptr, &ship_rect);
	SDL_RenderCopy(renderer, bullet_texture, nullptr, &bullet_rect);

	SDL_RenderPresent(renderer);
}

void UpdateLogic()
{
	if (keys[SDL_SCANCODE_D] == KEY_REPEAT)
	{
		ship_rect.x += 3;
		if (ship_rect.x > 1920 - ship_rect.w) ship_rect.x = 1920 - ship_rect.w;

	}
	if (keys[SDL_SCANCODE_A] == KEY_REPEAT)
	{
		ship_rect.x -= 3;
		if (ship_rect.x < 0) ship_rect.x = 0;
	}
	if (keys[SDL_SCANCODE_W] == KEY_REPEAT)
	{
		ship_rect.y -= 3;
		if (ship_rect.y < 0) ship_rect.y = 0;

	}
	if (keys[SDL_SCANCODE_S] == KEY_REPEAT)
	{
		ship_rect.y += 3;
		if (ship_rect.y > 1080 - ship_rect.h) ship_rect.y = 1080 - ship_rect.h;

	}
	if (keys[SDL_SCANCODE_SPACE] == KEY_DOWN)
	{
		bullet_rect = { ship_rect.x + ship_rect.w, ship_rect.y + ship_rect.h / 2, bullet_rect.w, bullet_rect.h };
		shot = true;
	}

	if (shot)
	{
		bullet_rect.x += 10;
	}
}

int main(int argc, char* argv[])
{
	if (InitSDL())
	{
		InitVariables();
		while (ProcessInput())
		{
			UpdateLogic();
			Draw();
		}
	}

	CleanupSDL();
	return 0;
}

