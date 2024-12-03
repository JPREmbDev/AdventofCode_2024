#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int* arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        int pi = i + 1;

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int total_distance(int* left_list, int* right_list, int n) {
    quicksort(left_list, 0, n - 1);
    quicksort(right_list, 0, n - 1);

    int total_distance = 0;
    for (int i = 0; i < n; ++i) {
        total_distance += abs(left_list[i] - right_list[i]);
    }

    return total_distance;
}

int main() {
    FILE *file;
    int left_list[1000], right_list[1000];
    int left, right;
    int count = 0;
    struct timespec start, end;
    double elapsed_time;

    file = fopen("D:/Workspace/AdventofCode_2024/Dia_1/dia_1_imput_parte1.txt", "r");
    if (file == NULL) {
        printf("No se puede abrir el archivo\n");
        return 1;
    }

    while (fscanf(file, "%d %d", &left, &right) != EOF) {
        left_list[count] = left;
        right_list[count] = right;
        count++;
    }
    fclose(file);

    clock_gettime(CLOCK_MONOTONIC, &start);
    int distance = total_distance(left_list, right_list, count);
    clock_gettime(CLOCK_MONOTONIC, &end);

    elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

    printf("La distancia total es: %d\n", distance);
    printf("El tiempo de ejecución fue de %.9f segundos\n", elapsed_time);

    return 0;
}
