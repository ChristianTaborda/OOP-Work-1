#Compilación Taller 01
CPP = g++
CFLAGS = -c
OFLAGS = -o
.SUFFIXES: .cpp
.cpp.o:
	$(CPP) $(CFLAGS) $<
all:	\
	letreroBienvenida\
	traductor\
	inventario\
	triqui\
	matrices\
	generarPares\

letreroBienvenida:	letreroBienvenida.o
	$(CPP) $(OFLAGS) letreroBienvenida letreroBienvenida.o	
traductor:	traductor.o
	$(CPP) $(OFLAGS) traductor traductor.o
inventario:	inventario.o
	$(CPP) $(OFLAGS) inventario inventario.o
triqui:	triqui.o
	$(CPP) $(OFLAGS) triqui triqui.o
matrices:	matrices.o
	$(CPP) $(OFLAGS) matrices matrices.o
generarPares:	generarPares.o
	$(CPP) $(OFLAGS) generarPares generarPares.o 
clean:
	rm -rf *.o   
          
      
