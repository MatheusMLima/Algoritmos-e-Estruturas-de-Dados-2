#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quickSort(int vetor[], char nomes[][15], int inicio, int final);
int partition(int vetor[], char nomes[][15], int inicio, int final);

int main()
{
    int Npessoas, i, primeiro, m, j, l;
    scanf("%d", &Npessoas);

    int idade[Npessoas], idade2[Npessoas], aux = 0;
    char nomes[Npessoas][15], iguais[Npessoas][15];

    for(i = 0; i < Npessoas; i++)
    {
        scanf("%s", nomes[i]);
        strcpy(iguais[i],nomes[i]);
        scanf("%d", &idade[i]);
        idade2[i] = idade[i];
    }

    scanf("%d %d", &primeiro, &m);

    quickSort(idade, nomes, 0, Npessoas-1);

    for (i = 0; i < Npessoas; i++)
    {
        for (j = i+1; j < Npessoas; j++)
        {
            if(idade2[i]==idade2[j])
            {
                for(l = 0; l < Npessoas; l++)
                {
                    if(idade2[i] == idade[l])
                    {
                        if(strcmp(iguais[i],nomes[l])==0)
                        {
                            l = Npessoas;
                            j = Npessoas;
                        }
                        else
                        {
                            l = Npessoas;
                            j = Npessoas;
                            i = Npessoas;
                            aux = 1;
                        }
                    }
                }
            }
        }
    }

    if(aux == 0)
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }

    for(i = primeiro-1; i < (primeiro+m)-1; i++)
    {
        printf("%s %d\n", nomes[i], idade[i]);
    }

}
void quickSort(int vetor[], char nomes[][15], int inicio, int final)
{
    int meio;
    if(inicio < final)
    {
        meio = partition(vetor, nomes, inicio, final);
        quickSort(vetor, nomes, inicio, meio-1);
        quickSort(vetor, nomes, meio+1, final);
    }
}

int partition(int vetor[], char nomes[][15], int inicio, int final)
{
    int meio, a, b, c, medianaIndice, j;
    char aux1[15];
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

    strcpy(aux1, nomes[medianaIndice]);
    strcpy(nomes[medianaIndice], nomes[final]);
    strcpy(nomes[final], aux1);

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

                strcpy(aux1, nomes[i]);
                strcpy(nomes[i], nomes[j]);
                strcpy(nomes[j], aux1);
            }
        }
    }

    aux = vetor[i+1];
    vetor[i+1] = vetor[final];
    vetor[final] = aux;

    strcpy(aux1, nomes[i+1]);
    strcpy(nomes[i+1], nomes[final]);
    strcpy(nomes[final], aux1);

    return (i+1);
}