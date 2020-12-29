/***************************************************************************************************
 * Autores:  Christian Camilo Taborda Campiño - 1632081-3743                                       *
 *           Cristian Camilo Vallecilla Cuellar - 1628790-3743                                     *                                                                            *
 * Título: triqui.cpp                                                                              *
 * Descripción: Este programa simula el juego del triqui.                                          *
 * Fecha De Creación: 02 / Octubre / 2016                                                          *
 * Fecha De Última Modificación: 08 / Octubre / 2016                                               *
 ***************************************************************************************************
 */
 
#include <iostream>
#include "triqui.h"

using namespace std;
                              
int main () {
    int fila, columna;
    int triqui[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    bool decision = true;
    int empate = 0;
    dibujar_juego (triqui);
    do {
       if (decision) {
        do {
            cout << "JUGADOR 1 (X)\n" << endl;
            cout << "Ingrese la fila: " << endl;
            cin >> fila;
            cout << endl;
            cout << "Ingrese la columna: " << endl;
            cin >> columna;
            cout << endl;
            //Restamos 1 a cada dimensión para que podamos usar las posiciones de la matríz definida.
            fila -= 1;
            columna -= 1;
            //Verificamos que la posición no esté ocupada o sea incorrecta.
            if ((posicion_ocupada(fila,columna,triqui)) || (!(posicion_valida(fila,columna)))) {
                                                        cout << "Posición ocupada o no válida.\n" << endl;
            }
        } while ((posicion_ocupada(fila,columna,triqui)) || (!(posicion_valida(fila,columna))));
          //Seteamos la entrada del jugador 1 en la matríz.
          triqui [fila][columna] = 1;
          //Vamos contando el número de jugadas.
          empate++;
          fila = 0;
          columna = 0;
          //Imprimimos el juego parcial.
          dibujar_juego (triqui);
          //Verificamos si hay un ganador o empate.
          juzgar (triqui,decision,empate);
        }
        
        if (decision){
         do {
             cout << "JUGADOR 2 (O)\n" << endl;
             cout << "Ingrese la fila: " << endl;
             cin >> fila;
             cout << endl;
             cout << "Ingrese la columna: " << endl;
             cin >> columna;
             cout << endl;
             //Restamos 1 a cada dimensión para que podamos usar las posiciones de la matríz definida.
             fila -= 1;
             columna -= 1;
             //Verificamos que la posición no esté ocupada o sea incorrecta.
             if ((posicion_ocupada(fila,columna,triqui)) || (!(posicion_valida(fila,columna)))) {
                                                        cout << "Posición ocupada o no válida.\n" << endl;
            }            
         } while ((posicion_ocupada(fila,columna,triqui)) ||(!(posicion_valida(fila,columna))));
           //Seteamos la entrada del jugador 2 en la matríz.
           triqui [fila][columna] = 2;
           //Vamos contando la cantidad de jugadas.
           empate++;
           fila = 0;
           columna = 0; 
           //Imprimimos el juego parcial.
           dibujar_juego(triqui);
           //Verificamos si hay un ganador o empate.
           juzgar (triqui,decision,empate);
         }
    } while (decision);
          
return 0;
}

//Esta función imprime las entradas de una matríz, si hay 1 imprime X, si hay 2 imprime O, en otro caso imprime _ .
void dibujar_juego (int M [3][3]) { 
         cout << endl;
         cout << "|---------TRIQUI--------|\n" << endl;
         cout << "*************************" << endl;
         cout << "*    ESTADO DEL JUEGO   *" << endl;
         cout << "*************************" << endl;
         for (int x=0; x<3; x++) {
             for (int y=0; y<3; y++) {
                 switch (M[x][y]) {
                        case 1:
                             cout << "|  " << "X" << "  |  ";
                             break;
                        case 2:
                             cout << "|  " << "O" << "  |  ";
                             break;
                        default:
                             cout << "|  " << "_" << "  |  ";
                             break;
                 }
             }
             cout << endl;
             cout << "*************************" << endl;
         }
         cout << endl;
}

//Esta función verifica si la entrada de una matríz es igual a 1 o a 2.
bool posicion_ocupada (int F, int C, int M [3][3]) {
     if ((M[F][C]==1)||(M[F][C]==2)) {
                                     return true;
     }
     else {
          return false;
     }
}                  

//Esta función verifica que las dimensiones de una entrada estén entre 0 y 2.
bool posicion_valida (int F, int C) {
     if (((F <= 2) && (F >= 0)) && ((C <= 2) && (C >= 0))) {
             return true;
     }
     else {
          return false;
     }
}

//Esta función verifica si las entradas de una fila, columna o diagonal son iguales y decide quién gana o si hay empate.
void juzgar (int M[3][3], bool &decision, int empate){
      for(int i=0; i<3; i++){
              
              if((M[i][0]==1)&&(M[i][1]==1)&&(M[i][2]==1)&&(decision)){
                  cout << endl;
                  cout << "El juego ha terminado: Gana el jugador 1\n" << endl;
                  decision = false;
              }
              else {
                   if((M[0][i]==1)&&(M[1][i]==1)&&(M[2][i]==1)&&(decision)){
                        cout << endl;
                        cout << "El juego ha terminado: Gana el jugador 1\n" << endl;
                        decision = false;
                   }
                   else {
                        if ((M[i][0]==2)&&(M[i][1]==2)&&(M[i][2]==2)&&(decision)){
                            cout << endl;
                            cout << "El juego ha terminado: Gana el jugador 2\n" << endl;
                            decision = false;
                        } 
                        else{
                             if ((M[0][i]==2)&& (M[1][i]==2)&&(M[2][i]==2)&&(decision)){
                                  cout << endl;
                                  cout << "El juego ha terminado: Gana el jugador 2\n" << endl;
                                  decision = false;
                             }
                        } 
                   }
              }              
                 
      }     
      if ((M[0][0]==1)&&(M[1][1]==1)&&(M[2][2]==1)&&(decision)){
                  cout << endl;
                  cout << "El juego ha terminado: Gana el jugador 1\n" << endl;
                  decision = false;
      } 
      else {
           if ((M[0][2]==1)&&(M[1][1]==1)&&(M[2][0]==1)&&(decision)){
                  cout << endl;
                  cout << "El juego ha terminado: Gana el jugador 1\n" << endl;
                  decision = false;
            }
            else {
                 if ((M[0][0]==2)&&(M[1][1]==2)&&(M[2][2]==2)&&(decision)){
                  cout << endl;
                  cout << "El juego ha terminado: Gana el jugador 2\n" << endl;
                  decision = false;
                  }
                  else {
                       if ((M[0][2]==2)&&(M[1][1]==2)&&(M[2][0]==2)&&(decision)){
                           cout << endl;
                           cout << "El juego ha terminado: Gana el jugador 2\n" << endl;
                           decision = false;
                       }
                  } 
            }  
      }
      if ((empate==9)&&(decision)){
                     cout << endl;
                     cout << "El juego ha terminado: Empate\n" << endl;
                     decision = false;         
      }
                
} 

     
