all:
	gcc -o ../bin/watchedlist main.c database.c utils.c -I sqlite3 -L sqlite3 -lsqlite3 -Wall -Wextra

linux:
	gcc -o ../bin/watchedlist main.c database.c utils.c -lsqlite3 -Wall -Wextra

debug_linux:
	gcc -o -g ../bin/watchedlist main.c database.c utils.c -lsqlite3 -Wall -Wextra

windows:
	gcc -o ../bin/watchedlist main.c database.c utils.c -I sqlite3 -L sqlite3 -lsqlite3 -Wall -Wextra

clean:
	rm -r ../bin

clean_windows:
	rm -r -Force ../bin