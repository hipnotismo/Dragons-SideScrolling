#ifndef GAMEPLAY_TWO_H
#define GAMEPLAY_TWO_H

#include "raylib.h"

namespace Game
{
	namespace Gameplay_two
	{
		extern bool firstInit;
		extern bool left;
		extern bool right;
		void initGameTwo();
		void updateGameTwo();
		void DrawGameTwo();
		struct Player {
			Texture2D player_texture;
			Vector2 position;
			Vector2 speed;
			float acceleration;
			float rotation;
			Vector3 collider;
			Color color;
			Rectangle sourceRec;
			Rectangle destRec;
			Rectangle frameRec;
			Vector2 origin;

		};
		struct Player2 {
			Texture2D player2_texture;
			Vector2 position2;
			Vector2 speed;
			float acceleration;
			float rotation;
			Vector3 collider;
			Color color;
			Rectangle sourceRec;
			Rectangle destRec;
			Rectangle frameRec;
			Vector2 origin;

		};
		extern Player player;
		extern Player2 player2;

		extern float dragonHeight;
	}
}
#endif