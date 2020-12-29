/***************************************************************************************************
 * Autores:  Christian Camilo Taborda Campiño - 1632081-3743                                       *
 *           Cristian Camilo Vallecilla Cuellar - 1628790-3743                                     *                                                                            *
 * Título: matrices.cpp                                                                            *
 * Descripción: Este programa verifica si una matriz es un cuadrado mágico a partir de la lectura  *
 *              de una archivo de texto.                                                           *
 * Fecha De Creación: 04 / Octubre / 2016                                                          *
 * Fecha De Última Modificación: 08 / Octubre / 2016                                               *
 ***************************************************************************************************
 */

#include <iostream>
#include <fstream>
#include <vector>
#include "matrices.h"

using namespace std;                 

int main () {
    vector <int> elementos_matriz; 
    int longitud;
    int elemento;
    char nombre [30];
    cout << "Ingrese el nombre del archivo que contiene a la matríz: " << endl;
    cin >> nombre;
    cout << endl;
    ifstream archivo (nombre); 
    //Leemos el archivo carácter por carácter.
    while (!archivo.eof()){ 
          //Cada carácter se guarda en una variable de tipo entero.
          archivo >> elemento; 
          //Cada valor de la variable se inserta en un vector entero.
          elementos_matriz.push_back(elemento); 
    }
    longitud = elementos_matriz[0]; //Tomamos el primer elemento del vector como el tamaño de la matriz.
    elementos_matriz.erase(elementos_matriz.begin()); //Eliminamos la primera entrada para quedarnos sólo con la matríz.
    elementos_matriz.erase(elementos_matriz.begin() + (longitud * longitud)); //Eliminamos la última entrada debido a que se repite.
    
    int ** matriz = new int * [longitud]; //Definimos un puntero de punteros de tipo entero del tamaño de las filas.
    for (int x=0; x<longitud; x++){
        matriz[x] = new int [longitud]; //Definimos cada puntero como un arreglo del tamaño de las columnas.
    }
    int seleccionar = 0; 
    for (int x=0; x<longitud; x++){
        for (int y=0; y<longitud; y++){
            matriz [x][y] = elementos_matriz[seleccionar]; //Guardamos cada elemento del vector entero en la matriz contenida en el puntero.
            seleccionar += 1;
        }
    }
    
    int suma = 0;
    for (int x=0; x<longitud; x++){ //Determinamos el valor que debe tener la suma de cada lado de la matriz tomando la primera fila.
        suma += matriz[0][x];
    }
    
    //Verificamos que los elementos de la matríz sean únicos, estén entre 1 y n cuadrado, y la suma de sus dimensiones sea igual.   
    if ((comprobar_elementos(elementos_matriz,longitud))&&(elementos_repetidos(elementos_matriz))&&(cuadrado_magico(matriz,longitud,suma))){
      cout << "La matríz ingresada: \n" << endl;
      for (int x=0; x<longitud; x++){
        for (int y=0; y<longitud; y++){
            cout << " " << matriz[x][y] << " ";
        }
        cout << endl;    
        cout << endl;    
      }
      cout << endl;
      cout << "Sí es un cuadrado mágico.\n" << endl;
    }
    else {
         cout << "La matríz ingresada: \n" << endl;
         for (int x=0; x<longitud; x++){                 
             for (int y=0; y<longitud; y++){
                 cout << " " << matriz[x][y] << " ";
             }
             cout << endl;
             cout << endl;
         }
         cout << endl;
         cout << "No es un cuadrado mágico.\n" << endl;
    }      
                                          
    archivo.close(); 
    
return 0;
}
    
//Esta función verifica que todos los elementos de un vector estén entre 1 y un parámetro al cuadrado.
bool comprobar_elementos (vector <int> V, int T){
     for (int x=0; x<(int)V.size(); x++){
         if (!((V[x] >= 1) && (V[x] <= (T*T)))){
                     return false;
         }
     }
     return true;
}                     

//Esta función retorna la cantidad de veces que se repite un parámetro dentro de un vector.
int contar_repeticiones (vector <int> V, int numero){
    int repeticiones = 0;
    for (int x=0; x<(int)V.size(); x++){
        if (V[x] == numero){
                         repeticiones += 1;
        }
    }
    return repeticiones;
}

//Esta función verifica que cada elemento dentro de un vector sea único.
bool elementos_repetidos (vector <int> V){
     for (int x=0; x<(int)V.size(); x++){
         if ((contar_repeticiones(V,V[x])) > 1){
                                           return false;
         }
     }
     return true;
} 

//Esta función verifica que la suma de las filas, columnas y diagonales sean iguales a un parámetro.
bool cuadrado_magico (int ** M, int T, int S){
     int suma_parcial = 0;
     for (int x=0; x<T; x++){
         for (int y=0; y<T; y++){
             suma_parcial += M[x][y];
         }
         if (!(suma_parcial == S)){
                           return false;
         }
         suma_parcial = 0;
     }
     for (int x=0; x<T; x++){
         for (int y=0; y<T; y++){
             suma_parcial += M[y][x];
         }
         if (!(suma_parcial == S)){
                            return false;
         }
         suma_parcial = 0;
     }
     for (int x=0; x<T; x++){
         suma_parcial += M[x][x];
     }
     if (!(suma_parcial == S)){
                        return false;
     }
     suma_parcial = 0;
     for (int x=(T-1), y=0; x>=0, y<T; x--, y++){
         suma_parcial += M[y][x];
     }
     if (!(suma_parcial == S)){
                        return false;
     }
     return true;
}     
    
