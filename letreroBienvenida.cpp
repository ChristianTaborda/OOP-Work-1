/***************************************************************************************************
 * Autores:  Christian Camilo Taborda Campiño - 1632081-3743                                       *
 *           Cristian Camilo Vallecilla Cuellar - 1628790-3743                                     *                                                                            *
 * Título: letreroBienvenida.cpp                                                                   *
 * Descripción: Este programa imprime la simulación de un letrero luminoso.                        *
 * Fecha De Creación: 01 / Octubre / 2016                                                          *
 * Fecha De Última Modificación: 08 / Octubre / 2016                                               *
 ***************************************************************************************************
 */

#include <iostream>

using namespace std;

int main(){
    char letrero[22] = "SACARÉ IPOO EN 5.0 :)";
    
    int contador1 = 7;//Contador para controlar los espacios antes de la frase
    int contador2 = 29;//Contador para controlar los espacios despues de la frase
    //Se imprimen los asteriscos superiores que encierran el letrero 
    cout << "**********\n";
    
    for (int i=0; i<29; i++){
         cout <<"*";//Se imprime el asterisco inicial de cada fila que encierra el letrero
         if (i<7){
                  contador1 = 7-i;//Se modifica el contador con el número de espacios que necesita cada fila antes de la frase
         }    
         else {
              if (i>=20 && i<=29){
                        contador2 = 28-i;//Despues de la fila 20 se modifica con el número de espacios que necesita cada fila despues de la frase
              }
         }
         for(int j=0; j<8; j++){
                 //If para determinar cuando y en qué columnas imprimir los espacios 
                 if(((i>=0&& i<7)&&(j<contador1))or((i>=20 && i<=29)&&(j>=contador2))){//Condicion para que se impriman los espacios
                             cout << " ";
                 }
                 else{//Si no se cumplen esas condiciones es porque se debe imprimir una caracter de la frase que es determinada por lo siguiente:
                      cout << letrero[(j+i)-7];
                 }  
         }
         cout << "*" << endl;//Se imprime el asterisco final de cada fila que encierra el letrero
    }
    cout << "**********" << endl;//Se imprimen los asteriscos inferiores que encierran el letrero 

return 0;
}

