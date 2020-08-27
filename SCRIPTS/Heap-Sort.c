#include <stdio.h>
#include <stdlib.h>

void heapsort(int vetor[], int tamanho);
void buildMaxHeap(int vetor[], int tamanho);
int HeapExtractMax(int vetor[], int tamanho);
void maxHeapfy(int vetor[], int i, int tamanho);


int main()
{
    int vetor[11] = {1, 3, 0, 2, 1, 6, 9, 3, 6, 0, 1}, tamanho;
    tamanho = 11;
    heapsort(vetor,tamanho);
}

void heapsort(int vetor[], int tamanho)
{
    buildMaxHeap(vetor,tamanho);
    int V[tamanho];
    int n = tamanho-1;
    while(n>=0)
    {
        V[n] = HeapExtractMax(vetor,n);
        n--;
    }
    for(int i=0;i<11;i++)
    {
        printf("%d ", V[i]);
    }
}

void buildMaxHeap(int vetor[], int tamanho)
{
    int i = (tamanho/2)-1;
    for(i; i >= 0; i--)
    {
        maxHeapfy(vetor,i,tamanho-1);
    }
}

int HeapExtractMax(int vetor[], int tamanho)
{
    int n = tamanho;
    if(tamanho<0)
    {
        printf("Underflow");
    }
    int max = vetor[0];
    int last = tamanho;
    vetor[0] = vetor[last];
    maxHeapfy(vetor,0,n);
    return max;
}

void maxHeapfy(int vetor[], int i, int tamanho)
{
    int l = (2*i) + 1;
    int r = (2*i) + 2;
    int max = 0, aux = 0;
    if((l <= tamanho) && (vetor[l] > vetor[i]))
    {
        max = l;
    }
    else
    {
        max = i;
    }
    if((r <= tamanho) && (vetor[r] > vetor[max]))
    {
        max = r;
    }
    if(max!=i)
    {
        aux = vetor[i];
        vetor[i] = vetor[max];
        vetor[max] = aux;
        maxHeapfy(vetor,max,tamanho);
    }
}