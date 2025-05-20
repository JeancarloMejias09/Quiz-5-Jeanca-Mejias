/* Instrucciones breves a seguir. 
 * 
 *   1. Crear matriz m×n con valores aleatorios (1-100)
 *   2. Permite redimensionar a m2×n2 manteniendo valores existentes
 *   3. Llena nuevas posiciones con valores aleatorios
 *   4. Liberra toda la memoria correctamente
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funcion para una matriz de enteros en memoria dinamica mxn.
//
int** creacion_matriz(int m, int n) {
    int** matriz = (int**)malloc(m * sizeof(int*)); // Reservar memoria para 'm' filas (punteros a enteros)

    for (int i = 0; i < m; i++) {
        matriz[i] = (int*)malloc(n * sizeof(int));  // Reservar memoria para 'n' columnas en cada fila
    }
    return matriz; // Devolver nueva matriz.
}

// Funcion para llenar la matriz con números aleatorios de uno al cien (1-100)

void llenar_matriz(int** matriz, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = rand() % 100 + 1; // Asignar valor aleatorio entre 1 y 100
        }
    }
}

// Funcion para imprimir la matriz

void imprimir_matriz(int** matriz, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d ", matriz[i][j]); // Imprimir cada elemento con 3 de ancho.
        }
        printf("\n"); // Salto de linea.
    }
}

// Función para redimensionar la matriz

int** dimensionar_matriz(int** matriz, int m_old, int n_old, int m_new, int n_new) {
    int** nueva_matriz = creacion_matriz(m_new, n_new); // Crea una nueva matriz con las nuevas dimensiones

// Copiar los valores antiguos si aun caben en la nueva matriz

    for (int i = 0; i < m_new; i++) {
        for (int j = 0; j < n_new; j++) {
            if (i < m_old && j < n_old) {
                nueva_matriz[i][j] = matriz[i][j]; // Conserva el valor antiguo
            } else {
                nueva_matriz[i][j] = rand() % 100 + 1; // Rellenar nuevas posiciones con aleatorios
            }
        }
    }

// Liberar la memoria de la matriz antigua

    for (int i = 0; i < m_old; i++) {
        free(matriz[i]); // Libera cada fila
    }
    free(matriz); // Libera el arreglo de punteros

    return nueva_matriz; // Devuelve la nueva matriz redimensionada
}

// Función principal interaccion con usuario
int main() {
    srand(time(NULL)); // Inicia para números aleatorios

    int m, n, m2, n2;

    // Pide al usuario las dimensiones iniciales
    printf("Ingrese el número de filas (m): ");
    scanf("%d", &m);
    printf("Ingrese el número de columnas (n): ");
    scanf("%d", &n);

    int** matriz = creacion_matriz(m, n); // Crea la matriz inicial
    llenar_matriz(matriz, m, n);      // Llena la matriz con valores aleatorios

    printf("\nMatriz original:\n");
    imprimir_matriz(matriz, m, n);    // Muestra la matriz original

    // Solucitud al usuario las nuevas dimensiones
    printf("\nIngrese el nuevo número de filas (m2): ");
    scanf("%d", &m2);
    printf("Ingrese el nuevo número de columnas (n2): ");
    scanf("%d", &n2);

    matriz = dimensionar_matriz(matriz, m, n, m2, n2); // Redimensiona la matriz

    printf("\nMatriz redimensionada:\n");
    imprimir_matriz(matriz, m2, n2);  // Muestra la matriz redimensionada

    // Libera la memoria al finalizar
    for (int i = 0; i < m2; i++) {
        free(matriz[i]); // Liberar cada fila
    }
    free(matriz); // Libera el arreglo de punteritos

    return 0;
}
