#include"credits.h"

#include "raylib.h"

#include "screen\Gameplay\gameplay.h"
#include "Game\game.h"
namespace Game
{
	namespace initCredits
	{
		Texture2D fond;
		Rectangle recExit;
		Texture2D exit;
		Texture2D negativeExit;
		Texture2D menu;
		Texture2D negativeMenu;
		Rectangle recMenu;
		static int positionY = screenHeight / 4;
		static bool menuButtonAnimationOn;
		static bool exitButtonAnimationOn;
		static bool firstInit = true;
		
		static int fontSize = 20;
		void initCredits() 
		{
			if (firstInit)
			{
				firstInit = false;
				menu = LoadTexture("res/boton_menu.png");
				negativeMenu = LoadTexture("res/boton_menu2.png");
				exit = LoadTexture("res/exit.png");
				negativeExit = LoadTexture("res/exit2.png");
				fond = LoadTexture("res/menu.png");
				recMenu = { (float)halfScreenWidth - menu.width / 2,(float)screenHeight / 2 ,(float)menu.width,(float)menu.height };
				recExit = { (float)halfScreenWidth - exit.width / 2,(float)screenHeight / 2 + exit.height + 5,(float)exit.width,(float)exit.height };
			}
		}
		void UpdateCredits()
		{
			initCredits();
			if (CheckCollisionPointRec(GetMousePosition(), recMenu))
			{
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				{
					screen = MENU;
				}
				menuButtonAnimationOn = false;
			}
			else
			{
				menuButtonAnimationOn = true;
			}
			if (CheckCollisionPointRec(GetMousePosition(), recExit))
			{
				exitButtonAnimationOn = false;

				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				{
					Game::endGame = !Game::endGame;
				}
			}
			else
			{
				exitButtonAnimationOn = true;
			}
		}
		void DrawCredits() 
		{
			DrawTexture(fond, 0, 0, WHITE);
			if (menuButtonAnimationOn)
			{
				DrawTexture(menu, halfScreenWidth - menu.width / 2,screenHeight / 2, WHITE);
			}
			else
			{
				DrawTexture(negativeMenu, halfScreenWidth  - negativeMenu.width / 2, screenHeight / 2, WHITE);
			}
			if (exitButtonAnimationOn)
			{
				DrawTexture(exit, halfScreenWidth - exit.width / 2, screenHeight / 2 + exit.height + 5, WHITE);
			}
			else
			{
				DrawTexture(negativeExit, halfScreenWidth - exit.width / 2,screenHeight / 2 + exit.height + 5, WHITE);
			}
			DrawText("Programmer: Cusumano Cristian", halfScreenWidth - (MeasureText("Programmer: Cusumano Cristian", fontSize) / 2), positionY , fontSize, GOLD);
			DrawText("Music and Efects By: Cusumano Cristian", halfScreenWidth - (MeasureText("Music and Efects By: Cusumano Cristian", fontSize) / 2), positionY + fontSize*2 + 5, fontSize, GOLD);
			DrawText("Tools: Raylib - BoscaCeoil - MusicMaker - Photoshop",halfScreenWidth - (MeasureText("Tools: Raylib - BoscaCeoil - MusicMaker - Photoshop", fontSize) / 2), positionY + fontSize * 4 + 5, fontSize, GOLD);
			DrawText("v0.2", halfScreenWidth - (MeasureText("v0.1", fontSize) / 2), positionY + fontSize * 13 + 5, fontSize, GOLD);
		}
	}
}