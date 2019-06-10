all: main.cpp
			g++ -c main.cpp -I home/me/SFML-2.5.1/include
			g++ main.o -o sfml-app -L home/me/SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system