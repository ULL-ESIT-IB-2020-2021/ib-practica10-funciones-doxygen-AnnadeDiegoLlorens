/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingenieria informatica 
 * Informática Básica
 *
 * @author Anna de Diego Llorens
 * @date 14/12/2020
 * @brief Programa que codifica y descodifica un código, \
 *        tiene el defecto de no respetar los cambios de línea.
 */

#include <iostream>
#include <string>
#include <fstream>
#include "funciones_cripto.h"

using namespace std;

int main(int argc, char* argv[]){
  Usage(argc,argv);
  string metodo1o2=argv[3], operacion = argv[5],
          mas = "+", menos = "-";

  if(metodo1o2== "2"){
    if(operacion==mas){
       Codigo_cesar_encriptar(argv);
      }
    else{
      Codigo_cesar_desencriptar(argv);
    }
  }else{
    if(operacion==mas){
      Codigo_xor_encriptar(argv);
      }
    else{
      Codigo_xor_desencriptar(argv);
    }
  }
 return 0; 
}
 // if (!fichero_a_codificar.is_open()|!fichero_codificado.is_open()){ 
//  return EXIT_FAILURE; 
//  }

