//
// Created by Javier on 06/06/2020.
//

#ifndef PRACTICA_2_ABB_FUNCTIONS_H
#define PRACTICA_2_ABB_FUNCTIONS_H

#endif //PRACTICA_2_ABB_FUNCTIONS_H

#include <iostream>

/***********************************************************************
Objeto vehiculo
***********************************************************************/
struct VEHICULO
{
    string marca; //{Renault, Ford, BMW…}
    string modelo; //{Megane, X1, Focus…}
    int potencia; // entero ? [1..1000]
    char tipo_vehiculo; // carácter ? {G,D,M,I}
};

/***********************************************************************
Generar matricula
***********************************************************************/
string generateID(){
    char const alphabet[] = {'B','C','D','F','G','H','J','K','L','M','N','P','R','S','T','V','W','X','Y','Z'};
    const char* numbers = "0123456789";

    char *m = (char*)malloc(sizeof(char)*16); // Es necesario para poder devolver m, ya que sino devuelve un puntero NULL
    string mat;
    int r;

    for (int i = 0; i < 7; ++i) { // Generamos cada letra

        if( i == 4 | i == 5 | i==6 ){

            r = (rand() % sizeof(alphabet));
            m[i] = alphabet[r];
            mat+=alphabet[r];
        }else{
            r = (rand() % 10);
            m[i] = numbers[r];
            mat+=numbers[r];
        }
    }

    return mat;
}


void printMenu(){

    cout << "\nOPCIONES:" << endl;
    cout << "   (A): Introducir un vehiculo" << endl;
    cout << "   (B): Buscar cualquier vehiculo" << endl;
    cout << "   (C): Imprimir todos los vehiculos del ABB" << endl;
    cout << "   (D): Determinar el grado del arbol" << endl;
    cout << "   (E): Determinar la altura maxima del árbol" << endl;
    cout << "   (F): Borrar un vehiculo" << endl;
    cout << "   (G): Generar al azar los datos de 10 vehiculos" << endl;
    cout << "   (H): Generar al azar 10 matrículas de vehiculos y borrar" << endl;
    cout << "   (I): Salir" << endl;

}

void printVehicle(nodoA *item){
    cout << "Datos del vehiculo:" << endl;
    cout << "- Matricula:" << item->matricula << endl;
    cout << "- Tipo:" << item->tipo_vehiculo << endl;
    cout << "- Marca:" << item->marca << endl;
    cout << "- Modelo:" << item->modelo << endl;
    cout << "- Potencia:" << item->potencia << endl;
}