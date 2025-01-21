#include <stdio.h>

// Função para trocar dois elementos
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função de partição
int partition(int list[], int low, int high) {
    int pivot = list[high]; // Pivô
    int i = low - 1;       // Índice do menor elemento

    for (int j = low; j < high; j++) {
        if (list[j] <= pivot) {
            i++;
            swap(&list[i], &list[j]);
        }
    }
    swap(&list[i + 1], &list[high]);
    return (i + 1);
}

// Função QuickSort
void quickSort(int list[], int low, int high) {
    if (low < high) {
        int pivot = partition(list, low, high);

        quickSort(list, low, pivot - 1);
        quickSort(list, pivot + 1, high);
    }
}

// Função para imprimir a Lista
void printList(int list[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

int main() {
    int list[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(list) / sizeof(list[0]);

    printf("Lista original:\n");
    printList(list, n);

    quickSort(list, 0, n - 1);

    printf("Lista ordenado:\n");
    printList(list, n);

    return 0;
}