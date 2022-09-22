CC=g++
OUT=game

build: game.cpp feather/main.cpp feather/text.cpp feather/entity.cpp feather/input.cpp feather/sound.cpp feather/debug.cpp feather/util.cpp
	$(CC) game.cpp feather/main.cpp feather/text.cpp feather/entity.cpp feather/input.cpp feather/sound.cpp feather/debug.cpp feather/util.cpp -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer -o $(OUT)

clean:
	rm $(OUT)
