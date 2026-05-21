#include <stdio.h>
#include <stdlib.h>

#define ASIGNATURAS 3
#define NOTA_APROBATORIA 6.0

// PROTOTIPOS DE FUNCIONES
void ingresarNotas(float **notas, int estudiantes);
void mostrarNotas(float **notas, int estudiantes);
void promedioEstudiante(float **notas, int estudiantes);
void promedioAsignatura(float **notas, int estudiantes);
void maximoMinimoEstudiante(float **notas, int estudiantes);
void maximoMinimoAsignatura(float **notas, int estudiantes);
void aprobadosReprobados(float **notas, int estudiantes);

int main() {

    int estudiantes;
    int i;

    printf("=========================================\n");
    printf(" SISTEMA DE GESTION DE CALIFICACIONES\n");
    printf("=========================================\n\n");

    // EL USUARIO INGRESA EL NUMERO DE ESTUDIANTES
    printf("Ingrese el numero de estudiantes: ");
    scanf("%d", &estudiantes);

    // RESERVA DINAMICA DE MEMORIA (PUNTEROS + ARREGLOS)
    float **notas;

    notas = (float **)malloc(estudiantes * sizeof(float *));

    for(i = 0; i < estudiantes; i++) {
        notas[i] = (float *)malloc(ASIGNATURAS * sizeof(float));
    }

    // LLAMADO DE FUNCIONES
    ingresarNotas(notas, estudiantes);
    mostrarNotas(notas, estudiantes);
    promedioEstudiante(notas, estudiantes);
    promedioAsignatura(notas, estudiantes);
    maximoMinimoEstudiante(notas, estudiantes);
    maximoMinimoAsignatura(notas, estudiantes);
    aprobadosReprobados(notas, estudiantes);

    // LIBERAR MEMORIA
    for(i = 0; i < estudiantes; i++) {
        free(notas[i]);
    }

    free(notas);

    return 0;
}

// FUNCION PARA INGRESAR NOTAS
void ingresarNotas(float **notas, int estudiantes) {

    int i, j;

    printf("\n=========== INGRESO DE NOTAS ===========\n");

    for(i = 0; i < estudiantes; i++) {

        printf("\nEstudiante %d\n", i + 1);

        for(j = 0; j < ASIGNATURAS; j++) {

            do {

                printf("Ingrese nota de la asignatura %d: ", j + 1);
                scanf("%f", &notas[i][j]);

                if(notas[i][j] < 0 || notas[i][j] > 10) {
                    printf("ERROR: La nota debe estar entre 0 y 10\n");
                }

            } while(notas[i][j] < 0 || notas[i][j] > 10);
        }
    }
}

// MOSTRAR TABLA DE NOTAS
void mostrarNotas(float **notas, int estudiantes) {

    int i, j;

    printf("\n=========================================\n");
    printf(" TABLA DE CALIFICACIONES\n");
    printf("=========================================\n");

    printf("Estudiante\tA1\tA2\tA3\n");

    for(i = 0; i < estudiantes; i++) {

        printf("%d\t\t", i + 1);

        for(j = 0; j < ASIGNATURAS; j++) {
            printf("%.1f\t", notas[i][j]);
        }

        printf("\n");
    }
}

// PROMEDIO POR ESTUDIANTE
void promedioEstudiante(float **notas, int estudiantes) {

    int i, j;
    float suma, promedio;

    printf("\n=========================================\n");
    printf(" PROMEDIO POR ESTUDIANTE\n");
    printf("=========================================\n");

    for(i = 0; i < estudiantes; i++) {

        suma = 0;

        for(j = 0; j < ASIGNATURAS; j++) {
            suma += notas[i][j];
        }

        promedio = suma / ASIGNATURAS;

        printf("Estudiante %d -> %.2f\n", i + 1, promedio);
    }
}

// PROMEDIO POR ASIGNATURA
void promedioAsignatura(float **notas, int estudiantes) {

    int i, j;
    float suma, promedio;

    printf("\n=========================================\n");
    printf(" PROMEDIO POR ASIGNATURA\n");
    printf("=========================================\n");

    for(j = 0; j < ASIGNATURAS; j++) {

        suma = 0;

        for(i = 0; i < estudiantes; i++) {
            suma += notas[i][j];
        }

        promedio = suma / estudiantes;

        printf("Asignatura %d -> %.2f\n", j + 1, promedio);
    }
}

// MAXIMO Y MINIMO POR ESTUDIANTE
void maximoMinimoEstudiante(float **notas, int estudiantes) {

    int i, j;
    float maximo, minimo;

    printf("\n=========================================\n");
    printf(" MAXIMO Y MINIMO POR ESTUDIANTE\n");
    printf("=========================================\n");

    for(i = 0; i < estudiantes; i++) {

        maximo = notas[i][0];
        minimo = notas[i][0];

        for(j = 1; j < ASIGNATURAS; j++) {

            if(notas[i][j] > maximo) {
                maximo = notas[i][j];
            }

            if(notas[i][j] < minimo) {
                minimo = notas[i][j];
            }
        }

        printf("Estudiante %d -> Max: %.1f | Min: %.1f\n",
               i + 1, maximo, minimo);
    }
}

// MAXIMO Y MINIMO POR ASIGNATURA
void maximoMinimoAsignatura(float **notas, int estudiantes) {

    int i, j;
    float maximo, minimo;

    printf("\n=========================================\n");
    printf(" MAXIMO Y MINIMO POR ASIGNATURA\n");
    printf("=========================================\n");

    for(j = 0; j < ASIGNATURAS; j++) {

        maximo = notas[0][j];
        minimo = notas[0][j];

        for(i = 1; i < estudiantes; i++) {

            if(notas[i][j] > maximo) {
                maximo = notas[i][j];
            }

            if(notas[i][j] < minimo) {
                minimo = notas[i][j];
            }
        }

        printf("Asignatura %d -> Max: %.1f | Min: %.1f\n",
               j + 1, maximo, minimo);
    }
}

// APROBADOS Y REPROBADOS
void aprobadosReprobados(float **notas, int estudiantes) {

    int i, j;
    int aprobados, reprobados;

    printf("\n=========================================\n");
    printf(" APROBADOS Y REPROBADOS\n");
    printf("=========================================\n");

    for(j = 0; j < ASIGNATURAS; j++) {

        aprobados = 0;
        reprobados = 0;

        for(i = 0; i < estudiantes; i++) {

            if(notas[i][j] >= NOTA_APROBATORIA) {
                aprobados++;
            } else {
                reprobados++;
            }
        }

        printf("Asignatura %d -> Aprobados: %d | Reprobados: %d\n",
               j + 1, aprobados, reprobados);
    }
}
