// Práctica 2 - Estructuras de Datos
// Abstracción. TDA Imagen

/*******************************
 * Álvaro Maldonado Medina y   *
 * Javier Jiménez Peláez       *
 * 2ºD, D2                     *
 * Fichero: zoom.cpp           *
 * Ejercicio 2                 *
********************************/

/**
 * @brief Genera una imagen con zoom 2x a partir de una porción de una imagen mediante interpolación.
 * @param <fich_orig> Imagen en formato PGM a partir de la que se va a generar una subimagen y aplicarle un zoom 2x
 * @param <fich_rdo> Imagen PGM resultante de calcularle el zoom 2x a la subimagen extraída a la imagen original
 * @param <fila> Fila de la imagen original desde la que se empiezan a coger pixeles
 * @param <col> Columna de la imagen original desde la que se empiezan a coger pixeles
 * @param <lado> Tamaño del lado de la subimagen a extraer de la original, para luego aplicarle el zoom 2x (p.ej. si lado = 60, el lado tras hacer el zoom y guardar será 120).
 * 
*/

#include <iostream>
#include <cstring>
#include <cstdlib>

#include "image.h"

using namespace std;

int main(int argc, char *argv[])
{
    char *fich_orig, *fich_rdo;
    Image imagen, zoom;

    int fila, col, lado;
    
    // Comprobación de argumentos escritos en la terminal durante la ejecución

    if (argc != 6){
        cerr << "Error: número de argumentos incorrecto" << endl;
        cerr << "Finalizando programa..." << endl;
        exit(1);
    }

    // Asignación de argumentos de la terminal a parámetros

    fich_orig = argv[1];
    fich_rdo = argv[2];
    fila = atoi(argv[3]);
    col = atoi(argv[4]);
    lado = atoi(argv[5]);

    // Muestra de la imagen de origen y destino

    cout << endl;
    cout << "Fichero original: " << fich_orig << endl;
    cout << "Fichero destino: " << fich_rdo << endl;

    // Comprobación de lectura del fichero original y si es correcto

    if (!imagen.Load(fich_orig)){
        cerr << "Error, no se puede leer y cargar la imagen original" << endl;
        cerr << "Programa finalizado" << endl;
        exit(1);
    }

    // Cálculo de la subimagen con zoom 2x llamando al método Zoom2X de la clase Image

    zoom = imagen.Zoom2X(fila, col, lado);

    // Muestra de la ruta donde se encuentra la imagen resultante y comprobación

    if (zoom.Save(fich_rdo)){
        cout << "La imagen se guardó en " << fich_rdo << endl;
        cout << "Programa finalizado" << endl;
    }
    else{
        cerr << "Error, no se pudo guardar la imagen" << endl;
        cerr << "Programa finalizado." << endl;
        exit(1);
    }

    return 0;
    
        
}