#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void countingSort(char VetorA[][15], char VetorB[][15], int tamanho, int k);
void RedixSort(char VetorA[][15], int tamanho, int d, int PosFirst, int QuantNum);

int main()
{
    int NumOrd, i, PosFirst, QuantNum, j, d = -1, aux;
    scanf("%d", &NumOrd);
    char nomes[NumOrd+1][15];
    for(i = 1;i <= NumOrd;i++)
    {
        scanf("%s", nomes[i]);
        aux = strlen(nomes[i]);
        if(aux > d)
        {
            d = aux;
        }
    }

    scanf("%d %d", &PosFirst, &QuantNum);
    for (i = 1; i <= NumOrd; i++)
    {
        for (j = 0; nomes[i][j] != '\0'; j++)
        {
            if((nomes[i][j] > 64) && (nomes[i][j] < 91))
            {
                nomes[i][j] += 32;
            }
        }
    }

    RedixSort(nomes,NumOrd,d,PosFirst,QuantNum);
}

void RedixSort(char VetorA[][15], int tamanho, int d, int PosFirst, int QuantNum)
{
    int i,j;

    for(i = 1; i <= tamanho; i++)
    {
        for(j = 0; j < d; j++)
        {
            if((VetorA[i][j] <= 96) || (VetorA[i][j] >= 123))
            {
                VetorA[i][j] = 32;
                VetorA[i][j+1] = '\0';
            }
            else if(VetorA[i][j] == '\0')
            {
                VetorA[i][j] = 32;
                VetorA[i][j+1] = '\0';
            }
        }
    }

    char VetorB[tamanho+1][15];
    for (i = d-1; i >= 0; i--)
    {
        countingSort(VetorA,VetorB,tamanho,i);
    }

    //saida dos nomes
    for(i = PosFirst; i < (PosFirst+QuantNum); i++)
    {
        printf("%s\n", VetorB[i]);
    }
}

void countingSort(char VetorA[][15], char VetorB[][15], int tamanho, int k)
{
    int i, VetorC[27], j, help=0;

    for(i = 0; i <= 26; i++)
    {
        VetorC[i] = 0;
    }

    for(j = 1; j <= tamanho; j++)
    {
        if(VetorA[j][k] == 32)
        {
            VetorC[0]++;
        }
        else if((VetorA[j][k] > 96) && (VetorA[j][k] < 123))
        {
            help = VetorA[j][k];
            help -= 96;
            VetorC[help]++;
        }
    }

    for(i = 1; i <= 26; i++)
    {
        VetorC[i] += VetorC[i-1];
    }

    //primeira parte da saida
    for(i = 0; i < 27;i++)
    {
        printf("%d ", VetorC[i]);
    }
    printf("\n");

    for(j = tamanho; j > 0; j--)
    {
        if(VetorA[j][k] == 32)
        {
            help = 0;
            strcpy(VetorB[VetorC[help]], VetorA[j]);
            VetorC[help]--;
        }
        else if((VetorA[j][k] > 96) && (VetorA[j][k] < 123))
        {
            help = VetorA[j][k];
            help -= 96;
            strcpy(VetorB[VetorC[help]], VetorA[j]);
            VetorC[help]--;
        }
    }

    for(j = 1; j <= tamanho; j++)
    {
        strcpy(VetorA[j],VetorB[j]);
    }
}