#include "Game\game.h"

#include "raylib.h"

#include "screen\Menu\menu.h"
#include "screen\Win\win.h"
#include "screen\Gameplay\gameplay.h"
#include "screen\Credits\credits.h"
#include "screen\Defeat\defeat.h"
#include"screen/Change/change.h"
//#define MUSIC_ON
namespace Game
{
	static void Init();
	static void Update();
	static void Draw();
	static void Close();
	bool endGame = false;
	Texture2D texture;
	Music MusicLoop;
	int screenWidth = 600;
	int screenHeight = 800;
	int halfScreenWidth = screenWidth / 2;
	void Init() 
	{
		InitWindow(screenWidth, screenHeight, "Dragons");
#ifdef MUSIC_ON
		InitAudioDevice();
		MusicLoop = LoadMusicStream("res/music.ogg");
		PlayMusicStream(MusicLoop);
#endif
	
	}

	void Update() 
	{
#ifdef MUSIC_ON
		if (music) 
		{
			UpdateMusicStream(MusicLoop);
		}
#endif
		switch (screen)
		{
		case GAME:
			if (Gameplay::firstInit)
			{


				Gameplay::initGame();
				Gameplay::firstInit = false;
			}
			Gameplay::updateGame();
			break;
		case MENU:
			initMenu::UpdateMenu();
			break;
		case WIN:
			initWin::UpdateWin();
			break;
		case CREDITS:
			initCredits::UpdateCredits();
			break;
		case DEFEAT:
			initDefeat::UpdateDefeat();
			break;
		case CHANGE:
			initChange::UpdateChange();
			break;
		default:
			break;
		}
	}
	
	void Draw() {
		BeginDrawing();
		ClearBackground(RAYWHITE);
		switch (screen)
		{
		case GAME:
			Gameplay::DrawGame();
			break;
		case MENU:
			initMenu::DrawMenu();
			break;
		case WIN:
			initWin::DrawWin();
			break;
		case CREDITS:
			initCredits::DrawCredits();
			break;
		case DEFEAT:
			initDefeat::DrawDefeat();
			break;
		case CHANGE:
			initChange::DrawChange();
			break;
		}
		EndDrawing();
	}



	void Close() {
#ifdef MUSIC_ON
			UnloadMusicStream(MusicLoop);   // Unload music stream buffers from RAM
			CloseAudioDevice();
#endif
			UnloadTexture(texture);       // Texture unloading
			initMenu::UnloadTextureMenu();
			initWin::closeWin();
			initDefeat::CloseDefeat();
			CloseWindow();
	}
	void LoadScreen()
	{
		Init();
		// Main game loop
		while (!WindowShouldClose() && !endGame)    // Detect window close button or ESC key
		{
			Update();
			Draw();
		}
		//--------------------------------------------------------------------------------------   
		Close();
		// Close window and OpenGL context
		//--------------------------------------------------------------------------------------
	}

}
