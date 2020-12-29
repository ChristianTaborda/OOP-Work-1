/***************************************************************************************************
 * Autores:  Christian Camilo Taborda Campiño - 1632081-3743                                       *
 *           Cristian Camilo Vallecilla Cuellar - 1628790-3743                                     *                                                                            *
 * Título: traductor.cpp                                                                           *
 * Descripción: Este programa traduce ciertas palabras del inglés al español.                      *
 * Fecha De Creación: 28 / Septiembre / 2016                                                       *
 * Fecha De Última Modificación: 08 / Octubre / 2016                                               *
 ***************************************************************************************************
 */
 
#include <iostream>
#include <string>
#include "traductor.h"

using namespace std;

int main () {
    
    //Definimos dos arreglos, uno con las palabras en inglés el otro con las palabras en español:
    string diccionario [] = {"shark", "house", "carrot", "apple", "notebook", "pencil", "lizard", "guitar", "water", "car"};
    string traducciones [] = {"tiburón", "casa", "zanahoria", "manzana", "cuaderno", "lápiz", "lagarto", "guitarra", "agua", "carro"};
    
    cout << endl;
    cout << "TRADUCTOR (INGLÉS - ESPAÑOL)\n" << endl;    
    string palabra;
    
    do {
        cout << "Ingrese una palabra: \n" << endl;
        cin >> palabra;
        cout << endl;
        //Convertimos las letras de la palabra ingresada a minúsculas:
        palabra = convertir_mayusculas (palabra);        
        
        //Buscamos la palabra y la traducimos si la encontramos:   
        if (buscar_palabra (diccionario,palabra)){
                           cout << "La traducción es: " << traducir(diccionario,traducciones,palabra) << endl;
                           cout << endl;
        }
        else {
             cout << "La palabra no existe en el diccionario. \n" << endl;
        }
    
    } while (!(buscar_palabra (diccionario,palabra)));  
   
return 0;
}

//Esta función verifica si una palabra está dentro de un arreglo.   
bool buscar_palabra (string D [], string P){
     bool encontrada = false;
     for (int x=0; x<10; x++){
         if ((D[x].compare(P)) == 0) {
                           encontrada = true;
         }
     }
     return encontrada;
}

//Esta función retorna la posición donde se encuentra una palabra si la encuentra dentro de un arreglo. 
int buscar_posicion (string D [], string P){
    int posicion;
    if (buscar_palabra(D,P)){
                             for (int x=0; x<10; x++){
                                 if ((D[x].compare(P)) == 0){
                                                       posicion = x;
                                 }
                             }
                             return posicion;    
    }
}    

//Esta función busca una palabra en un arreglo y según su posición retorna otra palabra de otro arreglo.
string traducir (string D [], string T [], string P){
     if (buscar_palabra(D,P)){
                              return T [buscar_posicion(D,P)];
     }
}   

//Esta función convierte las letras de una palabra a minúsculas.
string convertir_mayusculas (string P){
       for (int x=0; x<(int)P.length(); x++){
           if (((int)P[x]>=65) && ((int)P[x]<=90)){
                               P[x] = (char)((int)P[x] + 32);
           }
       }
       return P;
}                                  
                   
