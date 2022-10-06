#include "feather/include.h"

using namespace std;

//Runs on first frame
void Begin(){
}

//Runs every frame
void Step(){
	Player.transform.position.x += 1;
}

//Runs on last frame
void End(){
}
