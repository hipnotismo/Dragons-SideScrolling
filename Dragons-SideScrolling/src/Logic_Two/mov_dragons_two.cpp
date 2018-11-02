#include "mov_dragons_two.h"

#include <ctime>
#include <iostream>
#include <cmath>

#include "raylib.h"

#include "screen\GameplayTwo/gameplay_two.h"

namespace Game
{
	namespace Logic_dragon_Two
	{
		void mov_dragon_two()
		{
			using namespace Gameplay_two;
			//using namespace Gameplay_Two;
			static float delta_y;
			static float delta_x;
			static float position_y = 0.0f;
			static const int maxPosition_y = 900;
			static const int position_x = 1000;
			static const int aceleration = 200;
			static const int degrees = 90;

			static float delta2_y;
			static float delta2_x;
			static float position2_y = 0.0f;
			static const int maxPosition2_y = 900;
			static const int position2_x = 1000;
			static const int aceleration2 = 200;
			static const int degrees2 = 90;

			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				if (position_y > 0)
				{
					position_y -= 400;
				}
			}
			else
			{

				if (position_y < maxPosition_y)
				{
					position_y += 1;
				}
			}

			if (IsKeyPressed(KEY_SPACE))
			{
				if (position2_y > 0)
				{
					position2_y -= 400;
				}
			}
			else
			{

				if (position2_y < maxPosition2_y)
				{
					position2_y += 1;
				}
			}
			delta_y = player.destRec.y - position_y;
			delta_x = player.destRec.x - position_x;
			player.rotation = (atan2(delta_y, delta_x)*RAD2DEG) - degrees;
			player.speed.x = sin(player.rotation*DEG2RAD);
			player.speed.y = cos(player.rotation*DEG2RAD) * 5;
			player.acceleration = aceleration;
			player.position.y -= (player.speed.y*player.acceleration)* GetFrameTime();

			delta2_y = player2.destRec.y - position2_y;
			delta2_x = player2.destRec.x - position2_x;
			player2.rotation = (atan2(delta2_y, delta2_x)*RAD2DEG) - degrees;
			player2.speed.x = sin(player2.rotation*DEG2RAD);
			player2.speed.y = cos(player2.rotation*DEG2RAD) * 5;
			player2.acceleration = aceleration;
			player2.position2.y -= (player2.speed.y*player.acceleration)* GetFrameTime();
		}
	}
}
