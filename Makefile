APP = game
DEBUG_FLAG = -O1 -Wall -pedantic -Wno-missing-braces -g
RAYLIB_FLAG = -I src/includes -L src/libs -lraylib -lopengl32 -lgdi32 -lwinmm

main: main.o app.o player.o i_camera.o static_mesh.o level1.o collision_shape.o
	g++ $^ -o $(APP) $(DEBUG_FLAG) $(RAYLIB_FLAG)

main.o: main.cpp
	g++ $< -c

app.o: src/app.cpp
	g++ $< -c

player.o: src/player.cpp
	g++ $< -c

i_camera.o: src/i_camera.cpp
	g++ $< -c

static_mesh.o: src/static_mesh.cpp
	g++ $< -c

level1.o: src/scenes/level1.cpp
	g++ $< -c

collision_shape.o: src/collision_shape.cpp
	g++ $< -c

.PHONY: clean
clean:
	del *.o *.exe