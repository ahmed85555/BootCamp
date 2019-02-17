CC=gcc
CFLAG=-Wl,-Map,output.map main.o func1.o func2.o
sum.exe:main.o func1.o func2.o
	gcc -o Make_file.exe main.o func1.o func2.o
	$(CC) $(CFLAG) 
main.o:func1.h func2.h main.c
	gcc -c main.c
func1.o:func1.h func1.c
	gcc -c func1.c
func2.o:func2.h func2.c
	gcc -c func2.c
Clean:
	del *.o
					