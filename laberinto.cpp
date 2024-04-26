#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

// Para controlar si se ha encontrado la salida del laberinto
bool encontradoLab = false;

// clase que representa el laberinto
class LaberintoPersonalizado {
public:
    int filasLab;
    int columnasLab;
    vector<vector<int>> matrizLab;      //matriz que almacenera la estructura del laberinto
    
    // Constructor
    LaberintoPersonalizado(int filas, int columnas) : filasLab(filas), columnasLab(columnas) {
        // matriz de tamanho filas por columnas
        matrizLab.assign(filas, vector<int>(columnas, 1)); // Todas las celdas seran paredes 1 inicialmente 
    }

    void imprimirLaberinto() {
        // Imprimir fila superior del borde, +2 para los bordes
        cout << "\033[31m";
        for (int j = 0; j < columnasLab + 2; j++) {
            cout << "#";
        }
        cout << "\033[0m" << endl;

        // imprimir filas internas del laberinto 
        for (int i = 0; i < filasLab; i++) {
            // Imprimir columna izquierda del borde
            cout << "\033[31m#\033[0m";
            for (int j = 0; j < columnasLab; j++) {
                if (i == 0 && j == 0) {
                    cout << "\033[34mE\033[0m"; // Marcador de entrada E en azul (ANSI)
                } else if (i == filasLab - 1 && j == columnasLab - 1) {
                    cout << "\033[34mS\033[0m"; // Marcador de salida S en azul (ANSI)
                } else if (matrizLab[i][j] == 1) {
                    cout << "#"; // Si es una pared, imprimir #
                } else if (matrizLab[i][j] == 2) {
                    cout << "\033[32mO\033[0m"; // Si es parte de la solución, imprimir O en verde (ANSI)
                } else {
                    cout << " "; // Si es un camino, imprimir espacio en blanco
                }
            }
            // Imprimir columna derecha del borde
            cout << "\033[31m#\033[0m" << endl;
        }

        // Imprimir fila inferior del borde
        cout << "\033[31m";
        for (int j = 0; j < columnasLab + 2; j++) {
            cout << "#";
        }
        cout << "\033[0m" << endl;
    }

    void generarCaminoLaberinto(int x, int y) {
        matrizLab[x][y] = 0; // Marcar la celda actual como camino

        // Definir las posibles direcciones a explorar
        vector<pair<int, int>> direcciones = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        // reorganizar aleatoriamente el orden en el que se explorarán las direcciones disponibles.
        random_shuffle(direcciones.begin(), direcciones.end());

        // iterar sobre cada direccion del vector direcciones, en orden aleatorio
        for (int i = 0; i < direcciones.size(); i++) {

            // sumamos el cambio el cambio correspondiente y *2, ya que necesita 2 celdas para desplazarse
            int nuevoX = x + direcciones[i].first * 2;
            int nuevoY = y + direcciones[i].second * 2;

            // Verificar si la nueva posición es válida y si es una pared (1)
            if (nuevoX >= 0 && nuevoX < filasLab && nuevoY >= 0 && nuevoY < columnasLab && matrizLab[nuevoX][nuevoY] == 1) {
                matrizLab[x + direcciones[i].first][y + direcciones[i].second] = 0; // Marcar la nueva posición como camino
                generarCaminoLaberinto(nuevoX, nuevoY); // Recursivamente generar un nuevo camino desde la nueva posición
            }
        }
    }

    void generarLaberinto() {
        generarCaminoLaberinto(0, 0); // Comenzar la generación del laberinto desde la posición inicial
    }

    void buscarSolucionLaberinto(int x, int y) {
        if (x == filasLab - 1 && y == columnasLab - 1) {
            encontradoLab = true;
        }
        matrizLab[x][y] = 2; // Marcar la celda actual como parte de la solución

        vector<pair<int, int>> direcciones = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for (int i = 0; i < direcciones.size(); i++) {
            int nuevoX = x + direcciones[i].first;
            int nuevoY = y + direcciones[i].second;
            if (nuevoX >= 0 && nuevoX < filasLab && nuevoY >= 0 && nuevoY < columnasLab && !encontradoLab && matrizLab[nuevoX][nuevoY] == 0) {
                buscarSolucionLaberinto(nuevoX, nuevoY); // Explorar recursivamente las direcciones posibles
            }
        }
    }
};

int main() {
    int filasLab, columnasLab;
    cout << "Ingrese el numero de filas del laberinto (debe ser impar): "; cin >> filasLab;
    cout << "Ingrese el numero de columnas del laberinto (debe ser impar): "; cin >> columnasLab;
    LaberintoPersonalizado laberintoPersonalizado(filasLab, columnasLab);
    laberintoPersonalizado.generarLaberinto();
    laberintoPersonalizado.buscarSolucionLaberinto(0,0);
    laberintoPersonalizado.imprimirLaberinto();
    return 0;
}
