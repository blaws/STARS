stars: main.c gfx.c text.c scores.c
	gcc -c gfx.c -o gfx.o
	gcc -c text.c -o text.o
	gcc -c scores.c -o scores.o
	gcc -c main.c -o main.o
	gcc main.o scores.o text.o gfx.o -o stars -lm -lX11

clean:
	rm -f *.o stars
