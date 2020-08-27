#include <stdio.h>
#include <stdlib.h>

void quickSort(int vetor[], int inicio, int final);
int partition(int vetor[], int inicio, int final);

int main()
{
    int vetor[11] = {1, 3, 0, 2, 1, 6, 9, 3, 6, 0, 1}, inicio, final;
    inicio = 0;
    final = 10;
    quickSort(vetor, inicio, final);

    for(int i = 0; i < 11; i++)
    {
        printf("%d ", vetor[i]);
    }
}
void quickSort(int vetor[], int inicio, int final)
{
    int meio;
    if(inicio < final)
    {
        meio = partition(vetor, inicio, final);
        quickSort(vetor, inicio, meio-1);
        quickSort(vetor, meio+1, final);
    }
}

int partition(int vetor[], int inicio, int final)
{
    int meio, a, b, c, medianaIndice, j;
    meio = (inicio+final)/2;
    a = vetor[inicio];
    b = vetor[meio];
    c = vetor[final];
    medianaIndice = 0; 

    if (a < b){
        if (b < c) {
            medianaIndice = meio;
        }
        else
        {
            if (a < c)
            {
                medianaIndice = final;
            }
            else
            {
                medianaIndice = inicio;
            } 
        }
    }
    else
    {
        if (c < b)
        {
            medianaIndice = meio; 
        }
        else
        {
            if (c < a)
            {
                medianaIndice = final;
            }
            else 
            {
                medianaIndice = inicio;
            }
        }
    }
    int aux = vetor[medianaIndice];
    vetor[medianaIndice] = vetor[final];
    vetor[final] = aux;

    int x = vetor[final];
    int i = inicio - 1;

    for(j = inicio; j < final; j++)
    {
        if(vetor[j] <= x)
        {
            i++;
            if(vetor[i] != vetor[j]){
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }

    aux = vetor[i+1];
    vetor[i+1] = vetor[final];
    vetor[final] = aux;

    return (i+1);
}