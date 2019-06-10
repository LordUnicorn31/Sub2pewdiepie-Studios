#define _CRTDBG_MAP_ALLOC
#include "Globals.h"
#include "Application.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleSceneRyu.h"
#include "ModulePlayer.h"
#include "ModuleFadeToBlack.h"
#include "ModuleCongratsScreen.h"
#include "ModuleAudio.h"
#include "ModuleSceneZangief.h"
#include "ModuleUi.h"
#include "ModuleFonts.h"
#include "SDL/include/SDL.h"


ModuleUi::ModuleUi()
{
	win_hand.x = 107;
	win_hand.y = 12;
	win_hand.h = 17;
	win_hand.w = 16;
	//ui bars		//V
	uibg.x = 0;		//V
	uibg.y = 0;		//V
	uibg.w = 194;	//V
	uibg.h = 14;	//V
	uip1.x = 1;		//V
	uip1.y = 15;	//V
	uip1.w = 88;	//V
	uip1.h = 8;		//V
	uip2.x = 1;		//V
	uip2.y = 15;	//V
	uip2.w = 88;	//V
	uip2.h = 8;		//V
	next_round = false;
	to_next_round = true;
	round_index = -1;
}

ModuleUi::~ModuleUi()
{}

bool ModuleUi::Init() {
	orange_font = App->fonts->Load("media_files/fonts/orange_font.png", "ABCDEFGHI KLMNOP RSTU WYZ.!, 0123456789", 1);
	grey_font = App->fonts->Load("media_files/fonts/grey_font.png", "ABCDEFGHI KLMNOP RSTU WYZ.!,'?012345678", 1);
	blueorange_font= App->fonts->Load("media_files/fonts/blueorange_font.png", "ABCDEFGHI KLMNOP RSTUY:,YZ0123456789. @", 1);
	red_font= App->fonts->Load("media_files/fonts/red_font.png", "ABCDEFGHI KLMNOP RSTUV XYZ0123456789.,", 1);
	white_font= App->fonts->Load("media_files/fonts/white_font.png", "ABCDEFGHI KLMNOP RSTUV XYZ0123456789.,", 1);
	green_font= App->fonts->Load("media_files/fonts/green_font.png", "ABCDEFGHI KLMNOP RSTUV XYZ0123456789.,", 1);
	uitext = App->textures->Load("media_files/HPBAR.png"); //V
	return true;
	//HP update mechanic
}
// UnLoad assets
bool ModuleUi::CleanUp()
{
	App->fonts->UnLoad(orange_font);
	App->fonts->UnLoad(grey_font);
	App->fonts->UnLoad(blueorange_font);
	App->fonts->UnLoad(red_font);
	App->fonts->UnLoad(white_font);
	App->fonts->UnLoad(green_font);
	App->textures->Unload(uitext);
	return true;
}

// Update: draw background
update_status ModuleUi::Update()
{
	if (App->scene_Zangief->IsEnabled()) {
		current_time = SDL_GetTicks();
		if (prevHP1 > App->player->life)
		{
			prevHP1--;
		}
		else if (prevHP1 < App->player->life)
		{
			prevHP1++;
		}
		uip1.w = (prevHP1 * 0.88); // V
		if (prevHP2 > App->player2->life)
		{
			prevHP2--;
		}
		else if (prevHP2 < App->player2->life)
		{
			prevHP2++;
		}
		uip2.w = (prevHP2 * 0.88); // V
		//sprintf_s(time_text, 10, "%7d", time);
		App->render->Blit(uitext, 100, 13, &uibg);
		App->render->Blit(uitext, 101 + (88 - uip1.w), 16, &uip1); //V
		App->render->Blit(uitext, 205, 16, &uip2);
		App->fonts->BlitText(101, 29, blueorange_font, "ZANGIEF");
		App->fonts->BlitText(238, 29,	blueorange_font, "ZANGIEF");
		App->fonts->BlitText(70,3, blueorange_font, "1P");
		App->fonts->BlitText(130, 3, blueorange_font, "0");
		App->fonts->BlitText(155, 3, blueorange_font, "NIN");
		App->fonts->BlitText(198, 3, blueorange_font, "50000");
		App->fonts->BlitText(250, 3, blueorange_font, "2P");
		App->fonts->BlitText(305, 3, blueorange_font, "0");
		if ((App->scene_Zangief->zangief_init_time + 2000) > current_time) {
			App->fonts->BlitText(170, 85, orange_font, round_text[round_index]);
			App->fonts->BlitText(162, 105, red_font, "BATTLE 01");
			App->fonts->BlitText(190, 29, orange_font, "99");
		}
		else if ((App->scene_Zangief->zangief_init_time + 2000) < current_time &&(App->scene_Zangief->zangief_init_time + 3500) >current_time) {
			App->fonts->BlitText(170, 85, orange_font, "FIFHT!");
			App->fonts->BlitText(162, 105, red_font, "BATTLE 01");
			App->fonts->BlitText(190, 29, orange_font, "99");
		}
		else {
			if (App->scene_Zangief->time_index > 0) {
				second +=1.9f;
			}
			if (second>=60) {
				--(App->scene_Zangief->time_index);
				second=0;
			}
			App->fonts->BlitText(190, 29, orange_font, time_text[App->scene_Zangief->time_index]);
		}
		if (App->scene_Zangief->time_index == 0) {
			App->fonts->BlitText(179, 75, red_font, "TIME");
			App->fonts->BlitText(179, 87, red_font, "OVER");
		}
		if (App->scene_Zangief->time_index == 0 && to_next_round) {
			to_next_round = false;
			time_end_round = current_time+8000;
		}
		if (time_end_round < current_time&&App->scene_Zangief->time_index == 0) {
			next_round = true;
		}
		if (next_round) {
			next_round = false;
			App->fade->FadeToBlack(App->scene_Zangief, App->scene_Zangief, 0.5);
		}
		App->render->Blit(uitext, 62, 11, &win_hand);
	}
	return UPDATE_CONTINUE;
}
