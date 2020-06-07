//
// Created by Javier on 06/06/2020.
//

#ifndef PRACTICA_2_ABB_BINARYSEARCHTREE_H
#define PRACTICA_2_ABB_BINARYSEARCHTREE_H

#endif //PRACTICA_2_ABB_BINARYSEARCHTREE_H

#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std;

/***********************************************************************
Declaración del tipo Arbol
***********************************************************************/

typedef struct nodoA
{
    string matricula;
    string marca; //{Renault, Ford, BMW…}
    string modelo; //{Megane, X1, Focus…}
    int potencia; // entero ? [1..1000]
    char tipo_vehiculo; // carácter ? {G,D,M,I}
    struct nodoA *izq,*der;
}*nodoarbol;
typedef struct Tree
{
    struct nodoA *raiz;
}*arbol;

/***********************************************************************
Crear arbol
***********************************************************************/

arbol CrearArbol()
{
    arbol ar= new struct Tree;
    ar->raiz = new struct nodoA;
    ar->raiz->izq = ar->raiz->der = NULL;
    ar->raiz->matricula = "";
    return(ar);
}

/***********************************************************************
Función para determinar si el arbol está vacío
***********************************************************************/

bool ArbolVacio(arbol ar)
{
    if (ar->raiz->matricula == "") return(true);
    else return(false);
}

/***********************************************************************
Función para determinar si un valor existe en el árbol
***********************************************************************/


bool BusquedaclaveArbol(nodoarbol nodo, string matricula)
{
    if (nodo == NULL) return(false);
    else
    {
        if (nodo->matricula == matricula) return(true);
        else
        {
            if (nodo->matricula < matricula) return(BusquedaclaveArbol(nodo->der,matricula));
            else return(BusquedaclaveArbol(nodo->izq,matricula));
        };
    };
}

/*******************************************************************************
Función que inserta una clave en el árbol si ésta no existe en él.
*******************************************************************************/

void InsertarclaveArbol(arbol ar, nodoA *item)
{
    struct nodoA *nodo_padre,*nodo_aux;
    nodo_padre = new struct nodoA;
    nodo_aux = new struct nodoA;
    nodo_padre = NULL;
    nodo_aux = ar->raiz;
    if (ArbolVacio(ar))
    {
        nodo_aux->matricula = item->matricula;
        nodo_aux->marca = item->marca;
        nodo_aux->modelo = item->modelo;
        nodo_aux->potencia = item->potencia;
        nodo_aux->tipo_vehiculo = item->tipo_vehiculo;
        return;
        //EN EL CASO DE QUE EL ARBOL ESTE VACIO SE ASIGNA LA CLAVE AL NODO RAIZ
    }
    while ((nodo_aux!=NULL) && (nodo_aux->matricula!=item->matricula))
    {
        nodo_padre = nodo_aux; //RECORRER HASTA POSICIONARSE DONDE INSERTAR
        if( item->matricula < nodo_aux->matricula) nodo_aux = nodo_aux->izq;
        else nodo_aux = nodo_aux->der;
    }
    /* Si SE HA ENCONTRADO EL ELEMENTO, NO SE PUEDE INSERTAR */
    if (nodo_aux!=NULL)
    {
        cout << item->matricula << " NO SE PUEDE INSERTAR PUES YA EXISTE" << endl;
        return;
    };



    struct nodoA *nodo;
    nodo = new struct nodoA;

    if(item->matricula < nodo_padre->matricula)
    {
        /* SI LA CLAVE A INSERTAR ES MENOR QUE LA QUE CONTIENE EL NODO PADRE
        SE INSERTA EN EL SUBARBOL IZQUIERDO */
        nodo_padre->izq = nodo;
    }
    else
    {
        /* SI LA CLAVE A INSERTAR ES MAYOR QUE LA QUE CONTIENE EL NODO PADRE
        SE INSERTA EN EL SUBARBOL DERECHO */
        nodo_padre->der = nodo;
    }

    nodo->matricula = item->matricula;
    nodo->marca = item->marca;
    nodo->modelo = item->modelo;
    nodo->potencia = item->potencia;
    nodo->tipo_vehiculo = item->tipo_vehiculo;
    nodo->izq = nodo->der = NULL;


}


/***********************************************************************
Función para devolver un valor si existe en el árbol
***********************************************************************/


nodoarbol DevolverclaveArbol(nodoarbol nodo, string matricula)
{
    if (nodo == NULL) return(nodo);
    else
    {
        if (nodo->matricula == matricula) return(nodo);
        else
        {
            if (nodo->matricula < matricula) return(DevolverclaveArbol(nodo->der,matricula));
            else return(DevolverclaveArbol(nodo->izq,matricula));
        };
    };
}

/***********************************************************************
Funciones de recorrido Pre, In y Post orden
***********************************************************************/

