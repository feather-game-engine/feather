#include "feather/core.h"
#include "feather/entity.h"
#include "feather/input.h"
#include "feather/text.h"
#include "feather/sound.h"
#include "feather/debug.h"
#include "feather/util.h"
#include "feather/vector.h"
#include "feather/rigidentity.h"

#include <vector>

using namespace std;

Entity Player;
RigidEntity ball;

vector<RigidEntity> balls;

Vector offset;

int cash;

//Runs on first frame
void Begin() {
	Player.Create("example/assets/player.png", 0, 0, 128, 128);
	
	ball.Create("example/assets/ball.png", range(0, 1920), range(0, 1080), 140, 140);
	balls.push_back(ball);

	/*
	for (int i = 0; i < 5; i++) {
		Transform random;
		random.position = Vector(range(0, 1920), range(0, 1080));
		random.scale = Vector(128, 128);
		random.angle = 0.0;
		RigidEntity newClone = ball.clone(random);
		balls.push_back(newClone);
	} */
		
	offset.x = -32;
	offset.y = -32;

	cash = 0;
}

//Runs every frame
void Step() {
	drawText("Mouse X: " + to_string(getMousePosition().x) + " Mouse Y: " + to_string(getMousePosition().y), 255, 255, 255, 255, 0, 0);

	drawText("Cash: " + to_string(cash), 255, 255, 255, 255, Player.transform.position.x, Player.transform.position.y - 50);

	Player.transform.position = getMousePosition() + offset;

	for (int i = 0; i < balls.size(); i++) {
		if (Player.Collided(balls[i])) {
			cash++;
			balls[i].Destroy();
		}
	}


}

//Runs on last frame
void End() {
}
