#include <iostream>
#include "binarySearchTree.h"
#include "functions.h"

int main() {

    struct Tree *abeto; // Si, mi arbol binario es un abeto
    abeto = CrearArbol();

    struct nodoA *nodo_aux;
    nodo_aux = new struct nodoA;
    nodo_aux->matricula = "2460BZM";
    nodo_aux->tipo_vehiculo = 'G';
    nodo_aux->marca = "Citroen";
    nodo_aux->modelo = "Xantia";
    nodo_aux->potencia = 110;
    InsertarclaveArbol(abeto, nodo_aux);

    struct nodoA *nodo_aux2;
    nodo_aux2 = new struct nodoA;
    nodo_aux2->matricula = "3000DPX";
    nodo_aux2->tipo_vehiculo = 'G';
    nodo_aux2->marca = "Renault";
    nodo_aux2->modelo = "Laguna";
    nodo_aux2->potencia = 125;
    InsertarclaveArbol(abeto, nodo_aux2);

    struct nodoA *nodo_aux3;
    nodo_aux3 = new struct nodoA;
    nodo_aux3->matricula = "1010AAA";
    nodo_aux3->tipo_vehiculo = 'G';
    nodo_aux3->marca = "BMW";
    nodo_aux3->modelo = "320D";
    nodo_aux3->potencia = 125;
    InsertarclaveArbol(abeto, nodo_aux3);

    cout << "Tipo de vehículo: {G,D,M,I}" << endl;
//    InsertarclaveArbol(abeto, "5555PPP");
//    InsertarclaveArbol(abeto, "9999ZZZ");
//    InsertarclaveArbol(abeto, "1111ZZZ");
//
//    string A = "9995ZZZ";
//    const char *tab1 = A.c_str();
//
//    string Z = "9994ZZZ";
//    const char *tab2 = Z.c_str();
//
//    if(A > Z){
//        cout << "mayor" << endl;
//        printf("(%d) greater than (%d)", tab1,tab2);
//    }else{
//        cout << "menor" << endl;
//        printf("(%d) lower than (%d)", tab1,tab2);
//    }
//
//    std::cout << "Hello, World!" << std::endl;


    /*******************************************************************************
    Opciones
    *******************************************************************************/

    char option, selected;

    do{

        printMenu(); // Imprimir menú de opciones
        cin >> option;

        if(option == 'A'){

            /*******************************************************************************
            A)  Introducir un vehículo (junto con sus datos correspondientes) por teclado
                en el árbol. Se insertará de forma ordenada conforme a su matrícula
            *******************************************************************************/

            struct nodoA *nodo_aux;
            nodo_aux = new struct nodoA;

            // Generar matrícula automáticamente
            nodo_aux->matricula = generateID();

            // Pedir datos por pantalla
            cout << "Tipo de vehiculo: {G,D,M,I}" << endl;
            cin >> nodo_aux->tipo_vehiculo;

            cout << "Marca: " << endl;
            cin >> nodo_aux->marca;

            cout << "Modelo: " << endl;
            cin >> nodo_aux->modelo;

            cout << "Potencia: " << endl;
            cin >> nodo_aux->potencia;

            // Insertar
            InsertarclaveArbol(abeto, nodo_aux);

        }else if(option == 'B'){

            /*******************************************************************************
            B)  Buscar cualquier vehículo (a partir de su matrícula), introducida
                por teclado, en el árbol y mostrar sus datos.
            *******************************************************************************/

            string aux;
            struct nodoA *nodo_aux;
            nodo_aux = new struct nodoA;

            // Pedir datos por teclado
            cout << "Matricula: " << endl;
            cin >> aux;

            nodo_aux = DevolverclaveArbol(abeto->raiz, aux);

            if(nodo_aux != 0){ // Si el vehículo existe
                printVehicle(nodo_aux);
            }else{
                cout << "No existe el vehiculo" << endl;
            }


        }else if(option == 'C'){

            /*******************************************************************************
            C)  Imprimir todos los vehículos del ABB (sólo el dato matrícula) recorridos
                de cualquier forma: anchura, profundidad (PRE, IN, POST ORDEN). El
                recorrido en Inorden nos devolverá una secuencia ordenada de matrículas.
            *******************************************************************************/
            cout << "\nRecorridos Preorden, Inorden y Postorden:" << endl;
            cout << "\nPreorden:" << endl;
            preorden(abeto->raiz);
            cout << "\nInorden:" << endl;
            inorden(abeto->raiz);
            cout << "\nPostorden:" << endl;
            postorden(abeto->raiz);


        }else if(option == 'D'){

            /*******************************************************************************
            D)  Determinar el grado del árbol (número de nodos que tiene)
            *******************************************************************************/
            // NOTA: La definición de grado de un árbol:
            // Grado de un árbol: se corresponde con el máximo del grado de sus nodos.
            // - Árboles binarios: árboles de grado 2 (máximo de 2 hijos por nodo)

            int grado, total;

            cout << "Estadísticas" << endl;

            grado = calcularGradoArbol(abeto->raiz);
            cout << "Grado del arbol:" << grado << endl;

            total = calcularNumNodos(abeto->raiz);
            cout << "Numero de nodos del arbol:" << total << endl;

        }else if(option == 'E'){

            /*******************************************************************************
            E)  Determinar la altura máxima del árbol (máximo número de aristas desde el
                nodo raíz hasta el nodo hoja que se encuentre en un nivel más inferior).
            *******************************************************************************/

            // code...

        }else if(option == 'F'){

            /*******************************************************************************
            F)  Borrar un vehículo (a partir de su matrícula), introducido por
                teclado, si existe en el árbol.
            *******************************************************************************/

            // code...

        }else if(option == 'G'){

            /*******************************************************************************
            G)  Generar al azar los datos de 10 vehículos de cualquier tipo e
                insertarlos en el árbol.
            *******************************************************************************/

            // code...

        }else if(option == 'H'){

            /*******************************************************************************
            H)  Generar al azar 10 matrículas de vehículos y borrar los vehículos
                correspondientes, si existen, del árbol.
            *******************************************************************************/

            // code...

        }

    }while(option != 'I');

    cout << "Hasta luego!" << endl;

    return 0;
}
