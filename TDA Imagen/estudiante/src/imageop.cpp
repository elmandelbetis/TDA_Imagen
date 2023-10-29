/**
 * @file imageop.cpp
 * @brief Fichero con definiciones para el resto de métodos de la clase Image realizados por el estudiante.
 */

#include <iostream>
#include <cmath>
#include <image.h>
#include<math.h>
#include <cassert>
using namespace std;

/**
 * @brief Genera una subimagen.
 * @param nrow Fila inicial para recortar.
 * @param ncol Columna inicial para recortar.
 * @param height Número de filas.
 * @param width Número de columnas.
 * @returns Imagen con el recorte.
 * @post El objeto que llama a la función no se modifica.
*/

Image Image::Crop(int nrow, int ncol, int height, int width) const 
{

    if (height == 0 || width == 0)
    {
        cerr << "ERROR: no se puede trabajar con una subimagen de tamaño 0.";
        exit(1);
    }

    Image subimage(height, width);

    for(int i = 0; i < height; i++)
    {
            for (int j = 0; j < width; j++)
            {
                subimage.set_pixel(i,j, get_pixel(nrow+i, ncol+j));
            }
    }

    return subimage;

    
}

/**
 * @brief Genera una imagen con zoom 2x a partir de una porción de una imagen mediante interpolación.
 * @returns Una nueva imagen extraída a partir de una porción de la original, con zoom 2x aplicado.
*/

Image Image::Zoom2X(int fila, int columna, int lado) const{
    Image imagen(2*lado-1,2*lado-1);
    int indice1 = 0, indice2;

    for (int i = 0; i < 2*lado-1; i+=2){
        indice2 = 0;
        for (int j = 0; j < 2*lado-1; j+=2){
            imagen.set_pixel(i, j, (byte)this->get_pixel(indice1+fila,indice2+columna));
            indice2++;
        }
        indice1++;
    }
    indice1 = 0;

    for (int i = 0; i < 2*lado-1; i+=2){
        indice2 = 0;
        for (int j = 1; j < 2*lado-1; j+=2){
            imagen.set_pixel(i, j, (byte) roundf((float)(this->get_pixel(indice1+fila,indice2+columna)+this->get_pixel(indice1+fila,indice2+1+columna))/2));
            indice2++;
        }
        indice1++;
    }

    for (int i = 1; i < 2*lado-1; i+=2){
        for (int j = 0; j < 2*lado-1; j++){
            if ((j+1) % 2 == 1)
                imagen.set_pixel(i, j, (byte) roundf((float)(imagen.get_pixel(i+1,j)+imagen.get_pixel(i-1,j))/2));
            else{
                float media = imagen.get_pixel(i-1,j-1)+imagen.get_pixel(i+1,j-1)+imagen.get_pixel(i-1,j+1)+imagen.get_pixel(i+1,j+1);
                imagen.set_pixel(i, j, (byte) roundf(media/4));
            }

        }
    }

    return imagen;
}

/**
 * @brief Genera un icono como reducción de una imagen.
 * @param factor Factor de reducción de la imagen original con respecto al icono.
 * @pre factor > 0.
 * @returns La imagen iconizada .
 * @post La imagen no se modifica.
 * @post La imagen resultante tendrá tamaño int(filas/factor) X int(columnas/factor). Descartando los decimales de la división.
*/

Image Image::Subsample(int factor) const{
    
    Image icono(floor(get_rows() / factor), floor(get_cols() / factor));

    for (int i = 0; i < icono.get_rows(); i++){
        for (int j = 0; j < icono.get_cols(); j++){

            float media = 0;

            for (int subfila = 0; subfila < factor; subfila++){
                for (int subcol = 0; subcol < factor; subcol++){

                    media += (float)get_pixel(subfila + factor * i, subcol + factor * j);

                }
            }

            media = media / (float)(factor * factor);
            icono.set_pixel(i,j,(byte)roundf(media));


        }
    
    }

    return icono;


}

/**
 * @brief Modifica el contraste de una imagen.
 * @param in1 Umbral inferior de la imagen de entrada.
 * @param in2 Umbral superior de la imagen de entrada.
 * @param out1 Umbral inferior de la imagen de salida.
 * @param out2 Umbral superior de la imagen de salida.
 * @pre 0 <= (in1, in2, out1, out2) <= 255
 * @pre in1 < in2
 * @pre out1 < out2
 * @post El objeto que llama a la función es modificado.
*/

void Image::AdjustContrast (byte in1, byte in2, byte out1, byte out2){
    
    if(0 <= (in1, in2, out1, out2) <= 255 && in1 < in2 && out1 < out2){

        float min, max, a, b;
        for (int i = 0; i < rows*cols; i++){
            
            byte pixel = get_pixel(i);
            byte pixel_nuevo;
            
            if(0 <= pixel && pixel <= in1){
                a = 0;
                b = (float)in1;
                min = 0;
                max = (float)out1;
            }
            else if(in1 <= pixel && pixel <= in2){
                a = (float)in1;
                b = (float)in2;
                min = (float)out1;
                max = (float)out2;
            }
            else if(in2 <= pixel && pixel <= 255){
                a = (float)in2;
                b = 255;
                min = (float)out2;
                max = 255;
            }

            pixel_nuevo = (byte)roundf((min + (((max - min) / (b - a)) * ((float)pixel - a))));
            this->set_pixel(i,pixel_nuevo);
        }
    }

}




