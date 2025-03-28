all:
	gcc -o ../bins/watchedlist main.c

debug:
	gcc -g -o ../debug/watchedlist main.c