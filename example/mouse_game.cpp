#include "feather/core.h"
#include "feather/entity.h"
#include "feather/input.h"
#include "feather/text.h"
#include "feather/sound.h"
#include "feather/debug.h"
#include "feather/util.h"
#include "feather/vector.h"
#include "feather/rigidentity.h"

using namespace std;

Entity Player;
RigidEntity Ball1;
RigidEntity Ball2;
RigidEntity Ball3;
RigidEntity Ball4;
RigidEntity Ball5;
RigidEntity Ball6;

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

	Ball1.addForceY(5);
	Ball2.addForceY(5);
	Ball3.addForceY(5);
	Ball4.addForceY(5);
	Ball5.addForceY(5);
	Ball6.addForceY(5);

	offset.x = -32;
	offset.y = -32;

	cash = 0;
}

//Runs every frame
void Step(){
	drawText("Mouse X: " + to_string(getMousePosition().x) + " Mouse Y: " + to_string(getMousePosition().y), 255, 255, 255, 255, 0, 0);

	drawText("Cash: " + to_string(cash), 255, 255, 255, 255, Player.transform.position.x, Player.transform.position.y - 50);

	Player.transform.position = getMousePosition() + offset;

	if(Player.Collided(Ball1)){
		Ball1.Destroy();
		cash += 1;
	}
	if(Player.Collided(Ball2)){
		Ball2.Destroy();
		cash += 1;
	}
	if(Player.Collided(Ball3)){
		Ball3.Destroy();
		cash += 1;
	}
	if(Player.Collided(Ball4)){
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

	Ball1.addForceY(40);
	Ball2.addForceY(40);
	Ball3.addForceY(40);
	Ball4.addForceY(40);
	Ball5.addForceY(40);
	Ball6.addForceY(40);
}

//Runs on last frame
void End(){
}
