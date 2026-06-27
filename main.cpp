#include "GroceryTracker.h"
#include <iostream>

using namespace std;

int main() {

    GroceryTracker tracker;

    // Leer el archivo de entrada
    tracker.leerArchivo("CS210_Project_Three_Input_File.txt");

    // Crear automáticamente el archivo de respaldo
    tracker.guardarArchivo("frequency.dat");

    int opcion;
    string articulo;

    do {

        cout << "\n=====================================\n";
        cout << "      CORNER GROCER TRACKER\n";
        cout << "=====================================\n";
        cout << "1. Buscar un articulo\n";
        cout << "2. Mostrar frecuencia de todos los articulos\n";
        cout << "3. Mostrar histograma\n";
        cout << "4. Salir\n";
        cout << "=====================================\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {

        case 1:

            cout << "\nIngrese el nombre del articulo: ";
            cin >> articulo;

            cout << "\nEl articulo \""
                 << articulo
                 << "\" fue comprado "
                 << tracker.buscarArticulo(articulo)
                 << " veces.\n";

            break;

        case 2:

            tracker.mostrarFrecuencias();

            break;

        case 3:

            tracker.mostrarHistograma();

            break;

        case 4:

            cout << "\nGracias por utilizar Corner Grocer.\n";

            break;

        default:

            cout << "\nOpcion invalida. Intente nuevamente.\n";

        }

    } while (opcion != 4);

    return 0;
}