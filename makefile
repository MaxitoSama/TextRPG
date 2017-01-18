CC := g++

buildtest: generated/enemies.o generated/heroes.o 
	$(CC) -o Game src/*.cpp	generated/*.o

generated/enemies.o: src/Enemies/*.cpp
	mkdir -p generated
	$(CC) -c src/Enemies/*.cpp
	ld -r *.o -o enemies.o
	mv enemies.o generated
	rm *.o

generated/heroes.o: src/Heroes/*.cpp
	mkdir -p generated
	$(CC) -c src/Heroes/*.cpp
	ld -r *.o -o heroes.o
	mv heroes.o generated
	rm *.o

clean:
	rm -rf generated
	rm -f Game
