#define _CRTDBG_MAP_ALLOC
#include "Globals.h"
//#include "stdio.h"
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


ModuleUi::ModuleUi()
{
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
		App->fonts->BlitText(190,29, orange_font, "99");
		App->fonts->BlitText(70,3, blueorange_font, "1P");
		App->fonts->BlitText(130, 3, blueorange_font, "0");
		App->fonts->BlitText(155, 3, blueorange_font, "NIN");
		App->fonts->BlitText(198, 3, blueorange_font, "50000");
		App->fonts->BlitText(250, 3, blueorange_font, "2P");
		App->fonts->BlitText(305, 3, blueorange_font, "0");
	}
	return UPDATE_CONTINUE;
}
