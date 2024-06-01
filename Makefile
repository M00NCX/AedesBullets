all:
	g++ -Iinclude -Iinclude/sdl -Iinclude/headers -Iinclude/GL -Llib -o Main src/*.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lopengl32 -lglu32