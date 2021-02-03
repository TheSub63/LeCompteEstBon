le_compte_est_bon:main.o
	gcc -o le_compte_est_bon main.o numgen.o mt19937ar.o compte.o

tests:src/tests/tests.c
	gcc src/tests/*.c src/compte.c src/mt19937ar.c src/numgen.c -o tests -g

main.o:src/compte.c src/main.c src/compte.h src/numgen.c src/numgen.h
	gcc src/*.c -c 

teZZt.o:src/tests/teZZt.h src/tests/teZZt.h
	gcc -c src/tests/teZZt.c build/