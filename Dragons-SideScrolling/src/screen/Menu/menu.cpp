#include "screen\Menu\menu.h"

#include "raylib.h"

#include "screen\Gameplay\gameplay.h"
#include "Game\game.h"

namespace Game
{
	bool music = true;
	namespace initMenu
	{
		static bool settings = false;
		static int fontSizeTitle = 0;
		static int fontSize = 0;
		static bool playButtonAnimationOn;
		static bool helpButtonAnimationOn;
		static bool exitButtonAnimationOn;
		static bool muteOnButtonAnimationOn;
		static bool quitButtonAnimationOn;
		static bool creditsButtonAnimationOn;
		Texture2D fond;
		Texture2D play;
		Texture2D negativePlay;
		Texture2D credits;
		Texture2D negativeCredits;
		Texture2D help;
		Texture2D negativeHelp;
		Texture2D exit;
		Texture2D negativeExit;
		Texture2D mute;
		Texture2D negativeMute;
		Texture2D on;
		Texture2D negativeOn;
		Texture2D quit;
		Texture2D negativeQuit;
		Rectangle recplay;
		Rectangle recCredits;
		Rectangle recHelp;
		Rectangle recMuteOn;
		Rectangle recExit;
		Rectangle recQuit;

		static bool firstInit = true;
		void initSize()
		{
			if (firstInit)
			{
				firstInit = false;
				fontSizeTitle = 50;
				fontSize = 20;

				playButtonAnimationOn = true;
				helpButtonAnimationOn = true;
				exitButtonAnimationOn = true;
				muteOnButtonAnimationOn = true;
				fond = LoadTexture("res/menu.png");
				play = LoadTexture("res/play.png");
				negativePlay = LoadTexture("res/play2.png");
				credits = LoadTexture("res/credits.png");
				negativeCredits = LoadTexture("res/credits2.png");
				help = LoadTexture("res/help.png");
				negativeHelp = LoadTexture("res/help2.png");
				exit = LoadTexture("res/exit.png");
				negativeExit = LoadTexture("res/exit2.png");
				mute = LoadTexture("res/mute.png");
				negativeMute = LoadTexture("res/mute2.png");
				on = LoadTexture("res/on.png");
				negativeOn = LoadTexture("res/on2.png");
				quit = LoadTexture("res/quit.png");
				negativeQuit = LoadTexture("res/quit2.png");
				//recplay = {(float)play.width,(float)play.height,(float)Gameplay::screenWidth / 2 - play.width / 2 ,(float)Gameplay::screenHeight / 2 - play.height / 2 };
				recplay = { (float)halfScreenWidth - play.width / 2,(float)screenHeight / 2 - play.height,(float)play.width,(float)play.height };
				recCredits = { (float)halfScreenWidth - play.width / 2,(float)screenHeight / 2,(float)play.width,(float)play.height };
				recHelp = { (float)halfScreenWidth - help.width / 2,(float)screenHeight / 2 + help.height + 5,(float)help.width,(float)help.height };
				recMuteOn = { (float)halfScreenWidth - mute.width / 2,(float)screenHeight / 2 + mute.height * 2 + 5,(float)mute.width,(float)mute.height };
				recExit = { (float)halfScreenWidth - exit.width / 2,(float)screenHeight / 2 + exit.height * 3 + 5,(float)exit.width,(float)exit.height };
				recQuit = { (float)screenWidth - (screenWidth / 100 * 25) ,(float)screenHeight / 2 + help.height + help.height / 2 + 5,(float)quit.width,(float)quit.height };
			}
		}

