# g++ Main.cpp Renderer.cpp Sprite.cpp -Llib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -o Main

CC = g++
CFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -o Main

all:Main.cpp 
	$(CC) $(CFLAGS) Main.cpp 