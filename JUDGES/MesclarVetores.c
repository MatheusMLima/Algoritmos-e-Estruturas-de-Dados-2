#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ValoresVet1, ValoresVet2, ValoresVet3, *Vet1, *Vet2, *Vet3, i, j, aux;

    scanf("%d", &ValoresVet1);
    Vet1 = malloc(ValoresVet1 * sizeof(int));
    for(i=0;i<ValoresVet1;i++)
    {
        scanf("%d", &Vet1[i]);
    }

    scanf("%d", &ValoresVet2);
    Vet2 = malloc(ValoresVet2 * sizeof(int));
    for(i=0;i<ValoresVet2;i++)
    {
        scanf("%d", &Vet2[i]);
    }

    ValoresVet3 = ValoresVet1 + ValoresVet2;
    Vet3 = malloc(ValoresVet3 * sizeof(int));

    if(ValoresVet1 > ValoresVet2)
    {
        for(i=0;i<ValoresVet2;i++)
        {
            Vet3[i] = Vet2[i];
        }

        j = ValoresVet2;
        for(i=0;i<ValoresVet1;i++)
        {
            Vet3[j] = Vet1[i];
            j++;
        }
    }
    else
    {
        for(i=0;i<ValoresVet1;i++)
        {
            Vet3[i] = Vet1[i];
        }

        j = ValoresVet1;
        for(i=0;i<ValoresVet2;i++)
        {
            Vet3[j] = Vet2[i];
            j++;
        }
    }

    for(i=0;i<ValoresVet3;i++)
    {
        for(j=i+1;j<ValoresVet3;j++)
        {
            if(Vet3[i] > Vet3[j])
            {
                aux = Vet3[i];
                Vet3[i] = Vet3[j];
                Vet3[j] = aux;
            }
        }
    }

    for(i=0;i<ValoresVet3;i++)
    {
        printf("%d ", Vet3[i]);
    }

    free(Vet3);
    free(Vet1);
    free(Vet2);
}
