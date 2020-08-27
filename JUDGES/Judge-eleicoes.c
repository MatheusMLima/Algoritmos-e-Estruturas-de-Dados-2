//as partes comentadas são vestigios do codigo antigo que tava dando runtime error, 
//apelei pro vetor padrão sem alocar nada para funcionar
//funciona normal com alocação de memoria, mas no judge da Unifesp não aceita

#include <stdlib.h>
#include <stdio.h>

void DescobreIndice(int Ncandidatos, float media[], int *indice, float *maior);

int main()
{
    int Neleitores = 0, Ncandidatos = 0, i, j, indice = 0, indice2;
    float contador = 0;

    while((Neleitores < 1 || Neleitores > 10000) && (Ncandidatos < 1 || Ncandidatos > 100))
    {
        scanf("%d %d", &Neleitores, &Ncandidatos);
    }
    
    int eleitores[Neleitores][3];
    float media[Ncandidatos+1], candidatos[Ncandidatos+1][2];

    /*eleitores = malloc(Neleitores * sizeof(int));
    candidatos = calloc((Ncandidatos+1), sizeof(int));
    media = malloc((Ncandidatos+1) * sizeof(float));*/

    /*for(i = 0; i < Neleitores; i++)
    {
        eleitores[i] = malloc(3 * sizeof(int));
    }*/

    for (i = 1; i <= Ncandidatos; i++)
    {
        candidatos[i][0] = 0;
        candidatos[i][1] = 0;
    }

    for(i = 0; i < Neleitores; i++)
    {
        for(j = 0; j < 3; j++)
        {
            scanf("%d", &eleitores[i][j]);
        }
    }

    for(i = 0; i < Neleitores; i++)
    {
        if(eleitores[i][0] >= 1 && eleitores[i][0] <= Ncandidatos)
        {
            int auxiliar = eleitores[i][0];
            candidatos[auxiliar][0] += 1;
            contador++;  
        }
    }

    if(contador == 0)
    {
        printf("0\n");
    }
    else
    {
        for(i = 1; i <= Ncandidatos; i++)
        {
            media[i] = (candidatos[i][0] * 100) / contador;
        }

        float maior = -1.0;
        float maior2 = -1.0;

        DescobreIndice(Ncandidatos,media,&indice,&maior);

        media[indice] = 0;

        DescobreIndice(Ncandidatos,media,&indice2,&maior2);

        if(maior >= 50.0)
        {
            printf("%d %.2f\n", indice, maior);
        }
        else
        {
            printf("%d %.2f\n", indice, maior);
            contador = 0;
            for(i = 0; i < Neleitores; i++)
            {
                for(j = 0; j < 3; j++)
                {   
                    if(eleitores[i][j] == indice || eleitores[i][j] == indice2)
                    {
                        int auxiliar = eleitores[i][j];
                        candidatos[auxiliar][1] += 1;
                        contador++;
                        j = 3;
                    }
                }   
            }

            media[indice] = (candidatos[indice][1] * 100) / contador;
            media[indice2] = (candidatos[indice2][1] * 100) / contador;

            if(media[indice] > media[indice2])
            {
                printf("%d %.2f\n", indice, media[indice]);
            }
            else if(media[indice] < media[indice2])
            {
                printf("%d %.2f\n", indice2, media[indice2]);
            }
            else if(media[indice] == media[indice2])
            {
                if(indice < indice2)
                {
                    printf("%d %.2f\n", indice, media[indice]);
                }
                else
                {
                    printf("%d %.2f\n", indice2, media[indice2]);
                }
            }
        }
    }

    /*for(i = 0; i < Neleitores; i++){
        free(eleitores[i]);
        free(candidatos[i]);
    }
    free(media);
    free(eleitores);
    free(candidatos);*/
}

void DescobreIndice(int Ncandidatos, float media[], int *indice, float *maior)
{
    int i, j;
    for(i = 1; i <= Ncandidatos; i++)
    {
        for (j = i+1; j <= Ncandidatos; j++)
        {
            if(media[i] >= media[j])
            {
                if(media[i] > *maior)
                {
                    *maior = media[i];
                    *indice = i;
                }
            }
            else
            {
                if(media[j] > *maior)
                {
                    *maior = media[j];
                    *indice = j;
                }
             }
        }
    }
}