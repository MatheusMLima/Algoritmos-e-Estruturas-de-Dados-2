#include <stdio.h>

int main()
{
    int vetor[8] = {2, 4, 5, 7, 1, 2, 3, 6}, i, j, key;

    for(j = 1; j <= 8; j++)
    {
        key = vetor[j];
        i = j-1;
        while((i >= 0) && (vetor[i] > key))
        {
            vetor[i + 1] = vetor[i];
            i -= 1;
        }
        vetor[i + 1] = key;
    }

    for(int i = 0; i < 8; i++)
    {
        printf("%d ", vetor[i]);
    }
}