		static void drawTextMenu()
		{
			DrawTexture(fond, 0, 0, WHITE);
			if (playButtonAnimationOn)
			{
				DrawTexture(play, halfScreenWidth - play.width / 2, screenHeight / 2 - play.height, WHITE);
			}
			else
			{
				DrawTexture(negativePlay, halfScreenWidth - negativePlay.width / 2, screenHeight / 2 - play.height, WHITE);
			}
			if (creditsButtonAnimationOn)
			{
				DrawTexture(credits, halfScreenWidth - credits.width / 2, screenHeight / 2, WHITE);
			}
			else
			{
				DrawTexture(negativeCredits, halfScreenWidth - negativeCredits.width / 2, screenHeight / 2, WHITE);
			}

			if (helpButtonAnimationOn)
			{
				DrawTexture(help, halfScreenWidth - help.width / 2, screenHeight / 2 + help.height + 5, WHITE);
			}
			else
			{
				DrawTexture(negativeHelp, halfScreenWidth - help.width / 2, screenHeight / 2 + help.height + 5, WHITE);
			}
			if (muteOnButtonAnimationOn)
			{
				if (music)
				{
					DrawTexture(mute, halfScreenWidth - mute.width / 2, screenHeight / 2 + mute.height * 2 + 5, WHITE);
				}
				else
				{
					DrawTexture(on, halfScreenWidth - mute.width / 2, screenHeight / 2 + mute.height * 2 + 5, WHITE);
				}

			}
			else
			{
				if (music)
				{
					DrawTexture(negativeMute, halfScreenWidth - mute.width / 2, screenHeight / 2 + mute.height * 2 + 5, WHITE);
				}
				else
				{
					DrawTexture(negativeOn, halfScreenWidth - mute.width / 2, screenHeight / 2 + mute.height * 2 + 5, WHITE);
				}
			}
			if (exitButtonAnimationOn)
			{
				DrawTexture(exit, halfScreenWidth - exit.width / 2, screenHeight / 2 + exit.height * 3 + 5, WHITE);
			}
			else
			{
				DrawTexture(negativeExit, halfScreenWidth - exit.width / 2, screenHeight / 2 + exit.height * 3 + 5, WHITE);
			}
			DrawText("v1.0", screenWidth - (screenWidth / 100 * 5) - (MeasureText("v1.0", 25) / 2), screenHeight - screenHeight / 20, 25, BLACK);
			if (settings)
			{
				DrawRectangle(halfScreenWidth - (MeasureText(" Player 2: KeyUp -> Up / KeyDown -> Down ", fontSize) / 2) - 5, screenHeight - screenHeight / 3, MeasureText(" Player 2: KeyUp -> Up / KeyDown -> Down ", fontSize) + 10, fontSize * 3 + 15, GRAY);
				DrawRectangleLines(halfScreenWidth - (MeasureText(" Player 2: KeyUp -> Up / KeyDown -> Down ", fontSize) / 2) - 5, screenHeight - screenHeight / 3, MeasureText(" Player 2: KeyUp -> Up / KeyDown -> Down ", fontSize) + 10, fontSize * 3 + 15, GOLD);
				DrawText("RightClick -> Up", halfScreenWidth - (MeasureText("RightClick -> up", fontSize) / 2), screenHeight - screenHeight / 3 + fontSize + 5, fontSize, WHITE);
				DrawText("Space -> Up", halfScreenWidth - (MeasureText("Space -> up", fontSize) / 2), screenHeight - screenHeight / 3 + fontSize + 5, fontSize, WHITE);
				DrawText("Win-> 15 Points", halfScreenWidth - (MeasureText("Win-> 15 Points", fontSize) / 2), screenHeight - screenHeight / 3 + fontSize * 2 + 5, fontSize, WHITE);
				if (quitButtonAnimationOn)
				{
					DrawTexture(quit, screenWidth - (screenWidth / 100 * 25), screenHeight / 2 + help.height + help.height / 2, WHITE);
				}
				else
				{
					DrawTexture(negativeQuit, screenWidth - (screenWidth / 100 * 25), screenHeight / 2 + help.height + help.height / 2, WHITE);
				}
			}
		}

		void UpdateMenu()
		{

			initSize();
			if (!settings)
			{
				if (CheckCollisionPointRec(GetMousePosition(), recplay))
				{
					if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
					{
						screen = CHANGE;
					}
					playButtonAnimationOn = false;
				}
				else
				{
					playButtonAnimationOn = true;
				}
				if (CheckCollisionPointRec(GetMousePosition(), recCredits))
				{
					if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
					{
						screen = CREDITS;
					}
					creditsButtonAnimationOn = false;
				}
				else
				{
					creditsButtonAnimationOn = true;
				}
				if (CheckCollisionPointRec(GetMousePosition(), recHelp))
				{
					if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
					{
						settings = !settings;
					}
					helpButtonAnimationOn = false;
				}
				else
				{
					helpButtonAnimationOn = true;
				}
				if (CheckCollisionPointRec(GetMousePosition(), recMuteOn))
				{
					if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
					{
						music = !music;
					}
					muteOnButtonAnimationOn = false;
				}
				else
				{
					muteOnButtonAnimationOn = true;
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
			else
			{
				if (CheckCollisionPointRec(GetMousePosition(), recQuit))
				{
					if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
					{
						settings = !settings;
					}
					quitButtonAnimationOn = false;
				}
				else
				{
					quitButtonAnimationOn = true;
				}
			}
		}
		void DrawMenu()
		{
			drawTextMenu();
		}
		void UnloadTextureMenu()
		{
			UnloadTexture(fond);
			UnloadTexture(play);
			UnloadTexture(negativePlay);
			UnloadTexture(help);
			UnloadTexture(negativeHelp);
			UnloadTexture(exit);
			UnloadTexture(negativeExit);
			UnloadTexture(mute);
			UnloadTexture(negativeMute);
			UnloadTexture(on);
			UnloadTexture(negativeOn);
		}
	}
}