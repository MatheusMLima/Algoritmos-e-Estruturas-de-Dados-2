#include <stdio.h>

int main()
{
    int vetor[8] = {2, 4, 5, 7, 1, 2, 3, 6}, i, j;

    for(i = 0; i <= 8-2; i++)
    {
        for(j = 0; j <= 8-2-i; j++)
        {
            if(vetor[j+1] < vetor[j])
            {
                int aux = vetor[j+1];
                vetor[j+1] = vetor[j];
                vetor[j] = aux;
            }
        }
    }

    for(int i = 0; i < 8; i++)
    {
        printf("%d ", vetor[i]);
    }
}