SRC_DIR = feather
CC = g++
OUT = game
LINKERS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
INCLUDE = -Iinclude
LIBRARIES = -Llib/lib -Llib/lib_image -Llib/lib_ttf -Llib/lib_mixer


all: 
	$(CC) game.cpp $(SRC_DIR)/*.cpp $(LINKERS) $(INCLUDE) $(LIBRARIES) -o $(OUT)

clean:
	rm $(OUT)

ship:
	$(CC) game.cpp $(SRC_DIR)/*.cpp $(LINKERS) $(INCLUDE) $(LIBRARIES) -o $(OUT)
	cp $(OUT) build/
	cp -r assets/ build/
