
#ifndef TRADUCTOR_H
#define TRADUCTOR_H

#include <string>
using std::string;

bool buscar_palabra (string D [], string P);
int buscar_posicion (string D [], string P);
string traducir (string D [], string T [], string P);
string convertir_mayusculas (string P);

#endif