void Preorden(nodoarbol nodo){
    if (nodo != NULL) {
        cout << nodo->matricula << ": " << nodo->marca << " " << nodo->modelo << endl;
        Preorden(nodo->izq);
        Preorden(nodo->der);
    }
}

void Inorden(nodoarbol nodo){
    if (nodo != NULL) {
        Inorden(nodo->izq);
        cout << nodo->matricula << ": " << nodo->marca << " " << nodo->modelo << endl;
        Inorden(nodo->der);
    }
}

void Postorden(nodoarbol nodo){
    if (nodo != NULL){
        Postorden(nodo->izq);
        Postorden(nodo->der);
        cout << nodo->matricula << ": " << nodo->marca << " " << nodo->modelo << endl;
    }
}

/***********************************************************************
Número de nodos de un árbol
***********************************************************************/

int CalcularNumNodos(nodoarbol nodo){
    int cont = 1; //El nodo raiz se cuenta
    if (nodo == NULL)
        return 0;
    else
    {
        cont += CalcularNumNodos(nodo->izq);
        cont += CalcularNumNodos(nodo->der);
        return cont;
    }
}

/***********************************************************************
Funciones para calcular Altura del árbol: calcularAltura()
 y profundidad()
***********************************************************************/

int Profundidad(nodoarbol nodo, int nivel){
    int maxIzq = nivel;
    int maxDer = nivel;

    // hay que calcular profundidad en los dos caminos
    if(nodo != NULL){
        maxIzq = std::max(maxIzq, Profundidad(nodo->izq, nivel + 1));
        maxDer = std::max(maxDer, Profundidad(nodo->der, nivel + 1));
    }

    // devolver el máximo valor
    return std::max(maxIzq, maxDer);
}

int CalcularAltura(nodoarbol nodo){
    if (nodo == NULL)
        return 0;

    int maxIzq = 0;
    int maxDer = 0;

    // hay que calcular profundidad en los dos caminos
    if(nodo != NULL){
        maxIzq = std::max(maxIzq, Profundidad(nodo->izq, 0));
        maxDer = std::max(maxDer, Profundidad(nodo->der, 0));
    }

    // devolver el máximo valor
    return std::max(maxIzq, maxDer);

}


/***********************************************************************
Función borrar un nodo
***********************************************************************/

nodoarbol ExtremoIzquierdo(nodoarbol padre, nodoarbol nodo){

    if(nodo->izq == NULL){
        return padre;
    }else{
        ExtremoIzquierdo(padre->izq, nodo->izq);
    }

}

nodoarbol ExtremoDerecho(nodoarbol padre, nodoarbol nodo){
    if(nodo->der == NULL){
        return padre;
    }else{
        ExtremoIzquierdo(padre->der, nodo->der);
    }
}

nodoarbol BorrarNodoArbol(arbol ar, nodoarbol padre, nodoarbol nodo, string matricula)
{
    //nodoarbol padre;
    //padre == NULL;

    if (nodo != NULL)
    {
        if (nodo->matricula == matricula){

            if(nodo->izq == NULL && nodo->der == NULL){ // Si es nodo hoja

                if(padre->izq->matricula == nodo->matricula){ // Si raíz es la rama derecha de 'Padre'
                    padre->izq = NULL;
                } else if (padre->der->matricula == nodo->matricula){ // Si raíz es la rama izq de 'Padre
                    padre->der = NULL;
                } else if (padre == NULL){
                    ar->raiz == NULL;
                }

                //nodo = NULL;

                cout << "Borramos nodo hoja: " << nodo->matricula << endl;
            }else{ // Si no es nodo hoja
                nodoarbol nodo_aux, nodo_extremo;

                if(nodo->matricula < ar->raiz->matricula){ // Si es de la parte izquierda del arbol

                    nodo_extremo = ExtremoIzquierdo(padre,nodo);
                    if(nodo_extremo->der->matricula == nodo->matricula){ // si el extremo es igual al nodo que queremos borrar
                        nodo_aux = nodo->izq;
                        //delete(nodo->izq);
                        padre->der = nodo_aux;
                    }else{
                        padre->der = nodo_extremo->der;
                    }

                    //nodo = nodo_aux->der;
                    nodo_aux->der = NULL;

                }else{
                    nodo_extremo = ExtremoIzquierdo(padre,nodo);
                    if(nodo_extremo->izq->matricula == nodo->matricula){
                        nodo_aux = nodo->izq;
                        //delete(nodo->izq);
                        padre->izq = nodo_aux;
                    }else{
                        padre->izq = nodo_extremo->izq;
                    }
                }

                //nodo = nodoextremo;

                cout << "Borramos nodo interno: " << nodo->matricula << endl;
            }

            return 0;

        }
        else
        {
            if (nodo->matricula < matricula) return(BorrarNodoArbol(ar, nodo, nodo->der,matricula));
            else return(BorrarNodoArbol(ar, nodo, nodo->izq,matricula));
        };
    }else{
        return 0;
    }
}