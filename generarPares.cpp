/***************************************************************************************************
 * Autores:  Christian Camilo Taborda Campi�o - 1632081-3743                                       *
 *           Cristian Camilo Vallecilla Cuellar - 1628790-3743                                     *                                                                            *
 * T�tulo: generarPares.cpp                                                                        *
 * Descripci�n: Este programa genera un archivo de texto llamando numerosPares.txt con los n�meros *
 *              del 0 al 99998 contados de dos en dos.                                             *
 * Fecha De Creaci�n: 01 / Octubre / 2016                                                          *
 * Fecha De �ltima Modificaci�n: 08 / Octubre / 2016                                               *
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
        //Contamos el n�mero de iteraciones del for.
        contador++;
        //Imprimimos el n�mero con la cantidad de ceros que le correspondan.
        archivo << agregar_ceros(i) << i << " ";                
        //Si se han impreso 15 n�meros, se imprime un salto de l�nea.
        if(contador==15){
                         archivo << endl;
                         contador = 0;
        }
    }    
    archivo.close();  
    
return 0;    
}

//Esta funci�n determina cu�ntos ceros deben ir antes de un n�mero dependiendo de su tama�o para sumar 5 d�gitos.
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
