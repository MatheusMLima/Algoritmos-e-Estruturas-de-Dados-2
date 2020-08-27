#include <stdio.h>
#include <stdlib.h>

void countingSort(int VetorA[], int VetorB[], int tamanho, int k);

int main()
{
    int VetorA[11] = {1, 3, 0, 2, 1, 6, 9, 3, 6, 0, 1}, VetorB[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, tamanho, k;
    tamanho = 11;
    k = 9;
    countingSort(VetorA, VetorB, tamanho, k);
    for(int i = 0; i < 11; i++)
    {
        printf("%d ", VetorB[i]);
    }
}

void countingSort(int VetorA[], int VetorB[], int tamanho, int k)
{
    int i, VetorC[k+1], j;
    for(i = 0; i <= k; i++)
    {
        VetorC[i] = 0;
    }

    for(j = 1; j < tamanho; j++)
    {
        VetorC[VetorA[j]]++;
    }

    for(i = 1; i <= k; i++)
    {
        VetorC[i] += VetorC[i-1];
    }

    for(j = tamanho-1; j >= 0; j--)
    {
        VetorB[VetorC[VetorA[j]]] = VetorA[j];
        VetorC[VetorA[j]]--;
    }
}