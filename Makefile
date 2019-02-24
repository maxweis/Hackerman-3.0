CC=clang++
OUTPUT=bin/Hackerman-3.0
FLAGS=-lSDL2 -lSDL2_image -lSDL2_gfx -lSDL2_ttf
FILES = src/main.cpp src/player.cpp src/panel.cpp src/enemy.cpp src/render.cpp src/game.cpp src/image.cpp src/font.cpp src/maths.cpp src/filesystem.cpp src/store.cpp

all:
	$(CC) $(FILES) $(FLAGS) -o $(OUTPUT)
