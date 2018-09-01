main:	main.o Persona.o Grande.o Mediana.o Empresa.o Microempresa.o Pasante.o Estudiante.o Empleado.o
		g++ main.o Empresa.o Grande.o Mediana.o Microempresa.o Pasante.o Persona.o Estudiante.o Empleado.o -o main
		rm *.o

main.o: main.cpp Mediana.h Grande.h Empresa.h Microempresa.h Persona.h Estudiante.h Pasante.o Empleado.o
		g++ -c main.cpp

Persona.o:	Persona.h
		g++ -c Persona.cpp

Estudiante.o:	Estudiante.h Persona.h
		g++ -c Estudiante.cpp

Empleado.o:	Empleado.h Estudiante.h Persona.h
		g++ -c Empleado.cpp

Pasante.o:	Pasante.h Estudiante.h Persona.h
		g++ -c Pasante.cpp

Empresa.o:	Empresa.h Empleado.h Pasante.h
		g++ -c Empresa.cpp

Microempresa.o: Microempresa.h Empresa.h
		g++ -c Microempresa.cpp

Mediana.o: Mediana.h Microempresa.h
		g++ -c Mediana.cpp

Grande.o: Grande.h Mediana.h
		g++ -c Grande.cpp