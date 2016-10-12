kasse.o: kasse.c kasse.h
	gcc -c kasse.c

kasse: kasse.o
	gcc kasse.o -o kasse