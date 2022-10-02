#include "feather/core.h"
#include "feather/entity.h"
#include "feather/input.h"
#include "feather/text.h"
#include "feather/sound.h"
#include "feather/debug.h"
#include "feather/util.h"
#include "feather/vector.h"

using namespace std;

Entity Player;
Entity Ball1;
Entity Ball2;
Entity Ball3;
Entity Ball4;
Entity Ball5;
Entity Ball6;

Vector offset;

int cash;

//Runs on first frame
void Begin(){
	Player.Create("assets/player.png", 0, 0, 128, 128);

	Ball1.Create("assets/ball.png", range(0, 1920), range(0, 1080), 256, 256);
	Ball2.Create("assets/ball.png", range(0, 1920), range(0, 1080), 256, 256);
	Ball3.Create("assets/ball.png", range(0, 1920), range(0, 1080), 256, 256);
	Ball4.Create("assets/ball.png", range(0, 1920), range(0, 1080), 256, 256);
	Ball5.Create("assets/ball.png", range(0, 1920), range(0, 1080), 256, 256);
	Ball6.Create("assets/ball.png", range(0, 1920), range(0, 1080), 256, 256);

	offset.x = -32;
	offset.y = -32;

	cash = 0;
}

//Runs every frame
void Step(){
	drawText("Mouse X: " + to_string(getMousePosition().x) + " Mouse Y: " + to_string(getMousePosition().y), 255, 255, 255, 255, 0, 0);

	drawText("Cash: " + to_string(cash), 255, 255, 255, 255, Player.transform.position.x, Player.transform.position.y - 50);

	Player.transform.position = getMousePosition() + offset;

	if(Player.Collided(Ball1) && Ball1.isActive()){
		Ball1.Destroy();
		cash += 1;
	}
	if(Player.Collided(Ball2) && Ball2.isActive()){
		Ball2.Destroy();
		cash += 1;
	}
	if(Player.Collided(Ball3) && Ball3.isActive()){
		Ball3.Destroy();
		cash += 1;
	}
	if(Player.Collided(Ball4) && Ball4.isActive()){
		Ball4.Destroy();
		cash += 1;
	}
	if(Player.Collided(Ball5) && Ball5.isActive()){
		Ball5.Destroy();
		cash += 1;
	}
	if(Player.Collided(Ball6) && Ball6.isActive()){
		Ball6.Destroy();
		cash += 1;
	}

	Player.Draw();

	Ball1.Draw();
	Ball2.Draw();
	Ball3.Draw();
	Ball4.Draw();
	Ball5.Draw();
	Ball6.Draw();
}

//Runs on last frame
void End(){
	Player.Destroy();

	Ball1.Destroy();
	Ball2.Destroy();
	Ball3.Destroy();
	Ball4.Destroy();
	Ball5.Destroy();
	Ball6.Destroy();
}
