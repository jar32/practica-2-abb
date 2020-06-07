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

    struct nodoA *nodo_aux4;
    nodo_aux4 = new struct nodoA;
    nodo_aux4->matricula = "1010ZZZ";
    nodo_aux4->tipo_vehiculo = 'G';
    nodo_aux4->marca = "BMW";
    nodo_aux4->modelo = "320D";
    nodo_aux4->potencia = 125;
    InsertarclaveArbol(abeto, nodo_aux4);

    struct nodoA *nodo_aux6;
    nodo_aux6 = new struct nodoA;
    nodo_aux6->matricula = "2000AAA";
    nodo_aux6->tipo_vehiculo = 'G';
    nodo_aux6->marca = "FIAT";
    nodo_aux6->modelo = "55";
    nodo_aux6->potencia = 125;
    InsertarclaveArbol(abeto, nodo_aux6);

    struct nodoA *nodo_aux5;
    nodo_aux5 = new struct nodoA;
    nodo_aux5->matricula = "1999AAA";
    nodo_aux5->tipo_vehiculo = 'G';
    nodo_aux5->marca = "FIAT";
    nodo_aux5->modelo = "55";
    nodo_aux5->potencia = 125;
    InsertarclaveArbol(abeto, nodo_aux5);

    struct nodoA *nodo_aux7;
    nodo_aux7 = new struct nodoA;
    nodo_aux7->matricula = "2001AAA";
    nodo_aux7->tipo_vehiculo = 'G';
    nodo_aux7->marca = "FIAT";
    nodo_aux7->modelo = "55";
    nodo_aux7->potencia = 125;
    InsertarclaveArbol(abeto, nodo_aux7);



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
            Preorden(abeto->raiz);
            cout << "\nInorden:" << endl;
            Inorden(abeto->raiz);
            cout << "\nPostorden:" << endl;
            Postorden(abeto->raiz);


        }else if(option == 'D'){

            /*******************************************************************************
            D)  Determinar el grado del árbol (número de nodos que tiene)
            *******************************************************************************/

            int total;

            total = CalcularNumNodos(abeto->raiz);
            cout << "Numero de nodos del arbol:" << total << endl;

        }else if(option == 'E'){

            /*******************************************************************************
            E)  Determinar la altura máxima del árbol (máximo número de aristas desde el
                nodo raíz hasta el nodo hoja que se encuentre en un nivel más inferior).
            *******************************************************************************/

            int altura;

            altura = CalcularAltura(abeto->raiz);
            cout << "Altura del arbol:" << altura << endl;

        }else if(option == 'F'){

            /*******************************************************************************
            F)  Borrar un vehículo (a partir de su matrícula), introducido por
                teclado, si existe en el árbol.
            *******************************************************************************/

            // code...
            string matricula;
            bool resp;

            // Pedir datos por teclado
            cout << "Matricula: " << endl;
            cin >> matricula;

            BorrarNodoArbol(abeto, NULL, abeto->raiz, matricula);

//            if(resp){ // Si el vehículo existe
//                cout << "Borrado con éxito" << endl;
//            }else{
//                cout << "No existe el vehiculo" << endl;
//            }

        }else if(option == 'G'){

            /*******************************************************************************
            G)  Generar al azar los datos de 10 vehículos de cualquier tipo e
                insertarlos en el árbol.
            *******************************************************************************/

            //Dataset vehículos
            struct VEHICULO vehiculos[37] = {
                    {"AUDI", "A4 2.0 TFSI", 211, 'G'},
                    {"AUDI", "A4 2.0 TDI", 140, 'D'},
                    {"AUDI", "A5 Sportback 3.0 TFSI", 272, 'G'},
                    {"BMW", "118i", 136, 'G'},
                    {"BMW", "320i", 184, 'G'},
                    {"BMW", "320d", 184, 'D'},
                    {"CITROEN", "Xantia Activa 3.0 V6", 196, 'G'},
                    {"CITROEN", "Xantia 2.0 HDI", 110, 'D'},
                    {"CITROEN", "CX GTI turbo 2", 90, 'D'},
                    {"DELOREAN", "DMC-12", 132, 'G'},
                    {"FIAT", "Multipla 7.0 V8", 1000, 'G'},
                    {"FORD", "Fiesta 1.4 TDCI", 70, 'D'},
                    {"FORD", "Model T", 20, 'G'},
                    {"JEEP", "Wrangler Sahara 4.0", 190, 'G'},
                    {"MERCEDES-BENZ", "C220 CDI", 143, 'D'},
                    {"MERCEDES-BENZ", "300 SL", 243, 'G'},
                    {"PEUGEOT", "308 GTi", 263, 'G'},
                    {"RENAULT", "Clio 1.5 dci", 100, 'D'},
                    {"RENAULT", "Laguna 1.9 dci", 119, 'D'},
                    {"SEAT", "Ibiza 1.4 TDI", 65, 'D'},
                    {"VOLKSWAGEN", "Polo 1.4 TDI", 80, 'D'},
                    {"APRILIA", "RS 660", 100, 'M'},
                    {"BMW", "F900XR", 105, 'M'},
                    {"HONDA", "CBR 600", 95, 'M'},
                    {"HONDA", "CB 650", 108, 'M'},
                    {"HONDA", "NC750X", 120, 'M'},
                    {"SUZUKI", "Marauder 250", 20, 'M'},
                    {"SUZUKI", "GSX 750", 95, 'M'},
                    {"SUZUKI", "Intruder C800", 75, 'M'},
                    {"EBRO", "470", 10, 'I'},
                    {"EBRO", "6067", 15, 'I'},
                    {"IVECO", "Eurocargo", 320, 'I'},
                    {"RENAULT", "T HIGH", 520, 'I'},
                    {"VOLVO", "FH16", 750, 'I'},
                    {"VOLVO", "FH", 450, 'I'},
                    {"VOLVO", "FMX", 330, 'I'},
                    {"VOLVO", "FMX", 330, 'I'},
            };

            int index;

            for (int i=0 ; i<10 ; i++){
                index = (rand() % (sizeof(vehiculos)/sizeof(VEHICULO)) );

                struct nodoA *nodo_aux;
                nodo_aux = new struct nodoA;
                nodo_aux->matricula = generateID();
                nodo_aux->tipo_vehiculo = vehiculos[index].tipo_vehiculo;
                nodo_aux->marca = vehiculos[index].marca;
                nodo_aux->modelo = vehiculos[index].modelo;
                nodo_aux->potencia = vehiculos[index].potencia;
                InsertarclaveArbol(abeto, nodo_aux);
            }

        }else if(option == 'H'){

            /*******************************************************************************
            H)  Generar al azar 10 matrículas de vehículos y borrar los vehículos
                correspondientes, si existen, del árbol.
            *******************************************************************************/
            string matricula;
            cout << "Matriculas generadas: " << endl;
            for (int i=0 ; i<10 ; i++){
                matricula = generateID();
                cout << i << ": " << matricula;
                if(BusquedaclaveArbol(abeto->raiz,matricula)){
                    //borrar aux
                    cout << " - Matricula " << i << " coincide! Procedemos al borrado" << endl;
                    BorrarNodoArbol(abeto, NULL, abeto->raiz, matricula);
                }else{
                    cout << " - No existe " << endl;
                }
            }

        }

    }while(option != 'I');

    cout << "Hasta luego!" << endl;

    return 0;
}
