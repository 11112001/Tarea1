#include <iostream>
#include "libs/NumberList.h"
#include "libs/NumberMatrix.h"

using namespace std;

void printMenu();

int main() {
    printMenu();

    int option = 0;
    NumberList list;
    NumberList listWithoutRepetitions;
    NumberList listWithRepetitions;
    NumberMatrix matrix;

    do {
        cout << "\nIngrese una opción: ";
        cin >> option;

        switch (option)
        {
            case 1:
                // Crear e imprimir una lista de 20 números aleatorios
                list = generateNumberListWithRandomNumbers(20, 1, 10); // Puedes ajustar el rango
                cout << "Lista generada: " << list.toString() << endl;
                break;

            case 2:
                // Crear e imprimir lista sin repetir
                listWithoutRepetitions = getNumberListWithoutRepetitions(list);
                cout << "Lista sin repeticiones: " << listWithoutRepetitions.toString() << endl;
                break;

            case 3:
                // Crear e imprimir lista con número de repeticiones
                listWithRepetitions = getNumberListWithNumberOfRepetitions(list, listWithoutRepetitions);
                cout << "Lista con número de repeticiones (formato: número, cantidad): " << listWithRepetitions.toString() << endl;
                break;

            case 4:
                // Generar e imprimir matriz 5x5 aleatoria
                matrix = generateNumberMatrixWithRandomNumbers(5, 5, 1, 100); // Puedes ajustar el rango
                cout << "Matriz generada: \n" << matrix.toString() << endl;
                break;

            case 5:
                // Mostrar mínimo por columna
                if (matrix.rowSize == 0) {
                    cout << "Primero debes generar la matriz (opción 4)." << endl;
                    break;
                }

                cout << "Valores mínimos por columna:" << endl;
                for (int i = 0; i < matrix.columnSize[0]; i++) {
                    cell c = matrix.getMinimumValueOfColumn(i);
                    cout << "Columna " << c.column << ": mínimo = " << c.value << " (fila " << c.row << ")" << endl;
                }
                break;

            case 0:
                cout << "Saliendo..." << endl;
                break;

            default:
                cout << "Opción inválida" << endl;
                break;
        }

    } while (option != 0);

    return 0;
}

void printMenu() {
    cout << "===== MENÚ =====" << endl;
    cout << "1. Crear e imprimir una lista de números enteros de 20 elementos." << endl;
    cout << "2. Crear e imprimir una lista de números sin repetir." << endl;
    cout << "3. Crear e imprimir una lista con el número de veces que aparece cada número en la lista del punto 1." << endl;
    cout << "4. Generar una matriz de 5x5 con números aleatorios." << endl;
    cout << "5. Imprimir los valores mínimos de cada columna (con número de columna y fila)." << endl;
    cout << "0. Salir" << endl;
}
