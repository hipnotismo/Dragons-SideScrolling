#include "mov_ship.h"

#include <ctime>
#include <iostream>
#include <cmath>

#include "raylib.h"

#include "screen/Gameplay/gameplay.h"

namespace GameInit 
{
	namespace Logic_ship 
	{
		void mov_ship()
		{
			float delta_y;
			float delta_x;
			static float position_y=0.0f;
			static int maxPosition_y = 900;
			static int position_x = 600;
			using namespace Gameplay;
		
			//player.speed.x = sin(player.rotation*DEG2RAD);
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				if (position_y > 0)
				{
					position_y -= 400.0f;
				}
			}
			else
			{
				
				if (position_y < maxPosition_y)
				{
					position_y += 0.5f;

				}
			}
			
			delta_y = player.destRec.y - position_y;
			delta_x = player.destRec.x - position_x;
			player.rotation = (atan2(delta_y, delta_x)*RAD2DEG)-90;
			player.speed.x = sin(player.rotation*DEG2RAD);
			player.speed.y = cos(player.rotation*DEG2RAD);
			//player.speed.y = cos(player.rotation*DEG2RAD);
		
			player.acceleration = 300;
			//player.position.x += (player.speed.x*player.acceleration)* GetFrameTime();
			player.position.y -= (player.speed.y*player.acceleration)* GetFrameTime();
			if (player.position.x > screenWidth + shipHeight) player.position.x = -(shipHeight);
			else if (player.position.x < -(shipHeight)) player.position.x = screenWidth + shipHeight;
			if (player.position.y >(screenHeight + shipHeight)) player.position.y = -(shipHeight);
			else if (player.position.y < -(shipHeight)) player.position.y = screenHeight + shipHeight;
		}
	}
}
