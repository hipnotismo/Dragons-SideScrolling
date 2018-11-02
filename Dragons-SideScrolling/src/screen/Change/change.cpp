#include "screen\Change\change.h"

#include "raylib.h"

#include "screen\Gameplay\gameplay.h"
#include "Game\game.h"

namespace Game

{
	namespace initChange
	{
		static Rectangle rec1;
		static Rectangle rec2;
		static 	Vector2 mousePoint;

		void UpdateChange()
		{

			DrawChange();
			
			mousePoint = GetMousePosition();
			rec1.x = screenWidth / 2 - 50;
			rec1.y = screenHeight / 2;
			rec1.height = 50;
			rec1.width = 100;

			rec2.x = screenWidth / 2 - 50;
			rec2.y = screenHeight / 2 + 80;
			rec2.height = 50;
			rec2.width = 100;

			if (CheckCollisionPointRec(mousePoint, rec1))
			{

				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				{
					screen = GAME;
				}
			}
			if (CheckCollisionPointRec(mousePoint, rec2))
			{

				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				{
					screen = GAMETWO;
				}
			}
			


		}

		void DrawChange()
		{
			BeginDrawing();

			ClearBackground(RAYWHITE);


			DrawRectangle(rec1.x, rec1.y, rec1.width, rec1.height, BLACK);
			DrawRectangle(rec2.x, rec2.y, rec2.width, rec2.height, BLACK);

			DrawText("One player", rec1.x + 18, rec1.y + 10, 18, WHITE);
			DrawText("Two players", rec2.x + 5, rec2.y + 10, 18, WHITE);
			
			EndDrawing();
		}

	}
}