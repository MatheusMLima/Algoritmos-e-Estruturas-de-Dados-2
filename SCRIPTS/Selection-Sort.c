#include <stdio.h>

int main()
{
    int vetor[8] = {2, 4, 5, 7, 1, 2, 3, 6}, i, j, min;

    for(i = 0; i <= 8-2; i++)
    {
        min = i;
        for(j = i+1; j <= 8-1; j++)
        {
            if(vetor[j] < vetor[min])
            {
                min = j;
            }
        }
        int aux = vetor[i];
        vetor[i] = vetor[min];
        vetor[min] = aux;
    }
    
    for(int i = 0; i < 8; i++)
    {
        printf("%d ", vetor[i]);
    }
}