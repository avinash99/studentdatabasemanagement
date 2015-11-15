project : project.o
	cc project.c -o project

project.o : project.c
	cc -c project.c

clear :
	rm -rf *.o
