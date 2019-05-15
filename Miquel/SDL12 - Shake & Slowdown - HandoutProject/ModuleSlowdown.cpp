#include <math.h>
#include "Globals.h"
#include "Application.h"
#include "ModuleSlowdown.h"
#include "ModuleRender.h"
#include "SDL/include/SDL_render.h"
#include "SDL/include/SDL_timer.h"

ModuleSlowdown::ModuleSlowdown()
{
}

ModuleSlowdown::~ModuleSlowdown()
{}

// Load assets
bool ModuleSlowdown::Start()
{
	return true;
}

// Update: draw background
update_status ModuleSlowdown::PostUpdate()
{
	if (slowing_down)
	{
		UpdateSlowdown();
	}

	return UPDATE_CONTINUE;
}
void ModuleSlowdown::StartSlowdown(int duration, int magnitude)
{
	slowing_down = true;
	slowdown_duration = duration;
	slowdown_timer = 0;
	slowdown_magnitude = magnitude;
}

void ModuleSlowdown::UpdateSlowdown()
{
	if (slowdown_timer < slowdown_duration) {
		SDL_Delay(slowdown_magnitude);
		slowdown_timer++;
	}
	else
	{
		slowing_down = false;
		slowdown_duration = 0;
		slowdown_timer = 0;
		slowdown_magnitude = 0;
	}
	return;
}
