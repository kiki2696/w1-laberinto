## Generador de Laberintos Aleatorios y Solucionador de Laberintos
Este programa en C++ genera un laberinto aleatorio y proporciona un algoritmo para encontrar una solución para dicho laberinto.

## Generación Aleatoria
El programa utiliza un algoritmo recursivo para generar un laberinto aleatorio. Comienza con una cuadrícula de paredes y crea caminos aleatorios entre las celdas, asegurando que no haya bucles infinitos ni caminos que conduzcan a un callejón sin salida.

## Entendimiento del Laberinto
El laberinto se representa mediante una matriz bidimensional donde cada celda puede ser una pared (1) o un camino (0). La entrada se marca como 'E' y la salida como 'S'. El laberinto se imprime en la consola, mostrando los caminos en verde, las paredes en rojo y las celdas especiales en azul.

## Garantizando la Solucionabilidad
Antes de imprimir el laberinto, se asegura de que exista al menos una solución válida desde la entrada hasta la salida. El algoritmo de generación de laberintos se modifica ligeramente para garantizar que no se creen laberintos sin solución.

## Algoritmo de Solución
El algoritmo para encontrar la solución del laberinto utiliza una búsqueda recursiva en profundidad. Comienza desde la entrada y explora todas las posibles direcciones hasta encontrar la salida. Se marca cada celda visitada como parte de la solución.
