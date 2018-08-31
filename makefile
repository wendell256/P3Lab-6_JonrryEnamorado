main:	main.o Ingredientes.o Bodega.o Clientes.o Platos.o
		g++ main.o Ingredientes.o Bodega.o Clientes.o Platos.o -o main
		rm *.o

main.o: main.cpp Clientes.h Platos.h Ingredientes.h Bodega.h
		g++ -c main.cpp

Clientes.o:	Clientes.h
		g++ -c Clientes.cpp

Ingredientes.o: Ingredientes.h
		g++ -c Ingredientes.cpp

Bodega.o: Ingredientes.h Bodega.h Platos.h
		g++ -c Bodega.cpp

Platos.o: Ingredientes.h Platos.h
		g++ -c Platos.cpp