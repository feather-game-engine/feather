SRC_DIR=feather
CC=g++
OUT=game

all: 
	$(CC) game.cpp $(SRC_DIR)/*.cpp -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer -o $(OUT)

clean:
	rm $(OUT)

ship:
	$(CC) game.cpp $(SRC_DIR)/*.cpp -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer -o $(OUT)
	cp $(OUT) build/
	cp -r assets/ build/
