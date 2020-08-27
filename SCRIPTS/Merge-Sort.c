#include <stdio.h>
#include <stdlib.h>

void mergeSort(int vetor[], int inicio, int final);
void merge(int vetor[], int inicio, int meio, int final);

int main()
{
    int vetor[8] = {2, 5, 4, 7, 1, 2, 3, 6}, inicio, final;
    inicio = 0;
    final = 7;
    mergeSort(vetor, inicio, final);

    for(int i = 0; i < 8; i++)
    {
        printf("%d ", vetor[i]);
    }
}
void mergeSort(int vetor[], int inicio, int final)
{
    int meio;
    if(inicio < final)
    {
        meio = (inicio + final)/2;
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio+1, final);
        merge(vetor, inicio, meio, final);
    }
}

void merge(int vetor[], int inicio, int meio, int final)
{
    int n1 = meio - inicio + 1;
    int n2 = final - meio;
    int i, j, k;
    int *left = malloc(final * sizeof(int));
    int *right = malloc(final * sizeof(int));
    for(i = 0; i < n1; i++)
    {
        left[i] = vetor[inicio + i];
    }
    for(j = 0; j < n2; j++)
    {
        right[j] = vetor[meio + j + 1];
    }
    left[i] = 9999999;
    right[j] = 9999999;
    i = 0;
    j = 0;

    for(k = inicio; k <= final; k++)
    {
        if(left[i] <= right[j])
        {
            vetor[k] = left[i];
            i += 1;
        }
        else
        {
            vetor[k] = right[j];
            j += 1;
        }
    }
}



