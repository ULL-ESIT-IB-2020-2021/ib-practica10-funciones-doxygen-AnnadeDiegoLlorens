/**
*@author Anna de Diego Llorens
*@brief Este programa pretende codificar textos con el codico Cesar\
*      el programa funciona pero va más lento de lo deseado y no detecta los espacios ni caracteres especiales. 
*@see https://ascii.cl/es/
*@see https://www.geeksforgeeks.org/caesar-cipher-in-cryptography/
*/

#include<iostream>
#include<string>
 
using namespace std;

int main(){
    string texto_a_desencriptar = "KrodSdfrfxdqwrwlhpsrvlqyhuwhdpljr", texto_desencriptado = "";
    const char kspace = ' ';
    int numero_a_sumar = 3;
    int i = 0;

    for (i=0 ; i <= texto_a_desencriptar.length(); i++){
        
        if(isupper(texto_a_desencriptar[i])){
            texto_desencriptado[i] = (((texto_a_desencriptar[i])- numero_a_sumar)%90);
            texto_desencriptado += texto_desencriptado[i];
        }
        if (islower(texto_a_desencriptar[i])){
            texto_desencriptado[i] = (((texto_a_desencriptar[i])- numero_a_sumar)%122);
            texto_desencriptado += texto_desencriptado[i];
        }
        else{ texto_a_desencriptar += kspace;}
    }
    cout << "Su codigo encriptado es: " << texto_desencriptado << endl; 
return 0;
}