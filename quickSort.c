#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Define uma constante
// Define a constant
#define MAX 10000

void quick_sort(int *a, int left, int right);

// Função main
// Main Function
int main()
{
    clock_t t;
    srand(time(NULL));
    int i, vet[MAX];
    int vAux;
    // Lê MAX ou 10 valores
    // Read MAX or 10 values
    for (vAux = 0; vAux < MAX; vAux++)
    {
        vet[vAux] = (rand()); // Preenche o vetor aleatóriamente;
        printf(" %d,", vet[vAux]);
    }

    printf("\n");
    t = clock();
    printf("\n");
    // Ordena os valores
    // Order values
    quick_sort(vet, 0, MAX - 1);

    // Imprime os valores ordenados
    // Print values in order ascendant
    printf("Valores ordenados\n");
    for (i = 0; i < MAX; i++)
    {
        printf("%d, ", vet[i]);
    }
    printf("\n");
    t = clock() - t;
    printf("Tempo de execucao: %1fs\n", ((double)t) / ((CLOCKS_PER_SEC)));
    system("pause");
    return 0;
}

// Função de Ordenação por Seleção
// Quick sort function
void quick_sort(int *a, int left, int right)
{
    int i, j, x, y;

    i = left;
    j = right;
    x = a[(left + right) / 2];

    while (i <= j)
    {
        while (a[i] < x && i < right)
        {
            i++;
        }
        while (a[j] > x && j > left)
        {
            j--;
        }
        if (i <= j)
        {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }

    if (j > left)
    {
        quick_sort(a, left, j);
    }
    if (i < right)
    {
        quick_sort(a, i, right);
    }
}