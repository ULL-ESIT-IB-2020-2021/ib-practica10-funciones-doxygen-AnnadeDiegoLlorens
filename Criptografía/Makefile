# Universidad de La Laguna
#Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Informática Básica
#
# @author Anna de Diego
# @date 14/12/2020
# @brief Un fichero Makefile para el programa Cripto
# 
# @see https://www.gnu.org/software/make/
# @see http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/

CXX = g++						
CXXFLAGS = -g -O0
LDFLAGS =						


all: Cripto

Cripto: cripto.o funciones_cripto.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: all clean

# hello_world.o: hello_world.cc

	$(CXX) $(CXXFLAGS) -c $<


clean :
	rm -f cripto*.o
	rm -rf *~ basura b i
	rm -rf a.out
	find . -name '*~' -exec rm {} \;
	find . -name basura -exec rm {} \;

push:
	git pull 
	git add . 
	git commit -m "Another example" 
	git push