#include "GroceryTracker.h"
#include <fstream>
#include <iomanip>

//==============================
// Constructor
//==============================
GroceryTracker::GroceryTracker() {

}

//==============================
// Leer archivo
//==============================
void GroceryTracker::leerArchivo(string nombreArchivo) {

    ifstream archivo(nombreArchivo);

    string articulo;

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    while (archivo >> articulo) {

        frecuencias[articulo]++;

    }

    archivo.close();

}

//==============================
// Buscar un artículo
//==============================
int GroceryTracker::buscarArticulo(string articulo) {

    if (frecuencias.find(articulo) != frecuencias.end()) {

        return frecuencias[articulo];

    }

    return 0;

}
//==============================
// Mostrar todas las frecuencias
//==============================
void GroceryTracker::mostrarFrecuencias() {

    cout << "\n===== FRECUENCIA DE ARTICULOS =====\n" << endl;

    for (const auto& elemento : frecuencias) {

        cout << left << setw(15)
             << elemento.first
             << elemento.second << endl;

    }

}

//==============================
// Mostrar histograma
//==============================
void GroceryTracker::mostrarHistograma() {

    cout << "\n===== HISTOGRAMA =====\n" << endl;

    for (const auto& elemento : frecuencias) {

        cout << left << setw(15)
             << elemento.first;

        for (int i = 0; i < elemento.second; i++) {

            cout << "*";

        }

        cout << endl;

    }

}

//==============================
// Crear archivo frequency.dat
//==============================
void GroceryTracker::guardarArchivo(string nombreArchivo) {

    ofstream salida(nombreArchivo);

    if (!salida.is_open()) {

        cout << "No se pudo crear el archivo." << endl;

        return;

    }

    for (const auto& elemento : frecuencias) {

        salida << elemento.first
               << " "
               << elemento.second
               << endl;

    }

    salida.close();

}