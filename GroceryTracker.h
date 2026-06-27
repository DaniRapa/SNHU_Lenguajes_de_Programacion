#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H

#include <iostream>
#include <string>
#include <map>

using namespace std;

class GroceryTracker {

private:
    // Mapa que almacena el nombre del artículo y su frecuencia
    map<string, int> frecuencias;

public:
    // Constructor
    GroceryTracker();

    // Lee el archivo de entrada y llena el mapa
    void leerArchivo(string nombreArchivo);

    // Busca un artículo específico
    int buscarArticulo(string articulo);

    // Muestra todos los artículos y su frecuencia
    void mostrarFrecuencias();

    // Muestra el histograma
    void mostrarHistograma();

    // Crea el archivo frequency.dat
    void guardarArchivo(string nombreArchivo);
};

#endif