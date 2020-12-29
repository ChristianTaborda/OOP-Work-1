/***************************************************************************************************
 * Autores:  Christian Camilo Taborda Campiño - 1632081-3743                                       *
 *           Cristian Camilo Vallecilla Cuellar - 1628790-3743                                     *                                                                            *
 * Título: inventario.cpp                                                                          *
 * Descripción: Este programa administra el inventario de una empresa.                             *
 * Fecha De Creación: 28 / Septiembre / 2016                                                       *
 * Fecha De Última Modificación: 08 / Octubre / 2016                                               *
 ***************************************************************************************************
 */
 
#include <iostream>
#include <string>
#include <vector>
#include "inventario.h"

using namespace std;

int main () {
    
    vector <string> elementos;
    vector <int> cantidades;
    int opcion;
    bool encontrar = false;
    int posicion;
    string eliminar;
    string elemento;
    int cantidad;
    
    inventario ();
    do {
        cout << "Ingrese su opción: \n";
        cin >> opcion;
        cout << endl;
        
    switch (opcion) {
           case 1:
                cout << "**************************************" << endl;
                cout << "*        Ingresar un elemento:       *" << endl;
                cout << "**************************************\n" << endl;
                cout << "Ingrese el nombre del elemento: \n";
                cin >> elemento;
                cout << endl;
                cout << "Ingrese la cantidad de elementos:  \n";
                cin >> cantidad;
                cout << endl;
                //Verificamos si el elemento ya hace parte del inventario.
                for (int x=0; x<elementos.size(); x++) {
                    if ( elementos[x].compare(elemento) == 0) {
                         encontrar = true;
                         posicion = x;
                    }
                }
                if (encontrar) {
                               //Si lo encontramos, sólo sumamos la cantidad ingresada en vez de hacer una nueva entrada.
                               cantidades[posicion] += cantidad;
                               cout << "Ingreso exitoso!\n";
                               cout << endl;
                }
                else {
                     //En otro caso hacemos una nueva entrada en el vector.
                     elementos.push_back (elemento);
                     cantidades.push_back (cantidad);
                     cout << "Ingreso exitoso!\n";
                     cout << endl;
                }
                encontrar = false;
                inventario ();
                break;
           case 2:
                cout << "**************************************" << endl;
                cout << "*        Eliminar un elemento:       *" << endl;
                cout << "**************************************\n" << endl;
                cout << "Ingrese el nombre del elemento: \n";
                cin >> eliminar;
                cout << endl;
                //Buscamos si el elemento está en el inventario.
                for (int x=0; x<elementos.size(); x++) {
                    if ( elementos[x].compare(eliminar) == 0) {
                         encontrar = true;
                         posicion = x;
                    }
                }
                if (encontrar) {
                               //Si lo encontramos, eliminamos su entrada de ambos vectores.
                               elementos.erase (elementos.begin() + posicion);
                               cantidades.erase (cantidades.begin() + posicion);
                               cout << "Eliminación exitosa!\n";
                               cout << endl;
                               encontrar = false;
                               inventario ();
                }
                else {
                     //En otro caso informamos que el elemento no existe.
                     cout << "El elemento no existe.\n";
                     cout << endl;
                     encontrar = false;
                     inventario ();
                }
                break;
           case 3:
                cout << "**************************************" << endl;
                cout << "*        Elementos Almacenados:      *" << endl;
                cout << "**************************************" << endl;
                cout << "*      Nombre:     *     Cantidad:   *" << endl;
                cout << "**************************************" << endl;
                imprimir_elementos(elementos,cantidades);
                cout << "**************************************\n";
                cout << endl;
                inventario ();
                break;
           case 4:
                return 0;
                break;
           default:
                   cout << "Dato equivocado.\n";
                   cout << endl;
                   break;           
     }
    } while (!(opcion == 4));
    
return 0;
}
   
//Esta función imprime el menú principal del programa.     
void inventario () {
     cout << endl;
     cout << "**************************************" << endl;
     cout << "*    BIENVENIDO A MI INVENTARIO      *" << endl;
     cout << "**************************************" << endl;
     cout << "*   Seleccione una opción:           *" << endl;
     cout << "*                                    *" << endl;
     cout << "*   1. Ingresar un elemento.         *" << endl;
     cout << "*   2. Eliminar un elemento.         *" << endl;
     cout << "*   3. Mostrar elementos.            *" << endl;
     cout << "*   4. Salir.                        *" << endl;
     cout << "*                                    *" << endl;
     cout << "**************************************\n";
     cout << endl;
}

//Esta función imprime las entradas de ambos vectores, cada una frente a la otra.
void imprimir_elementos (vector <string> E, vector <int> C){
     for (int x=0; x<E.size(); x++) {
                    cout << "      " << E[x] << " .............. " << C[x] << endl;
     }
}                
                
                
                
                
    
    
    
    
    
    
                         
    
    
    
