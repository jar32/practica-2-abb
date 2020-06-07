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


bool BusquedaclaveArbol(nodoarbol nodo, nodoA *item)
{
    if (nodo == NULL) return(false);
    else
    {
        if (nodo->matricula == item->matricula) return(true);
        else
        {
            if (nodo->matricula < item->matricula) return(BusquedaclaveArbol(nodo->der,item));
            else return(BusquedaclaveArbol(nodo->izq,item));
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
Función para determinar si un valor existe en el árbol
***********************************************************************/

void preorden(nodoarbol nodo){
    if (nodo != NULL) {
        cout << nodo->matricula << endl;
        preorden(nodo->izq);
        preorden(nodo->der);
    }
}

void inorden(nodoarbol nodo){
    if (nodo != NULL) {
        inorden(nodo->izq);
        cout << nodo->matricula << endl;
        inorden(nodo->der);
    }
}

void postorden(nodoarbol nodo){
    if (nodo != NULL){
        postorden(nodo->izq);
        postorden(nodo->der);
        cout << nodo->matricula << endl;
    }
}