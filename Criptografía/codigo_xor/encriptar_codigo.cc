/**
 * @author Anna de Diego Llorens
 * @date 13.dic.2020
 * @brief encripta con el método xor una cadena de texto tipo string \
 *        a través de una palabra clave (clave_secreta) que a sido previamente\
 *        encriptada usando el número 128. 
 * @see http://www.cplusplus.com/forum/articles/38516/
 * @see https://es.wikipedia.org/wiki/Cifrado_XOR
 */

#include<iostream>
#include<string>

using namespace std;

string ClaveEncriptada( string clave_secreta){
    string knumero = "128";
    string clave_encriptada = "";
    int k = 0;
    int i = 0;
    for( i = 0; i <= clave_secreta.length(); i++){
        k = k + 1; 
        clave_encriptada[i] = (clave_secreta[i]^knumero[k]); 
        clave_encriptada += clave_encriptada[i];
        if (k >= knumero.length()){ k= 0; }
    } 
    return clave_encriptada; 
}

int main(){
 
    string texto_a_encriptar = "Hola Alex,¿Que tal estas?";
    string clave_secreta = "alfa y omega";
    string clave_secreta_encriptada = ClaveEncriptada(clave_secreta); 
    string texto_encriptado = ""; 

    int k = 0; 
    for( int i = 0; i <= texto_a_encriptar.length(); i++){
        k = k + 1; 
        texto_encriptado[i] = (texto_a_encriptar[i]^clave_secreta_encriptada[k]); 
        texto_encriptado += texto_encriptado[i];
        if (k >= clave_secreta_encriptada.length()){ k= 0; }
    } 
    cout << "su texto codificado es: " << texto_encriptado << endl; 
}