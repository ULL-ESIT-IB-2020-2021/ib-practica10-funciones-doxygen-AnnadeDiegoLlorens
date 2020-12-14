/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingenieria Informatica
 * Informática Básica
 *
 * @author Anna de Diego Llorens
 * @date 14/12/2020
 * @brief Programa que codifica y descodifica un código, \
 *        tiene el defecto de no respetar los cambios de línea.
 * @see https://www.w3schools.in/cplusplus-tutorial/working-with-files/
 * @see https://ascii.cl/es/
 * @see https://www.geeksforgeeks.org/caesar-cipher-in-cryptography/
 * @see http://www.cplusplus.com/forum/articles/38516/
 * @see https://es.wikipedia.org/wiki/Cifrado_XOR
 */
#include <iostream>
#include <fstream>
#include <string>
#include "funciones_cripto.h"

using namespace std; 

void Usage(int argc,char *argv[]){
  if (argc !=5){
    cout << argv[0] << " -- Cifrado de ficheros" << endl
         << "Modo de uso: " << argv[0] << "fichero_entrada fichero_salida" <<
         "método contraseña operación" << endl
         << "Pruebe " << argv[0] << " --help para más información" << endl;
    exit(EXIT_SUCCESS);
  }
    string parameter{argv[1]};

  if (parameter == "--help") {
    cout << argv[0] << "-- Cifrado de ficheros" << endl << "Modo de uso:" << argv[0] 
         << "fichero_entrada fichero_salida método contraseña operación" << endl
         << "fichero_entrada: Fichero a codificar." 
         << "Esto es, fichero que aporta los datos" << endl
         << "fichero_salida:  Fichero codificado" 
         << "Esto es, fichero que recibirá los datos modificados" << endl
         << "método: Indica el método de encriptado" << endl
         << "        1: Cifrado xor" << endl << "        2: Cifrado de César" << endl
         << "contraseña: Palabra secreta en el caso de método 1, Valor de K en el método 2" << endl
         << "operación: Operación a realizar en el fichero" << endl
         << "       +: encriptar el fichero" << endl
         << "       -: desencriptar el fichero" << endl;
    exit(EXIT_SUCCESS);
  }
}
ofstream Codigo_cesar_encriptar(char *argv[]){
   string entrada = argv[1], salida = argv[2], 
           linea = "", texto_encriptado = "", contrasenya = argv[4];
  ifstream fichero_a_codificar;
  ofstream fichero_codificado;

  fichero_a_codificar.open(entrada, ios_base::in);
  fichero_codificado.open(salida, ios_base::out);

  while(getline(fichero_a_codificar,linea)){

    string texto = linea;
    const char kspace = ' ';
    int numero_a_sumar = stoi(contrasenya);
    int i = 0;

    for (i=0 ; i <= texto.length(); i++){
        
        if(isupper(texto[i])){
         texto_encriptado += (((((texto[i])-65)+ numero_a_sumar)%26)+65);
        }
        if (islower(texto[i])){
            texto_encriptado += (((((texto[i])-97)+ numero_a_sumar)%26)+97); 
        }
        else{ texto_encriptado += kspace;}
    }
  }
  fichero_codificado << texto_encriptado << endl;
    return fichero_codificado; 
}
ofstream Codigo_cesar_desencriptar(char *argv[]){
   string entrada = argv[1], salida = argv[2], 
           linea = "", texto_desencriptado = "", contrasenya = argv[4];
  ifstream fichero_a_codificar;
  ofstream fichero_codificado;

  fichero_a_codificar.open(entrada, ios_base::in);
  fichero_codificado.open(salida, ios_base::out);

  while(getline(fichero_a_codificar,linea)){

    string texto = linea;
    const char kspace = ' ';
    int numero_a_sumar = stoi(contrasenya);
    int i = 0;

    for (i=0 ; i <= texto.length(); i++){
        
        if(isupper(texto[i])){
         texto_desencriptado += (((((texto[i])-65)- numero_a_sumar)%26) + 65);
        }
        if (islower(texto[i])){
            texto_desencriptado += (((((texto[i])-97)- numero_a_sumar)%26 +97); 
        }
        else{ texto_desencriptado += kspace;}
    }
  }
  fichero_codificado << texto_desencriptado << endl;
    return fichero_codificado; 
}
ofstream Codigo_xor_encriptar(char *argv[]){

   string entrada = argv[1], salida = argv[2], 
           linea = "", texto_encriptado = "", 
           contrasenya = argv[4],contrasenya_modificada = "";
  ifstream fichero_a_codificar;
  ofstream fichero_codificado;

  fichero_a_codificar.open(entrada, ios_base::in);
  fichero_codificado.open(salida, ios_base::out);

    string knumero = "128";
    int k = 0;
    int i = 0;
    for( i = 0; i <= contrasenya.length(); i++){
        k = k + 1; 
        contrasenya_modificada += (contrasenya[i]^knumero[k]); 
        if (k >= knumero.length()){ k= 0; }
    }

  while(getline(fichero_a_codificar,linea)){
    string texto = linea;
    int k = 0; 
    for( int i = 0; i <= texto.length(); i++){
        k = k + 1; 
        texto_encriptado += (texto[i]^contrasenya_modificada[k]); 
        if (k = contrasenya_modificada.length()){ k= 0; }
    } 
  }
  fichero_codificado << texto_encriptado << endl;
    return fichero_codificado; 
}
ofstream Codigo_xor_desencriptar(char *argv[]){
   string entrada = argv[1], salida = argv[2], 
           linea = "", texto_desencriptado = "", 
           contrasenya = argv[4],contrasenya_modificada = "";
  ifstream fichero_a_codificar;
  ofstream fichero_codificado;

  fichero_a_codificar.open(entrada, ios_base::in);
  fichero_codificado.open(salida, ios_base::out);

    string knumero = "128";
    int k = 0;
    int i = 0;
    for( i = 0; i <= contrasenya.length(); i++){
        k = k + 1; 
        contrasenya_modificada += (contrasenya[i]^knumero[k]); 
        if (k >= knumero.length()){ k= 0; }
    }

  while(getline(fichero_a_codificar,linea)){
    string texto = linea;
    int k = 0; 
    for( int i = 0; i <= texto.length(); i++){
        k = k + 1; 
        texto_desencriptado += (texto[i]^contrasenya_modificada[k]); 
        if (k = contrasenya_modificada.length()){ k= 0; }
    } 
  }
  fichero_codificado << texto_desencriptado << endl;
    return fichero_codificado; 
}