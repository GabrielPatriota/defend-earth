CC = g++ src/main.cpp -o DefendEarth.appImage

LIBS = -lsfml-graphics -lsfml-system -lsfml-window

Compiler:
	$(CC) $(LIBS)

run:
	./DefendEarth.appImage