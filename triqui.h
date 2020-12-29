
#ifndef TRIQUI_H
#define TRIQUI_H

void dibujar_juego (int M [3][3]);
bool posicion_ocupada (int F, int C, int M [3][3]);
bool posicion_valida (int F, int C);
void juzgar (int M[3][3], bool &decision, int empate);

#endif
