build: generated/enemies.o generated/heroes.o
	g++ -o Game src/main.cpp src/info_menu.cpp src/main_game.cpp \
	generated/enemies.o generated/heroes.o generated/characters.o

generated/enemies.o: generated/characters.o
	g++ -c src/Enemies/enemies.cpp
	mv enemies.o generated

generated/heroes.o: generated/characters.o
	g++ -c src/Heroes/heroes.cpp
	mv heroes.o generated

generated/characters.o:
	mkdir -p generated
	g++ -c src/characters.cpp
	mv characters.o generated

clean:
	rm -rf generated
	rm -f Game
