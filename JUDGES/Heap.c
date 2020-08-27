#include <stdio.h>
#include <stdlib.h>

void heapsort(int vetor[], int tamanho);
void buildMaxHeap(int vetor[], int tamanho);
int HeapExtractMax(int vetor[], int tamanho);
void maxHeapfy(int vetor[], int i, int tamanho);


int main()
{
    int N,i;
    scanf("%d", &N);
    int vetor[N];
    for(i=0;i<N;i++)
    {
        scanf("%d", &vetor[i]);
    }
    heapsort(vetor,N);
}

void heapsort(int vetor[], int tamanho)
{
    buildMaxHeap(vetor,tamanho);
    int V[tamanho], i;
    int n = tamanho-1;
    while(n>=0)
    {
        V[n] = HeapExtractMax(vetor,n);
        n--;
    }
    for(i=0;i<tamanho;i++)
    {
        printf("%d ", V[i]);
    }
    printf("\n");
}

void buildMaxHeap(int vetor[], int tamanho)
{
    int i = (tamanho/2)-1;
    for(i; i >= 0; i--)
    {
        maxHeapfy(vetor,i,tamanho-1);
    }
    for(i=0;i<tamanho;i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");
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