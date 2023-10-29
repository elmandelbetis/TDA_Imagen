# TDA_Imagen
Ejercicios sobre Procesamiento de Imágenes Digitales de la asignatura de Estructuras de Datos.

Consta de 4 ejercicios sobre el procesamiento de imágenes a partir de los métodos brindados por el profesorado para el TDA Imagen. El alumno debía implementar los métodos Crop, Zoom2X, Subsample y AdjustContrast, y acto seguido crear sus respectivos archivos main.cpp para probar si de verdad funcionaban.

Descripción de los archivos:

- image.cpp : Fichero con definiciones para los métodos primitivos de la clase Image. Brindados por el profesor en la realización de los ejercicios.

- imageop.cpp : Fichero con definiciones para el resto de los métodos de la clase Image realizados por el estudiante. Aquí el alumnado llama e implementa los métodos mencionados anteriormente.

- ImageIO.cpp : Fichero con definiciones para la E/S de imágenes. Brindado por el profesorado.

- negativo.cpp : Fichero estilo main.cpp brindado por el profesorado como ejemplo para realizar las pruebas de los métodos implementados en imageop.cpp. En este en concreto se proporciona como argumentos una imagen original, y una imagen resultado. Aquí, se calcula el valor negativo de los píxeles de la imagen, y se devuelve la imagen "negativizada".

- subimagen.cpp : Fichero main que se apoya en el método Image::Crop() y genera una subimagen a partir de una imagen original dada como argumento. Se pasan como parámetros dentro de los argumentos en la llamada al ejecutable, la fila y columna de la imagen original desde la que se empiezan a coger los píxeles, para luego definir en otros dos argumentos el nº de filas y columnas ocupados por la imagen resultante. Pensemos en el recorte de una imagen.

- zoom.cpp : Fichero main que se apoya en el método Image::Zoom2X() y genera una imagen con tamaño y zoom 2x a partir de una porción de una imagen dada, mediante cálculos de interpolación entre los píxeles de ésta.

- icono.cpp : Fichero main que, apoyándose en el método Image::Subsample() genera un icono bajo reducción condicionada por el parámetro <factor> a partir de una imagen dada y cargada en el programa.

- contraste.cpp : Fichero main que, apoyado sobre el método AdjustContrast() modifica y aumenta el contraste de una imagen bajo determinadas condiciones para los argumentos que se le pasan en terminal en la llamada a la ejecución del programa. 
