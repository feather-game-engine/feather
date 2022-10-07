#include "feather/include.h"

using namespace std;

Entity Player;
Entity Clone;
RigidEntity ball;

vector<RigidEntity*> balls;

Vector offset;

int cash;

//Runs on first frame
void Begin() {
	Player.Create("assets/player.png", 0, 0, 128, 128);

	ball.Create("assets/ball.png", 30, 30, 140, 140);
	ball.gravity = 0;
	balls.push_back(&ball);


	for (int i = 0; i < 5; i++) {
		Transform random;
		random.position = Vector(range(0, 1920), range(0, 700));
		random.scale = Vector(128, 128);
		random.angle = 0.0;
		balls.push_back(ball.clone(random));
	}

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
		if (Player.Collided(*balls[i])) {
			cash++;
			balls[i]->Destroy();
		}
		if (balls[i]->transform.position.y >= 970) {
			balls[i]->gravity = 0;
			balls[i]->velocity = 0;
		}
	}


}

//Runs on last frame
void End() {
}
