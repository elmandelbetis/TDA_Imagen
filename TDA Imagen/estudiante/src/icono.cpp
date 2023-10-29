// Práctica 2 - Estructuras de Datos
// Abstracción. TDA Imagen

/*******************************
 * Álvaro Maldonado Medina y   *
 * Javier Jiménez Peláez       *
 * 2ºD, D2                     *
 * Fichero: icono.cpp          *
 * Ejercicio 3                 *
********************************/

/**
 * @brief Genera un icono bajo reducción <factor> a partir de una imagen dada
 * @param <fich_orig> Imagen en formato PGM a partir de la que se va a calcular el icono
 * @param <fich_rdo> Imagen en formato PGM donde se va a guardar el icono tras el cálculo
 * @param <factor> Factor de reducción de la imagen para calcular y generar el icono
*/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <image.h>
using namespace std;

int main(int argc, char *argv[])
{   
    char *fich_orig, *fich_rdo;
    Image imagen, icono;

    int factor;

    // Comprobación de argumentos escritos en la terminal durante la ejecución

    if (argc != 4){
        cerr << "Error: número de argumentos incorrecto" << endl;
        cerr << "Finalizando programa..." << endl;
        exit(1);
    }

    // Asignación de argumentos de la terminal a parámetros

    fich_orig = argv[1];
    fich_rdo = argv[2];
    factor = atoi(argv[3]);

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

    // Cálculo del icono llamando al método Subsample de la clase Image

    icono = imagen.Subsample(factor);

    // Muestra de la ruta donde se encuentra la imagen resultante y comprobación

    if (icono.Save(fich_rdo)){
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