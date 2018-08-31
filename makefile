main:	main.o Persona.o Estudiante.o 
		g++ main.o Persona.o Estudiante.o -o main
		rm *.o

main.o: main.cpp Persona.h Estudiante.h
		g++ -c main.cpp

Persona.o:	Persona.h
		g++ -c Persona.cpp

Estudiante.o:	Estudiante.h Persona.h
		g++ -c Estudiante.cpp