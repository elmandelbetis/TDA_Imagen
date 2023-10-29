// Práctica 2 - Estructuras de Datos
// Abstracción. TDA Imagen

/*******************************
 * Álvaro Maldonado Medina y   *
 * Javier Jiménez Peláez       *
 * 2ºD, D2                     *
 * Fichero: contraste.cpp      *
 * Ejercicio 4                 *
********************************/

/**
 * @brief Genera una imagen con un aumento en el contraste con respecto de la original
 * @param <fich_orig> Imagen en formato PGM a partir de la que se va a calcular el aumento de contraste
 * @param <fich_rdo> Imagen PGM donde se va a almacenar la imagen cuyo contraste ya ha sido aumentado
 * @param <e1> Umbral inferior de la imagen de entrada
 * @param <e2> Umbral superior de la imagen de entrada
 * @param <s1> Umbral inferior de la imagen resultante
 * @param <s2> Umbral superior de la imagen resultante
*/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include "image.h"
using namespace std;

int main(int argc, char *argv[]){

   char *fich_orig, *fich_rdo;
    Image imagen;

    int pixel, nuevo_pixel,
        e1, e2, s1, s2;

    // Comprobación de argumentos escritos en la terminal durante la ejecución

    if (argc != 7){
        cerr << "Error: número de argumentos incorrecto" << endl;
        cerr << "Finalizando programa..." << endl;
        exit(1);
    }

    // Asignación de argumentos de la terminal a parámetros

    fich_orig = argv[1];
    fich_rdo = argv[2];
    e1 = atoi(argv[3]);
    e2 = atoi(argv[4]);
    s1 = atoi(argv[5]);
    s2 = atoi(argv[6]);

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

    // Cálculo del aumento de contraste llamando al método AdjustContrast de la clase Image

    imagen.AdjustContrast((byte)e1, (byte)e2, (byte)s1, (byte)s2);

    // Muestra de la ruta donde se encuentra la imagen resultante y comprobación

    if (imagen.Save(fich_rdo)){
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