// Práctica 2 Estructuras de Datos
// Abstracción. TDA Imagen

/*******************************
 * Álvaro Maldonado Medina y   *
 * Javier Jiménez Peláez       *
 * 2ºD, D2                     *
 * Fichero: subimagen.cpp      *
 * Ejercicio 1                 *
********************************/

/**
 * @brief Genera una subimagen a partir de una imagen dada
 * @param <fich_orig> Imagen en formato PGM a partir de la que se va a generar una subimagen 
 * @param <fich_rdo> Imagen PGM resultante de calcularle la subimagen a la anterior
 * @param <fila> Fila de la imagen original desde la que se empiezan a coger pixeles
 * @param <col> Columna de la imagen original desde la que se empiezan a coger pixeles
 * @param <filas_sub> Numero de filas de la imagen resultante
 * @param <cols_sub> Numero de columnas de la imagen resultante
*/

#include <iostream>
#include <cstring>
#include <cstdlib>

#include "image.h"

using namespace std;


int main(int argc, char *argv[]){
    
    char *fich_orig, *fich_rdo;
    Image imagen, subimagen;
    int fila, col, filas_sub, cols_sub;

    // Comprobamos la validez de la llamada en la terminal

    if (argc != 7){
        cerr << "Error, número de parámetros incorrecto" << endl;
        cerr << "Modo correcto: subimagen <fich_original> <fich_resultado> <fila> <col> <filas_sub> <cols_sub>";
        exit(1);
    }    

    // Asignación de los parámetros dados a las variables del programa

    fich_orig = argv[1];
    fich_rdo = argv[2];
    fila = atoi(argv[3]);
    col = atoi(argv[4]);
    filas_sub = atoi(argv[5]);
    cols_sub = atoi(argv[6]);

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

    // Mostramos los parámetros de la imagen

    cout << "Dimensiones de la imagen original " << fich_orig << ":" << endl;
    cout << "Imagen: " << imagen.get_rows() << " filas * " << imagen.get_cols() << " columnas" << endl;

    // Cálculo de la subimagen llamando al método Crop de la clase Image
    
    subimagen = imagen.Crop(fila, col, filas_sub, cols_sub);

    // Muestra de la ruta donde se encuentra la imagen resultante y comprobación

    if (subimagen.Save(fich_rdo)){
        cout << "La imagen se guardó en " << fich_rdo << endl;
    }
    else{
        cerr << "Error, no se pudo guardar la imagen" << endl;
        cerr << "Programa finalizado" << endl;
        exit(1);
    }

    return 0;

}