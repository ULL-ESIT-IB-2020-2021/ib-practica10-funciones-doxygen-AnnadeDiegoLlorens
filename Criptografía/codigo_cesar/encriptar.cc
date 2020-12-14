/**
*@author Anna de Diego Llorens
*@brief Este programa pretende codificar textos con el codico Cesar\
*       el programa funciona pero no respeta los cambios de linea.
*@see https://ascii.cl/es/
*@see https://www.geeksforgeeks.org/caesar-cipher-in-cryptography/
*/

#include<iostream>
#include<string>
 
using namespace std;

int main(){
    string texto_a_encriptar = "Hola Paco ¡cuanto tiempo sin verte amigo!", texto_encriptado = "";
    const char kspace = ' ';
    int numero_a_sumar = 3;
    int i = 0;

    for (i=0 ; i <= texto_a_encriptar.length(); i++){
        
        if(isupper(texto_a_encriptar[i])){
            texto_encriptado[i] = (((texto_a_encriptar[i])+ numero_a_sumar)%90);
            texto_encriptado += texto_encriptado[i];
        }
        if (islower(texto_a_encriptar[i])){
            texto_encriptado[i] = (((texto_a_encriptar[i])+ numero_a_sumar)%122);
            texto_encriptado += texto_encriptado[i];
        }
        else{ texto_a_encriptar += kspace;}
    }
    cout << "Su codigo encriptado es: " << texto_encriptado << endl; 
return 0;
}
