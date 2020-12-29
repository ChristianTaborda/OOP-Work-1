/***************************************************************************************************
 * Autores:  Christian Camilo Taborda Campiño - 1632081-3743                                       *
 *           Cristian Camilo Vallecilla Cuellar - 1628790-3743                                     *                                                                            *
 * Título: generarPares.cpp                                                                        *
 * Descripción: Este programa genera un archivo de texto llamando numerosPares.txt con los números *
 *              del 0 al 99998 contados de dos en dos.                                             *
 * Fecha De Creación: 01 / Octubre / 2016                                                          *
 * Fecha De Última Modificación: 08 / Octubre / 2016                                               *
 ***************************************************************************************************
 */

#include <iostream>
#include <fstream>
#include "generarPares.h"

using namespace std;              

int main(){
    ofstream archivo("numerosPares.txt");
    int contador = 0;
    
    for (int i=0; i<100000; i+=2){
        //Contamos el número de iteraciones del for.
        contador++;
        //Imprimimos el número con la cantidad de ceros que le correspondan.
        archivo << agregar_ceros(i) << i << " ";                
        //Si se han impreso 15 números, se imprime un salto de línea.
        if(contador==15){
                         archivo << endl;
                         contador = 0;
        }
    }    
    archivo.close();  
    
return 0;    
}

//Esta función determina cuántos ceros deben ir antes de un número dependiendo de su tamaño para sumar 5 dígitos.
string agregar_ceros (int i){
     if (i<9){
              return "0000";
     }
     else {
          if ((i>=10) && (i<100)){
                      return "000";
          }
          else {
               if ((i>=100)&&(i<1000)){
                                        return "00";
               }
               else {
                    if ((i>=1000)&&(i<10000)){
                                              return "0";
                    }
                    else {
                         if ((i>=10000)&&(i<100000)){
                                                     return "";
                         }
                    }
               }
          }
     }
}
