#include<iostream>
#include<string>

using namespace std;

string EncriptadoXor(string clave_secreta){
    string knumero = "128";
    string clave_encriptada = "";
    int k = 0;
    int i = 0;
    for( i = 0; i< clave_secreta.length(); i++){
        k = k + 1; 
        clave_encriptada[i] = (clave_secreta[i]^knumero[k]); 
        clave_encriptada += clave_encriptada[i];
        if (k >= knumero.length()){ k= 0; }
    } 
    cout << "Su codigo era: " << clave_secreta << " y encriptado obtenemos " << clave_encriptada << endl;
    return clave_encriptada; 
}

//desencriptar un código encriptado 
int main(){
    string codigo_encriptado = "", clave_secreta = "alfa y delta",
           codigo_desencriptado = "", knumero = "128";
    codigo_encriptado = EncriptadoXor(clave_secreta); 
    int k = 0;
    for(int i = 0; i< clave_secreta.length(); i++){
        k = k + 1; 
        codigo_desencriptado[i] = (codigo_encriptado[i]^knumero[k]); 
        codigo_desencriptado += codigo_desencriptado[i];
        if (k >= knumero.length()){ k= 0;}
    } 
    cout << "Su codigo encriptado era: " << codigo_encriptado 
    << " y desencriptado obtenemos " << codigo_desencriptado << endl;
    return 0; 
}