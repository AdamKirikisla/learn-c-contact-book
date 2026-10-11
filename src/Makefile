main: main.o contact.o 
	gcc -Wall -Wextra -o main main.o contact.o

main.o: main.c contact.h
	gcc -Wall -Wextra -c main.c

contact.o: contact.c contact.h
	gcc -Wall -Wextra -c contact.c

clean:
	rm -f main main.o contact.o 